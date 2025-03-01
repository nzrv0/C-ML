CC = gcc
library_conf = -c -fpic

all: linear_regression clean

.PHONY: linear_regression
linear_regression: librandom_generator.so
	$(CC) -o linear_regression.so linear_regression.c -L. -lrandom_generator -Wl,-rpath=.

librandom_generator.so: create_generator
	$(CC) random_generator.o -shared -o librandom_generator.so

.PHONY: create_generator 
create_generator:
	$(CC) $(library_conf) random_generator.c -o random_generator.o

.PHONY: clean
clean:
	rm -rf *.o




