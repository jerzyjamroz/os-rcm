/*** BeginHeader */
#ifndef __DEV_INT_MOUNT_H
#define __DEV_INT_MOUNT_H
/*** EndHeader */


/*** BeginHeader*/
//<UDP_DRIVER>
//<Mount_DEV_INT_Driver>
#ifdef Mount_DEV_INT_Driver
	#warnt "DEV_INT: ACTIVE"
//------------------------------------------------------------------------------
//<HEADER>
   #use "DEV_INT.LIB"
//</HEADER>
//<INIT>
	#define Dev_Int_Init(isr,edge) Int_Init(isr,edge)
//</INIT>
//------------------------------------------------------------------------------
//<BODY>
   #define Dev_Int_Dis() Int_Dis()
   #define Dev_Int_En(edge) Int_En(edge)
	#define Dev_Int_Isr_Event_Tick() Int_Isr_Event_Tick()
   #define Dev_Int_Tick(ms,edge) Int_Tick(ms,edge)

//</BODY>
//------------------------------------------------------------------------------
//</UDP_DRIVER>
#else

//	#ifdef Sim_Mount_DEV_INT_Driver

		#warnt "Sim_DEV_INT: ACTIVE"
//<INIT>
	#define Dev_Int_Init(isr,edge)
//</INIT>
//------------------------------------------------------------------------------
//<BODY>

   #define Dev_Int_Dis()
   #define Dev_Int_En(edge)
	#define Dev_Int_Isr_Event_Tick()
   #define Dev_Int_Tick(ms,edge)

//</BODY>
//   #endif

#endif
//</Mount_DEV_INT_Driver>



/*** EndHeader */


/*** BeginHeader */
#endif
/*** EndHeader */