/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateymour <ateymour@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:41:37 by ateymour          #+#    #+#             */
/*   Updated: 2022/02/20 17:41:37 by ateymour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str);

void	fill_array(char *ones, char clue[][7]);

int	check_input(int n, char *input_fixed, char **argv)
{
	int	i;

	i = 0;
	while (input_fixed[i] != '\0')
	{	
		if (input_fixed[i] > n + '0' || input_fixed[i] < '1')
			return (0);
		i++;
	}
	if (i < 4 * n || argv[1][31] != '\0')
		return (0);
	return (1);
}

/* 	1. 	also usueful for bigger. 
	one side can have maximum value of the difference 
	of the opposite side and number of rows + 1. */
int	opposite_side(char *input_fixed, int n, int i)
{
	int	x;

	n = 4;
	i = 0;
	while (i < n)
	{		
		x = n - (input_fixed[i] - '0');
		if (input_fixed[i + n] - '0' <= x + 1)
			i++;
		else
			return (0);
	}
	i = 2 * n;
	while ((i < 3 * n))
	{		
		x = n - (input_fixed[i] - '0');
		if (input_fixed[i + n] - '0' <= x + 1)
			i++;
		else
			return (0);
	}
	return (1);
}

/* 2.	maximum allowed number of each clue on each side = x + 1
!!!not for 1 and n.!!!  */
int	max_num(int n, char *input_fixed, int i)
{
	int	j;
	int	count_2;
	int	count_3;

	i = 0;
	while (i < 4)
	{	
		count_2 = 0;
		count_3 = 0;
		j = 0;
		while (j < n)
		{
			if (input_fixed[j + (i * 4)] == '2')
				count_2 += 1;
			else if (input_fixed[j + (i * 4)] == '3')
				count_3 += 1;
			j++;
		}
		if (count_3 > (1 + 1) || count_2 > (2 + 1))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/* 	3.	also usueful for bigger. 
only max one 1 and one n on each side   */
int	max_one_n(int n, char *input_fixed, int i)
{
	int	j;
	int	count_1;
	int	count_n;

	i = 0;
	while (i < 4)
	{	
		count_1 = 0;
		count_n = 0;
		j = 0;
		while (j < n)
		{
			if (input_fixed[j + (i * 4)] == '1')
				count_1 += 1;
			else if (input_fixed[j + (i * 4)] == n + '0')
				count_n += 1;
			j++;
		}
		if (count_1 > 1 || count_n > 1)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/* 	4. if we have 1 on edges the edge before  is also 1
most be modified for each puzzle */
int	edges(char clue[][7])
{
	int		i;
	char	ones[8];

	fill_array(ones, clue);
	i = 0;
	while (ones[i] != '\0')
	{
		if (ones[i] == '1' && i % 2 == 0)
		{
			if (ones[i + 1] != '1')
			{
				return (0);
			}
		}
		else if (ones[i] == '1' && i % 2 == 1)
		{
			if (ones[i - 1] != '1')
			{	
				return (0);
			}
		}
		i++;
	}
	return (1);
}
