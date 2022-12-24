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
int main()
{
	char buff[10000];
	int fd;
	int idx = 0;
	int rdcnt;
	fd = open("a.txt", O_RDONLY);

	printf("fd : %d\n", fd);
	
	rdcnt = read(fd, &buff[idx], 2);
	printf("rdcnt : %d\n", rdcnt);

	buff[2] = '\0';
	printf("%s", buff);
	

		
}