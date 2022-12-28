#include <stdlib.h>
#include <string.h>

size_t	ft_strlen_d(const char *ch)
{
	size_t	i;

	i = 0;
	while (ch[i])
		++i;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	size;
	size_t	i;

	i = 0;
	if (start > ft_strlen_d(s))
		size = 0;
	else if (len > ft_strlen_d(s + start))
		size = ft_strlen_d(s + start);
	else
		size = len;
	string = (char *)malloc(sizeof(char) * (size + 1));
	if (!string || !s)
		return (NULL);
	if (size)
		while (i < len && s[start])
			string[i++] = s[start++];
	string[i] = '\0';
	return (string);
}