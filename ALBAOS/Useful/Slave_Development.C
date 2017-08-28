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

#define Idx_Max 10
struct tester{
char test[32767];
//char test1[32767];
//char test2[32767];
//char test3[32767];
}a;

long int Buf[Idx_Max];
int Idx=0;

root interrupt void Slave_Isr(void)
{
Buf[Idx]=(long)RdPortI(SPD2R)<<16;
Buf[Idx]|=(long)RdPortI(SPD1R)<<8;
Buf[Idx]|=(long)RdPortI(SPD0R);
Idx++;
if(Idx>=Idx_Max)Idx=0;
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
long address=0;
char bufek[12];

Int_INT1_PE1_Init(Slave_Isr);
WrPortI(SPCR,&SPCRShadow,0xE8);

//address=xalloc(1048500);
//address=xalloc(12);
	while(1)
	{
   //xmem2root(bufek,address,12);
	}
}