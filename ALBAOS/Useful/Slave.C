#class auto
#use "slave_port.lib"
#use "sp_stream.lib"
#define STREAM_BUFFER_SIZE 31
main()
{
char buffer[10];
int bytes_read;
SPStream stream;
// Circular buffers need 9 bytes for bookkeeping.
char stream_inbuf[STREAM_BUFFER_SIZE + 9];
char stream_outbuf[STREAM_BUFFER_SIZE + 9];
SPStream *stream_ptr;
// setup buffers
cbuf_init(stream_inbuf, STREAM_BUFFER_SIZE);
stream.inbuf = stream_inbuf;
cbuf_init(stream_outbuf, STREAM_BUFFER_SIZE);
stream.outbuf = stream_outbuf;
stream_ptr = &stream;
SPinit(1);
//SPsetHandler(0x42, SPShandler, stream_ptr);
SPsetHandler(0x00, SPShandler, stream_ptr);
while(1)
{
bytes_read = SPSread(stream_ptr, buffer, 10, 10);
if(bytes_read)
{
SPSwrite(stream_ptr, buffer, bytes_read);
}
}
}