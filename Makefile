TARGET = kwatch
SRCS = main.c

OBJS = $(SRCS:.c=.o)
CC = gcc

all : $(TARGET)

$(TARGET) : $(OBJS)
$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

.c.o :
$(CC) $(CFLAGS) -c $<

clean :
rm -f $(OBJS) $(TARGET)
