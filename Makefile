NAME = fdf
LIBNAME = $(NAME).a
LIBFT_DIR = ../libft
MLX_DIR = .mlx
INCLUDE_LIBFT = -L $(LIBFT_DIR) -l:libft.a
INCLUDE_MLX = -L $(MLX_DIR) -l:libmlx.a -lX11 -lXext -lm
CFLAGS = -Wall -Werror -Wextra -g

CFILES =	SRCS/HOOKS/hooks.c		SRCS/HOOKS/hooks_event.c					\
			SRCS/PARSER/parser.c	SRCS/PARSER/parser_utils.c					\
			SRCS/DRAW/draw_utils.c	SRCS/DRAW/line_utils.c		SRCS/DRAW/draw.c\
			SRCS/MAIN/main.c		SRCS/MAIN/init.c			SRCS/MAIN/quit.c
OFILES = $(CFILES:.c=.o)

.SECONDARY: $(OBJ)

all: $(NAME)

$(NAME): $(LIBNAME)
	@cc SRCS/MAIN/main.c -L. -l:$(LIBNAME) $(INCLUDE_MLX) $(INCLUDE_LIBFT) -o $(NAME)

$(LIBNAME): $(OFILES) makelibft makemlx
	@cp $(LIBFT_DIR)/libft.a $(LIBNAME)
	@ar -rc $(LIBNAME) $(OFILES)
	@printf "\033[34m          Compiled $(NAME) successfully!\033[0m\n"

makemlx:
	@if [ ! -f $(MLX_DIR)/libmlx.a ]; then \
		printf "\rCompiling MLX..."; \
		make -C $(MLX_DIR) >/dev/null 2>&1; \
		printf "\r\033[34m          MLX compiled successfully!\033[0m\n"; \
	fi

makelibft:
	@if [ ! -f $(LIBFT_DIR)/libft.a ]; then \
		printf "\rCompiling Libft..."; \
		make -C $(LIBFT_DIR) >/dev/null 2>&1; \
		printf "\r\033[34m          Libft compiled successfully!\033[0m\n"; \
	fi

%.o: %.c
	@printf "\r\033[K\033[34mCompiling: $<\033[0m"  
	@cc $(CFLAGS) -I INCLUDES -c $< -o $@
	@printf "\r\033[K"

clean:
	@make clean -C $(LIBFT_DIR) -s
	@rm -f $(OFILES)
	@echo "    \033[32m$(NAME) object files cleaned\033[0m"

fclean: clean
	@make clean -C $(MLX_DIR) -s
	@make fclean -C $(LIBFT_DIR) -s
	@rm -f $(LIBNAME) $(NAME)
	@echo "    \033[32m$(NAME) cleaned.\033[0m"

re: fclean all

cleanmlx:
	@make clean -C $(MLX_DIR) -s

norm:
	@norminette | grep -E --color=always "Error" || echo "\e[32mNorminette is fine!\e[0m"
