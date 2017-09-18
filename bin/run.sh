#!/bin/bash

BIN="$( cd  "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ROOT=$( cd $BIN/../ && pwd )
source $BIN/vars.sh

# Ensure build is up to date before running.
$BIN/build.sh

if [[ $? != 0 ]]; then
  echo "Build Failed"
  exit 1
fi

D=${D:-${DISPLAY}}
echo "DISPLAY=$D"

BUILD_TYPE=${BUILD_TYPE:-_debug}

CMD="${ROOT}/build/${APP_EXE_NAME}${BUILD_TYPE} $@"
echo $CMD
DISPLAY=$D $CMD
