.phony: clean

SRCS=ejecutar.c ejecutar2.c ejecutar3.c ejecutar4.c
OBJS=$(SRCS:.c=.o)
EXECS=$(OBJS:.o=)

all: ${EXECS}

ejecutar: ejecutar.o

ejecutar.o: ejecutar.c

ejecutar2: ejecutar2.o

ejecutar2.o: ejecutar2.c

ejecutar3: ejecutar3.o

ejecutar3.o: ejecutar3.c

ejecutar4: ejecutar4.o

ejecutar4.o: ejecutar4.c

# ejecutar5: ejecutar5.o

# ejecutar5.o: ejecutar5.c

# ejecutar6: ejecutar6.o

# ejecutar6.o: ejecutar6.c

clean:
	rm -f ${OBJS}
	rm -f ${EXECS}
	rm -f *~
