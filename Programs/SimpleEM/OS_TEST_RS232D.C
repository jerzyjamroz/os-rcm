#class auto
#use RCM42xx.LIB

const char Firmware[]="NONE";
//******************************************************************************/
//*** BeginDebugs ***/   ENVIRONMENT SETTINGS
void Debugger(void);
//*** EndDebugs ***/	ENVIRONMENT SETTINGS

//********************<RABBIT_SYS>************************************************/
//***********************<DEVICES>************************************************/

//***********************</DEVICES>***********************************************/
//********************</RABBIT_SYS>************************************************/


//***********************<RUNSYSTEM>***********************************************/
//<MOUNT_ALBAOS>
#use "ALBAOS_EXE.C" //void main()
//</MOUNT_ALBAOS>

//<PROGRAMS>
//#use "DEV_ETH_BODY.LIB"
//#use "DEV_UDP_BODY.LIB"
#use "DEV_SER_D_BODY.LIB"
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
SerD_Init();
//**********************</TESTINIT>*********************************************/

while(1)
{
//<SYS_DAEMONS>

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
SerD_Write("ABCDEFGH\n");
SYS_DelayMs(100);
}

//-------------------</DEBUGFUNCTIONS>----------------------------------------------*/



