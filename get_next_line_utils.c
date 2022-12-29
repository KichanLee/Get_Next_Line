#include <stdlib.h>
#include <string.h>
#include<stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	len = 0;
	while (s1[len])
		++len;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	while (*s1)
	{
		*str = *s1;
		s1++;
		str++;
	}
	*str = '\0';
	while (len--)
		--str;
	return (str);
}


size_t	ft_strlen_d(const char *ch)
{
	size_t	i;

	i = 0;
	while (ch[i])
		++i;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	unsigned char	find;

	find = (unsigned char)c;
	while (*s && *s != find)
		s++;
	if (*s == find)
		return ((char *)s);
	return (0);
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
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	if (!(s1) || !(s2))
		return (0);
	dest = (char *)malloc(sizeof(char) *(strlen(s1) + strlen(s2) + 1));
	if (!dest)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}