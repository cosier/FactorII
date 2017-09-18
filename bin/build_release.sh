#!/bin/sh

set -euf -o pipefail

BIN="$( cd  "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ROOT=$( cd $BIN/../ && pwd )

source $BIN/vars.sh
$BIN/clean.sh
RELEASE=true $BIN/build.sh