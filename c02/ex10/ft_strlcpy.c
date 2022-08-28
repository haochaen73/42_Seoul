#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (*src)
		{
			*dest = *src;
			dest++;
			src++;
			i++;
		}
	}
	*dest = '\0';
}	
