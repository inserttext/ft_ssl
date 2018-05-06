#include <stdio.h>

static unsigned long	hash(unsigned char *str)
{
	unsigned long hash;

	hash = 5381;
	while (*str)
	{
		hash = ((hash << 5U) + hash) ^ *str;
		str++;
	}
	return (hash);
}

int					main(int ac, char **av){
	if (ac > 1) {
		for (int i = 1; i < ac; i++) {
			printf("% 10s = %lu\n", av[i], hash((unsigned char *)av[i]) % 128);
		}
	}
	return (0);
}
