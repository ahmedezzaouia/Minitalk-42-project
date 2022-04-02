
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

libprintf.a:
	make -C ft_printf

client: client.c
	$(CC) $(CFLAGS) client.c -o client
server: server.c
	$(CC) $(CFLAGS) server.c ft_putnbr_fd.c -o server 

clean:
	rm -f server client
	
fclean: clean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re
