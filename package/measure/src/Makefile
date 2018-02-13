SRC=main.c BNO055.h I2C.h
OBJ = main.o BNO055.o I2C.o
CFLAGS = -Wall -Wextra
TARGET=measure

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)

install:
	cp measure $(DESTDIR)/bin/measure
