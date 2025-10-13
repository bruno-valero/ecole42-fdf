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
INCLUDES_CORE = -I src/core -I src/core/color -I src/core/state -I src/core/event_callbacks -I src/core/frame -I src/core/frame/render_lines -I src/core/event_hooks
INCLUDES = -I . $(LIBFT_INCLUDES) -I $(MLX_DIR) -I includes $(INCLUDES_VIEWER) $(INCLUDES_PARSER) $(INCLUDES_UTILS) $(INCLUDES_CORE)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -O3 -march=native -flto -funroll-loops $(INCLUDES)
# CFLAGS = -Wall -Werror -Wextra -g3 $(INCLUDES)

# ============== SRC FILES =================
SRC_UTILS_FILES = src/utils/coordinates.c src/utils/line.c src/utils/point.c

SRC_PARSER_FILES = src/parser/reader_nodes.c src/parser/reader_list.c src/parser/reader_matrix.c src/parser/reader.c \
src/parser/reader_print.c src/parser/parser_matrix.c src/parser/parse_matrix.c src/parser/parse_point.c src/parser/parse_file.c

ALGORITHMS = src/viewer/line/line_algorithms
SRC_VIEWER_FILES = $(ALGORITHMS)/bresenham/bresenham_color.c $(ALGORITHMS)/bresenham/bresenham_utils.c $(ALGORITHMS)/bresenham/bresenham.c \
src/viewer/minilibx/minilibx.c src/viewer/minilibx/minilibx_layer.c src/viewer/line/viewer_line.c src/viewer/viewer_context.c \
src/viewer/minilibx/devices_events/mouse_events.c src/viewer/minilibx/devices_events/keyboard_events.c src/viewer/minilibx/devices_events/window_events.c \
src/viewer/minilibx/devices_events/loop_event.c

SRC_CORE_STATE_FILES = src/core/state/state.c src/core/state/camera.c src/core/state/actions/reset_camera.c src/core/state/actions/projections.c src/core/state/actions/change_z_factor.c src/core/state/actions/auto_rotate.c \
src/core/state/modes/shadow_mode.c src/core/state/modes/resolution_mode.c src/core/state/actions/toggle_open_menu.c

SRC_CORE_EVENT_CALLBACKS_FILES = src/core/event_callbacks/mouse_callbacks/mouse_move.c src/core/event_callbacks/mouse_callbacks/mouse_buttons.c src/core/event_callbacks/keyboard_callbacks/keyboard_sessions/alpanum_key_press.c \
src/core/event_callbacks/keyboard_callbacks/keyboard_sessions/special_key_press.c src/core/event_callbacks/keyboard_callbacks/keyboard_sessions/special_key_release.c \
src/core/event_callbacks/keyboard_callbacks/keyboard_sessions/alpanum_key_release.c src/core/event_callbacks/keyboard_callbacks/key_press.c src/core/event_callbacks/keyboard_callbacks/key_release.c \
src/core/event_callbacks/keyboard_callbacks/keyboard_sessions/key_release_utils.c src/core/event_callbacks/keyboard_callbacks/keyboard_sessions/key_press_utils.c src/core/event_callbacks/loop_callback/loop_callback.c

SRC_CORE_EVENT_HOOKS_FILES = src/core/event_hooks/keyboard_hooks.c src/core/event_hooks/mouse_hooks.c src/core/event_hooks/window_hooks.c src/core/event_hooks/loop_hook.c

SRC_CORE_FRAME_FILES = src/core/frame/render_lines/build_lines.c src/core/frame/render_lines/update_line.c src/core/frame/render_lines/update_rotation.c src/core/frame/render_background.c src/core/frame/render_frame.c \
src/core/frame/menu/menu.c src/core/frame/menu/menu.c src/core/frame/menu/menu_divs.c

SRC_CORE_FILES = src/core/core.c src/core/color/color.c \
$(SRC_CORE_STATE_FILES) $(SRC_CORE_EVENT_CALLBACKS_FILES) $(SRC_CORE_EVENT_HOOKS_FILES) $(SRC_CORE_FRAME_FILES)

SRC_FILES = $(SRC_UTILS_FILES) $(SRC_PARSER_FILES) $(SRC_VIEWER_FILES) $(SRC_CORE_FILES)

# ============== PROGRAM FILES =================
TEST_PROGRAM=teste.c
MAIN_PROGRAM=src/main.c
BONUS_PROGRAM=src/main.c

PROGRAM=teste

# ============== CUSOM SLEEP =================
SLEEP = 0.07

# ============== COMPILATION =================
COMPILATION_DEPENDENCIES = $(SRC_FILES) $(LIBFT) $(MLX)

# ***************************************************************************************************
# ********************************************           ********************************************
# ********************************************  TARGETS  ********************************************
# ********************************************           ********************************************
# ***************************************************************************************************

all: $(NAME)

$(NAME): $(MAIN_PROGRAM) $(COMPILATION_DEPENDENCIES)
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$@$(RESET)..." && sleep $(SLEEP)
	@$(CC) $(CFLAGS) $^ -o $@ $(MLX_DEPENDENCIES)

bonus: $(BONUS)

$(BONUS): $(BONUS_PROGRAM) $(COMPILATION_DEPENDENCIES)
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$@$(RESET)..." && sleep $(SLEEP)
	@$(CC) $(CFLAGS) $^ -o $@ $(MLX_DEPENDENCIES)

test: $(TEST_PROGRAM) $(COMPILATION_DEPENDENCIES)
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$@$(RESET)..." && sleep $(SLEEP)
	@$(CC) $(CFLAGS) $^ -o $@ $(MLX_DEPENDENCIES)

test_reader: tests/test_reader.c fclean $(COMPILATION_DEPENDENCIES)
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$@$(RESET)..." && sleep $(SLEEP)
	@$(CC) $(CFLAGS) tests/test_reader.c $(COMPILATION_DEPENDENCIES) -o $@ $(MLX_DEPENDENCIES)


reader: test_reader
	@echo "$(LIGHT_CYAN)>> $(BOLD)running$(RESET) $(LIGHT_CYAN)./$<$(RESET)..." && sleep $(SLEEP)
	@valgrind -q --track-origins=yes --leak-check=full --show-leak-kinds=all ./$< tests/maps/42.fdf

test_parser: tests/test_parser.c fclean $(COMPILATION_DEPENDENCIES)
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$@$(RESET)..." && sleep $(SLEEP)
	@$(CC) $(CFLAGS) $< $(COMPILATION_DEPENDENCIES) -o $@ $(MLX_DEPENDENCIES)


parser: test_parser
	@echo "$(LIGHT_CYAN)>> $(BOLD)running$(RESET) $(LIGHT_CYAN)./$< $(RESET)..." && sleep $(SLEEP)
	@valgrind -q --track-origins=yes --leak-check=full --show-leak-kinds=all ./$< tests/maps/42mod.fdf

test_core: tests/test_core.c fclean $(COMPILATION_DEPENDENCIES)
	@echo "$(LIGHT_GREEN)>> $(BOLD)compiling$(RESET) $(LIGHT_CYAN)./$@$(RESET)..." && sleep $(SLEEP)
	@$(CC) $(CFLAGS) $< $(COMPILATION_DEPENDENCIES) -o $@ $(MLX_DEPENDENCIES)


core: test_core
	@echo "$(LIGHT_CYAN)>> $(BOLD)running$(RESET) $(LIGHT_CYAN)./$< $(RESET)..." && sleep $(SLEEP)
	@valgrind -q --track-origins=yes --leak-check=full --show-leak-kinds=all ./$< tests/maps/42.fdf

valgrind:
	valgrind -q --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose ./$(PROGRAM) reader_tests/42.fdf


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
