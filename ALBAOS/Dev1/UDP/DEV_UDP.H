#ifndef __DEV_UDP_H
#define __DEV_UDP_H


#ifdef UDP_DEBUG
#define _UDP_NODEBUG
#else
#define _UDP_NODEBUG nodebug
#endif

//#define MAX_UDP_SOCKET_BUFFERS 1        //ETHERNET CONFIG
//#define DISABLE_TCP     //ETHERNET CONFIG
//#define LOCAL_PORT	7  //standart echo port     //ETHERNET CONFIG

static udp_Socket 				UDP_Sock;

#endif