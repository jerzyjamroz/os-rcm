#class auto
#use RCM42xx.LIB

const char Firmware[]="NONE";
//******************************************************************************/
//*** BeginDebugs ***/   ENVIRONMENT SETTINGS
void Debugger(void);
//*** EndDebugs ***/	ENVIRONMENT SETTINGS

//********************<RABBIT_SYS>************************************************/
//***********************<DEVICES>************************************************/
#define Mount_Dev_ETH_Driver
#define Mount_Dev_UDP_Driver
//***********************</DEVICES>***********************************************/
//********************</RABBIT_SYS>************************************************/


//***********************<RUNSYSTEM>***********************************************/
//<MOUNT_ALBAOS>
#use "ALBAOS_EXE.C" //void main()
//</MOUNT_ALBAOS>

//<PROGRAMS>
#use "EM_ORDER_HEADER.LIB"
//</PROGRAMS>

debug
void main(void)
{
int i;
//**********************<DRIVERS>***********************************************/
//<SYS_INIT>
//</SYS_INIT>
//**********************</DRIVERS>**********************************************/

//**********************<TESTINIT>**********************************************/
brdInit();			//reads calibration constants
Dev_Eth_Init();
Dev_UDP_Init();
//**********************</TESTINIT>*********************************************/

while(1)
{
//<SYS_DAEMONS>
Eth_DHCP_Daemon();
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
tcp_tick(NULL);
}

//-------------------</DEBUGFUNCTIONS>----------------------------------------------*/

int Dev_UDP_Handler(int event, udp_Socket * udpSock, ll_Gather * udpGath, _udp_datagram_info * udpInfo)
{
//udp_xsendto(udpSock, (long)udpGath->data2, udpGath->len2, udpInfo->remip, udpInfo->remport);
}

