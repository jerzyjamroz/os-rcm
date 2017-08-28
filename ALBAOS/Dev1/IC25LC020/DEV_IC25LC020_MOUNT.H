/*** BeginHeader */
#ifndef __DEV_IC25LC020_MOUNT_LIB
#define __DEV_IC25LC020_MOUNT_LIB
/*** EndHeader */


/*** BeginHeader*/

//<IC25LC020_DRIVER>
//<Mount_Dev_IC25LC020_Driver>
#ifdef Mount_Dev_IC25LC020_Driver
	#warnt "Dev_IC25LC020: ACTIVE"
//------------------------------------------------------------------------------
//<HEADER>
   #use "DEV_IC25LC020.LIB"
//</HEADER>
//<INIT>
//</INIT>
//------------------------------------------------------------------------------
//<BODY>
	#define Dev_IC25LC020_Byte_Wr(addr_byte,byte)				IC25LC020_Byte_Wr(addr_byte,byte)
	#define Dev_IC25LC020_Byte_Rd(addr_byte)           		IC25LC020_Byte_Rd(addr_byte)
	#define Dev_IC25LC020_Wr_En()                      		IC25LC020_Wr_En()
	#define Dev_IC25LC020_Wr_Dis()                      		IC25LC020_Wr_Dis()
   #define Dev_IC25LC020_RDSR()                             IC25LC020_RDSR()
//</BODY>
//------------------------------------------------------------------------------
//</IC25LC020_DRIVER>
#else

	#warnt "Sim_Dev_IC25LC020: ACTIVE"

//<BODY>
	#define Dev_IC25LC020_Byte_Wr(addr_byte,byte)
	#define Dev_IC25LC020_Byte_Rd(addr_byte) 0
	#define Dev_IC25LC020_Wr_En()
	#define Dev_IC25LC020_Wr_Dis()
   #define Dev_IC25LC020_RDSR() 0
//</BODY>

#endif
//</Mount_Dev_IC25LC020_Driver>


/*** EndHeader */


/*** BeginHeader */
#endif
/*** EndHeader */