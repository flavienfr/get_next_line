#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int		main(int ac, char **av)
{
	int 	fd;
	int i;
	char 	*line;

	ac = 0;
	//(void)av;
	//line = (char*)malloc(sizeof(char));
	fd = open(av[1], O_RDONLY);

	//fd = 0;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%-5d|%s|\n", i, line);
		free(line);
	}
	printf("%-5d|%s|\n", i, line);
	free(line);

while (1)
	;
	/*
	i = get_next_line(fd, &line); 
	printf("%-5d|%s|\n", i, line);
	free(line);
	i = get_next_line(42, &line); 
	printf("%-5d|%s|\n", i, line);
*/
	//while (1)
	//	;

	//test fichier vide
	/*BONUS
	int fd1;
	int fd2;
	fd = open("other", O_RDONLY);
	fd1 = open("TESTATION/16-one", O_RDONLY);
	fd2 = open("lorem", O_RDONLY);

	//printf("|-1-|\n");
	i = get_next_line(fd1, &line);
	printf("%s\n", line);
		free(line);
	//printf("|-1-|\n");
	
	//printf("|-2-|\n");
	i = get_next_line(fd1, &line);
	printf("%s\n", line);
		free(line);
	//printf("|-2-|\n");
	
	//printf("|-3-|\n");
	i = get_next_line(fd1, &line);
	printf("%s\n", line);
		free(line);
	//printf("|-3-|\n");
	i = get_next_line(fd, &line);
	printf("%s\n", line);
		free(line);
	i = get_next_line(fd2, &line);
	printf("%s\n", line);
		free(line);
	i = get_next_line(fd, &line);
	printf("%s\n", line);
		free(line);
	get_next_line(0, &line);
	printf("%s\n", line);
	i = get_next_line(fd2, &line);
	printf("%s\n", line);
		free(line);
	i = get_next_line(fd1, &line);
	printf("%s\n", line);
		free(line);
	i = get_next_line(fd2, &line);
	printf("%s\n", line);
		free(line);

	close(fd);
	close(fd1);
	close(fd2);*/
}
