NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx #-fsanitize=address

RM = rm -rf
SRCS = main.c parsing.c gnl/get_next_line.c gnl/get_next_line_utils.c split.c tools.c helpers.c game.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	

clean :
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)

re : fclean all
