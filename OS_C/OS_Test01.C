#class auto
#use RCM57xx.lib
const char Firmware[]="NONE";
//******************************************************************************/
//*** BeginDebugs ***/   ENVIRONMENT SETTINGS
//#define ALBAOS_UNMOUNT_DEV
//#define TLN_DEBUG
//#define ALBAOS_LIB_DEBUG

//	#define SCPIprot_EXE_DEBUG
//#define SCPIprot_DEBUG
//	#define COMORD_EXE_DEBUG
//#define ORD_CONV_DEBUG
//	#define BRIDGE_EXE_DEBUG
//#define SFlash_DEBUG

//#define IO_DEBUG
//#define SNTP_DEBUG
void Debugger(void);
//*** EndDebugs ***/	ENVIRONMENT SETTINGS

//********************<RABBIT_SYS>************************************************/
//***********************<DEVICES>************************************************/
//#define Mount_Dev_SFlash_Driver
//#define Mount_Dev_Eth_Driver
//#define Mount_Dev_Tln_Driver
//#define Mount_Dev_SerD_Driver
//#define Mount_Dev_SNTP_Driver
//#define Mount_Dev_Time_Driver
//#define Mount_Dev_IO_Driver
//***********************</DEVICES>***********************************************/
//********************</RABBIT_SYS>************************************************/


//***********************<RUNSYSTEM>***********************************************/
//<MOUNT_ALBAOS>
#use "ALBAOS_EXE.C" //void main()
//</MOUNT_ALBAOS>

//<PROGRAMS>
//#use "DEV_RTC_MOUNT.LIB"
//#use "DEV_IO_BODY.LIB"
//#use "GPSTS_HEADER.LIB"
//#use "PACK_SCPI_PROT_BODY.lib"
//#use "PACK_SYSORDERS_BODY.LIB"
//#use "DEV_SPIB_MOUNT.LIB"
//#use "DEV_AD7610_BODY.LIB"
//#use "DEV_MCP23S17_BODY.LIB"
#use "DEV_ExtIO_BODY.LIB"
//</PROGRAMS>

char buf[1000];
char buf1[1000];
int intvar;
debug
void main(void)
{
int i;
//**********************<DRIVERS>***********************************************/
//<SYS_INIT>
ALBAOS_INIT();//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//******************************************************************************

//******************************************************************************
//</SYS_INIT>
//**********************</DRIVERS>**********************************************/

//**********************<TESTINIT>**********************************************/
//AD7610_Init();
ExtIO_Init(15,0x11);

//BitWrPortI(PEDDR, 	&PBDDRShadow, 		1, 0);
//BitWrPortI(PEDR,  	&PBDRShadow,  		1, 0);
//**********************</TESTINIT>*********************************************/

while(1)
{
//<SYS_DAEMONS>
ALBAOS_DAEMONS();//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//</SYS_DAEMONS>

//<TESTSOFT>
Debugger();
//</TESTSOFT>
}

//<Forbidden state>
SYS_Reset;
//</Forbidden state>
}
//***********************</RUNSYSTEM>***********************************************/



//-------------------<DEBUGFUNCTIONS>----------------------------------------------*/

void Debugger(void)
{
int i;
int int1;
int int2;
MS_TIMER=0;

SYS_Timestamp(1);
for(i=0;i<1000;i++)
	{
//   intvar=ExtIO_Read(0x0001);
//   printf("%02X,",intvar);
   ExtIO_Write(0x0001,1);
   SYS_DelayMs(1000);
//   intvar=ExtIO_Read(0x0007);
//   printf("%02X/",intvar);
   ExtIO_Write(0x0002,1);
   SYS_DelayMs(1000);
//   printf("%d,%d\n",int1,int2);
   }

//printf("STR\n%s",buf);
//gets(buf1);

}

//-------------------</DEBUGFUNCTIONS>----------------------------------------------*/


/*
SYS_Timestamp(1);
BitWrPortI(PBDR,&PBDRShadow,0,6);
SYS_DelayMs(50);
BitWrPortI(PBDR,&PBDRShadow,1,6);
SYS_DelayMs(50);
SYS_Timestamp(3);
*/