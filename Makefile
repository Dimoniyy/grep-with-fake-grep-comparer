CC=gcc
clang_format_path= ../materials/linters/.clang-format
CFLAGS= -Wall -Wextra -Werror -std=c11
grep=./grep
cat=./cat
ARGS=
LEAKS=leaks
GREPARGS=Nya text

clang-format:
	cp $(clang_format_path) $(cat)
	clang-format -i $(cat)/*.c
	rm ./cat/.clang-format
	cp $(clang_format_path) $(grep)
	clang-format -i $(grep)/*.c
	rm ./grep/.clang-format

test:
	$(CC) $(CFLAGS) -g -o test.out ./test.c
	./test.out

test_s21_cat.c:
	$(CC) $(CFLAGS) -o s21_cat.out ./cat/s21_cat.c
	./s21_cat.out

s21_cat:
	$(CC) $(CFLAGS) -o cat/s21_cat ./cat/s21_cat.c

s21_grep:
	make -C $(grep)

sanitize: 
	clang $(grep)/*.c -static

leaks_grep: s21_grep
	$(LEAKS) --atExit -- $(grep)/s21_grep $(ARGS)

test_compare_grep:
	grep $(ARGS) $(GREPARGS)
	./grep/s21_grep $(ARGS) $(GREPARGS)
