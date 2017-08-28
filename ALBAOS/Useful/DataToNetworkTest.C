#class auto 			// Change default storage class for local variables: on the stack
#define TCPCONFIG		5
#define MAX_UDP_SOCKET_BUFFERS 1
#define DISABLE_TCP		// Not using TCP
#define LOCAL_PORT	7
#memmap xmem
#use "dcrtcp.lib"

udp_Socket sock;

#define Buf_Len 8000
char far bufek[5]="ALA";
char far pktbuf[Buf_Len];	// Temp root buffer for packet reassembly
int echo_handler(int event, udp_Socket * s, ll_Gather * g,
						_udp_datagram_info * udi)
{
/*
	if (event == UDP_DH_ICMPMSG) {
		return 1;	// Just ignore incoming ICMP errors.
	}
//   printf("Got UDP  len1=%2u len2=%4u len3=%4u remip=%08lX remport=%5u len=%u\n",
//   	g->len1, g->len2, g->len3, udi->remip, udi->remport, udi->len);

	if (!g->len3)
   	// No second buffer.  This is easy - just use udp_sendto directly
		udp_sendto(s, g->data2, g->len2, udi->remip, udi->remport);
   else {
   	// Awkward: got 2 areas, so copy them into a contiguous root buffer and send.
		_f_memcpy(pktbuf, g->data2, g->len2);
      _f_memcpy(pktbuf + g->len2, g->data3, g->len3);
		udp_sendto(s, pktbuf, g->len2+g->len3, udi->remip, udi->remport);
   }
	return 1;
*/

udp_sendto(s, pktbuf, Buf_Len, udi->remip, udi->remport);
//udp_sendto(s, bufek, 4, udi->remip, udi->remport);
}


void main()
{
int i=0;
	// Start network and wait for interface to come up (or error exit).
	sock_init_or_exit(1);

	if(!udp_extopen(&sock, IF_ANY, LOCAL_PORT, -1L, 0, echo_handler, 0, 0)) {
		printf("udp_extopen failed!\n");
		exit(0);
	}

   for (i=0;i<Buf_Len;i++)
   	{
       pktbuf[i]='A';
      }

	/* Let the stack do everything... */
	for(;;)
   	{
		tcp_tick(NULL);
      }
}

