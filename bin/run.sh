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

DISPLAY=${DISPLAY:-}

if [[ -n ${D-:} ]]; then
  DISPLAY=${D:-}
fi

echo "DISPLAY=$DISPLAY"

CMD="$EXE_BUILD $@"
echo $CMD
DISPLAY=$DISPLAY $CMD
