# Makefile for OPS exercise 8: filter/redirect


# Make both programs by default:
all: printversion filter redirect


# Link and create binary executable
filter: filter.o
	gcc -Wall -o filter filter.o

# Compile .c files to object files (.o files)
filter.o: filter.c
	gcc -c -Wall filter.c


# Link and create binary executable
redirect: redirect.o
	gcc -Wall -o redirect redirect.o

# Compile .c files to object files (.o files)
redirect.o: redirect.c
	gcc -c -Wall redirect.c


clean:
	rm -f *.o

cleanall: clean
	rm -f filter redirect

printversion:
	@gcc --version |grep gcc
