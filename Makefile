SRCS	= client.c server.c utils.c

OBJS	= $(SRCS:.c=.o)

NAME	= server client

CFLAGS	= -Wall -Wextra -Werror

all		: server client

server	: server.c utils.c
	cc $(CFLAGS) $^ -o $@

client	: client.c utils.c
	cc $(CFLAGS) $^ -o $@

clean	:
	$(RM) $(OBJS)

fclean	: 
	$(RM) $(OBJS) $(NAME)

re		: fclean all