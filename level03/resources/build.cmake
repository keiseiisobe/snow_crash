execute_process(
	COMMAND cp /etc/burbclave/burbclave.conf /var/lib/burbclave/staging/copy/
	COMMAND cp /home/flag03/.flag /var/lib/burbclave/staging/copy/
	COMMAND chmod 777 /var/lib/burbclave/staging/copy/burbclave.conf /var/lib/burbclave/staging/copy/.flag
)
