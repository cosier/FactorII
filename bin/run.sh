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

CMD="$EXE_BUILD $@"
echo $CMD
DISPLAY=$D $CMD
