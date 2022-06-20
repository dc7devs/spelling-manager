TARGET=app
C_SOURCE=$(wildcard *.c)
OBJS=$(C_SOURCE:.c=.o)
CC=g++
FLAGS=-Wall

all: $(OBJS)
	@ echo "Gerando arquivo objeto.."
	$(CC) -o $(TARGET) $^ $(FLAGS)
 
%.o: %.c
	@ echo "Compilando.."
	$(CC) -c $< -o $@

clean:
	rm -f *.o