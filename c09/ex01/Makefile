SRC = $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_putstr.c $(SRC_DIR)/ft_strcmp.c $(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_swap.c

SRC_DIR := srcs
OBJ_DIR := srcs
INC_DIR := includes

TARGET = libft.a
OBJS := $(SRC:%.c=%.o)

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

all: $(TARGET)

$(TARGET): $(OBJS) 
	ar rc $(TARGET) $(OBJS)
	ranlib $(TARGET)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CCFLAGS) -c $? -o $@ -I$(INC_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all
