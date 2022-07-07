TARGET=ortografia
C_SOURCE=$(wildcard *.c)
OBJS=$(C_SOURCE:.c=.o)
CC=gcc
FLAGS=-Wall

all: $(OBJS)
	@ echo "Gerando arquivo objeto.."
	$(CC) -o $(TARGET) $^ $(FLAGS)

%.o: %.c
	@ echo "Compilando.."
	$(CC) -c $< -o $@

clean:
	rm -f *.o
