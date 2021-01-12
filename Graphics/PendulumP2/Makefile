
CC = gcc
LDLIBS =  -lglut -lGL -lGLU -lm 
HEADERS = includes.h globals.h
OBJS = init.o display.o reshape.o globals.o showFps.o input.o

all : pendpoc tags

pendpoc : main.o $(OBJS)
	$(CC) $(CFLAGS) main.o $(OBJS) -o pendpoc $(LDLIBS)

main.o : main.cc $(HEADERS)
	$(CC) $(CFLAGS) main.cc -c

init.o : init.cc $(HEADERS)
	$(CC) $(CFLAGS) init.cc -c

display.o : display.cc $(HEADERS)
	$(CC) $(CFLAGS) display.cc -c


globals.o : globals.cc $(HEADERS)
	$(CC) $(CFLAGS) globals.cc -c

reshape.o : reshape.cc $(HEADERS)
	$(CC) $(CFLAGS) reshape.cc -c

showFps.o : showFps.cc $(HEADERS)
	$(CC) $(CFLAGS) showFps.cc -c

input.o : input.cc $(HEADERS)
	$(CC) $(CFLAGS) input.cc -c

clean :
	rm *.o

pristine :
	rm *.o
	touch *

tags :
	ctags *.h *.cc *.c

DESIRED FRAME RATE : 
	define SYNC
	endef
