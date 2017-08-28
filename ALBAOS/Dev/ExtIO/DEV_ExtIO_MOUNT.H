/*** BeginHeader */
#ifndef __DEV_ExtIO_MOUNT_LIB
#define __DEV_ExtIO_MOUNT_LIB
/*** EndHeader */


/*** BeginHeader*/


#ifdef Mount_Dev_ExtIO_Driver
	#warnt "Dev_ExtIO: ACTIVE"
//------------------------------------------------------------------------------
//<HEADER>
	#use "DEV_ExtIO.LIB"
//</HEADER>

//<INIT>
	#define Dev_ExtIO_Init	(w8StNum,handshake_conf)	ExtIO_Init(w8StNum,handshake_conf)
//</INIT>
//------------------------------------------------------------------------------
//<BODY>
	#define Dev_ExtIO_Read	(int address)					RdPortE(address)
	#define Dev_ExtIO_Write	(int address, char byte)	WrPortE(address, NULL, byte)
//</BODY>
//------------------------------------------------------------------------------
#else

	#warnt "Sim_Dev_ExtIO: ACTIVE"

#endif
//</ExtIO_DRIVER>



/*** EndHeader */


/*** BeginHeader */
#endif
/*** EndHeader */