#class auto

//******************************************************************************
//*** BeginDebugs ***/   ENVIRONMENT SETTINGS
//#define ALBAOS_UNMOUNT_DEV
//#define TLN_DEBUG
//	#define ALBAOS_LIB_DEBUG

//	#define SCPIprot_EXE_DEBUG
//#define SCPIprot_DEBUG
//	#define COMORD_EXE_DEBUG
//#define ORD_CONV_DEBUG
//	#define BRIDGE_EXE_DEBUG

//*** EndDebugs ***/	ENVIRONMENT SETTINGS
//<patches>
int Eth_DHCP_Daemon(void);
int Eth_isLink(void);
//</patches>
//********************RABBIT_SYS************************************************
const char Firmware[]="Fim_Ver:1.03.01";
#define SYS_Tln_Dev_Name "<FAST INTERLOCK MODULE>"
//***********************<DEVICES>************************************************
#define Mount_Dev_SFlash_Driver
#define Mount_Dev_Tln_Driver
#define Mount_Dev_SerD_Driver
//***********************</DEVICES>***********************************************
//********************RABBIT_SYS************************************************

//<MOUNT_ALBAOS>
#use "ALBAOS_EXE.C" //void main()
//</MOUNT_ALBAOS>
//<PROGRAMS>
//#use "PROG_XML_MOUNT.LIB"
#use "FIM_BRIDGE_TLN_COM_MOUNT.LIB"
//</PROGRAMS>
nodebug
void main(void)
{
//**********************<DRIVERS>***********************************************
ALBAOS_INIT();
//**********************</DRIVERS>**********************************************
while(1)
 {
 Eth_DHCP_Daemon();
 ALBAOS_DAEMONS();

 //<PROGRAM>
 TLN_COM_BRIDGE_TASK
 //</PROGRAM>
 }

SYS_Reset;
}

nodebug
int Eth_isLink(void)
{
return pd_havelink(IF_DEFAULT);
}

nodebug
int Eth_DHCP_Daemon(void)
{
static unsigned long int timer;
static int flag;
#GLOBAL_INIT{
flag=-1;
timer=0;
}

if( (Eth_isLink()==1) && (flag!=0) && (chk_timeout(timer)>0) )
   {
   timer = _SET_TIMEOUT(5000);
 	dhcp_release();
 	flag=dhcp_acquire();
   tcp_tick(NULL);
//   printf("\nSEC=%u",SEC_TIMER);
   }
else if(Eth_isLink()==0) flag=-1;

return flag;
}

/*
costate{
	printf("\nP1=%d",SCPI_CmdinStr("SERGSADSxSTATusPPPPPP"));
   printf("\nP2=%d",SCPI_CmdinStr("SERGSADSxusPPPPPP"));
   waitfor(DelayMs(1000));
   }
*/
/*
   costate{
   SCPI_Parse("SYSTem:COMMunicate:TELNet:PASSword 1234,5678");
   ComOrd2Buf_Conv(buf,Buf2ComOrd_Conv("ERROR 12/",F2Rdir));
   printf("\nbuf=%s",buf);
   waitfor(DelayMs(1000));
   }
*/