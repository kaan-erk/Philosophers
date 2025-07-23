NAME = philo

CC = cc -g

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

UTILS =	utils/utils.c

PARSE = parse/parse.c

SRCS =	$(UTILS) \
		$(PARSE) \
		main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus