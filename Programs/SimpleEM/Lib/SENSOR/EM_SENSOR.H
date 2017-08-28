/*** BeginHeader */
#ifndef __EM_SENSOR_H
#define __EM_SENSOR_H
/*** EndHeader */

/*** BeginHeader
*/
#ifdef EM_SENSOR_DEBUG
#define _EM_SENSOR_NODEBUG
#else
#define _EM_SENSOR_NODEBUG nodebug
#endif

struct _EM_SEN_CONF_DUMP{
	word _crc;
	int 	ShadowDAC			[EM_SENSOR_MAX];
	int 	ShadowINV			[EM_SENSOR_MAX];
	float ShadowGain			[EM_SENSOR_MAX][2];      //transimp,voltage
	float ShadowBandwidth	[EM_SENSOR_MAX][2];      //prefilter,postfilter
	int 	ShadowRange      	[EM_SENSOR_MAX];
};

const struct _EM_SEN_CONF_DUMP Elem_Sen_Default={
	EM___CRC,
	0x07FF,0x07FF,0x07FF,0x07FF,
	0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,
};

bbram struct _EM_SEN_CONF_DUMP Elem_Sen;

/*** EndHeader */



/*** BeginHeader */
#endif
/*** EndHeader */