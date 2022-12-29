#include "get_next_line.h"

#define	BUFFERSIZE 2

// 첫번째가 개행일 수 있으니까 처리해주기 - 완료.
int	check_enter(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if(string[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char 			buffer[BUFFERSIZE + 1];
	char 			*temp;
	static char 	*str;
	ssize_t			rdnum;
	int				idx;
	str = "";
	
	rdnum = read(fd, buffer, BUFFERSIZE);
	if(fd < 0)
		return NULL;
	buffer[BUFFERSIZE] = '\0';
	while (rdnum == BUFFERSIZE)
	{
		idx = check_enter(buffer);
		if (idx == -1)
			str = ft_strjoin(str, buffer);
		// else
		// {
		// 	str = ft_substr(buffer, 0, idx);
		// 	temp = ft_strjoin(str, temp);
	 	// 	str = ft_substr(buffer, idx + 1, BUFFERSIZE);
		// 	return (str);
		// }
		rdnum = read(fd, buffer, BUFFERSIZE);
		buffer[rdnum] = '\0';
	}
	return (str);
}

int main()
{
	int fd;
	char *str;

	fd = open("a.txt", O_RDONLY);
	int count = 5;
	while (count)
	{
		str = get_next_line(fd);
		--count;
		printf("%s", str);
	}
	close(fd);	
}