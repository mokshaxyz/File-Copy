CC = gcc
CFLAGS = -Wall

TARGET = flame_cp
SRC = my_copy.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
