CC = gcc
CFLAGS = -Wall -Wextra -g

all: addition product_vector multiplication

addition: addition.o matrix.o
	$(CC) $(CFLAGS) -o $@ $^

product_vector: product_vector.o matrix.o
	$(CC) $(CFLAGS) -o $@ $^

multiplication: multiplication.o matrix.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm addition
	rm product_vector