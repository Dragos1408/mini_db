CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = src/main.c src/utils.c src/dynarray.c
OBJ = $(SRC:.c=.o)
TARGET = mini_db

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLASG) -o $@ $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)
