/* Copyright (c) 2013 Owen McAree
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/* This is a simple test program for the RFM22B class
 *	Currently all it can do it get and set the carrier frequency of the module
 *	as this is all the functionality available from the class. More coming soon...
 */

#define rf22_write	myRadio->setRegister
 
#include "rfm22b.h"
#include <string.h> 
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv) {

    	time_t timer;
    	char buffer[26];
    	struct tm* tm_info;

	int dumpreg=0;

	for (int i=0; i<argc; i++)
	{
		if (argv[i][0]=='r')
			dumpreg=1;
	}
	// Initialise the radio
	RFM22B *myRadio = new RFM22B("/dev/spidev1.0");
	// Set the bus speed
	myRadio->setMaxSpeedHz(200000);
	
	// Radio configuration
	myRadio->reset();
//	myRadio->setCarrierFrequency(433.225E6);
//	myRadio->setModulationType(RFM22B::GFSK);
//	myRadio->setModulationDataSource(RFM22B::FIFO);
//	myRadio->setDataClockConfiguration(RFM22B::NONE);
//	myRadio->setTransmissionPower(5);
	myRadio->setGPIOFunction(RFM22B::GPIO0, RFM22B::RX_STATE);
	myRadio->setGPIOFunction(RFM22B::GPIO1, RFM22B::TX_STATE);

	// What header do we want?
//	myRadio->setCheckHeader(1752133733);

/*
        myRadio->setRegister(0x75, 0x53 );
        myRadio->setRegister(0x76, 0x4B );
        myRadio->setRegister(0x77, 0x00);

	myRadio->setRegister(0x6e, 0x10); //
        myRadio->setRegister(0x6f, 0x62); //
        myRadio->setRegister(0x70, 0x2e);
        myRadio->setRegister(0x58, 0x80);

	myRadio->setRegister(0x72, 0x08 ); //
	myRadio->setRegister(0x71, 0x23 );

        myRadio->setRegister(0x1c, 0x27); //
        myRadio->setRegister(0x20, 0xfa); //
        myRadio->setRegister(0x21, 0x01); //
 	myRadio->setRegister(0x22, 0x41); //
        myRadio->setRegister(0x23, 0x89); //
        myRadio->setRegister(0x24, 0x10);
        myRadio->setRegister(0x25, 0xd4); //
        myRadio->setRegister(0x1d, 0x40);
        myRadio->setRegister(0x1e, 0x0a);
        myRadio->setRegister(0x2a, 0x1d); //
        myRadio->setRegister(0x1f, 0x00);
        myRadio->setRegister(0x69, 0x60);

    	myRadio->setRegister(0x30, 0x61);
    	myRadio->setRegister(0x33, 0x0a);
    	myRadio->setRegister(0x34, 0x05);
    	myRadio->setRegister(0x35, 0x2a);
    	myRadio->setRegister(0x36, 0x2d);
    	myRadio->setRegister(0x37, 0xd4);
    	myRadio->setRegister(0x38, 0x00);
    	myRadio->setRegister(0x39, 0x00);
   	myRadio->setRegister(0x70, 0x26);
    	myRadio->setRegister(0x71, 0x2b);
*/
rf22_write(0x20, 0xe8);
rf22_write(0x21, 0x60);
rf22_write(0x22, 0x10);
rf22_write(0x23, 0x62);
rf22_write(0x24, 0x00);
rf22_write(0x25, 0x05);
rf22_write(0x2a, 0x20);
rf22_write(0x30, 0xac);
rf22_write(0x32, 0x8c);
rf22_write(0x33, 0x02);

rf22_write(0x6d, 0x0F);		// tx power: +17dBm


rf22_write(0x6e, 0x08);
rf22_write(0x6f, 0x31);
rf22_write(0x70, 0x2e);
rf22_write(0x71, 0x23);
rf22_write(0x72, 0x50);

rf22_write(0x75, 0x53); //
rf22_write(0x76, 0x50); //
rf22_write(0x77, 0xa0); //

rf22_write(0x1c, 0x2b);
rf22_write(0x1f, 0x03);
rf22_write(0x20, 0xf4);
rf22_write(0x21, 0x20);
rf22_write(0x22, 0x41);
rf22_write(0x23, 0x89);
rf22_write(0x24, 0x00);
rf22_write(0x25, 0x36);
rf22_write(0x2c, 0x40);
rf22_write(0x2d, 0x0a);
rf22_write(0x2e, 0x1d);
rf22_write(0x58, 0x80);
rf22_write(0x69, 0x60);
rf22_write(0x6e, 0x10);
rf22_write(0x6f, 0x62);
rf22_write(0x70, 0x2c);
rf22_write(0x71, 0x23);
rf22_write(0x72, 0x08);
rf22_write(0x27, 0x10);         // RSSI Threashold: -120dB

rf22_write(0x1c, 0x2b);
rf22_write(0x1f, 0x03);
rf22_write(0x20, 0xa1);
rf22_write(0x21, 0xe0);
rf22_write(0x22, 0x10);
rf22_write(0x23, 0xc7);
rf22_write(0x24, 0x00);
rf22_write(0x25, 0x09);
rf22_write(0x2c, 0x40);
rf22_write(0x2d, 0x0a);
rf22_write(0x2e, 0x1d);
rf22_write(0x58, 0x80);
rf22_write(0x69, 0x60);
rf22_write(0x6e, 0x04);
rf22_write(0x6f, 0x32);
rf22_write(0x70, 0x2c);
rf22_write(0x71, 0x23);
rf22_write(0x72, 0x04);

 myRadio->setInterruptEnable(RFM22B::VALID_PACKET_RECEIVED, 1);

	if (dumpreg)
		for (int i=0; i<=0x7f; i++)
			printf("Reg: %02x = %02x\n", i,  myRadio->getRegister(i));
	printf("Listening to a message...\n");

	myRadio->enableRXMode();

	int rxl,st;
	char input[80];
	input[41]=0;
	while (1)
	{

	 	usleep(500000);
//		st=myRadio->getOperatingMode();
//		printf(" %x \t", st);
//sleep(1);
//printf( "Status: %x \t",  myRadio->getRegister(0));
//printf( "%x \t",  myRadio->getRegister(1));
//printf( "%x \n",  myRadio->getRegister(4));

//		if (st!=lst)
//		{
//			lst=st;
//			printf("%x \n", st);
//		}
		if (myRadio->poll()==0) { // Got an interupt		
			if (myRadio->getInterruptStatus(RFM22B::VALID_PACKET_RECEIVED)) {
    				time(&timer);
    				tm_info = localtime(&timer);

    			strftime(buffer, 26, "%Y:%m:%d %H:%M:%S", tm_info);
    			printf("%s",buffer);

			rxl=myRadio->getData((uint8_t*)input,40);
			myRadio->enableRXMode();
		if (rxl>0)
		{
			char *kpos, *epos, *cpos, *npos;
			int ptype;
			int pindex;
			char *pval1, *pval2;
			float rx_sig;

			input[rxl]=0;

			rx_sig= 0.56*myRadio->getRSSI()-128.8;
			printf("\tRSSI: %.2f dBm \t", rx_sig);
//			printf("%s\n", input);

			kpos=strchr(input, ':');
			epos=strchr(input, '=');
			cpos=strchr(input, ',');
			npos=strchr(input, '\n');

			if ((kpos!=0)&&(epos!=0)&&(npos!=0))
			{ // Looks ok
				ptype=input[0];
				*epos=0;
				*npos=0;
				pindex=atoi(kpos+1);
				if (cpos!=0)
				{
					// two data values
					*cpos=0;
					pval2=cpos+1;
					pval1=epos+1;
				}
				else
				{
					pval2=0;
					pval1=epos+1;
				}

				if (ptype=='A')
				{
					printf("Sensor %d ID: %s\n", pindex, pval1);
				}
				else if (ptype=='B')
				{
					int tval,cval;
					float fval;
					tval=atol(pval2);
					cval=strtol(pval1,0,16);
					fval=tval/10.0;
					printf("Sensor %d cycle %d, temp: %02.1f\n",pindex, cval, fval);
				}
				else if (ptype=='Z')
				{
					int rval, hval, bval;
					float fval;
					rval=pindex;
					hval=strtol(pval1,0,16);
					bval=strtol(pval2,0,16);
					fval=bval/204.7;
					printf("Board reset: %02x, Flag: %02x, Battery voltage: %02.2f\n", rval, hval, fval);
				}
				else
				{
					printf("Unknown packet type: %s\n", input);
				}
			}
			else
			{
				input[40]=0;
				printf("FE");
				//printf("Frame error: %s\n", input);
				myRadio->clearRXFIFO();
			}
		 }			
		}
		}
//		else

//			printf("tmo");
	}
		
	myRadio->close();
}
