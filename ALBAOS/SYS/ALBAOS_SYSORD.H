/*** BeginHeader */
#ifndef __ALBAOS_SYSORD_H
#define __ALBAOS_SYSORD_H
/*** EndHeader */

/*** BeginHeader
*/

//#define _SYSOrd_ANS_HANDLER() SYSOrd_Ans(SYSOrdRef_Ans,SYSOrd_Ans_Repeat,ord)
//#define _SYSOrd_ERR_SYNTAX_HANDLER() SYSOrd_Ans(SYSOrdRef_Err,SYSOrd_ERR_SYNTAX,ord)

char const SYSOrd_Prefix_Ans[] = {"%Fs"};
//<INIT>
struct _SYSOrd{
   int Id;
   char far * Input;
   int Len;
   char * Output;
   int Idx;
   struct _SYSOrd_REF *Ref;
   unsigned long int Ip;
   unsigned int Port;
   int Arg;
};
//#define SYSVarOrd_ID_END -1
struct _SYSOrd_REF{
   int Id;
   int Len;
   char far * Syntax;
   char * Arg;
	char * Unit;
	char * Ans;
	int Att;
	int (*Func)(struct _SYSOrd *ord);
};

int SYSOrd_Null_Func(struct _SYSOrd *ord){}

struct _SYSOrd_REF SYSOrdRef_Null={
SYSNULL_INT,
SYSNULL_INT,
&SYSNULL_FCHAR,
SYSNULL_PCHAR,
SYSNULL_PCHAR,
SYSNULL_PCHAR,
SYSNULL_INT,
SYSOrd_Null_Func,
};

const struct _SYSOrd SYSOrd_Null={
SYSNULL_INT,&SYSNULL_FCHAR,SYSNULL_INT,SYSNULL_PCHAR,SYSNULL_INT,&SYSOrdRef_Null,
};

//eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
enum{
SYSOrd_ERR_NULL=0,
SYSOrd_ERR_SYNTAX,
SYSOrd_ERR_MODE,
SYSOrd_ERR_OPERATION,
SYSOrd_ERR_BUF,
SYSOrd_ERR_ARG,
}_SYS_ERR_ID;

//char const SYS_ERR_Format[]={"%Fs ERROR"};
struct _SYSOrd_REF SYSOrdRef_Err[]={
SYSOrd_ERR_NULL,        SYSNULL_INT,   &SYSNULL_FCHAR,         SYSNULL_PCHAR,  SYSNULL_PCHAR,  SYSNULL_PCHAR, SYSNULL_INT,   SYSOrd_Null_Func,
SYSOrd_ERR_SYNTAX,		13,          	"?SYNTAX ERROR",        SYSNULL_PCHAR,  SYSNULL_PCHAR,  "%Fs",  			SYSNULL_INT,   SYSOrd_Null_Func,
SYSOrd_ERR_MODE, 			11,         	"?WRONG MODE",          SYSNULL_PCHAR,  SYSNULL_PCHAR,  "%Fs",  			SYSNULL_INT,   SYSOrd_Null_Func,
SYSOrd_ERR_OPERATION, 	18,         	"?ILLEGAL OPERATION",   SYSNULL_PCHAR,  SYSNULL_PCHAR,  "%Fs",  			SYSNULL_INT,   SYSOrd_Null_Func,
SYSOrd_ERR_BUF, 			13,         	"?BUFFER ERROR",    		SYSNULL_PCHAR,  SYSNULL_PCHAR,  "%Fs",  			SYSNULL_INT,   SYSOrd_Null_Func,
SYSOrd_ERR_ARG, 			15,         	"?WRONG ARGUMENT",  		SYSNULL_PCHAR,  SYSNULL_PCHAR,  "%Fs",  			SYSNULL_INT,   SYSOrd_Null_Func,


SYSNULL_INT,   			SYSNULL_INT,	&SYSNULL_FCHAR,          SYSNULL_PCHAR,  SYSNULL_PCHAR,  SYSNULL_PCHAR, SYSNULL_INT,   SYSOrd_Null_Func,
};
//eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
//char const SYSOrd_Ans_Repeat[] = {"%Fs ANS"};

enum{
SYSOrd_Ans_Done,
SYSOrd_Ans_Repeat,
}SYSAns_Id;

struct _SYSOrd_REF SYSOrdRef_Ans[]={
SYSOrd_Ans_Done,		SYSNULL_INT,   &SYSNULL_FCHAR,    		SYSNULL_PCHAR,  SYSNULL_PCHAR,  SYSNULL_PCHAR,  SYSNULL_INT,   SYSOrd_Null_Func,
SYSOrd_Ans_Repeat,	SYSNULL_INT,   &SYSNULL_FCHAR,    		SYSNULL_PCHAR,  SYSNULL_PCHAR,  "%Fs ACK",  		SYSNULL_INT,   SYSOrd_Null_Func,

SYSNULL_INT,   		SYSNULL_INT,	&SYSNULL_FCHAR,    		SYSNULL_PCHAR,  SYSNULL_PCHAR,  SYSNULL_PCHAR, 	SYSNULL_INT,   SYSOrd_Null_Func,
};

//<IDs>
enum{
SYS_ID_HQHELP = 0,
SYS_ID_HPROG,
SYS_ID_HCREDITS,
SYS_ID_HUBWRITE,

}_SYSOrdRef_ID;
//</IDs>

int SYSOrd_HPROG_Func		(struct _SYSOrd *);
int SYSOrd_HCREDITS_Func	(struct _SYSOrd *);
int SYSOrd_HUBWRITE_Func   (struct _SYSOrd *);

struct _SYSOrd_REF SYSOrdRef[]={
SYS_ID_HQHELP,	 	6,   			"#?HELP",			 SYSNULL_PCHAR,	SYSNULL_PCHAR,		SYSNULL_PCHAR,	   SYSNULL_INT,   SYSOrd_Null_Func,
SYS_ID_HPROG,	 	5,   			"#PROG",				 "%s %s",			SYSNULL_PCHAR,		"%Fs %d",		   SYSNULL_INT,   SYSOrd_HPROG_Func,
SYS_ID_HCREDITS,	8,   			"#CREDITS",			 SYSNULL_PCHAR,	SYSNULL_PCHAR,		"%s",		  			SYSNULL_INT,   SYSOrd_HCREDITS_Func,

SYS_ID_HUBWRITE,	8,   			"#UBWRITE",			 "%100s",			SYSNULL_PCHAR,		SYSNULL_PCHAR,		SYSNULL_INT,   SYSOrd_HUBWRITE_Func,

SYSNULL_INT,	 SYSNULL_INT,		&SYSNULL_FCHAR,	 SYSNULL_PCHAR,	SYSNULL_PCHAR,	  	SYSNULL_PCHAR,		SYSNULL_INT,   SYSOrd_Null_Func,
};

/*** EndHeader */


/*** BeginHeader */
#endif
/*** EndHeader */