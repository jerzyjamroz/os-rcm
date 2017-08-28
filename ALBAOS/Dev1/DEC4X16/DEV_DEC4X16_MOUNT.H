/*** BeginHeader */
#ifndef __DEV_DEC4X16_MOUNT_H
#define __DEV_DEC4X16_MOUNT_H
/*** EndHeader */


/*** BeginHeader*/
//<DEC4X16_DRIVER>
//<Mount_Dev_DEC4X16_Driver>
#ifdef Mount_Dev_DEC4X16_Driver
	#warnt "Dev_DEC4X16: ACTIVE"
//------------------------------------------------------------------------------
//<HEADER>
   #use "DEV_DEC4X16.LIB"
//</HEADER>
//<INIT>
	#define Dev_DEC4X16_Init() DEC4X16_Init()
//</INIT>
//------------------------------------------------------------------------------
//<BODY>
	#define Dev_DEC4X16_Set(dec4)                 DEC4X16_Set(dec4)
	#define Dev_DEC4X16_Res()                     DEC4X16_Res()
//</BODY>
//------------------------------------------------------------------------------
//</DEC4X16_DRIVER>
#else

//	#ifdef Sim_Mount_Dev_DEC4X16_Driver

		#warnt "Sim_Dev_DEC4X16: ACTIVE"

      //<INIT>
		#define Dev_DEC4X16_Init()
		//</INIT>

      //<BODY>
		#define Dev_DEC4X16_Set(dec4)
		#define Dev_DEC4X16_Res()
		//</BODY>

//   #endif

#endif
//</Mount_Dev_DEC4X16_Driver>



/*** EndHeader */


/*** BeginHeader */
#endif
/*** EndHeader */