TARGET=kwatch
NOMAKEDIR=
SRCS=$(shell find * -name "*.c")
OBJS=$(patsubst %.c, %.o, $(SRCS))
INCLUDE=$(addprefix -I./,$(filter-out $(NOMAKEDIR), $(shell find * -type d)))
LINK=
CC=gcc

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(LINK) $(OBJS)

%.o : %.c
	$(CC) $(INCLUDE) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)

remake:
	make clean && make
