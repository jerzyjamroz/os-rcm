#class auto
#use RCM42xx.lib
const char Firmware[]="GPSTS:1.03.02";
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
#define SFlash_DEBUG

//#define SNTP_DEBUG
//#define PACK_SCPIprot_DEBUG
#define GPSTS_DEBUG
//*** EndDebugs ***/	ENVIRONMENT SETTINGS

//********************<RABBIT_SYS>************************************************/
//***********************<DEVICES>************************************************/
#define Mount_Dev_SFlash_Driver
#define Mount_Dev_Eth_Driver
#define Mount_Dev_Tln_Driver
/////////////////////////////////////////#define Mount_Dev_SerD_Driver
#define Mount_Dev_SNTP_Driver
#define Mount_Dev_RTC_Driver
#define Mount_Dev_Time_Driver
#define Mount_Dev_IO_Driver
#define Mount_Dev_DAlloc_Driver
//***********************</DEVICES>***********************************************/
//********************</RABBIT_SYS>************************************************/
#define SYS_Tln_Dev_Name "<GPS TIMESTAMP BRIDGE>"
#define GPSTS_SNO 1001
//***********************<RUNSYSTEM>***********************************************/
//<MOUNT_ALBAOS>
#use "ALBAOS_EXE.C" //void main()
//</MOUNT_ALBAOS>
//<PROGRAMS>
//#use "DEV_RTC_BODY.LIB"
#use "PACK_SYSORDERS_BODY.LIB"
#use "PACK_SCPI_PROT_BODY.lib"
#use "GPSTS_BODY.LIB"
//</PROGRAMS>
//_________________________________<CONFIGLOCAL>________________________________
#define LOC_PPS_Pin 0
#define LOC_Pin1_No 2
#define LOC_Pin0_No 1
#define LOC_Ser_Delay 100
#define LOC_GPSTS_Port SYSPORTE

#define LOC_LED_Eth_Pin 4
#define LOC_LED_RTC_Pin 3
#define LOC_LED_Port SYSPORTE

//_________________________________</CONFIGLOCAL>_______________________________

static int STAT_VECT;

void Debugger(void);
int GPSTS_Init1(char * gps_sntp_serv_ip);

char buf[5000];
debug
void main(void)
{
static int gps_pps;
static char buf[1024];
static struct SYSVarOrd sys_tln_ords[256];
static unsigned long int timer;

#GLOBAL_INIT{
STAT_VECT=0xFFFF;
sys_tln_ords[0]=SYSVarOrd_REF_NULL.SYSVarOrdRef;
buf[0]=0;
timer=0;
}


//**********************<DRIVERS>***********************************************/
ALBAOS_INIT();
//**********************</DRIVERS>**********************************************/

//**********************<TESTINIT>**********************************************/
GPSTS_Init1(SYS_SNTP_Cells_IP_dft);
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
char buf[100];

SYS_SFlash_Str2FlPage("22:22:xx:ff",100);
SFlash_FlPage2Str(buf,100);

while(1);

}


int GPSTS_Init1(char * gps_sntp_serv_ip)
{
char buf[SYS_SFlash_Page_Size+1];

SYS_IO_PortX_Config(SYSPORTE,0x00); //just a fast init as input - to remove eventual alternative pin generations

/*
if(SYS_SFlash_FlPage2Str(buf,SYS_SFl_IP_StrPage)>0)
	GPSTS_SNTP_Serv_IP_Set(buf);
else GPSTS_SNTP_Serv_IP_Set(gps_sntp_serv_ip);
*/
//SYS_Time_SNTP2RTC1900_Update_hdl(GPSTS_SNTP_Serv_IP_Get());

//SYS_IO_PortX_Pin_Res(LOC_GPSTS_Port,LOC_Pin0_No);
//SYS_IO_PortX_Pin_Res(LOC_GPSTS_Port,LOC_Pin1_No);
//SYS_IO_PortX_Pin_Res(LOC_LED_Port,LOC_LED_Eth_Pin);

return 1;
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