#ifndef TFTP_SERVER
	#define TFTP_SERVER  "84.89.255.184"
	#define TFTP_FILE "firmware.bin"
#endif

//	#define BU_TEMP_USE_FAT				// use file on FAT filesystem
//	#define BU_TEMP_USE_SBF				// use unused portion of serial boot flash
	#define BU_TEMP_USE_SFLASH			// use serial data flash (without FAT)
//	#define BU_TEMP_USE_DIRECT_WRITE	// write directly to boot firmware image

//	#define BU_TEMP_PAGE_OFFSET 0     //----------------------------------------

//#define TCPCONFIG 5

// Make sure an option has been enabled.
#if ! defined BU_TEMP_USE_FAT && \
	 ! defined BU_TEMP_USE_SBF && \
	 ! defined BU_TEMP_USE_SFLASH && \
	 ! defined BU_TEMP_USE_DIRECT_WRITE && \
	 ! defined BU_ENABLE_SECONDARY
#fatal "You must uncomment a BU_TEMP_USE_xxx macro at the top of this sample."
#endif

// need a UDP buffer for the TFTP connection
//#define MAX_UDP_SOCKET_BUFFERS 2

//#use "dcrtcp.lib"
#use "tftp.lib"

#ifdef BU_TEMP_USE_SFLASH
	#use "sflash.lib"
#endif

#use "board_update.lib"