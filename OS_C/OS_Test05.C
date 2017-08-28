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
#use "DEV_AD7610_BODY.LIB"
//#use "DEV_MCP23S17_BODY.LIB"
//</PROGRAMS>
char buf[10000];
char buf1[10000];
//int intbuf[10000];
debug
void main(void)
{
int i;
//struct SYSVarOrd sys_orders[100];
//unsigned long int ulint_var;
//unsigned long int server;
//**********************<DRIVERS>***********************************************/
//<SYS_INIT>
ALBAOS_INIT();//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//</SYS_INIT>
//**********************</DRIVERS>**********************************************/

//**********************<TESTINIT>**********************************************/
AD7610_Init();
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

WrPortI(PBDDR, 	&PBDDRShadow, 0xFF);
WrPortI(PBDR,  	&PBDRShadow,  0xFF);

WrPortI(PDDDR, 	&PBDDRShadow, 0x00);
WrPortI(PDDR,  	&PBDRShadow,  0xFF);

WrPortI(PEDDR, 	&PBDDRShadow, 0x00);
WrPortI(PEDR,  	&PBDRShadow,  0xFF);

SYS_Timestamp(1);
for(i=0;i<1000;i++)
	{

   BitWrPortI(PBDR, &PBDRShadow, 0, 6);
   BitWrPortI(PBDR, &PBDRShadow, 1, 6);

//   WrPortI(PBDR,  	&PBDRShadow,  0xFF);
//   buf[2*i]=RdPortI(PDDR);
//   buf[2*i+1]=RdPortI(PEDR);
//   WrPortI(PBDR,  	&PBDRShadow,  0x00);
   }

SYS_Timestamp(3);

SYS_Timestamp(1);
for(i=0;i<1000;i++)
	{
   }
SYS_Timestamp(3);


printf("\n\n");
for(i=0;i<1000;i++)
	{
	printf("%02X%02X,",buf[2*i],buf[2*i+1]);
	}

//printf("STR\n%s",buf);
gets(buf1);

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