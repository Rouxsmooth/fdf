#include <stdio.h>
#include "../../libft/INCLUDES/libft.h"
#include <fcntl.h>

int	main(void)
{
	int		i;
	char	*line;
	int		map;

	i = 0;
	map = open("maps/test_maps/mars.fdf", O_RDONLY);
	while ((line = get_next_line(map)))
		printf("l%d : '%s'\n", i++, line); free(line);
	close(map);
	//map = open("test.txt", O_RDONLY);
	//while ((line = get_next_line(map)))
	//	printf("l%d : '%s'\n", i++, line); free(line);
	//close(map);
	
}