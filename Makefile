# ============== CUSTOM TEXT =================
BOLD=\033[1m
RESET=\033[0m
LIGHT_RED=\033[91m
LIGHT_GREEN=\033[92m
LIGHT_CYAN=\033[96m

# ============== MAIN INFO =================
NAME = fdf
BONUS = checker

# ============== LIBFT COMMANDS =================
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = -I $(LIBFT_DIR)/includes -I $(LIBFT_DIR)/dependency_includes

# ============== MINILIBX COMMANDS =================
MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a
MLX_DEPENDENCIES = -lXext -lX11 -lm -lbsd

# ============== COMPILATION COMMANDS =================
INCLUDES_UTILS = -I src/utils
INCLUDES_PARSER = -I src/parser
INCLUDES_VIEWER = -I src/viewer -I src/viewer/line -I src/viewer/line/line_algorithms/bresenham -I src/viewer/minilibx
INCLUDES = -I . $(LIBFT_INCLUDES) -I $(MLX_DIR) -I includes $(INCLUDES_VIEWER) $(INCLUDES_PARSER) $(INCLUDES_UTILS)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 $(INCLUDES)

# ============== SRC FILES =================
SRC_PARSER_FILES = src/parser/reader_list.c src/parser/reader_matrix.c src/parser/reader.c
ALGORITHMS = src/viewer/line/line_algorithms
SRC_FILES = src/utils/coordinates.c $(ALGORITHMS)/bresenham/bresenham_utils.c $(ALGORITHMS)/bresenham/bresenham.c \
	src/viewer/minilibx/minilibx.c src/viewer/minilibx/minilibx_layer.c src/viewer/line/line.c $(SRC_PARSER_FILES)

# ============== PROGRAM FILES =================
TEST_PROGRAM=teste.c
MAIN_PROGRAM=src/main.c
BONUS_PROGRAM=src/checker_bonus.c

PROGRAM=teste

# ============== CUSOM SLEEP =================
SLEEP = 0.07


# ***************************************************************************************************
# ********************************************           ********************************************
# ********************************************  TARGETS  ********************************************
# ********************************************           ********************************************
# ***************************************************************************************************

all: $(NAME)

$(NAME): $(SRC_FILES) $(MAIN_PROGRAM) $(LIBFT) $(MLX)
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$@$(RESET)..." && sleep $(SLEEP)
	@$(CC) $(CFLAGS) $^ -o $@ $(MLX_DEPENDENCIES)

bonus: $(BONUS)

$(BONUS): $(SRC_FILES) $(BONUS_PROGRAM) $(LIBFT) $(MLX)
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$@$(RESET)..." && sleep $(SLEEP)
	@$(CC) $(CFLAGS) $^ -o $@ $(MLX_DEPENDENCIES)

test: $(SRC_FILES) $(TEST_PROGRAM) $(LIBFT) $(MLX)
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$@$(RESET)..." && sleep $(SLEEP)
	@$(CC) $(CFLAGS) $^ -o $@ $(MLX_DEPENDENCIES)

test_reader: $(SRC_FILES) test_reader.c $(LIBFT) $(MLX)
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$@$(RESET)..." && sleep $(SLEEP)
	@$(CC) $(CFLAGS) $^ -o $@ $(MLX_DEPENDENCIES)

valgrind:
	valgrind -q --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(PROGRAM) reader_tests/42.fdf


$(LIBFT):
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$@$(RESET)..." && sleep $(SLEEP)
	@make -s -C $(LIBFT_DIR) SLEEP="$(SLEEP)"

$(MLX):
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$@$(RESET)..." && sleep $(SLEEP)
	@make -s -C $(MLX_DIR) SLEEP="$(SLEEP)"

minilibx:
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$@$(RESET)..." && sleep $(SLEEP)
	@make -s -C $(MLX_DIR) SLEEP="$(SLEEP)"


clean:
	@echo "$(LIGHT_RED)>> $(BOLD)cleanning$(RESET) $(LIGHT_CYAN)./$(LIBFT_DIR)$(RESET)..." && sleep $(SLEEP)
	@make -s -C $(LIBFT_DIR) clean SLEEP="$(SLEEP)"
	@echo "$(LIGHT_RED)>> $(BOLD)cleanning$(RESET) $(LIGHT_CYAN)./$(MLX_DIR)$(RESET)..." && sleep $(SLEEP)
	@make -s -C $(MLX_DIR) clean SLEEP="$(SLEEP)"

fclean: clean
	@echo "$(LIGHT_RED)>> $(BOLD)deletting$(RESET) $(LIGHT_CYAN)./$(LIBFT)$(RESET)..." && sleep $(SLEEP)
	@make -s -C $(LIBFT_DIR) fclean SLEEP="$(SLEEP)"
	@echo "$(LIGHT_RED)>> $(BOLD)deletting$(RESET) $(LIGHT_CYAN)./$(NAME)$(RESET)..." && sleep $(SLEEP)
	@rm -rf $(NAME)
	@echo "$(LIGHT_RED)>> $(BOLD)deletting$(RESET) $(LIGHT_CYAN)./$(BONUS)$(RESET)..." && sleep $(SLEEP)
	@rm -rf $(BONUS)

re: fclean all

.PHONY: all clean fclean re minilibx
