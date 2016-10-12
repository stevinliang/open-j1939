CC = gcc
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*c)
OBJS = $(patsubst %.c, %.o, $(SOURCES))

INCLUDES = -I./inc

CFLAGS = -fPIC -shared

TARGETS = open_j1939.so

all: $(OBJS) $(TARGETS)

.PHONY: all clean

%.o : %.c
	@$(CC) -c $(CFLAGS) $(INCLUDES) $^ -o $@
	@echo "compiling $^ ..."

$(TARGETS): $(OBJS)
	@$(CC) $^ $(CFLAGS) -o $@
	@echo "generate $@ done"

clean:
	@rm $(OBJS) $(TARGETS)
	@echo "clean done"


