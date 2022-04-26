CC = gcc

all: HW4_basic HW4_ignore HW4_handler

HW4_basic: HW4_basic.c
	$(CC) HW4_basic.c -o HW4_basic -pthread

HW4_ignore: HW4_ignore.c
	$(CC) HW4_ignore.c -o HW4_ignore -pthread

HW4_handler: HW4_handler.c
	$(CC) HW4_handler.c -o HW4_handler -pthread

clean:
	rm -f HW4_basic HW4_ignore HW4_handler
