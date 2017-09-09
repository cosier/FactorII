#!/bin/bash
set -euf -o pipefail

BIN="$( cd  "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ROOT=$( cd $BIN/../ && pwd )

BUILD_DIR=$ROOT/build

EXE_NAME=factorii
EXE_BUILD=$BUILD_DIR/src/main/$EXE_NAME
EXE_LINK=$ROOT/bin/$EXE_NAME

