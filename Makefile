
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client
	
client: client.c
	$(CC) $(CFLAGS) client.c -o client
server: server.c
	$(CC) $(CFLAGS) server.c -o server

clean:
	rm -f server client
	
fclean: clean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re
