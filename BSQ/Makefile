SRC = *.c
OBJ = $(SRC:.c=.o)
TARGET = bsq
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@

%.o: %.c
	$(CC) -c $^ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all
