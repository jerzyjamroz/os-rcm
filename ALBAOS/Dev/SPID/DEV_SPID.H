/*** BeginHeader */
#ifndef __DEV_SPID_HEADER_LIB
#define __DEV_SPID_HEADER_LIB
/*** EndHeader */

/*** BeginHeader
*/
#ifdef SPID_DEBUG
#define _SPID_NODEBUG
#else
#define _SPID_NODEBUG nodebug
#endif

#define SPI_SER_D
#define SPI_CLK_DIVISOR 32            //5 = 5MHz the most optimal
#define SPI_MASTER
#define SPI_RX_PORT SPI_RX_PC

//4 modes;0;1;2;3
#define SPI_CLOCK_MODE 0
//#define SPI_CLOCK_MODE 1

#use "spi.lib"
/*** EndHeader */



/*** BeginHeader */
#endif
/*** EndHeader */