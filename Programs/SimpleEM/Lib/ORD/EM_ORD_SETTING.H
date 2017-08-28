/*** BeginHeader */
#ifndef __EM_ORD_SETTING_H
#define __EM_ORD_SETTING_H
/*** EndHeader */

/*** BeginHeader */
//<SETTINGS>

//<Functions>
//int EM_HELP_Func			(char *retBuf, struct _SYSOrd *em_ord);    //made as EM_QHELP_Func
int EM_FILTER_Func     	(struct _SYSOrd *);

int EM_OFFSETCORR_Func 	(struct _SYSOrd *);
int EM_GAINCORR_Func   	(struct _SYSOrd *);

int EM_RANGE_Func      	(struct _SYSOrd *);
int EM_OFFSET_Func     	(struct _SYSOrd *);
int EM_INV_Func         (struct _SYSOrd *);

int EM_AVSAMPLES_Func  	(struct _SYSOrd *);
int EM_SRATE_Func      	(struct _SYSOrd *);
int EM_TRIGMODE_Func   	(struct _SYSOrd *);
int EM_POINTS_Func     	(struct _SYSOrd *);
int EM_STRIG_Func			(struct _SYSOrd *);
int EM_TRIGPERIODE_Func	(struct _SYSOrd *);

int EM_STARTADC_Func   	(struct _SYSOrd *);
int EM_STOPADC_Func    	(struct _SYSOrd *);

int EM_START_Func      	(struct _SYSOrd *);
int EM_STOP_Func       	(struct _SYSOrd *);
int EM_ENABLE_Func     	(struct _SYSOrd *);

int EM_RESET_Func     	(struct _SYSOrd *);
int EM_SENINIT_Func     (struct _SYSOrd *);
int EM_DEFAULT_Func     (struct _SYSOrd *);

int EM_AMPMODE_Func     (struct _SYSOrd *);
int EM_GAIN1_Func       (struct _SYSOrd *);
int EM_GAIN2_Func       (struct _SYSOrd *);

int EM_EVTMODE_Func     (struct _SYSOrd *);
int EM_EVTCLIENT_Func   (struct _SYSOrd *);

int EM_TESTNCSSET_Func	(struct _SYSOrd *);
int EM_TESTNCSRES_Func	(struct _SYSOrd *);
int EM_TESTSPIWRITE_Func(struct _SYSOrd *);
int EM_TESTCLKPOL_Func  (struct _SYSOrd *);

int EM_TRIGPOL_Func		(struct _SYSOrd *);

int EM_AUTORANGEMIN_Func(struct _SYSOrd *);
int EM_AUTORANGEMAX_Func(struct _SYSOrd *);
int EM_AUTORANGE_Func	(struct _SYSOrd *);

int EM_TRIGDELAY_Func   (struct _SYSOrd *);

//</Functions>


//<IDs>
enum{
EM_HELP = 0,

EM_OFFSETCORR,
EM_GAINCORR,

EM_FILTER,
EM_RANGE,
EM_OFFSET,
EM_INV,

EM_AVSAMPLES,
EM_SRATE,
EM_TRIGMODE,
EM_POINTS,
EM_STRIG,
EM_TRIGPERIODE,

EM_STARTADC,
EM_STOPADC,

EM_START,
EM_STOP,
EM_ENABLE,
EM_RESET,
EM_SENINIT,
EM_DEFAULT,

EM_AMPMODE,
EM_GAIN1,
EM_GAIN2,

EM_EVTMODE,
EM_EVTCLIENT,

EM_TESTNCSSET,
EM_TESTNCSRES,
EM_TESTSPIWRITE,
EM_TESTCLKPOL,

EM_TRIGPOL,

EM_AUTORANGEMIN,
EM_AUTORANGEMAX,
EM_AUTORANGE,

EM_TRIGDELAY,

}_EMOrdRef_ID_Setting;
//</IDs>

struct _SYSOrd_REF EMOrdRef_Setting[]={
EM_HELP,					4,   			"HELP",				 	SYSNULL_PCHAR,				  				SYSNULL_PCHAR,			" %Fs",	    					SYSNULL_INT,     		EM_QHELP_Func,   		//DONE

EM_OFFSETCORR,      10,   			"OFFSETCORR",       	" %d %f %d %f %d %f %d %f",			SYSNULL_PCHAR,   		SYSNULL_PCHAR,	    			'\r',         			EM_OFFSETCORR_Func,
EM_GAINCORR,      	8,	   		"GAINCORR",       	" %d %f %d %f %d %f %d %f",    		SYSNULL_PCHAR,   		SYSNULL_PCHAR,	    			'\r',         			EM_GAINCORR_Func,


EM_FILTER,				6,				"FILTER",			 	" %d %4s %d %4s %d %4s %d %4s",		"[CH]",	        		SYSNULL_PCHAR,					'\c',     				EM_FILTER_Func,
EM_RANGE,				5,  			"RANGE",		  		 	" %d %6s %d %6s %d %6s %d %6s", 		"[CH]",	        		SYSNULL_PCHAR,					SYSNULL_INT,     		EM_RANGE_Func,
EM_OFFSET,				6,				"OFFSET",			 	" %d %d %d %d %d %d %d %d",			"[CH]",	        		SYSNULL_PCHAR, 				'\c',     				EM_OFFSET_Func,
EM_INV,					3,				"INV",			 		" %d %4s %d %4s %d %4s %d %4s",		"[CH]",	        		SYSNULL_PCHAR, 				'\c',     				EM_INV_Func,

EM_AVSAMPLES,			9,				"AVSAMPLES",		 	" %d",			    						SYSNULL_PCHAR,   		SYSNULL_PCHAR,					'\c',     				EM_AVSAMPLES_Func,
EM_SRATE,				5,				"SRATE",				 	" %d",						      		SYSNULL_PCHAR,   		SYSNULL_PCHAR,				   '\c',     				EM_SRATE_Func,

EM_TRIGMODE,			8,				"TRIGMODE",			 	" %10s",			     						SYSNULL_PCHAR,   		SYSNULL_PCHAR,				   '\c',     				EM_TRIGMODE_Func,
EM_POINTS,				6,				"POINTS",			 	" %d",						      		SYSNULL_PCHAR,   		SYSNULL_PCHAR,				   '\c',     				EM_POINTS_Func,
EM_STRIG,				5,				"STRIG",			 		SYSNULL_PCHAR,						      SYSNULL_PCHAR,   		SYSNULL_PCHAR,				   '\a',     				EM_STRIG_Func,
EM_TRIGPERIODE,		11,			"TRIGPERIODE",		 	" %d",			  							SYSNULL_PCHAR,   		SYSNULL_PCHAR,					'\c',     				EM_TRIGPERIODE_Func,


EM_STARTADC,			8,				"STARTADC",				SYSNULL_PCHAR,								SYSNULL_PCHAR,	      SYSNULL_PCHAR,					SYSNULL_INT,     		EM_STARTADC_Func,       //DONE
EM_STOPADC,				7,				"STOPADC",				SYSNULL_PCHAR,								SYSNULL_PCHAR,	      SYSNULL_PCHAR,					SYSNULL_INT,     		EM_STOPADC_Func,        //DONE

EM_START,				5,				"START",				 	SYSNULL_PCHAR,								SYSNULL_PCHAR,	      SYSNULL_PCHAR,					SYSNULL_INT,     		EM_START_Func,       //DONE
EM_STOP,					4,				"STOP",				 	SYSNULL_PCHAR,								SYSNULL_PCHAR,	      SYSNULL_PCHAR,					SYSNULL_INT,     		EM_STOP_Func,        //DONE
EM_ENABLE,				6,				"ENABLE",			 	" %d %4s %d %4s %d %4s %d %4s",		"[CH]",	        		SYSNULL_PCHAR,					'\c',     				EM_ENABLE_Func,  		//DONE

EM_RESET,           	5,          "RESET",             SYSNULL_PCHAR,                      SYSNULL_PCHAR,       SYSNULL_PCHAR,             '\c',                EM_RESET_Func,
EM_SENINIT,				7,				"SENINIT",			 	" %d %4s %d %4s %d %4s %d %4s",		"[CH]",	        		SYSNULL_PCHAR,					'\c',     				EM_SENINIT_Func,  	//DONE
EM_DEFAULT,				7,				"DEFAULT",			 	SYSNULL_PCHAR,								"[CH]",	        		SYSNULL_PCHAR,					'\c',     				EM_DEFAULT_Func,  	//DONE

EM_AMPMODE,          7,				"AMPMODE",           " %d %8s %d %8s %d %8s %d %8s",		"[CH]",	        		SYSNULL_PCHAR,					'\c',     				EM_AMPMODE_Func,  	//DONE
EM_GAIN1,          	5,				"GAIN1",           	" %d %8s %d %8s %d %8s %d %8s",		"[CH]",	        		SYSNULL_PCHAR,					'\c',     				EM_GAIN1_Func,  		//DONE
EM_GAIN2,          	5,				"GAIN2",           	" %d %8s %d %8s %d %8s %d %8s",		"[CH]",	        		SYSNULL_PCHAR,					'\c',     				EM_GAIN2_Func,  		//DONE

EM_EVTMODE,				7,				"EVTMODE",		 		" %d",			    						SYSNULL_PCHAR,   		SYSNULL_PCHAR,					'\c',     				EM_EVTMODE_Func,
EM_EVTCLIENT,			9,				"EVTCLIENT",		 	" %20s %d",			    					SYSNULL_PCHAR,   		SYSNULL_PCHAR,					'\c',     				EM_EVTCLIENT_Func,

EM_TESTNCSSET,		  	10,			"TESTNCSSET",		 	" %d %d",			    					SYSNULL_PCHAR,   		SYSNULL_PCHAR,					'\c',     				EM_TESTNCSSET_Func,
EM_TESTNCSRES,		  	10,			"TESTNCSRES",		 	SYSNULL_PCHAR,			    				SYSNULL_PCHAR,   		SYSNULL_PCHAR,					'\c',     				EM_TESTNCSRES_Func,
EM_TESTSPIWRITE,		12,			"TESTSPIWRITE",		" %d",			    						SYSNULL_PCHAR,   		SYSNULL_PCHAR,					'\c',     				EM_TESTSPIWRITE_Func,
EM_TESTCLKPOL,       10,			"TESTCLKPOL",			" %d",			    						SYSNULL_PCHAR,   		SYSNULL_PCHAR,					'\c',     				EM_TESTCLKPOL_Func,

EM_TRIGPOL,				7,				"TRIGPOL",			 	" %10s",			     						SYSNULL_PCHAR,   		SYSNULL_PCHAR,				   '\c',     				EM_TRIGPOL_Func,

EM_AUTORANGEMIN,		12,			"AUTORANGEMIN",		" %d %d %d %d %d %d %d %d",		SYSNULL_PCHAR,   		SYSNULL_PCHAR,				   '\c',     				EM_AUTORANGEMIN_Func,
EM_AUTORANGEMAX,		12,			"AUTORANGEMAX",		" %d %d %d %d %d %d %d %d",		SYSNULL_PCHAR,   		SYSNULL_PCHAR,				   '\c',     				EM_AUTORANGEMAX_Func,
EM_AUTORANGE,			9,				"AUTORANGE",			" %d %4s %d %4s %d %4s %d %4s",		"[CH]",		   		SYSNULL_PCHAR,				   '\c',     				EM_AUTORANGE_Func,

EM_TRIGDELAY,			9,				"TRIGDELAY",			" %lu",						      		SYSNULL_PCHAR,   		SYSNULL_PCHAR,				   '\c',     				EM_TRIGDELAY_Func,

SYSNULL_INT,			SYSNULL_INT,&SYSNULL_FCHAR,	 	SYSNULL_PCHAR,								SYSNULL_PCHAR,	  		SYSNULL_PCHAR,					SYSNULL_INT,         SYSOrd_Null_Func,
};
//</SETTINGS>
/*** EndHeader */


/*** BeginHeader */
#endif
/*** EndHeader */