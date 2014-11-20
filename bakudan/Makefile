TARGET  = a.out
SRCS    = $(wildcard *.c)
OBJS    = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^
