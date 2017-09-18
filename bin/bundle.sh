#!/bin/sh

set -euf -o pipefail

BIN="$( cd  "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ROOT=$( cd $BIN/../ && pwd )

source $BIN/vars.sh
DEFAULT_BUILD=debug
BUILD_TYPE=${1:-debug}
EXE=$BUILD_DIR/${APP_EXE_NAME}_${BUILD_TYPE}

if [ ! -f $EXE ]; then
    if [ -f $BUILD_DIR/${APP_EXE_NAME} ]; then
        mv $BUILD_DIR/${APP_EXE_NAME} $BUILD_DIR/${APP_EXE_NAME}_${BUILD_TYPE}
    else
        exit 1;
    fi
fi

if [[ "$(uname)" == "Darwin" ]]; then
    echo "Bundling MacOS Application"
    TARGET_APP=$BUILD_DIR/factorii_${BUILD_TYPE}.app
    if [ -d $TARGET_APP ]; then
        rm -rf $TARGET_APP
    fi

    cp -Rv $ROOT/assets/factorii.app $TARGET_APP
    cp $EXE $BUILD_DIR/factorii_${BUILD_TYPE}.app/Contents/MacOS/fii
fi
