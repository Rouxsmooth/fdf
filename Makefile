NAME = fdf
LIBNAME = $(NAME).a
LIBFT_DIR = ../libft
INCLUDE_LIBFT = -L $(LIBFT_DIR) -l:libft.a
INCLUDE_MLX = -L .mlx -l:libmlx.a  -lX11 -lXext
CFLAGS = -Wall -Werror -Wextra -g

CFILES = SRCS/hooks/hooks.c SRCS/hooks/hooks_event.c SRCS/parser/parser.c SRCS/parser/parser_utils.c SRCS/main.c
OFILES = $(CFILES:.c=.o)

$(LIBNAME) : $(OFILES)
	@make -C $(LIBFT_DIR)
	@make -C .mlx
	@rm -f $(LIBNAME)
	@cp $(LIBFT_DIR)/libft.a $(LIBNAME)
	@ar -rc $(LIBNAME) $(OFILES)

%.o : %.c compiled
	@cc $(CFLAGS) -I INCLUDES -c $< -o $@

compiled :
	@echo "All $(LIBNAME) files compiled."

all: $(LIBNAME)
	@make all -C $(LIBFT_DIR)

clean :
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OFILES) $(NAME) && echo "$(LIBNAME) object files cleaned.\n"

fclean:
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(OFILES) $(LIBNAME) $(NAME) && echo "$(LIBNAME) cleaned.\n"

re: fclean all
	@make re -C $(LIBFT_DIR)

norm:
	@norminette | grep -E --color=always "Error" || echo "\e[32mnorminette is fine!\e[0m"

allc: $(LIBNAME) clean

rec: fclean allc
	@make rec -C $(LIBFT_DIR)

rerun: rec
	@cc SRCS/main.c -L. -l:fdf.a $(INCLUDE_MLX) $(INCLUDE_LIBFT) -lX11 -lXext -o fdf -g

re : fclean $(LIBNAME)