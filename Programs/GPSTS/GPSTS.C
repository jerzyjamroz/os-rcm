#class auto
const char Firmware[]="GPSTS:1.03.01";
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

//#define SNTP_DEBUG
//#define PACK_SCPIprot_DEBUG
//*** EndDebugs ***/	ENVIRONMENT SETTINGS

//********************<RABBIT_SYS>************************************************/
//***********************<DEVICES>************************************************/
#define Mount_Dev_SFlash_Driver
#define Mount_Dev_Eth_Driver
#define Mount_Dev_Tln_Driver
//#define Mount_Dev_SerD_Driver
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

static int STAT_VECT;

nodebug
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
GPSTS_Init(SYS_SNTP_Cells_IP_dft);
//**********************</TESTINIT>*********************************************/
while(1)
 {
 ALBAOS_DAEMONS();
//<GPS_SERIALIZATION_hdl>
 costate{
 	waitfor(GPSTS_PPS_Read()==1);
   waitfor(DelayMs(100));
//   SYS_Timestamp(1);
   	SYS_Bit_Cpy(&STAT_VECT, SYS_Time_SNTP2RTC1900_Update_hdl( GPSTS_SNTP_Serv_IP_Get() ),GPS_StatVectBit_ACTIVITY );
      if(SYS_RTC_isCorrect()==1)
      	{
      	SYS_Serialize_Int32(buf,SYS_RTC_UTC1900_Read());
   		GPSTS_Ser_Int32HSB_Send(buf);
         }
//   SYS_Timestamp(3);
   waitfor(DelayMs(200));
   waitfor(GPSTS_PPS_Read()==0);
   }
//</GPS_SERIALIZATION_hdl>

//<GPS_LED_hdl>
	costate{
      GPSTS_PPS_LED(GPSTS_PPS_Read());
   }

   costate{
   wfd GPSTS_Ethernet_LED( STAT_SYNCH,  SYS_RTC_isCorrect() );
   }
//<GPS_LED_hdl>

//<GPS_TLN_ORDER_hdl>
   costate{
   if (SYS_Tln_Read(buf,sizeof(buf)-1)>0)
      {
	   SYSOrd_Get(sys_tln_ords,buf,GPSTS_SCPI_REF);
	   GPSTS_SCPI_Ord_Exe(sys_tln_ords);
   	}
   }
//<GPS_TLN_ORDER_hdl>

//<GPS_FLAGS_hdl>
   costate{
   gps_pps=GPSTS_PPS_Read();
   timer = _SET_TIMEOUT(1500);
   waitfor( (gps_pps!=GPSTS_PPS_Read()) || (chk_timeout(timer)) );
	if(chk_timeout(timer)==0) SYS_Bit_Cpy(&STAT_VECT,1,GPS_StatVectBit_PPS);
   else SYS_Bit_Cpy(&STAT_VECT,0,GPS_StatVectBit_PPS);
   }
//</GPS_FLAGS_hdl>


//<STAT_VECTOR_hdl>
	costate{
 	SYS_Bit_Cpy(&STAT_VECT,
   STAT_ACTIVITY&&STAT_PPS,
   GPS_StatVectBit_SYNCH);
   }
//</STAT_VECTOR_hdl>


//<GPS_TLN_EVENT_hdl>
   costate{
	GPSTS_Tln_Event_hdl(&STAT_VECT);
   }
//</GPS_TLN_EVENT_hdl>

 }

SYS_Reset;
}
//***********************</RUNSYSTEM>***********************************************/