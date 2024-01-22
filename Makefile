SRCS	= client.c server.c utils.c

SRCS_B	= client_bonus.c server_bonus.c utils_bonus.c

NAME	= server

NAME2	= client

CFLAGS	= -Wall -Wextra -Werror

all		: $(NAME) $(NAME2)

$(NAME)	: server.c utils.c minitalk.h
	cc $(CFLAGS) server.c utils.c -o server

$(NAME2): client.c utils.c minitalk.h
	cc $(CFLAGS) client.c utils.c -o client

bonus	: client_bonus server_bonus minitalk_bonus.h

client_bonus : client_bonus.c utils_bonus.c minitalk_bonus.h
	cc $(CFLAGS) client_bonus.c utils_bonus.c -o client_bonus

server_bonus : server_bonus.c utils_bonus.c minitalk_bonus.h
	cc $(CFLAGS) server_bonus.c utils_bonus.c -o server_bonus

clean	:
	$(RM) $(NAME) $(NAME2) client_bonus server_bonus

fclean	: clean

re		: fclean all

