.PHONY:clean

excute:main.o boom.o
	cc -o exe main.o boom.o

main.o:main.c
	cc -c main.c

boom.o:boom.c boom.h
	cc -c boom.c

clean:
	rm *.o -rf
