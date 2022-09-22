SRC = $(SRC_DIR)/ft_display_file.c

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := .

TARGET = ft_display_file
EXE := $(BIN_DIR)/$(TARGET)
OBJS := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $? $(CFLAGS) -o $@ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all
