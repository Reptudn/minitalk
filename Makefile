SERVER	:= server
CLIENT	:= client
SRC		:= ./client.c ./server.c
CFLAGS	:= -Wall -Wextra -Werror

.PHONY: all clean fclean server client

all: $(SERVER) $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER): server.o
	./lib/ft_printf/make
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): client.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all