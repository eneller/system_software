CC = gcc
CFLAGS = -Wall -Wextra -O2

# Compile when running `make a`
%: %.c
	$(CC) $(CFLAGS) -o $@ $<
	
clean: 
	git clean