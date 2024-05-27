CC=gcc
CFLAGS= -Wall -Wextra -Werror
ARGS=
LEAKS=leaks
GREPARGS=Nya text
grep=./grep

test: s21_grep
	chmod 755 $(grep)/s21_grep
	$(CC) $(CFLAGS) -g -o test.out ./test.c
	./test.out

leaks_$(NAME): $(NAME)
	$(LEAKS) --atExit -- $(NAME) $(ARGS)

s21_grep:
	make -C $(grep)