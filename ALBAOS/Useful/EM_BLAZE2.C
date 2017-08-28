#use EM_ADC7608.LIB
#use EM_ADC7608_Proces.LIB

char bufek[12];
void main()
{
ADC7608_Init();

	while(1)
	{
   printf("%.5f\n",ADC_retMEAS(0,1000));
	}
}