CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11 -g -Wvla

# Compile when running `make a`
%: %.c
	$(CC) $(CFLAGS) -o $@ $<
	
clean: 
	git clean
