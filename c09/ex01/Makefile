SRC_DIR = ./srcs
INC_DIR = ./includes
BIN_DIR = .
SRC = $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_swaps.c $(SRC_DIR)/ft_putstr.c $(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_strcmp.c
OBJ = $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)%.o)
TARGET = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $^ $(CFLAGS) -o $(BIN_DIR)/$@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $^ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all