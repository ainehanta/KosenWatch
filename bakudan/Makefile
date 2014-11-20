TARGET  = a.out
SRCS    = $(wildcard *.c)
OBJS    = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^
