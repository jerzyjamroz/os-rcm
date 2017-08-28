/*** BeginHeader */
#ifndef __DEV_ETH_H
#define __DEV_ETH_H
/*** EndHeader */

/*** BeginHeader
*/
#ifdef ETH_DEBUG
#define _ETH_NODEBUG
#else
#define _ETH_NODEBUG nodebug
#endif

//_________________________________<CONFIG>_____________________________________
//****************************<SETTINGS>****************************************
//****************************<SETTINGS>****************************************
//#define TCPCONFIG 7
#define TCPCONFIG 5   //for the RCM5700

#define _PRIMARY_STATIC_IP  "192.168.168.100"
#define _PRIMARY_NETMASK    "255.255.252.0"
#define MY_GATEWAY          "192.168.168.1"
#define MY_NAMESERVER       "192.168.168.1"

#define ETH_IP4_MAX_LEN 15

//<UDP control settings>
//#ifdef Mount_Dev_UDP_Driver
	#define MAX_UDP_SOCKET_BUFFERS 3      //GLOBAL VAR - How many UDP sockets are you gonna use
 	#define DISABLE_TCP                   //GLOBAL VAR
	#define DEV_UDP_LOCAL_PORT 7          //Local variable inside DEV_UDP
//#endif
//</UDP control settings>

#use "dcrtcp.lib"       //It can be used only once

//****************************</SETTINGS>***************************************
//****************************</SETTINGS>***************************************
//_________________________________</CONFIG>____________________________________
/*** EndHeader */



/*** BeginHeader */
#endif
/*** EndHeader */