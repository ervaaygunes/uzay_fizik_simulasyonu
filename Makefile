CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = -lm
TARGET = uzay_fizik_simulasyonu
SOURCE = main.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE) $(LDFLAGS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run

