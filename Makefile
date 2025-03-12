CC = gcc
library_conf = -c -fpic

all: linear_regression clean

.PHONY: linear_regression
linear_regression: librandom_generator.so
	$(CC) -o ./regression/linear_regression.so ./regression/linear_regression.c -L./random -lrandom_generator -lm -Wl,-rpath=./random

librandom_generator.so: create_generator
	$(CC) ./random/random_generator.o -shared -o ./random/librandom_generator.so

.PHONY: create_generator 
create_generator:
	$(CC) $(library_conf) ./random/random_generator.c -o ./random/random_generator.o

.PHONY: clean
clean:
	rm -rf **/*.o




