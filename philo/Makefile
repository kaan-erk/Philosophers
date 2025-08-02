NAME = philo

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

UTILS =	utils/utils.c

PARSE = parse/parse.c

EXECUTE =	execute/execute.c \
			execute/execute_utils.c

SRCS =	$(UTILS) \
		$(PARSE) \
		$(EXECUTE) \
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