NAME = libstr.a
INCLUDES = -I includes
CC = cc
CFLAGS = -Wall -Werror -Wextra $(INCLUDES)

SRC = src
SRC_FILES = ft_atoi.c ft_atol.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_issign.c ft_itoa.c ft_itoa.c ft_split.c ft_destroy_char_matrix.c ft_strchr.c \
ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJ = obj
OBJ_FILES := $(SRC_FILES:%.c=$(OBJ)/%.o)

all: $(NAME)

test: $(NAME)
	@$(CC) $(CFLAGS) -g3 test/main.c $(NAME) -o a.out

$(NAME): $(OBJ) $(OBJ_FILES)
	@ar rcs $(NAME) $(OBJ_FILES)

$(OBJ):
	@mkdir $(OBJ)

$(OBJ)/%.o: $(SRC)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ) a.out

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re so
