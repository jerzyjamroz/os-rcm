/*** BeginHeader */
#ifndef __DEV_MCP23S08_MOUNT_LIB
#define __DEV_MCP23S08_MOUNT_LIB
/*** EndHeader */


/*** BeginHeader*/

//<MCP23S08_DRIVER>
//<Mount_Dev_MCP23S08_Driver>
#ifdef Mount_Dev_MCP23S08_Driver
	#warnt "Dev_MCP23S08: ACTIVE"
//------------------------------------------------------------------------------
//<HEADER>
   #use "DEV_MCP23S08.LIB"
//</HEADER>
//<INIT>
//</INIT>
//------------------------------------------------------------------------------
//<BODY>
#define Dev_MCP23S08_Init() MCP23S08_Init()
#define Dev_MCP23S08_Byte_Write(reg,byte) MCP23S08_Byte_Write(reg,byte)
#define Dev_MCP23S08_Port_Dir(byte) MCP23S08_Port_Dir(byte)
#define Dev_MCP23S08_Port_Write(byte) MCP23S08_Port_Write(byte)
#define Dev_MCP23S08_Byte_Read(reg) MCP23S08_Byte_Read(reg)
//</BODY>
//------------------------------------------------------------------------------
//</MCP23S08_DRIVER>
#else

		#warnt "Sim_Dev_MCP23S08: ACTIVE"
      //<BODY>
		#define Dev_MCP23S08_Init()
		#define Dev_MCP23S08_Byte_Write(reg,byte)
		#define Dev_MCP23S08_Port_Dir(byte)
		#define Dev_MCP23S08_Port_Write(byte)
		#define Dev_MCP23S08_Byte_Read(reg) 0
		//</BODY>

      enum{
			IODIR 	=  0x00,
			IPOL     =	0x01,
			GPINTEN  =	0x02,
			DEFVAL   =	0x03,
			INTCON   =	0x04,
			IOCON   	=	0x05,		//if possible to not modify BIT7
			GPPU     =	0x06,
			INTF     =	0x07,
			INTCAP 	=	0x08,    //(Read-only)
			GPIO     =	0x09,
			OLAT     =	0x0A,
			}MCP23S08;

#endif
//</Mount_Dev_MCP23S08_Driver>


/*** EndHeader */


/*** BeginHeader */
#endif
/*** EndHeader */