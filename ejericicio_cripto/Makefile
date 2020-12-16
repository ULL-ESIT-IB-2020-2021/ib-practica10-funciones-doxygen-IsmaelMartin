C++ = g++						
CFLAGS = -Wall

all: cripto

cripto:     cripto.cc cripto_funciones.cc cripto_funciones.h
		$(C++) -o cripto cripto.cc cripto_funciones.cc cripto_funciones.h $(CFLAGS)

clean:
	rm -f *.o 