/*** BeginHeader */
#ifndef __DEV_UDP_MOUNT_H
#define __DEV_UDP_MOUNT_H
/*** EndHeader */


/*** BeginHeader*/
//<UDP_DRIVER>
//<Mount_Dev_UDP_Driver>
#ifdef Mount_Dev_UDP_Driver
	#warnt "Dev_UDP: ACTIVE"
//------------------------------------------------------------------------------
//<HEADER>
   #use "DEV_UDP.LIB"
//</HEADER>
//<INIT>
	#define Dev_UDP_Init() UDP_Init()
//</INIT>
//------------------------------------------------------------------------------
//<BODY>
	#define Dev_UDP_User_Handler(buf,buf_max_len,ord) UDP_User_Handler(buf,buf_max_len,ord)
	#define Dev_UDP_XSendTo(udpSock,fBuf,len,remip,remport) udp_xsendto(udpSock,fBuf,len,remip,remport)
	#define Dev_UDP_SendTo(udpSock,fBuf,len,remip,remport) udp_sendto(udpSock,fBuf,len,remip,remport)
	#define Dev_UDP_Event_Flag_Check() UDP_Event_Flag_Check()
//</BODY>
//------------------------------------------------------------------------------
//</UDP_DRIVER>
#else

//	#ifdef Sim_Mount_Dev_UDP_Driver

		#warnt "Sim_Dev_UDP: ACTIVE"
//      #define Dev_UDP_Init()

//    #define Dev_UDP_User_Handler()
//		#define Dev_UDP_XSendTo(udpSock, fBuf, len, remip, remport)
//		#define Dev_UDP_SendTo(udpSock, fBuf, len, remip, remport)

//   #endif

#endif
//</Mount_Dev_UDP_Driver>



/*** EndHeader */


/*** BeginHeader */
#endif
/*** EndHeader */