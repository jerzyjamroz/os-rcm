/*** BeginHeader */
#ifndef __SYS_REMPROGUPDATE_MOUNT_H
#define __SYS_REMPROGUPDATE_MOUNT_H
/*** EndHeader */


/*** BeginHeader
Tftp_and_install,
*/
//<UDP_DRIVER>
//<Mount_Dev_UDP_Driver>
#ifdef Mount_SYS_REMPROGUPDATE_Driver
	#warnt "SYS_REMPROGUPDATE: ACTIVE"
//------------------------------------------------------------------------------
//<HEADER>
   #use "SYS_REMPROGUPDATE.LIB"
//</HEADER>
//<INIT>
//</INIT>
//------------------------------------------------------------------------------
//<BODY>
	#define SYS_Tftp_and_install(serv,file)	   Tftp_and_install(serv,file)
//</BODY>
//------------------------------------------------------------------------------
//</UDP_DRIVER>
#else

//#ifdef Sim_Mount_Dev_UDP_Driver

	#warnt "SIM_SYS_REMPROGUPDATE: ACTIVE"

	int SYS_Tftp_and_install(char *TFTP_Server,char *TFTP_File){return -1;}

//#endif

#endif
//</Mount_Dev_UDP_Driver>



/*** EndHeader */


/*** BeginHeader */
#endif
/*** EndHeader */