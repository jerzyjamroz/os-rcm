/*** BeginHeader */
#ifndef __DEV_MCP23S08_H
#define __DEV_MCP23S08_H
/*** EndHeader */

/*
It depends on
- SPID
- DEC4X16
*/

/*** BeginHeader
*/
#ifdef MCP23S08_DEBUG
#define _MCP23S08_NODEBUG
#else
#define _MCP23S08_NODEBUG nodebug
#endif

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
/*** EndHeader */



/*** BeginHeader */
#endif
/*** EndHeader */