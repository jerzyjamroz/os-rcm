#class auto
#define ADC_SCLKBRATE 115200ul
#use RCM42xx.LIB
#ifndef ADC_ONBOARD
   #error "This core module does not have ADC support.  ADC programs will not "
   #fatal "   compile on boards without ADC support.  Exiting compilation."
#endif

#define STARTCHAN	0
#define ENDCHAN 6
//#use RCM57xx.lib
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
//#use "GPSTS_HEAD1ER.LIB"
//#use "PACK_SCPI_PROT_BODY.lib"
//#use "PACK_SYSORDERS_BODY.LIB"
//#use "DEV_SPIB_MOUNT.LIB"
//#use "DEV_AD7610_BODY.LIB"
//#use "DEV_MCP23S17_BODY.LIB"
//#use "DEV_ExtIO_BODY.LIB"
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
brdInit();			//reads calibration constants
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
intvar = anaIn(0, DIFF, 1);
printf("%d\n",intvar);
SYS_DelayMs(1000);
}

//-------------------</DEBUGFUNCTIONS>----------------------------------------------*/