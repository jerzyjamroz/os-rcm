#class auto
#use RCM57xx.LIB

int Int_INT1_PE1_En(void)
{
BitWrPortI(PEDDR, 	&PBDDRShadow, 		0, 1);

return 1;
}

int Int_INT1_PE1_Dis(void)
{
BitWrPortI(PEDDR, 	&PBDDRShadow, 		1, 1);

return 1;
}

void Int_INT1_PE1_Init(void *isr)
{
//   #GLOBAL_INIT
//   {
		//SET PE1 as input
		BitWrPortI(PEDDR, 	&PBDDRShadow, 		0, 1);
		BitWrPortI(PEDR,  	&PBDRShadow,  		1, 1);
		SetVectExtern4000(1,isr);
		WrPortI(I1CR, &I1CRShadow, 0x09);		// enable external INT1 on PE1, rising edge, priority 1
		Int_INT1_PE1_En();
//		Interrupt.Status=0;    //interrupt enable - everything ok
//   }
}

/*
void Int_INT1_PE1_Exe(void)
{


}
*/

#define PORTA_AUX_IO          // required to enable external I/O bus

//_____________________________<FUNCTIONS>______________________________________
int ExtIO_Init(int w8StNum, int hanshake_pin_conf);
//_____________________________</FUNCTIONS>______________________________________


/* Driving port E procedures
WrPortI(PEDDR, &PEDDRShadow,  0x00);
WrPortI(PEDCR, &PEDCRShadow,  0x00);
WrPortI(PEFR, &PEFRShadow,  0x00);
*/

//_________________________________<CONFIGLOCAL>________________________________
//_________________________________</CONFIGLOCAL>_______________________________
/* START FUNCTION DESCRIPTION ********************************************
DEV_ExtIO<.LIB>
SYNTAX: int ExtIO_Init(int w8StNum, int hanshake_pin_conf)
DESCRIPTION:   Initializes the external bus but only for bank 0
PARAMETER:  (int w8StNum, int hanshake_pin_conf)
RETURN VALUE:  1
END DESCRIPTION **********************************************************/

int ExtIO_Init(int w8StNum, int handshake_conf)
{
int config;

switch (w8StNum)
{
  case 1:
  	config=0xC0;
  break;
  case 3:
  	config=0x80;
  break;
  case 7:
  	config=0x40;
  break;
  case 15:
  	config=0x00;
  break;
  default:
  	return -1;
}
// initialize PE0 as an I/O strobe
WrPortI(PEFR, 	&PEFRShadow,   (PEFRShadow  | 0x01) );

// set PE0 to be an output
WrPortI(PEDDR, &PEDDRShadow, 	(PEDDRShadow | 0x01) );

// set PE0  = 1 wait state, I/O Strobe, writes are enabled
WrPortI(IB0CR, &IB0CRShadow, 	(0x38 | config)  );  //F8 - one cicle

//Two lines below do the same as #define PORTA_AUX_IO
WrPortI(IB5CR, &IB5CRShadow, 	0x68);
WrPortI(SPCR,  &SPCRShadow,  	0x8C);    //External I/O data bus (write 0x08C to SPCR)

//<HANDSHAKE>
/*
handshake_conf- first byte = pin number
4th bit - low/high level sensivity
*/
if (handshake_conf>0)
{
WrPortI(IHCR, &IHCRShadow, handshake_conf);
BitWrPortI(IHSR, &IHSRShadow, 1, 0);
WrPortI(IHTR, NULL, 0x3F); //3F cycles wait
}
//</HANDSHAKE>

return 1;
}

/*
root void ExtIO_Write(int address, char byte)
{
WrPortE(address, NULL, byte);
}

root int ExtIO_Read(int address)
{
return RdPortE(address);
}
*/


int count=0;

static long int Global_Data=0;
root interrupt void Int_ADC_Data_Read(void)
{
static int counter=0;
long int helper=0;

if( (counter==0) && (BitRdPortI(PEDR, 2)==1) )
	{
   Global_Data=0;
   helper=RdPortE(0x00);
   Global_Data=helper;
   }
else if ( (counter==1) && (BitRdPortI(PEDR, 2)==0))
	{
   helper=RdPortE(0x00);
   Global_Data|=(helper<<8)&0xFF00;
	}
else if ( (counter==2) && (BitRdPortI(PEDR, 2)==0))
	{
   helper=RdPortE(0x00);
   Global_Data|=(helper<<16)&0xFF0000;
   }
else counter=-1;

counter=counter+1;
}


/*
static long int Global_Data=0;
root interrupt void Int_ADC_Data_Read(void)
{
long int helper=0;

   helper=RdPortE(0x00);
   Global_Data=helper;
   helper=RdPortE(0x01);
   Global_Data|=(helper<<8)&0xFF00;
   helper=RdPortE(0x02);
   Global_Data|=(helper<<16)&0xFF0000;
   RdPortE(0x03);
}
*/

debug
void main(void)
{
brdInit();

ExtIO_Init(15,1);
Int_INT1_PE1_Init(Int_ADC_Data_Read);
BitWrPortI(PEDDR, 	&PBDDRShadow, 		0, 2);

//   Int_En(2);


while(1)
{
// WrPortE(0x22,NULL,0x11);
// printf("%X\n",RdPortE(0x22));
//RdPortE(0x03);
printf("%06lX\n",Global_Data);
//  RdPortE(0x00);
}


}
//***********************</RUNSYSTEM>***********************************************/


