/*
root interrupt void slave_isr(void){

#asm
//slave_isr::
push af ; save used registers
; read the data sent by the master
ioi ld a, (SPD2R)
ld (to_slv_d2), a
ioi ld a, (SPD1R)
ld (to_slv_d1), a
ioi ld a, (SPD0R)
ld (to_slv_d0), a
; if a response is required, perform it here
;ld a, (to_mas_d2)
;ioi ld (SPD2R), a
;ld a, (to_mas_d1)
;ioi ld (SPD1R), a
;ld a, (to_mas_d0)
;ioi ld (SPD0R), a ; this write asserts /SLVATTN
; the interrupt request is cleared by any read/write of the registers
pop af ; restore used registers
ipres
//ret
#endasm
}
*/
#define Data_Buf_Len 1048500
long Adr_Begin=0;
long Adr_End=0;
long Idx=0;
char Buf[3];
root interrupt void Slave_Isr(void)
{
Buf[0]=RdPortI(SPD2R);
Buf[1]=RdPortI(SPD1R);
Buf[2]=RdPortI(SPD0R);
root2xmem(Adr_End,Buf,3);
Adr_End+=3;
if(Adr_End>=Adr_Begin+Data_Buf_Len) Adr_End=Adr_Begin;
}

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


void main()
{
char bufek[12];

Int_INT1_PE1_Init(Slave_Isr);
WrPortI(SPCR,&SPCRShadow,0xE8);

//address=xalloc(1048500);
Adr_Begin=xalloc(Data_Buf_Len);
Adr_End=Adr_Begin;
	while(1)
	{
   xmem2root(bufek,Adr_End-9,9);
	}
}