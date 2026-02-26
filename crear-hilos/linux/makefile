.phony: clean

SRCS=crear-hilos.c crear-hilos2.c
OBJS=$(SRCS:.c=.o)
EXECS=$(OBJS:.o=)

all: ${EXECS}

crear-hilos: crear-hilos.o

crear-hilos.o: crear-hilos.c

crear-hilos2: crear-hilos2.o

crear-hilos2.o: crear-hilos2.c

clean:
	rm -f ${OBJS}
	rm -f ${EXECS}
	rm -f *~
