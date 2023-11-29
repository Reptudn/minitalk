SERVER	:= server
CLIENT	:= client
SRC		:= ./client.c ./server.c
CFLAGS	:= -Wall -Wextra -Werror
CC		:= gcc
INCLUDE	:= -I ./lib/libft -I ./lib/ft_printf

.PHONY: all clean fclean server client

all: $(SERVER) $(CLIENT)

%.o: %.c
	@make -C ./lib/libft
	@make -C ./lib/ft_printf
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER): server.o
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): client.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	@make -C ./lib/libft clean
	@make -C ./lib/ft_printf clean
	rm -f *.o

fclean: clean
	@make -C ./lib/libft fclean
	@make -C ./lib/ft_printf fclean
	rm -f $(SERVER) $(CLIENT)

re: fclean all