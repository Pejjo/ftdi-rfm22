#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "rflib.h"


int main(void){
char buf[80];
rf_init(0,0);

while (1)
{

usleep(500000);
rf_poll(buf,80);
printf(buf);
}

rf_close();
return 0;
}

