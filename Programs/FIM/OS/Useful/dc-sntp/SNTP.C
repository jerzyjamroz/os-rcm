#class auto
#define TCPCONFIG 3

#define MAX_UDP_SOCKET_BUFFERS  1

#use "dcrtcp.lib"

#define SNTP_DEBUG
#use "sntp.lib"

print_time(unsigned long time)
{
	struct tm t;
	mktm(&t, time);
	printf("%02d/%02d/%04d %02d:%02d:%02d",
		            t.tm_mon, t.tm_mday, 1900+t.tm_year, t.tm_hour, t.tm_min, t.tm_sec);
}

main()
{
	unsigned long tr, tn;

//	WrPortI(SPCR, &SPCRShadow, 0x84);
//	BitWrPortI(PADR, &PADRShadow, 0, 1);  // turn beeper off

	sock_init();


//	tn = sntp_gettime(inet_addr("192.168.1.100"), 1000);
//	tn = sntp_gettime(resolve("time.belnet.be"), 1000);
//   tn = sntp_gettime(resolve("gps.cells.es"), 1000);
	tn = sntp_gettime(resolve("84.89.255.109"), 5000);
	tr = read_rtc();

	printf("RTC: ");
	print_time(tr);
	printf("\n");
	printf("NTP: ");
	print_time(tn);

   while(1);

}