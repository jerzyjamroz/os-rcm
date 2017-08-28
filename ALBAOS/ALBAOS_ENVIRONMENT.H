/*** BeginHeader */
#ifndef __ALBAOS_ENVIRONMENT_H
#define __ALBAOS_ENVIRONMENT_H
/*** EndHeader */

/*** BeginHeader
*/
#ifdef ALBAOS_DEBUG
#define _ALBAOS_NODEBUG
#else
#define _ALBAOS_NODEBUG nodebug
#endif

/*
#ifndef u8
	#define u8 unsigned char
#endif
#ifndef u16
	#define u16 unsigned short int
#endif
#ifndef u32
	#define u32 unsigned long int
#endif
*/

//#define SYS_Reset exit(0)
#define SYS_Reset forceWatchdogTimeout()
//#define SYS_Reset forceSoftReset()
#define MULTI_ARG_DET(pbuf) ((char*)&pbuf+sizeof(pbuf))

char ALBAOS_Ver[]="2.01.01";
char SYSCRNL[] = "\r\n";
//<NULLS>
char SYSNULL_PCHAR[] = "";
char * SYSNULL_PCHAR2D[]={""};
int SYSNULL_PINT[]={0};
nodebug void SYSNULL_PFUNC(void){}
#define SYSNULL_INT -1
far char SYSNULL_FCHAR = 0;
//</NULLS>

const char SYSYES[] = {"YES"};
const char SYSNO[] = {"NO"};
#define SYS_FLOAT_MAX 1E38

const char *SYS_CREDITS[] = {
//"Project Engineer:\n Julio Lidon\n",
"Designer:\n Jerzy Jamroz\n",
"Engineering Manager:\n Oscar Matilla\n",
"CELLS-ALBA Synchrotron light source\n"
" Computing Division - Electronics Section",
"",
};


/*** EndHeader */


/*** BeginHeader */
#endif
/*** EndHeader */