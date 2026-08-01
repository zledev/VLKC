CC = gcc
CFLAGS = -Wall -Wextra -std=c23 -O2 -Iinclude
LIBS = -lvulkan -lglfw -lcglm -lGL -lm

TARGET = vulkan_engine

SRC = main.c $(wildcard src/*.c)
OBJS = $(SRC:.c=.o)
HEADERS = $(wildcard include/*.h)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LIBS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	# Removes the final executable AND all temporary object (.o) files
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean