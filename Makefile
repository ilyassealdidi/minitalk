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

bonus	: client_bonus server_bonus utils_bonus minitalk_bonus.h



clean	:
	$(RM) $(NAME)

fclean	: clean

re		: fclean all