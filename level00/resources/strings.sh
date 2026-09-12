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
    file_name=$(sshpass -e ssh -p "$PORT" "$USER"@"$ADDRESS" "find / -type f -user flag00 2> /dev/null")
    echo -e "\nGot a binary file:"
    echo -e $file_name
    sshpass -e scp -P $PORT $USER@$ADDRESS:$file_name ./
   
    echo -e "\nRunning strings command to an extracted file ..."
    echo -e "\n\n\n---------- Output ----------"

    strings ./hiro

    echo -e "----------------------------"
fi    
