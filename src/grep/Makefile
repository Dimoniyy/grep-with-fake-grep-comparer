NAME = s21_grep

OBJ_DIR = obj/
SRC_DIR = ./
INCLUDE = -I headers/

CFLAGS = -g -std=c11 -Wall
CC = gcc

SRC_LIST = $(wildcard $(SRC_DIR)*.c)
OBJ_LIST = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_LIST))
DEP_LIST = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.d, $(SRC_LIST))

$(NAME): $(OBJ_DIR) $(OBJ_LIST)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJ_LIST)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -MMD $(CFLAGS) -c $< -o $@

-include $(DEP_LIST)

clean:
	rm -rf $(OBJ_DIR)
	rm $(NAME)

rebuild: clean $(NAME)

$(OBJ_DIR): 
	mkdir -p $(OBJ_DIR)