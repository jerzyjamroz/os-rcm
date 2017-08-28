#class auto

#use "DEV_SFlash_MOUNT.LIB"

int SFlash_VarWrite_Fucker(int id, int var)
{
char flash_buf[1060];

sf_pageToRAM(10);
sf_readRAM(flash_buf, 0, sf_blocksize);

sprintf(&flash_buf[7*id],"%06d",var);
flash_buf[7*id+6]=0;

sf_writeRAM(flash_buf, 0, sf_blocksize);
sf_RAMToPage(10);

return strlen(&flash_buf[7*id]);
}


void main()
{
int i;

SFlash_Init();

for(i=0;i<100;i++)
	{
	SFlash_VarWrite(i,12300+i);
   SFlash_VarWrite_Fucker(i,i);
   }

for(i=0;i<100;i++)
printf("V%d=%d\n",i,SFlash_VarRead(i));

while(1);
}