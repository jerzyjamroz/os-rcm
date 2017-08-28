//#define PACK_I2P_CONV_HVS_DEBUG
//#define SYSTEM_HVS_DEBUG
//#define DEVICE_HVS_DEBUG
//#define GENERAL_HVS_DEBUG
//#define SYSTEM_HVS_DEBUG
//#define TELNET_HVS_DEBUG
//#define MENU_HVS_DEBUG
/*******************************************************************************
*****************************HV*Splitter****************************************
*******************************************************************************/

char * const SW_Ver="FW:1.04.02";
#define Ethernet_Password_Default 1243

#use "Config_sys_HVS.lib"
#use "Initialization_HVS.lib"

#use "SFLASH_STORE_BROKEN_HVS.lib"
#use "CURRENT2PRESSURE_CONV_PACK.LIB"

//#use "TFTP_GET_FIRMWARE.LIB"

//<patches>
int Eth_DHCP_Daemon(void);
int Eth_isLink(void);
//</patches>

//nodebug
void main(void)
{
I2P_Init();
Initialization_HVS();
SFlash_Slope_Init();
//****************************INIT**********************************************
while(1)
	{

	Eth_DHCP_Daemon();

	//***START continous ADC data aqusision
   costate{
   wfd ADC_Processing_Handler();      //to collect raw values
   System_Arg_Handler();              //System VARS
   }
	//***END continous ADC data aqusision

//------------------------------------------------------------------------------
   costate{
		Prt_OverInterval_Handler();
      Prt_Slope_Handler();
		Prt_Sys_DamagedQLambda_Handler();

		System_Threshold_Warning_Handler();
		System_Threshold_EPS_Handler();
		Sys_ConfigEPS_Occurence_Handler();
//test i think it will not block the interlock	//Sys_BrokenQlambda_Remover_Handler();		//it must be directly after  System_Threshold_Warning_Handler(); AND Sys_ConfigEPS_Occurence_Handler();
   SFlash_Slope_Save_Handler();  //*slope*protection*
   }
   //***END system Flags

   //broken channels recovery
   costate{
   wfd SFlash_SlopeFl_Handler();
   waitfor(DelayMs(500)); //1.03.01
   }

//*********************************<MENU>***************************************
   costate{
   wfd Sys_Timer_ButPress();
   }
   //***START- menu
   		costate{
   		wfd Keypad_Handler();
  			}

         costate{
         wfd Keypad_Order_Handler();
         }

         if(Menu.Mode==0)
         	{
   				costate{
   				wfd Menu1_Data_Handler();
   				}
            }
         else
         	{
            	if (System_Flag.HVS_Mode!=2)
               	{
   						costate{
   						wfd Menu2_Data_Handler();
   						}
               	}
               else
               	{
                  	costate{
                  	Message_ModeBox();
                  	waitfor( DelayMs(5000) );
                     Menu_Mod_Toggle();
                  	}
                  }
            }

   		costate{
   		if (System_Flag.Test_Blocker==1) LED_Special_All(1);
   		}
//*********************************</MENU>**************************************


   //***START- inerlock fully working and tested
   costate{
   //disable/enable
	Interlock_Handler_Relays();
   //sensing
   Interlock_Handler_Int_Dis_Sense();
   Interlock_Handler_Int_Sense();
   waitfor(DelayMs(300)); //1.03.01
   }

   if(System_Flag.Test_Blocker!=1)
   {
   	costate{
   	wfd Interlock_Handler();
      //iterlock small update
   	System_Update_Flag_Interlock(); //small handler which updates number of interlocked channel
      waitfor(DelayMs(300)); //1.03.01
   	}
   }

   costate{
   wfd Interlock_Handler_Manual_Interlock();
   }
   //***END- interlock fully working and tested

   //***START- Device handlers
   if(System_Flag.Test_Blocker!=1)
   {
   	costate{
   	 	Dev_LED_Alarm_Handler();
		}
   	costate{
   	wfd Dev_EPS_Relay_Handler();
   	}
   	costate{
   	wfd Dev_LED_Calibration_Handler();
		}
   	costate{
   	wfd Dev_LED_Telnet_Handler();
   	}
   }

   //***START- Protection handlers
   costate{
   Protection_Expander1_Handler();
   Protection_Expander2_Handler();
   waitfor(DelaySec(1)); //1.03.01
   }

   if (System_Flag.HVS_Mode!=2)
    {
      costate{
      wfd Protection_LCD_Handler(); //******************************************
      waitfor(DelaySec(1)); //1.03.01
      }
    }
    //***END- Protection handlers

   //*** Start - Telnet Handlers
   costate{
   wfd recv_tick();
//   tcp_tick(state->s);
   }
   costate{
   wfd Telnet_Alarm_EPS_Handler();
   }
   costate{
   wfd Telnet_Alarm_EPS_EXE_Handler();
   }
   costate{
   wfd Telnet_Alarm_Warning_Handler();
   }
   costate{
   wfd Telnet_Alarm_Interlock_Handler();
   }
   costate{
   	Telnet_BrkCh_Handler();
   }
   costate{
   wfd Sys_Telnet_Timer_Handler();
   }

   //*** End - Telnet Handlers

   //***START- alerts

   if (System_Flag.MsgBox_BlockFlag>0)
   {
   costate{
		wfd Message_Box_Handler();    //this message box handler doesn't work properly
		}
   }

   costate{
   if(Dev.Manual_EPS==1) wfd Msg_LED_Man_EPS();
   }

   costate{
//   if(Broken_Channel.FlashFlag_Char>0) wfd Msg_LED_BrokenQLambda();
//   else if(System_Flag.EPS>0) wfd Msg_LED_EPS();
//   else if(System_Flag.Pth_Warning>0) wfd Msg_LED_Warning();
	wfd Msg_LED_Problems();
   }

   //***END- alerts
 	}
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