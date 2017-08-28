/*** BeginHeader */
#ifndef __EM_ORD_QUERY_H
#define __EM_ORD_QUERY_H
/*** EndHeader */


/*** BeginHeader */
//<QUERIES>
//<Functions>
int EM_QHELP_Func			     	(struct _SYSOrd *);

int EM_QOFFSETCORR_Func       (struct _SYSOrd *);
int EM_QGAINCORR_Func         (struct _SYSOrd *);

int EM_QFILTER_Func		     	(struct _SYSOrd *);
int EM_QRANGE_Func		     	(struct _SYSOrd *);
int EM_QOFFSET_Func		     	(struct _SYSOrd *);
int EM_QINV_Func					(struct _SYSOrd *);

int EM_QAVSAMPLES_Func	     	(struct _SYSOrd *);
int EM_QSRATE_Func		     	(struct _SYSOrd *);
int EM_QTRIGMODE_Func	     	(struct _SYSOrd *);
int EM_QPOINTS_Func		     	(struct _SYSOrd *);
int EM_QTRIGPERIODE_Func     	(struct _SYSOrd *);

int EM_QMEAS_Func			     	(struct _SYSOrd *);
int EM_QIINST_Func            (struct _SYSOrd *);

int EM_QDATA_Func			     	(struct _SYSOrd *);
int EM_QLDATA_Func		     	(struct _SYSOrd *);
int EM_QAVDATA_Func          	(struct _SYSOrd *);
int EM_QRAWDATA_Func         	(struct _SYSOrd *);
int EM_QSTATUS_Func		     	(struct _SYSOrd *);
int EM_QMODE_Func			     	(struct _SYSOrd *);
int EM_QSTATE_Func           	(struct _SYSOrd *);
int EM_QENABLE_Func		     	(struct _SYSOrd *);
int EM_QFIM_Func      	     	(struct _SYSOrd *);
int EM_QVINST_Func      	   (struct _SYSOrd *);
int EM_QVMEAS_Func      	   (struct _SYSOrd *);

int EM_QRAWINST_Func          (struct _SYSOrd *);
int EM_QRAWMEAS_Func          (struct _SYSOrd *);

int EM_QDEVMAC_Func	         (struct _SYSOrd *);
int EM_QDEVIP_Func            (struct _SYSOrd *);
int EM_QDEVSNO_Func           (struct _SYSOrd *);
int EM_QSENTEST_Func          (struct _SYSOrd *);
int EM_QMEMDUMP_Func          (struct _SYSOrd *);

int EM_QAMPMODE_Func          (struct _SYSOrd *);
int EM_QGAIN1_Func            (struct _SYSOrd *);
int EM_QGAIN2_Func            (struct _SYSOrd *);

int EM_QEVTMODE_Func       	(struct _SYSOrd *);
int EM_QEVTCLIENT_Func        (struct _SYSOrd *);

int EM_QTESTSPIREAD_Func      (struct _SYSOrd *);

int EM_QTRIGPOL_Func      		(struct _SYSOrd *);

int EM_QAUTORANGEMIN_Func    	(struct _SYSOrd *);
int EM_QAUTORANGEMAX_Func    	(struct _SYSOrd *);
int EM_QAUTORANGE_Func       	(struct _SYSOrd *);

int EM_QTRIGDELAY_Func        (struct _SYSOrd *);

//</Functions>


//<IDs>
enum{
EM_QHELP = 0,

EM_QOFFSETCORR,
EM_QGAINCORR,

EM_QFILTER,
EM_QRANGE,
EM_QOFFSET,
EM_QINV,

EM_QAVSAMPLES,
EM_QSRATE,
EM_QTRIGMODE,
EM_QPOINTS,
EM_QTRIGPERIODE,

EM_QMEAS,
EM_QIINST,

EM_QDATA,
EM_QLDATA,
EM_QAVDATA,
EM_QRAWDATA,
EM_QSTATUS,
EM_QMODE,
EM_QSTATE,
EM_QENABLE,
EM_QFIM,

EM_QVINST,
EM_QVMEAS,

EM_QRAWINST,
EM_QRAWMEAS,

EM_QDEVMAC,
EM_QDEVIP,
EM_QDEVSNO,
EM_QSENTEST,

EM_QMEMDUMP,

EM_QAMPMODE,
EM_QGAIN1,
EM_QGAIN2,

EM_QEVTMODE,
EM_QEVTCLIENT,

EM_QTESTSPIREAD,

EM_QTRIGPOL,

EM_QAUTORANGEMIN,
EM_QAUTORANGEMAX,
EM_QAUTORANGE,

EM_QTRIGDELAY,

}_EMOrdRef_ID_Query;
//</IDs>

struct _SYSOrd_REF EMOrdRef_Query[]={
EM_QHELP,				5, 	"?HELP",				   SYSNULL_PCHAR,						SYSNULL_PCHAR,			" %Fs", 			    			'\r',         EM_QHELP_Func,

EM_QOFFSETCORR,      11,   "?OFFSETCORR",       " %d %d %d %d",    				SYSNULL_PCHAR,   		" %d %.3f",	    				'\r',         EM_QOFFSETCORR_Func,
EM_QGAINCORR,      	9,	   "?GAINCORR",       	" %d %d %d %d",    				SYSNULL_PCHAR,   		" %d %.3f",	    				'\r',         EM_QGAINCORR_Func,

EM_QFILTER,				7,		"?FILTER",			 	" %d %d %d %d",					"CH",	        			" %d %.1f",						'\r',         EM_QFILTER_Func,
EM_QRANGE,				6, 	"?RANGE",			  	" %d %d %d %d",					"CH",	        			" %d %d%cA",					'\r',         EM_QRANGE_Func,
EM_QOFFSET,				7,		"?OFFSET",			 	" %d %d %d %d",					"CH",	        			" %d %d", 						'\r',         EM_QOFFSET_Func,
EM_QINV,					4,		"?INV",			 		" %d %d %d %d",					"CH",	        			" %d %s", 						'\r',         EM_QINV_Func,

EM_QAVSAMPLES,			10,	"?AVSAMPLES",		 	SYSNULL_PCHAR,						SYSNULL_PCHAR,   		" %d",					    	'\r',         EM_QAVSAMPLES_Func,
EM_QSRATE,				6,		"?SRATE",			 	SYSNULL_PCHAR,						SYSNULL_PCHAR,   		" %d",				    		'\r',         EM_QSRATE_Func,

EM_QTRIGMODE,			9,		"?TRIGMODE",		 	SYSNULL_PCHAR,						SYSNULL_PCHAR,   		" %s",				    		'\r',         EM_QTRIGMODE_Func,
EM_QPOINTS,				7,		"?POINTS",			 	SYSNULL_PCHAR,						SYSNULL_PCHAR,   		" %d",				    		'\r',         EM_QPOINTS_Func,
EM_QTRIGPERIODE,		12,	"?TRIGPERIODE",	 	SYSNULL_PCHAR,						"ms",   	  				" %d",					   	'\r',         EM_QTRIGPERIODE_Func,                                                                                    //not finished in here

EM_QMEAS,				5,		"?MEAS",				 	" %d %d %d %d",					"CH",	        			" %d %.5E",						'\r',         EM_QMEAS_Func,
EM_QIINST,				6,		"?IINST",			 	" %d %d %d %d",					SYSNULL_PCHAR,	   	" %d %.5E",				  		'\r',      	  EM_QIINST_Func,

EM_QDATA,				5,		"?DATA",				 	" %d %d %d %d",					"CH", 	        		" %d %.5E",				  		'\r',         EM_QDATA_Func,
EM_QLDATA,				6,		"?LDATA",			 	" %d %d %d %d",					"CH", 	        		" %d %.5E",						'\r',         EM_QLDATA_Func,
EM_QAVDATA,          7,		"?AVDATA",			 	" %d",								"CH", 	        		" %.5E",							'\r',         EM_QAVDATA_Func,

EM_QRAWDATA,     		8,		"?RAWDATA",			 	" %d",								"CH", 	        		" %d",							'\r',         EM_QRAWDATA_Func,
EM_QSTATUS,				7,		"?STATUS",			 	SYSNULL_PCHAR,						SYSNULL_PCHAR,   		" %04X",	    					'\r',         EM_QSTATUS_Func,
EM_QMODE,   			5,		"?MODE",				 	SYSNULL_PCHAR,						SYSNULL_PCHAR,   		SYSNULL_PCHAR,	    			'\r',         EM_QMODE_Func,
EM_QSTATE,       		6,		"?STATE",          	SYSNULL_PCHAR,						SYSNULL_PCHAR,   		" %s",	    					'\r',         EM_QSTATE_Func,
EM_QENABLE,				7,		"?ENABLE",			 	" %d %d %d %d",					"CH",	        			" %d %s",						'\r',         EM_QENABLE_Func,
EM_QFIM,					4,		"?FIM",			 		SYSNULL_PCHAR,						SYSNULL_PCHAR,	   	" %s",							'\r',      	  EM_QFIM_Func,

EM_QVINST,				6,		"?VINST",			 	" %d %d %d %d",					SYSNULL_PCHAR,	   	" %d %.3f",				  		'\r',      	  EM_QVINST_Func,
EM_QVMEAS,				6,		"?VMEAS",			 	" %d %d %d %d",					SYSNULL_PCHAR,	   	" %d %.3f",				  		'\r',      	  EM_QVMEAS_Func,

EM_QRAWINST,			8,		"?RAWINST",			 	" %d %d %d %d",					SYSNULL_PCHAR,	   	" %d %d",				  		'\r',      	  EM_QRAWINST_Func,
EM_QRAWMEAS,			8,		"?RAWMEAS",			 	" %d %d %d %d",					SYSNULL_PCHAR,	   	" %d %.3f",				  		'\r',      	  EM_QRAWMEAS_Func,

EM_QDEVMAC,				7,		"?DEVMAC",			 	SYSNULL_PCHAR,						SYSNULL_PCHAR,   		" %s",	    				  	'\r',         EM_QDEVMAC_Func,
EM_QDEVIP,				6,		"?DEVIP",			 	SYSNULL_PCHAR,						SYSNULL_PCHAR,   		" %s",	    					'\r',         EM_QDEVIP_Func,
EM_QDEVSNO,         	7,    "?DEVSNO",           SYSNULL_PCHAR,    				SYSNULL_PCHAR,   		" %s",	    					'\r',         EM_QDEVSNO_Func,
EM_QSENTEST,        	8,    "?SENTEST",          " %d %d %d %d",    				SYSNULL_PCHAR,   		" %d %04X",	    				'\r',         EM_QSENTEST_Func,

EM_QMEMDUMP,         8,    "?MEMDUMP",          SYSNULL_PCHAR,                SYSNULL_PCHAR,   		" %04X",	    					'\r',         EM_QMEMDUMP_Func,

EM_QAMPMODE,         8,    "?AMPMODE",          " %d %d %d %d",               SYSNULL_PCHAR,   		" %d %s",	    				'\r',         EM_QAMPMODE_Func,
EM_QGAIN1,           6,		"?GAIN1",            " %d %d %d %d",               SYSNULL_PCHAR,   		" %d %s",	    				'\r',         EM_QGAIN1_Func,
EM_QGAIN2,           6,		"?GAIN2",            " %d %d %d %d",               SYSNULL_PCHAR,   		" %d %s",	    				'\r',         EM_QGAIN2_Func,

EM_QEVTMODE,         8,    "?EVTMODE",          SYSNULL_PCHAR,                SYSNULL_PCHAR,       " %d",                     '\r',         EM_QEVTMODE_Func,
EM_QEVTCLIENT,       10,   "?EVTCLIENT",        SYSNULL_PCHAR,                SYSNULL_PCHAR,       " %s %d",                  '\r',         EM_QEVTCLIENT_Func,

EM_QTESTSPIREAD,     12,   "?TESTSPIREAD",      SYSNULL_PCHAR,                SYSNULL_PCHAR,       " %d",                   	'\r',         EM_QTESTSPIREAD_Func,
//EM_QSENREGTEST,    11,   "?SENREGTEST",      	"%d %d %d %d",    				SYSNULL_PCHAR,   		"%d %02X ",	    				'\r',         EM_QSENTEST_Func,
EM_QTRIGPOL,     		8,   	"?TRIGPOL",      		SYSNULL_PCHAR,                SYSNULL_PCHAR,       " %s",                   	'\r',         EM_QTRIGPOL_Func,

EM_QAUTORANGEMIN,    13,   "?AUTORANGEMIN",     " %d %d %d %d",               "CH",				      " %d %d",                	'\r',         EM_QAUTORANGEMIN_Func,
EM_QAUTORANGEMAX,    13,   "?AUTORANGEMAX",     " %d %d %d %d",               "CH",       			" %d %d",                	'\r',         EM_QAUTORANGEMAX_Func,
EM_QAUTORANGE,     	10,   "?AUTORANGE",      	" %d %d %d %d",					"CH",	        			" %d %s",                 	'\r',         EM_QAUTORANGE_Func,

EM_QTRIGDELAY,     	10,   "?TRIGDELAY",      	SYSNULL_PCHAR,                SYSNULL_PCHAR,       " %lu",                   	'\r',         EM_QTRIGDELAY_Func,

SYSNULL_INT,			SYSNULL_INT,&SYSNULL_FCHAR,	SYSNULL_PCHAR,		SYSNULL_PCHAR,	  		SYSNULL_PCHAR,					SYSNULL_INT,  SYSOrd_Null_Func,
};
//</QUERIES>
/*** EndHeader */

/*** BeginHeader */
#endif
/*** EndHeader */