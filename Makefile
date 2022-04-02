
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client
bonus: server_bonus client_bonus

client: client.c
	$(CC) $(CFLAGS) client.c -o client
server: server.c
	$(CC) $(CFLAGS) server.c ft_putnbr_fd.c -o server 

client_bonus: client_bonus.c
	$(CC) $(CFLAGS) client_bonus.c -o client_bonus
server_bonus: server_bonus.c
	$(CC) $(CFLAGS) server_bonus.c ft_putnbr_fd.c -o server_bonus 

clean:
	rm -f server client client_bonus server_bonus
	
fclean: clean
	rm -f server client client_bonus server_bonus

re: fclean all

.PHONY: all clean fclean re
