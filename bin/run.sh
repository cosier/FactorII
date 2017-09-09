#!/bin/bash

BIN="$( cd  "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ROOT=$( cd $BIN/../ && pwd )
source $BIN/vars.sh

# Provide clean hooks from the cli
if [[ $1 == "clean" ]]; then
  shift;
  $BIN/clean.sh
fi

# Provide auto build hooks from the cli
if [[ $1 == "build" ]]; then
  shift;
  $BIN/build.sh

  if [[ $? != 0 ]]; then
    echo "Build Failed"
    exit 1
  fi
fi

# If the executable output does not exist, build it first
if [[ ! -f $EXE_BUILD ]]; then
  $BIN/build.sh

  if [[ $? != 0 ]]; then
    echo "Build Failed"
    exit 1
  fi
fi

CMD="$EXE_BUILD $@"
echo $CMD
$CMD
