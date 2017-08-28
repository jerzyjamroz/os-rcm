#class auto
#define TCPCONFIG 5
#memmap xmem
#use "dcrtcp.lib"
#use TFTP_GET_FIRMWARE1.LIB

void main(void)
{
Firmware_Upload();
while(1);
}