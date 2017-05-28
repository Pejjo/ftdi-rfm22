CXXFLAGS=-Wall -O3 -I./include -g

all: rfm22b_ftdi rfm22b_receive_ftdi rfm

#rfm22b_setup_test : rfm22b_setup_test.cpp src/rfm22b.o src/spi.o
#	g++ $(CXXFLAGS) rfm22b_setup_test.cpp src/rfm22b.o src/spi.o -o rfm22b_setup_test
	
#rfm22b_send_test : rfm22b_send_test.cpp src/rfm22b.o src/spi.o
#	g++ $(CXXFLAGS) rfm22b_send_test.cpp src/rfm22b.o src/spi.o -o rfm22b_send_test
	
#rfm22b_receive_test : rfm22b_receive_test.cpp src/rfm22b.o src/spi.o
#	g++ $(CXXFLAGS) rfm22b_receive_test.cpp src/rfm22b.o src/spi.o -o rfm22b_receive_test
	
rfm22b_ftdi : rfm22b_ftdi_test.cpp src/rfm22b.o src/spiftdi.o src/ftdispill.c
	g++ $(CXXFLAGS) rfm22b_ftdi_test.cpp src/rfm22b.o src/spiftdi.o  src/ftdispill.c -lftd2xx -o rfm22b_ftdi

rfm22b_receive_ftdi : rfm22b_receive_ftdi.cpp src/rfm22b.o src/spiftdi.o src/ftdispill.c
	g++ $(CXXFLAGS) rfm22b_receive_ftdi.cpp src/rfm22b.o src/spiftdi.o  src/ftdispill.c -lftd2xx -o rfm22b_receive_ftdi

rfm: rfm.cpp rfm22b_receive_lib.cpp src/rfm22b.o src/spiftdi.o src/ftdispill.c
	g++ $(CXXFLAGS) rfm.cpp rfm22b_receive_lib.cpp src/rfm22b.o src/spiftdi.o  src/ftdispill.c -lftd2xx -shared -o rfm.so

src/rfm22b.o: src/rfm22b.cpp include/rfm22b.h
src/spi.o: src/spi.cpp include/spi.h
src/spiftdi.o: src/spiftdi.cpp include/spiftdi.h src/ftdispill.c include/ftdispill.h include/debug.h
clean:
	rm rfm22b_setup_test rfm22b_send_test rfm22b_receive_test rfm2b_ftdi rfm22b_receive_ftdi src/*.o
