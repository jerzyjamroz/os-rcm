#define ADC_Var_Data_Buf_Len 1048500
struct ADC_Struct{
long Adr_Begin;
long Adr_End;
int Idx_Act;
int Num;
char Buf[3];
};

struct ADC_Struct ADC_Var={
0,
0,
0,
0,
0,0,0,
};

void ADC7608_Init(void)
{
WrPortI(SPCR,&SPCRShadow,0xE8);
ADC_Var.Adr_Begin=xalloc(ADC_Var_Data_Buf_Len);
ADC_Var.Adr_End=ADC_Var.Adr_Begin;
ADC_Var.Idx_Act=0;
}

#define Int_INT1_PE1_En() WrPortI(I1CR,&I1CRShadow,0x09)
#define Int_INT1_PE1_Dis() WrPortI(I1CR,&I1CRShadow,0x08)

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


root interrupt void ADC_Slave_Isr(void)
{
ADC_Var.Buf[0]=RdPortI(SPD2R);
ADC_Var.Buf[1]=RdPortI(SPD1R);
ADC_Var.Buf[2]=RdPortI(SPD0R);

root2xmem(ADC_Var.Adr_End,ADC_Var.Buf,3);
ADC_Var.Adr_End+=3;
if(ADC_Var.Adr_End>=ADC_Var.Adr_Begin+ADC_Var_Data_Buf_Len) ADC_Var.Adr_End=ADC_Var.Adr_Begin;
ADC_Var.Idx_Act+=1;
if (ADC_Var.Num<ADC_Var_Data_Buf_Len) ADC_Var.Num+=1;
}


void ADC_Reset_Raw(void)
{
ADC_Var.Idx_Act=0;
ADC_Var.Num=0;
}

char bufek[12];
void main()
{
Int_INT1_PE1_Init(ADC_Slave_Isr);
ADC7608_Init();

	while(1)
	{
   xmem2root(bufek,ADC_Var.Adr_End-9,9);
	}
}