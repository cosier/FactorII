#!/bin/bash
set -euf -o pipefail

BIN="$( cd  "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ROOT=$( cd $BIN/../ && pwd )

source $BIN/vars.sh

if [ -d $BUILD_DIR ]; then
  rm -rf $BUILD_DIR/CMakeCache.txt
  rm -rf $BUILD_DIR/vendor
  rm -rf $BUILD_DIR/tests
  rm -rf $BUILD_DIR/src
fi
