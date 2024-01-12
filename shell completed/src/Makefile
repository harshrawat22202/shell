CC = gcc
CFLAGS = -Wall -Wextra -g   # Add any desired compiler flags here

SRCS = shell.c globals.c insert.c parse.c history.c pipes.c
OBJS = $(SRCS:.c=.o)

all: a.out

a.out: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f a.out $(OBJS)
