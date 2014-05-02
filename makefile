CC = g++
CFLAGS = -ansi

ipcount: ipcount.o
	$(CC) -o ipcount ipcount.o

ipcount.o: ipcount.h

clean:
	rm -f *.o

real_clean: clean
	rm -f ipcount

