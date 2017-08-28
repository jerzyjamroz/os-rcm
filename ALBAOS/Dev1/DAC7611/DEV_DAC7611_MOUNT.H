/*** BeginHeader */
#ifndef __DEV_DAC7611_MOUNT_LIB
#define __DEV_DAC7611_MOUNT_LIB
/*** EndHeader */


/*** BeginHeader*/

//<DAC7611_DRIVER>
//<Mount_Dev_DAC7611_Driver>
#ifdef Mount_Dev_DAC7611_Driver
	#warnt "Dev_DAC7611: ACTIVE"
//------------------------------------------------------------------------------
//<HEADER>
   #use "DEV_DAC7611.LIB"
//</HEADER>
//<INIT>
//</INIT>
//------------------------------------------------------------------------------
//<BODY>
#define Dev_DAC7611_Wr(mv) DAC7611_Wr(mv)
//</BODY>
//------------------------------------------------------------------------------
//</DAC7611_DRIVER>
#else

		#warnt "Sim_Dev_DAC7611: ACTIVE"

      //<BODY>
		#define Dev_DAC7611_Wr(mv)
		//</BODY>

#endif
//</Mount_Dev_DAC7611_Driver>


/*** EndHeader */


/*** BeginHeader */
#endif
/*** EndHeader */