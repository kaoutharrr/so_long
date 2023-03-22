NAME = so_long
CC = cc
#CFLAGS =  -Wall -Wextra -Werror -Imlx -fsanitize=address

RM = rm -rf
SRCS = main.c parsing.c gnl/get_next_line.c gnl/get_next_line_utils.c split.c tools.c helpers.c play.c \
	ft_printf/ft_printf.c ft_printf/ft_putadress.c ft_printf/ft_putchar.c ft_printf/ft_puthexa.c ft_printf/ft_puthexad.c ft_printf/ft_putnbr.c\
	ft_printf/ft_putstr.c ft_printf/ft_uputnbr.c norm.c moves.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	$(RM) $(OBJS) $(OBJS_B)
fclean : clean
	$(RM) $(NAME) 

re : fclean all
