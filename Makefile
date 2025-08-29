CC = gcc
CFLAGS = -Wall -O2
TARGET = llmod

all: $(TARGET)

$(TARGET): llmod.c
	$(CC) $(CFLAGS) -o $(TARGET) lsmod.c

clean:
	rm -f $(TARGET)