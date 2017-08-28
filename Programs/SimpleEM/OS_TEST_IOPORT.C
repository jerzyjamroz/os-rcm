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
#use "DEV_IO_BODY.LIB"
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

//WrPortI(PADDR, 	&PBDDRShadow, 0x00);
WrPortI(PADR,  	&PBDRShadow,  0xFF);

WrPortI(PBDDR, 	&PBDDRShadow, 0xFF);
// Set all of the outputs high. ~low
WrPortI(PBDR,  	&PBDRShadow,  0xFF);
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
WrPortI(PADR,  	&PBDRShadow,  0x00);
WrPortI(PBDR,  	&PBDRShadow,  0xFF);
SYS_DelayMs(100);
WrPortI(PBDR,  	&PBDRShadow,  0x00);
SYS_DelayMs(1000);
WrPortI(PADR,  	&PBDRShadow,  0xFF);
WrPortI(PBDR,  	&PBDRShadow,  0xFF);
SYS_DelayMs(100);
WrPortI(PBDR,  	&PBDRShadow,  0x00);
SYS_DelayMs(1000);
}

//-------------------</DEBUGFUNCTIONS>----------------------------------------------*/



