/*** BeginHeader */
#ifndef __DEV_SPID_MOUNT_LIB
#define __DEV_SPID_MOUNT_LIB
/*** EndHeader */


/*** BeginHeader*/
//<UDP_DRIVER>
//<Mount_Dev_UDP_Driver>
#ifdef Mount_Dev_SPID_Driver
	#warnt "Dev_SPID: ACTIVE"
//------------------------------------------------------------------------------
//<HEADER>
	#use "DEV_SPID.LIB"
//</HEADER>
//<INIT>
	#define Dev_SPID_Init() SPID_Init()
//</INIT>
//------------------------------------------------------------------------------
//<BODY>
	#define Dev_SPI_Write(buf,len) SPIWrite(buf,len)
	#define Dev_SPI_Read(buf,len) SPIRead(buf,len)
//   #define Dev_SPID_CLK_Inv(int1)					SPID_CLK_Inv(int1)
//</BODY>
//------------------------------------------------------------------------------
//</UDP_DRIVER>
#else

	#warnt "Sim_Dev_SPID: ACTIVE"

//<INIT>
	#define Dev_SPID_Init()
//</INIT>
//------------------------------------------------------------------------------
//<BODY>
	#define Dev_SPI_Write(buf,len)
	#define Dev_SPI_Read(buf,len)
//   #define Dev_SPID_CLK_Inv(int1)					SPID_CLK_Inv(int1)
//</BODY>
#endif
//</Mount_Dev_UDP_Driver>

/*** EndHeader */


/*** BeginHeader */
#endif
/*** EndHeader */