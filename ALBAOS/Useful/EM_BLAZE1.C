#use EM_ADC7608.LIB
#use EM_ADC7608_Proces.LIB

char bufek[12];
void main()
{
ADC7608_Init();

	while(1)
	{
   xmem2root(bufek,ADC_Var.Adr_End-9,9);
	}
}