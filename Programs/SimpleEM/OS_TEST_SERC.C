#class auto
#use RCM42xx.LIB


	#define SPI_SER_C
	#define SPI_CLK_DIVISOR 8            //8 for Port expanders
   #define SPI_MASTER
	#define SPI_RX_PORT SPI_RX_PC
   #define CSB_NO 7



	#use "spi.lib"


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
//#use "ALBAOS_EXE.C" //void main()
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
//ALBAOS_INIT();//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//******************************************************************************

//******************************************************************************
//</SYS_INIT>
//**********************</DRIVERS>**********************************************/

//**********************<TESTINIT>**********************************************/
brdInit();			//reads calibration constants
SPIinit();
// Initialize PC4 (SPI TX) to output
WrPortI(PCDDR, &PCDDRShadow, 0xFF);
// Initialize PC4 to use alternate function
WrPortI(PCFR, &PCFRShadow, 0xFF);
// Initialize PC4 (SPI TX) to output
WrPortI(PEDDR, &PCDDRShadow, 0xFF);
// Initialize PC4 to use alternate function
WrPortI(PEFR, &PCFRShadow, 0xFF);
WrPortI(PEAHR, &PEAHRShadow, 0xE0);

//**********************</TESTINIT>*********************************************/

while(1)
{
//<SYS_DAEMONS>
//ALBAOS_DAEMONS();//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//</SYS_DAEMONS>

//<TESTSOFT>
Debugger();
//</TESTSOFT>
}

//<Forbidden state>
//SYS_Reset;
//</Forbidden state>
}
//***********************</RUNSYSTEM>***********************************************/



//-------------------<DEBUGFUNCTIONS>----------------------------------------------*/
void Debugger(void)
{
SPIWrite("ALA",3);
//SYS_DelayMs(1000);
}

//-------------------</DEBUGFUNCTIONS>----------------------------------------------*/