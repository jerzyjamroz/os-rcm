#use "TFTP_GET_FIRMWARE.LIB"

int main()
{
	int result;
	char url[128];
	char localfile[128];

	printf( "Firmware Download Sample (TFTP)\n\n");

	printf( "Initializing TCP/IP stack...\n");

	// Start network and wait for interface to come up (or error exit).
	sock_init_or_exit(1);

	printf( "Press any key to download\n\t%s from %s\n", TFTP_FILE, TFTP_SERVER);
	getchar();
	printf( "Connecting...\n");

	result = tftp_and_install( TFTP_SERVER, TFTP_FILE);

	if (result)
	{
		exit( result);
	}

	return 0;
}