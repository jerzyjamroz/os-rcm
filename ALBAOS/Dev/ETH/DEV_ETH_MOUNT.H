/*** BeginHeader */
#ifndef __DEV_ETH_MOUNT_H
#define __DEV_ETH_MOUNT_H
/*** EndHeader */


/*** BeginHeader*/

//<ETH_DRIVER>
//<Mount_Dev_ETH_Driver>
#ifdef Mount_Dev_ETH_Driver
	#warnt "Dev_ETH: ACTIVE"
//------------------------------------------------------------------------------
//<HEADER>
	#use "DEV_ETH.LIB"
//</HEADER>
//<INIT>
	#define Dev_Eth_Init()						Eth_Init()
//</INIT>
//<DAEMON>
	#define DEV_Eth_Daemon()					Eth_Daemon()
//</DAEMON>
//------------------------------------------------------------------------------
//<BODY>
	#define Dev_Eth_isLink()	  				Eth_isLink()
	#define Dev_Eth_Resolve(dns) 				Eth_Resolve(dns)
	#define Dev_Eth_IP2Num(ip_string)		Eth_IP2Num(ip_string)
	#define DEV_ETH_IP4_MAX_LEN		      ETH_IP4_MAX_LEN
//</BODY>
//------------------------------------------------------------------------------
//</ETH_DRIVER>
#else

	#warnt "Sim_Dev_ETH: ACTIVE"

   #define Dev_Eth_Init()

	#define DEV_Eth_Daemon()

	#define Dev_Eth_isLink()
	#define Dev_Eth_Resolve(dns)
	#define Dev_Eth_IP2Num(ip_string)
	#define DEV_ETH_IP4_MAX_LEN

#endif
//</Mount_Dev_ETH_Driver>



/*** EndHeader */


/*** BeginHeader */
#endif
/*** EndHeader */