#include "gnl.h"

int		main(void)
{
	int		fd;
	char	*result;

	fd = open("/home/dgeorgiy/42_cursus_personal/gnlmike/test.txt", O_RDONLY);
	result = gnl(fd);
	while (result)
	{
		printf("gnl = %s", result);
		free(result);
		result = gnl(fd);
	}
	// printf("gnl = %s", gnl(fd));
	// printf("gnl = %s", gnl(fd));
	// printf("gnl = %s", gnl(fd));
	// printf("gnl = %s", gnl(fd));
	// printf("gnl = %s", gnl(fd));
	return (0);
}