//<DEVICE PARAMETERS>
//DONE in the userblock const char DEV_ID[]=				"ELEM01R42-XXX";
#define DEV_SNO_LEN 3
const char DEV_SNO[]="EM#R6";
const char DEV_ID_PCB[]="EM#-SPECIAL";
const char DEV_ID_FIMWARE[]="2.00.02";        //03 autorange

#define EM_PROCESSING_BUF_LEN 2048
static char EM_PROCESSING_BUF[EM_PROCESSING_BUF_LEN];
//</DEVICE PARAMETERS>

//</DEBUG>
#define ALBAOS_DEBUG
#define ETH_DEBUG
#define UDP_DEBUG
#define EM_ORD_DEBUG
//#define EM_SENSOR_DEBUG
//#define EM_ADC_DEBUG
#define EM_DEBUG
#define INT_DEBUG
//</DEBUG>

//#class auto
//#use RCM67xx.LIB
#use RCM67xx.LIB
//********************<RABBIT_SYS>*********************************************/
//#define Mount_SYS_REMPROGUPDATE_Driver     //<NOTE: DEPENDS ON ETH>
//***********************<DEVICES>*********************************************/
#define Mount_Dev_ETH_Driver
#define Mount_Dev_UDP_Driver              	//<NOTE: DEPENDS ON ETH>
//#define Mount_Dev_ADS7870_Driver
//#define Mount_Dev_DEC4X16_Driver
//#define Mount_Dev_SPID_Driver
//#define Mount_Dev_MCP23S08_Driver
//#define Mount_Dev_IC25LC020_Driver
//#define Mount_Dev_DAC7611_Driver
//#define Mount_DEV_INT_Driver
//***********************</DEVICES>********************************************/
//********************</RABBIT_SYS>********************************************/


//***********************<RUNSYSTEM>*******************************************/
//<MOUNT_ALBAOS>
#use "ALBAOS_RUN.LIB" //void main()
//</MOUNT_ALBAOS>

//<GLOBAL_VARS>
//struct EMOrd EmOrd_Tester;
//</GLOBAL_VARS>

//<PROGRAMS>

#use "EM_API.LIB"
#use "EM_ORD_API.LIB"
#use "EM_ADC_API.LIB"
#use "EM_SENSOR.LIB"
//nodebug
int main(void)
{
unsigned long int trig_periode_timer=0;
int i;
//**********************<DRIVERS>**********************************************/
//<SYS_INIT>
ALBAOS_INIT
//</SYS_INIT>
Dev_DEC4X16_Init();
EM_Elem_Init();
Dev_Int_Init(EM_Trig_Ext_Event, Elem.Int_Edge);

for (i=0;i<EM_SENSOR_MAX;i++) EM_SEN_Init(i);
for (i=0;i<EM_SENSOR_MAX;i++) EM_SEN_Init(i);

//**********************</DRIVERS>*********************************************/
//***********************<LOOP>************************************************/
if(Elem.State==EM_ST_RUNNING)Elem.State=EM_ST_ON;
EM_ADC_API_State_Handler();

Elem_SYS.Timer_Srate=_SET_TIMEOUT(Elem.Srate);
trig_periode_timer=_SET_TIMEOUT(Elem.Trig_Periode);
EM_ADC_Tick(Elem.State,&Elem_SYS.Trig);    // to set up counters from -1 to 0;

//<TRIGER INIT>
if(Elem.Trig_Mode==EM_TR_MD_INT) Dev_Int_Dis();
else if(Elem.Trig_Mode==EM_TR_MD_EXT) Dev_Int_En(Elem.Int_Edge);
//</TRIGER INIT>

while(1)
{
//</PROGRAMS>
if( ((Elem.State==EM_ST_RUNNING) && (Elem_SYS.Trig_Incrementer>0))!=1 )
{
	//<SYS_DAEMONS>
   costate{
		ALBAOS_DAEMONS
   }
	//</SYS_DAEMONS>
	//<HANDLERS>
   costate{
   	waitfor(Dev_UDP_Event_Flag_Check()>0);
		Dev_UDP_User_Handler(EM_PROCESSING_BUF,EM_PROCESSING_BUF_LEN,&EM_Ord_Buf);
   }
   //</HANDLERS>
}

/*
if( (Elem.Trig_Mode==EM_TR_MD_INT) && (Elem.State==EM_ST_RUNNING) )
{

	costate{
   waitfor(DelayMs(Elem.Trig_Periode));
   Elem_SYS.Trig_Incrementer++;
   }

}
*/


   costate{

      waitfor(EM_ADC_API_State_Handler()!=EM_ST_IDLE); //if the status got changed
      //<INTERNAL TRIGGER>
		if( (Elem.Trig_Mode==EM_TR_MD_INT) && (Elem.State==EM_ST_RUNNING) )
      {
      	if(chk_timeout(trig_periode_timer)>0)
      	{
      	trig_periode_timer=_SET_TIMEOUT(Elem.Trig_Periode);
         Elem_SYS.Trig_Incrementer++;Elem_SYS.Trig_Timer=_SET_TIMEOUT(Elem.Trig_Delay);
      	}
      }
      //</INTERNAL TRIGGER>

		//<ADC accquisition only>
   	if(chk_timeout(Elem_SYS.Timer_Srate)>0)
   		{
      	Elem_SYS.Timer_Srate=_SET_TIMEOUT(Elem.Srate);
			EM_ADC_Raw_Tick();
         EM_Autorange_Handler();
      	}
		//</ADC accquisition only>
      //<HARDWARE TRIGGER DELAY>
      if(chk_timeout(Elem_SYS.Trig_Timer)>0)
      	{
      	Elem_SYS.Trig=EM_Trig_Tick();
//         printf("%u\n",MS_TIMER);
         }

      //</HARDWARE TRIGGER DELAY>

      EM_ADC_Tick(Elem.State,&Elem_SYS.Trig);
      EM_EVT_Tick(EM_PROCESSING_BUF,Elem.Event_Mode,Elem.Event_Client);

      }
//    printf("%ld\n",MS_TIMER);

   //<ADC acquisition>
//</PROGRAM>
}
//***********************</LOOP>***********************************************/
//<Forbidden state>
SYS_Reset;
//</Forbidden state>
return 0;
}
//***********************</RUNSYSTEM>******************************************/



