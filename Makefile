SRCS	= client.c server.c utils.c

SRCS_B	= client_bonus.c server_bnous.c utils_bonus.c

NAME	= server client

CFLAGS	= -Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	: $(SRCS) minitalk.h
	cc $(CFLAGS) server.c utils.c -o server  && cc $(CFLAGS) client.c utils.c -o client

bonus	: $(SRCS_B) minitalk_bonus.h
	cc $(CFLAGS) server_bonus.c utils_bonus.c -o server  && cc $(CFLAGS) client_bonus.c utils_bonus.c -o client

clean	:
	$(RM) $(NAME)

fclean	: clean

re		: fclean all