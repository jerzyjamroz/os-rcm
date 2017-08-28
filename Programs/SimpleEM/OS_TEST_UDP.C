#class auto
#use RCM42xx.LIB

	//strukture "ll_Gather * g"
   //---------------------------------------------------------------
	// Datagram has come in.  It is in the Ethernet receive buffer.  No need to
	// copy it anywhere - we just transmit it straight back to the sender.
	// The relevant information comes in the following fields (not all of which
	// we use here) (see LIB\tcpip\net.lib for structure):
	//  g->data1  ->  IP and UDP headers (root)
	//  g->len1   ->  IP and UDP header length
	//  g->data2  ->  UDP datagram data (xmem) - first buffer
	//  g->len2   ->  UDP datagram data length - first buffer
	//  g->data3  ->  UDP datagram data (xmem) - second buffer **
	//  g->len3   ->  UDP datagram data length - second buffer
	//  udi->remip  -> sender's IP address
	//  udi->remport  ->  sender's UDP port number
	//  udi->flags  -> flags.

   // ** Note: prior to Dynamic C 9.0, only one buffer would be provided (i.e. g->data3 would
   // always be zero).  From DC9.0, it is now possible for the incoming data to be split into
   // two areas.

	// The 'event' parameter determines the type of event.  As of DC 7.30, this is either
	//  UDP_DH_INDATA : incoming datagram
	//  UDP_DH_ICMPMSG : incoming ICMP message.

#define TCPCONFIG		5
#define MAX_UDP_SOCKET_BUFFERS 1
#define DISABLE_TCP
#define LOCAL_PORT	7  //standart echo port

#memmap xmem
#use "dcrtcp.lib"

char pktbuf[1500];	// Temp root buffer for packet reassembly

udp_Socket sock;

const char Firmware[]="NONE";
//******************************************************************************/
//*** BeginDebugs ***/   ENVIRONMENT SETTINGS
//#define ALBAOS_UNMOUNT_DEV
//#define TLN_DEBUG
//#define ALBAOS_LIB_DEBUG

//	#define SCPIprot_EXE_DEBUG
//#define SCPIprot_DEBUG
//	#define COMORD_EXE_DEBUG
//#define ORD_CONV_DEBUG
//	#define BRIDGE_EXE_DEBUG
//#define SFlash_DEBUG

//#define IO_DEBUG
//#define SNTP_DEBUG
void Debugger(void);
//*** EndDebugs ***/	ENVIRONMENT SETTINGS

//********************<RABBIT_SYS>************************************************/
//***********************<DEVICES>************************************************/
//#define Mount_Dev_SFlash_Driver
//#define Mount_Dev_Eth_Driver
//#define Mount_Dev_Tln_Driver
//#define Mount_Dev_SerD_Driver
//#define Mount_Dev_SNTP_Driver
//#define Mount_Dev_Time_Driver
//#define Mount_Dev_IO_Driver
//***********************</DEVICES>***********************************************/
//********************</RABBIT_SYS>************************************************/


//***********************<RUNSYSTEM>***********************************************/
//<MOUNT_ALBAOS>
#use "ALBAOS_EXE.C" //void main()
//</MOUNT_ALBAOS>

//<PROGRAMS>
//#use "DEV_RTC_MOUNT.LIB"
//#use "DEV_IO_BODY.LIB"
//#use "GPSTS_HEAD1ER.LIB"
//#use "PACK_SCPI_PROT_BODY.lib"
//#use "PACK_SYSORDERS_BODY.LIB"
//#use "DEV_SPIB_MOUNT.LIB"
//#use "DEV_AD7610_BODY.LIB"
//#use "DEV_MCP23S17_BODY.LIB"
//#use "DEV_ExtIO_BODY.LIB"
//</PROGRAMS>

int echo_handler(int event, udp_Socket * s, ll_Gather * g,
						_udp_datagram_info * udi);
char buf[1000];
char buf1[1000];
int intvar;
debug
void main(void)
{
int i;
//**********************<DRIVERS>***********************************************/
//<SYS_INIT>
ALBAOS_INIT();//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//******************************************************************************

//******************************************************************************
//</SYS_INIT>
//**********************</DRIVERS>**********************************************/

//**********************<TESTINIT>**********************************************/
brdInit();			//reads calibration constants

	// Start network and wait for interface to come up (or error exit).
	sock_init_or_exit(1);

	if(!udp_extopen(&sock, IF_ANY, LOCAL_PORT, -1L, 0, echo_handler, 0, 0)) {
		printf("udp_extopen failed!\n");
		exit(0);
	}
//**********************</TESTINIT>*********************************************/

while(1)
{
//<SYS_DAEMONS>
ALBAOS_DAEMONS();//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//</SYS_DAEMONS>

//<TESTSOFT>
Debugger();
//</TESTSOFT>
}

//<Forbidden state>
SYS_Reset;
//</Forbidden state>
}
//***********************</RUNSYSTEM>***********************************************/



//-------------------<DEBUGFUNCTIONS>----------------------------------------------*/
void Debugger(void)
{
tcp_tick(NULL);
}

//-------------------</DEBUGFUNCTIONS>----------------------------------------------*/


int echo_handler(int event, udp_Socket * s, ll_Gather * g,
						_udp_datagram_info * udi)
{

	if (event == UDP_DH_ICMPMSG) {
		return 1;	// Just ignore incoming ICMP errors.
	}


   printf("Got UDP  len1=%2u len2=%4u len3=%4u remip=%08lX remport=%5u len=%u\n",
   	g->len1, g->len2, g->len3, udi->remip, udi->remport, udi->len);

	if (!g->len3)
   	// No second buffer.  This is easy - just use udp_xsendto directly
		udp_xsendto(s, (long)g->data2, g->len2, udi->remip, udi->remport);
   else {
   	// Awkward: got 2 areas, so copy them into a contiguous root buffer and send.
		xmem2root(pktbuf, (long)g->data2, g->len2);
      xmem2root(pktbuf + g->len2, (long)g->data3, g->len3);
		udp_sendto(s, pktbuf, g->len2+g->len3, udi->remip, udi->remport);
   }

	// Return 1 to indicate that all processing has been done.  No copy to
	// normal udp socket receive buffer.
	return 1;
}