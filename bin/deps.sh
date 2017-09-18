#!/bin/bash
set -euf -o pipefail

BIN="$( cd  "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
source $BIN/vars.sh

if [[ ! -d $VENDOR/ubelt ]]; then
  echo "ubelt: initialising submodule"
  git submodule update --init --recursive
else
  echo "ubelt:                 ready"
fi

VENDOR_PREFIX=$VENDOR/build

######################################
# Depend on Nuklear
if [[ ! -f $VENDOR/nuklear/nuklear.h ]]; then
  echo "nuklear: initialising submodule"
  git submodule update --init --recursive
else
  echo "nuklear:               ready"
fi

######################################
# Depend on Freetype2
LIBFREETYPE=$VENDOR_PREFIX/lib/libfreetype.a
if [[ ! -f $LIBFREETYPE ]]; then
  echo "libfreetype:           building"

  # Apply apple specific patch for builing with xcode
  cd $ROOT/vendor/freetype
  ./autogen.sh
  ../configure \
    --prefix=$VENDOR_PREFIX

  if [[ "$?" != 0 ]]; then
    echo "libfreetype2: failed to configure freetype"
    exit 1
  fi

  make -j4
  if [[ "$?" != 0 ]]; then
    echo "libfreetyp: failed to build freetype"
    exit 1
  fi

  make install
  if [[ -f $LIBDB ]]; then
    echo "libfreetype: installed successfully"
  else
    echo -e "libfreetype: failed to install libdb to:\n$LIBFREETYPE"
  fi

else
  echo "libfreetype:           ready ($(basename $LIBFREETYPE))"
fi

######################################
# Depend on Berkeley DB, aka. libDB
LIBDB=$VENDOR_PREFIX/lib/libdb.a
if [[ ! -f $LIBDB ]]; then
  echo "libdb: building"

  # Apply apple specific patch for builing with xcode
  # if [[ $TARGET_OS == "Darwin" ]]; then
    # patch --forward --quiet  \
      # $ROOT/vendor/libdb/src/dbinc/atomic.h < \
      # $ROOT/vendor/patches/libdb_atomic.patch
  # fi

  cd $ROOT/vendor/libdb/build_unix
  ../dist/configure \
    --prefix=$VENDOR_PREFIX --enable-static
  if [[ "$?" != 0 ]]; then
    echo "libdb: failed to configure berkeley db"
    exit 1
  fi

  make -j4
  if [[ "$?" != 0 ]]; then
    echo "libdb: failed to build berkeley db"
    exit 1
  fi

  make install
  if [[ -f $LIBDB ]]; then
    echo "libdb: installed successfully"
  else
    echo -e "libdb: failed to install libdb to:\n$LIBDB"
  fi

else
  echo "libdb:                 ready ($(basename $LIBDB))"
fi

echo -e "======================="
