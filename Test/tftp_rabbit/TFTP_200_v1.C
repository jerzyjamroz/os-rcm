	#define TFTP_SERVER  "84.89.255.184"
	#define TFTP_FILE "HVS.bin"

	#define BU_TEMP_USE_SFLASH			// use serial data flash (without FAT)

#define TCPCONFIG 3
#if(_FIRMWARE_VERSION_ == 1 || _FIRMWARE_VERSION_ == 3)
	#define _PRIMARY_STATIC_IP  "192.168.1.200"
#else
	#define _PRIMARY_STATIC_IP  "192.168.1.201"
#endif
#define _PRIMARY_NETMASK    "255.255.255.0"
#define MY_GATEWAY          "192.168.1.1"

#define  STDIO_DEBUG_SERIAL   SDDR
#define	STDIO_DEBUG_BAUD		115200
#define	STDIO_DEBUG_ADDCR

#define TIMEOUT_LENGTH	10000

#memmap xmem

#define MAX_UDP_SOCKET_BUFFERS 2

#use "dcrtcp.lib"
#use tftp_get_firmware.lib

//#use "dcrtcp.lib"
//#use "tftp.lib"

//#use "sflash.lib"


udp_Socket demosock;



int main()
{
	int result;
	char url[128];
	char localfile[128];

	printf( "Firmware Download Sample (TFTP)\n\n");

	printf( "Initializing TCP/IP stack...\n");

	// Start network and wait for interface to come up (or error exit).
	sock_init_or_exit(1);

   printf("this version is %d\n", _FIRMWARE_VERSION_);

	printf( "Press any key to download\n\t%s from %s\n", TFTP_FILE,TFTP_SERVER);

   while(1)
   {

   	if(kbhit())
      {
      	getchar();
			printf( "Connecting...\n");

			result = tftp_and_install( TFTP_SERVER, TFTP_FILE);

			if (result)
         {
            exit( result);
         }
      }
      costate
      {
      	tcp_tick(NULL);

         waitfor(DelayMs(1000));
      }
   }

	return 0;
}

