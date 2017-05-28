#ifndef rflibh 
#define rflibh 
extern "C" int rf_init(int dumpreg, const char *serial);
extern "C" int rf_poll(char *outbuf, int bufsz);
extern "C" int rf_close(void);
#endif

