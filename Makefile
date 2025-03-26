NAME = fdf
LIBNAME = $(NAME).a
LIBFT_DIR = ../libft
INCLUDE_LIBFT = -L $(LIBFT_DIR) -l:libft.a
INCLUDE_MLX = -L .mlx -l:libmlx.a  -lX11 -lXext
CFLAGS = -Wall -Werror -Wextra -g

CFILES = SRCS/hooks/hooks.c SRCS/hooks/hooks_event.c SRCS/parser/parser.c SRCS/parser/parser_utils.c SRCS/draw/draw.c SRCS/main.c
OFILES = $(CFILES:.c=.o)

	
$(LIBNAME) : $(OFILES)
	@if [ ! -f .mlx/libmlx.a ]; then $(MAKE) makemlx; fi
	@make -C $(LIBFT_DIR)
	@rm -f $(LIBNAME)
	@cp $(LIBFT_DIR)/libft.a $(LIBNAME)
	@ar -rc $(LIBNAME) $(OFILES)
	@cc SRCS/main.c -L. -l:fdf.a $(INCLUDE_MLX) $(INCLUDE_LIBFT) -lX11 -lXext -lm -o fdf -g

makemlx:
	@make -C .mlx

%.o : %.c compiled
	@cc $(CFLAGS) -I INCLUDES/fdf.h -c $< -o $@

compiled :
	@echo "All $(LIBNAME) files compiled."

all: $(LIBNAME)
	@make all -C $(LIBFT_DIR)

clean :
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OFILES) && echo "$(LIBNAME) object files cleaned.\n"

fclean:
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(OFILES) $(LIBNAME) $(NAME) && echo "$(LIBNAME) cleaned.\n"

cleanmlx:
	@make clean -C .mlx

re: fclean all
	@make re -C $(LIBFT_DIR)

norm:
	@norminette | grep -E --color=always "Error" || echo "\e[32mnorminette is fine!\e[0m"

allc: $(LIBNAME) clean

rec: fclean allc
	@make rec -C $(LIBFT_DIR)

re : fclean $(LIBNAME)