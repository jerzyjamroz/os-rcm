/*** BeginHeader */
#ifndef __DEV_ADS7870_MOUNT_H
#define __DEV_ADS7870_MOUNT_H
/*** EndHeader */


/*** BeginHeader*/
//<ADS7870_DRIVER>
//<Mount_Dev_ADS7870_Driver>
#ifdef Mount_Dev_ADS7870_Driver
	#warnt "Dev_ADS7870: ACTIVE"
//------------------------------------------------------------------------------
//<HEADER>
   #use "DEV_ADS7870.LIB"
//</HEADER>
//<INIT>
//</INIT>
//------------------------------------------------------------------------------
//<BODY>
	#define Dev_ADS7870_DGAnaIn(ch,gain) 	anaIn(ch<<1,DIFF,gain)
//</BODY>
//------------------------------------------------------------------------------
//</ADS7870_DRIVER>
#else

	#warnt "Sim_Dev_ADS7870: ACTIVE"
   int Dev_ADS7870_DGAnaIn(int ch,int gain) 	{return -1;}

#endif
//</Mount_Dev_ADS7870_Driver>



/*** EndHeader */


/*** BeginHeader */
#endif
/*** EndHeader */