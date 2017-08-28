#class auto
const char Firmware[]="NONE";
//******************************************************************************/
//*** BeginDebugs ***/   ENVIRONMENT SETTINGS
//#define ALBAOS_UNMOUNT_DEV
#define TLN_DEBUG
#define ALBAOS_LIB_DEBUG

//	#define SCPIprot_EXE_DEBUG
//#define SCPIprot_DEBUG
//	#define COMORD_EXE_DEBUG
//#define ORD_CONV_DEBUG
//	#define BRIDGE_EXE_DEBUG
//#define SFlash_DEBUG

#define SNTP_DEBUG
//*** EndDebugs ***/	ENVIRONMENT SETTINGS

//********************<RABBIT_SYS>************************************************/
//***********************<DEVICES>************************************************/
//#define Mount_Dev_SFlash_Driver
//#define Mount_Dev_Eth_Driver
//#define Mount_Dev_Tln_Driver
//#define Mount_Dev_SerD_Driver
//#define Mount_Dev_SNTP_Driver
//#define Mount_Dev_Time_Driver
#define Mount_Dev_IO_Driver
//***********************</DEVICES>***********************************************/
//********************</RABBIT_SYS>************************************************/

//-------------------<DEBUGFUNCTIONS>----------------------------------------------*/

void Debugger(void)
{

}

//-------------------</DEBUGFUNCTIONS>----------------------------------------------*/


//***********************<RUNSYSTEM>***********************************************/
//<MOUNT_ALBAOS>
#use "ALBAOS_EXE.C" //void main()
//</MOUNT_ALBAOS>
//<PROGRAMS>
//#use "DEV_RTC_MOUNT.LIB"
#use "DEV_IO_BODY.LIB"
#use "GPSTS_HEADER.LIB"
#use "PACK_SCPI_PROT_BODY.lib"
#use "PACK_SYSORDERS_BODY.LIB"
//</PROGRAMS>
debug
void main(void)
{
int i;
char buf[100];
struct SYSVarOrd sys_orders[100];
//unsigned long int ulint_var;
//unsigned long int server;
//**********************<DRIVERS>***********************************************/
//<SYS_INIT>
ALBAOS_INIT();//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//</SYS_INIT>
//**********************</DRIVERS>**********************************************/

//**********************<TESTINIT>**********************************************/

//**********************</TESTINIT>**********************************************/
//SYS_Time_Update_hdl(SYS_SNTP_Serv);

while(1)
{
//<SYS_DAEMONS>
ALBAOS_DAEMONS();//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//</SYS_DAEMONS>
if(SYS_IO_PortB_Pin_Read(4)) SYS_IO_PortB_Pin_Set(2);
else SYS_IO_PortB_Pin_Res(2);
//**********************<TESTSOFT>**********************************************/
Debugger();
costate{
SYS_IO_PortB_Pin_Set(2);
SYS_IO_PortB_Pin_Res(3);
waitfor(DelayMs(1000));
SYS_IO_PortB_Pin_Res(2);
SYS_IO_PortB_Pin_Set(3);
waitfor(DelayMs(1000));
}
//SCPI_Parse("ABCD",SCPI_REF);
//SYSOrd_Get(sys_orders,"9876",SCPI_REF);
//SYS_DelayMs(4000);
//**********************</TESTSOFT>**********************************************/

}

SYS_Reset;
}
//***********************</RUNSYSTEM>***********************************************/