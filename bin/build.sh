#!/bin/bash

BIN="$( cd  "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ROOT=$( cd $BIN/../ && pwd )

source $BIN/vars.sh

# Provide clean hooks from the cli
if [[ "$1" == "clean" ]]; then
  rm -rf $ROOT/build
fi

# Ensure build dir exists and change directory
mkdir -p $BUILD_DIR && cd $BUILD_DIR;

if [[ "$RELEASE" == true ]]; then
  CMAKE_BUILD_TYPE=Release
elif [[ "$DEBUG" == true ]]; then
  CMAKE_BUILD_TYPE=Debug
fi

# Fallback to Debug build if no explicit type found
if [ -z "$CMAKE_BUILD_TYPE" ]; then
  CMAKE_BUILD_TYPE=Debug
fi

export BUILD_REVISION=$(git rev-parse --short --verify HEAD)
export BUILD_TIMESTAMP=$(date)

if [[ "$BUILD_REVISION" == "" ]]; then
  echo "Invalid Build Revision: $BUILD_REVISION"
  exit 1
fi

echo
echo -e " Building: $CMAKE_BUILD_TYPE"
echo -e " BUILD_TIMESTAMP: $BUILD_TIMESTAMP"
echo -e " BUILD_REVISION: $BUILD_REVISION "
echo -e "-------------------------------------\n"

# If Makefile doesn't exist, initiate cmake to generate it.
if [[ ! -f $BUILD_DIR/Makefile ]]; then
  cmake \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -DCMAKE_BUILD_TYPE=$CMAKE_BUILD_TYPE ..
  if [ ! $? -eq 0 ]; then
    exit 1
  fi
fi

# Run the build compiler
make -j4
if [ ! $? -eq 0 ]; then
  echo "Make failed"
  exit 1
fi

if [ ! -f $EXE_LINK ]; then
  ln -sf $EXE_BUILD $EXE_LINK
fi

