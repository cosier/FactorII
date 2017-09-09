#!/bin/bash
set -euf -o pipefail

BIN="$( cd  "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
source $BIN/vars.sh

if [[ ! -d $ROOT/vendor/ubelt ]]; then
  echo "ubelt: initialising submodule"
  git submodule update --init --recursive
else
  echo "ubelt: found"
fi

VENDOR_PREFIX=$ROOT/vendor/build
LIBDB=$VENDOR_PREFIX/lib/libdb.a

if [[ ! -f $LIBDB ]]; then
  echo "libdb: building"
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
  echo -e "libdb: found vendorized $(basename $LIBDB)"
fi

