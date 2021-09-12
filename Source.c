#include <stdio.h>
#include <stdlib.h>

void	*ft_fill(char *arr) 
{
	int	i;
	char* buf;

	buf = arr;
	i = 0;
	while (i < 100)
	{
		*arr = 'o';
		arr++;
		i++;
	}
	*arr = '\0';
}

void	ft_show(char *arr)
{
	int	i;
	char line;

	i = 0;
	write(1, "	1	2	3	4	5	6	7	8	9	10", 21);
	while (i < 100)
	{
		if (i % 10 == 0) 
		{
			write(1, "\n", 1);
			line = (i / 10 + 1) + 48;
			if (line == ':') write(1, "10", 2);
			else write(1, &line, 1);
			write(1, "	", 1);
		}
		write(1, arr, 1);
		write(1, "	", 1);
		arr++;
		i++;
	}
	write(1, "\n", 1);
}

char	*ft_reserve(char *arr, int action)
{
	int		i;
	char	*buf;
	int		line;
	int		column;

	line = ft_inputChek();
	column = ft_inputChek();
	if (line <= 0 || column <= 0) return (arr);
	buf = arr;
	i = 1;
	while (i < ((line - 1) * 10) + column) 
	{
		arr++;
		i++;
	}
	if (action == 1)
		if (*arr != 'x') *arr = 'x';
		else write(2, "		>>>>>Error! The space is already occupied<<<<<\n", 50);
	else if (action == 2 && *arr != 'o')
	{
		*arr = 'o';
		write(1, "	>>>>>The space is free<<<<<\n", 30);
	}

		
	return (buf);
}

int ft_input() 
{
	char	input;

	scanf_s(" %c", &input);
	return (input - 48);
}

int	ft_inputChek()
{
	int	input;

	input = ft_input();
	while (!(input >= 0 && input <= 10))
	{
		write(2, "Wrong input!!!\n", 16);
		input = ft_input();
	}
	return (input);
}

int	main(int argc, char** argv)
{
	char	input;
	char	*arr;

	arr = (char*)malloc(sizeof(char) * 101);
	if (arr == NULL) return (1);
	ft_fill(arr);
	ft_show(arr);
	input = '1';
	while (input) 
	{
		printf("1. Occupy a parking space\n2. free the parking space\n3. Exit\n");
		scanf_s(" %c", &input);
		if (!(input >= '1' && input <= '3')) write(2, "Wrong input!!!\n", 16);
		else if (input == '1')
		{
			arr = ft_reserve(arr, 1);	
		}
		else if (input == '2') arr = ft_reserve(arr, 2);
		else if (input == '3') break ;
		
		ft_show(arr);
	}
	free(arr);

	return (0);
}