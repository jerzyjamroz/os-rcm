#ifndef __EM_H
#define __EM_H

#ifdef EM_DEBUG
#define _EM_NODEBUG
#else
#define _EM_NODEBUG nodebug
#endif

#define EM_SENSOR_MAX 4
#define EM_SENSOR_ADDR(ch) (3-ch)
#define EM___CRC 0xEEEE

static struct _SYSOrd 	EM_Ord_Buf=SYSOrd_Null;

enum{
	EM_100p,
	EM_1n,
	EM_10n,
	EM_100n,
	EM_1u,
	EM_10u,
	EM_100u,
	EM_1m,
	EM_RANGE_MAX,
}_EM_RANGE_ID;
char *EM_SEN_TXT_Range[]={
"100pA",     //0
"1nA",       //1
"10nA",      //2
"100nA",     //3
"1uA",       //4
"10uA",      //5
"100uA",     //6
"1mA",       //7
"",
};
const float EM_STATUS_GAIN_TAB[]={
1/(10/100E-12),    	//0
1/(10/1E-9),      	//1
1/(10/10E-9),      	//2
1/(10/100E-9),     	//3
1/(10/1E-6),      	//4
1/(10/10E-6),      	//5
1/(10/100E-6),     	//6
1/(10/1E-3),      	//7
0,
};

enum{
	EM_TR_MD_NONE,
	EM_TR_MD_INT,
	EM_TR_MD_EXT,
}_EM_TR_ID;
char *EM_TR_MD_TXT[]={
	"NONE",
	"INT",
	"EXT",
	"",
};

enum{
	EM_ST_IDLE,
   EM_ST_ON,
	EM_ST_RUNNING,
}_EM_ST_ID;
char *EM_ST_TXT[]={
	"IDLE",
   "ON",
	"RUNNING",
	"",
};

enum{
	EM_RANGE_LN,
   EM_RANGE_HB,
   EM_RANGE_SHB,
	EM_RANGE_TEST,
}_EM_RANGE_ID;
char *EM_RANGE_MODE_TXT[]={
	"LN",
   "HB",
   "SHB",
	"TEST",
	"",
};

enum{
   EM_EVT_OFF,
	EM_EVT_ON,
}_EM_EVT;
char *EM_EVT_TXT[]={
	"OFF",
   "ON",
	"",
};

enum{
EM_INT_Default,
EM_INT_FALLING,
EM_INT_RISING,
}_EM_INT_EDGE;
char *EM_INT_EDGE_TXT[]={
	"DEFAULT",
   "FALLING",
	"RISING",
	"",
};

enum{
   EM_RANGE_AUTO_OFF,
	EM_RANGE_AUTO_ON,
}_EM_AUTO;
char *EM_RANGE_AUTO_TXT[]={
	"OFF",
   "ON",
	"",
};

//<ELEM_SYS_DUMP>
struct _ELEM_SYS_DUMP{
	char ** Trig_Mode_Txt;
   int Trig;
	int Trig_Incrementer;
   int Trig_Counter;
   unsigned long int Trig_Timer;
	char ** State_Txt;
   char ** Range_Mode_Txt;
   char ** Evt_Txt;
   unsigned long int Timer_Srate;
   char ** Int_Edge_Txt;
};
struct _ELEM_SYS_DUMP Elem_SYS ={
	EM_TR_MD_TXT,
   0,
	0,
   -1,
   0,
	EM_ST_TXT,
   EM_RANGE_MODE_TXT,
   EM_EVT_TXT,
   0,
   EM_INT_EDGE_TXT,
};
//</ELEM_SYS_CONF>

struct _ELEM_CONF_DUMP{
   word _crc;
   int Range_Mode[4];
	int Trig_Mode;
	int Trig_Periode;
	unsigned long int  Trig_Delay;
	int State;
	int Ch_Active;
	int Srate;         //min period = 1[ms]
	float Offset_Corr[EM_SENSOR_MAX][EM_RANGE_MAX];
	float Gain_Corr[EM_SENSOR_MAX][EM_RANGE_MAX];

   int Event_Mode;
   int Int_Edge;
   unsigned long Event_Client[2];
   int Range_Auto_St_Min_Max[4][3];  //(ON,OFF);MIN%;MAX%;Channel
};

const struct _ELEM_CONF_DUMP Elem_Default={
//<_ELEM_CONF_DUMP>
	EM___CRC,

   EM_RANGE_HB,EM_RANGE_HB,EM_RANGE_HB,EM_RANGE_HB,

	EM_TR_MD_INT,
	100,
   0,

	EM_ST_RUNNING,

	0x0F,
	1,

	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,

	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,

   EM_EVT_OFF,
   EM_INT_RISING,
   0,0,

   EM_RANGE_AUTO_OFF,5,95,
   EM_RANGE_AUTO_OFF,5,95,
   EM_RANGE_AUTO_OFF,5,95,
   EM_RANGE_AUTO_OFF,5,95,
//</_ELEM_CONF_DUMP>
};

bbram struct _ELEM_CONF_DUMP Elem;


extern struct _EM_SEN_CONF_DUMP Elem_Sen;
extern struct _EM_ADC_CONF Elem_ADC;

struct _EM_CONF_GLOBAL
{
	struct _ELEM_CONF_DUMP *Main;
	struct _EM_ADC_CONF *ADC;
	struct _EM_SEN_CONF_DUMP *Sen;

};

struct _EM_CONF_GLOBAL El_Gl={
&Elem,
&Elem_ADC,
&Elem_Sen,
};


#endif


