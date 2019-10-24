all:
	gcc -Wall -Wextra -Wformat-security -o boiler main.c boiler.c file.c mem.c strings.c
