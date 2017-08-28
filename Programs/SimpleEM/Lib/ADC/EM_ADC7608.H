#ifndef __EM_ADC7608_H
#define __EM_ADC7608_H


#ifdef EM_ADC_DEBUG
#define _EM_ADC_NODEBUG
#else
#define _EM_ADC_NODEBUG nodebug
#endif

#define EM_ADC_OVERRANGE -4096
#define EM_ADC_ACQ_MAX 1024

#ifndef EM_SENSOR_MAX
	#define EM_SENSOR_MAX 4
#endif

#ifndef EM___CRC
	#define EM___CRC 0xAAEE
#endif
//static int 				EM_ADC_Raw[EM_SENSOR_MAX+1][EM_ADC_ACQ_MAX];
//static far float 		EM_ADC_VectTab_Avr[EM_ADC_ACQ_MAX][EM_SENSOR_MAX+1];

static long int		EM_ADC_TotalAcc[4+1]={0,0,0,0,0};
static far float     EM_ADC_FloatAcc[4+1]={0,0,0,0,0};

#define EM_ADC_I_Sample_Get(x) EM_Calc_StatAuto_Ich(ch,*(EM_ADC_VectTab_Avr+x))
#define EM_ADC_I_Actual_Get EM_Calc_StatAuto_Ich(ch,EM_ADC_FloatAcc)
#define EM_ADC_I_Vect_Get(x) EM_Calc_StatAuto_Ich(ch,x)

#define EM_ADC_I_Sample_Status_Get(x) (int)EM_ADC_VectTab_Avr[x][EM_SENSOR_MAX]
#define EM_ADC_I_Status_Actual_Get (int)EM_ADC_FloatAcc[EM_SENSOR_MAX]

//<ONLY for instant current readings>
#define EM_ADC_Raw_Inst_Get EM_ADC_Raw[ch][Elem_ADC_SYS.Raw_Idx]
#define EM_ADC_Raw_Status_Get EM_ADC_Raw[EM_SENSOR_MAX][Elem_ADC_SYS.Raw_Idx]
#define EM_ADC_Raw_Status_Int_Get(ch) ((EM_ADC_Raw_Status_Get>>(EM_SENSOR_MAX*ch))&0x000F)
//</ONLY for instant current readings>

struct _EM_ADC_SYS{
	int Raw_Idx;    //index of raw data
	int Avs_Counter_Idx;    //
	int Avr_Idx;    //index of avr data
	int Avr_Counter_Idx;
//	int Avr_Act_Idx;
};

struct _EM_ADC_SYS Elem_ADC_SYS={
-1,
-1,
-1,
-1,
};

struct _EM_ADC_CONF{
word _crc;
int Avs_Max;
int Avr_Max;    //averaging factor
};

const struct _EM_ADC_CONF Elem_ADC_Default=
{
EM___CRC,
100,
10,
};
bbram struct _EM_ADC_CONF Elem_ADC;

//CH0,CH1,CH2,CH3,OVERRANGE,GAIN

#endif