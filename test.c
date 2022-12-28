#include <stdio.h>

char	*readline(int fd) // 딕에서 한줄 읽어오는 함수
{
	int			rdchar;
	static char	buffer[101]; // 한줄에서 100자까지는 입력 가능하게 넉넉하게 할당함
	int			idx;

	idx = 0;
	rdchar = read(fd, &buffer[idx], 1); 
	if (buffer[0] == '\n') // 불러온 라인에서 개행이면 개행은 그냥 리턴
	{
		buffer[1] = '\0';
		return (buffer);
	}
	while (buffer[idx] != '\n' && rdchar && idx < 100) //위에서 개행없음을 확인했을 때 그 한줄을 읽어서 리턴한다.
	{
		idx++;
		rdchar = read(fd, &buffer[idx], 1);
	}
	buffer[idx] = '\0';
	return (buffer);
}