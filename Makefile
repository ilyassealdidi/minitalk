LIBFT_SRC		= libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c\
				libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_toupper.c \
				libft/ft_tolower.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c \
				libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_strlcpy.c libft/ft_strlcat.c \
				libft/ft_strnstr.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c \
				libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c \
				libft/ft_putnbr_fd.c

LIBFT_OBJS 		= $(LIBFT_SRC:.c=.o)

LIBFT_LIBRARY	= libft/libft.h
LIBFT_NAME		= libft.a

CFLAGS			= -Wall -Wextra -Werror
ARC				= ar r


libft:			$(LIBFT_NAME)

$(LIBFT_NAME):	$(LIBFT_OBJS)
				$(ARC) $(LIBFT_NAME) $(LIBFT_OBJS)

libft_clean:
				$(RM) $(LIBFT_OBJS)

%.o 			: %.c $(LIBFT_LIBRARY)
				$(CC) $(CFLAGS) -o $@ -c $<
				
libft_fclean:			clean
				$(RM) $(NAME)
				
libft_re:		libft_fclean libft