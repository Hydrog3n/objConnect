SRC=cliudp.c
OBJ = cliudp.o
CFLAGS = -Wall -Wextra
TARGET=cliudp

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGER)

install:
	cp cliudp $(DESTDIR)/bin/cliudp
