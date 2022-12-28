/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:59:04 by kichlee           #+#    #+#             */
/*   Updated: 2022/12/24 17:58:39 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
#define	BUFFERSIZE 1000
static char *str;

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		rdnum;
	size_t			idx;

	buffer = malloc(BUFFERSIZE + 1);

	rdnum = read(fd, buffer, BUFFERSIZE);
	// 버퍼에 담긴 내용부터 개행해주어야함.
	idx = 0;
	while (buffer[idx] != '\n')
	{

		if(buffer[idx] == '\n')
			str = ft_substr(buffer, 0, idx);
	
	}
	while (rdnum > 0)
	{
		rdnum = read(fd, buffer, BUFFERSIZE);
	}

	return (buffer);
}

int main()
{
	int fd;
	int rdcnt;

	//printf("\nstatic idx value is : %d\n" ,idx);
	fd = open("a.txt", O_RDONLY);

	printf("fd : %d\n", fd);
	int cnt = 0;

	while (cnt < 4)
	{ 
		char *str = get_next_line(fd);
		printf("%s", str);
		printf("static idx value is : %d\n" ,idx);
		++cnt;
	}
	printf("cnt value is : %d", cnt);
	close(fd);	
}
