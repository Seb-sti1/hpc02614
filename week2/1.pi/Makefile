CC	= gcc
OPT	= -g -O3 -ffast-math
LIBS =

CFLAGS = $(OPT) -fopenmp # -ftree-parallelize-loops=8

SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

TARGET = compute_pi.$(CC)

all: $(TARGET)

$(TARGET): clean $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(OBJECTS) $(LIBS)

clean:
	rm -f $(TARGET) *.o

main.o: main.c
