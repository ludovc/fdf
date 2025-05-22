SRCS = \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \

SRCS_BONUS = \
ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c \

SRCS_GET_NEXT_LINE = \
get_next_line/get_next_line_bonus.c \
get_next_line/get_next_line_utils_bonus.c \

NAME = libft.a
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_GET_NEXT_LINE = $(SRCS_GET_NEXT_LINE:.c=.o)
CFLAGS = -Wall -Wextra -Werror
FT_PRINTF = ft_printf/libftprintf.a

.c.o:
			cc $(CFLAGS) -c $< -o $@

all:		$(NAME) bonus expansion

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:		$(NAME) $(OBJS_BONUS)
			ar rcs $(NAME) $(OBJS_BONUS)

expansion: $(FT_PRINTF) $(OBJS_GET_NEXT_LINE)
	ar rcs $(NAME) $(OBJS_GET_NEXT_LINE)

$(FT_PRINTF):
	make -C ft_printf
	rm ft_printf/*.o
	cd ./ft_printf && ar x libftprintf.a
	ar rcs $(NAME) ft_printf/*.o

clean:
			rm -f $(OBJS) $(OBJS_BONUS)
			make -C ft_printf clean

fclean:		clean
			rm -f $(NAME)
			make -C ft_printf fclean

re:			fclean all

test:
			git clone git@github.com:ludovc/tester_libft.git test
