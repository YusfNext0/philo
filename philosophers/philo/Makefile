NAME = philo

SRC = philo.c src/ft_strjoin.c src/free_mat.c src/ft_itoa.c src/ft_putstr_fd.c \
		src/ft_split.c src/ft_strchr.c src/ft_strcmp.c src/ft_strdup.c src/ft_strjoin.c \
		src/ft_strlcpy.c src/ft_strlen.c src/ft_substr.c src/ft_atoi.c parcing.c init_information.c

OBJ = $(SRC:.c=.o)

CC = cc -pthread
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -f

all: $(NAME)

%.o : %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $^ -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: all clean