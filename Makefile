CC=gcc
CFLAGS= -Wall -Wextra -Werror
ARGS=
LEAKS=leaks
GREPARGS=Nya text

test:
	$(CC) $(CFLAGS) -g -o test.out ./test.c
	./test.out

leaks_$(NAME): $(NAME)
	$(LEAKS) --atExit -- $(NAME) $(ARGS)