/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateymour <ateymour@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:36:02 by ateymour          #+#    #+#             */
/*   Updated: 2022/02/19 11:36:02 by ateymour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>

void ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{	
		write(1, &str[i], 1);
		i++;
	}
}

void ft_putmat(char str[6][6])
{
	int	i;
	int j;
	i = 0;
	j = 0;
	while (j < 6)
	{	

		while(i < 6)
		{
			write(1, &str[i][j], 1);
			i++;
		}
		i = 0;

		j++;
		write(1, "\n", 1);

	}
}




/* for four x four puzzle 
 */
int main (int argc, char **argv)
{
	int n; /* number of rows and colomns */
	int i;
	int j;
	char input_fixed[16];
	n = 4;
	i = 0;
	while (i < 16)
	{
		input_fixed[i] = argv[1][2*i];
		i++;
	}
	input_fixed[i] = '\0';
	ft_putstr(input_fixed);
	ft_putstr("\n");
	i = 0;
	while (input_fixed[i] != '\0')
	{	
		if (input_fixed[i] > n + '0'|| input_fixed[i] < '1')
		{
			ft_putstr("Error\n");
			ft_putstr("wrong output");
			return 0 ;
		}
		i++;
	}
	if (i < 4*n)
	{
		ft_putstr("Error\n");
		ft_putstr("wrong number of output");
		return 0 ;		
	}

	char clue[6][6] ={
		{'0',input_fixed[8], input_fixed[9],input_fixed[10], input_fixed[11],'0'},
		{input_fixed[0], '0','0','0','0',input_fixed[4]},
		{input_fixed[1], '0','0','0','0',input_fixed[5]},
		{input_fixed[2], '0','0','0','0',input_fixed[6]},
		{input_fixed[3], '0','0','0','0',input_fixed[7]},
		{'0',input_fixed[12], input_fixed[13],input_fixed[14], input_fixed[15], '0'}
	};	 

	if (argc == 2)
	{

		ft_putmat(clue);
		/* 	1. 	also usueful for bigger. 
			one side can have maximum value of the difference of the opposite side and number of rows + 1. */
		i = 0;
		while (i <n)
		{		
			int	x;
			x = n - (input_fixed[i] - '0');
			if (input_fixed[i + n] - '0' <= x + 1)
				i++;
			else
			{	
				char c = i + '0';
				ft_putstr("Error\n");
				ft_putstr("maximum value of opposite");
				write(1,&c,1);
				return 0 ;
			}
		}
		i = 2*n;
		while ((i <3*n))
		{		
			int	x;
			x = n - (input_fixed[i] - '0');
			if (input_fixed[i + n] - '0' <= x + 1)
				i++;
			else
			{	
				char c = i + '0';
				ft_putstr("Error\n");
				ft_putstr("maximum value of opposite");
				write(1,&c,1);
				return 0 ;
			}
		}
		/* 2.	maximum allowed number of each clue on each side = x + 1
			!!!not for 1 and n.!!!  */

		int x_2;
		int x_3;
		int count_2;
		int count_3;

		i = 0;
		x_2 = n - 2;
		x_3 = n - 3;

		while (i < 4)
		{	
			count_2 = 0;
			count_3 = 0;
			j = 0;
			while (j < n)
			{
				if (input_fixed[j + (i*4)] == '2')
					count_2 += 1;
				else if (input_fixed[j + (i*4)] == '3')
					count_3 += 1;

				j++;
			}
			if (count_3 > (x_3 + 1) || count_2 > (x_2 + 1))
			{
				ft_putstr("Error\n");
				ft_putstr("max number of clue reached");
				return 0 ;
			}

			i++;
		}




		/* 	3.	also usueful for bigger. 
		only max one 1 and one n on each side   */
		int x_1;
		int x_n;
		int count_1;
		int count_n;

		i = 0;
		x_1 = 1;
		x_n = 1;

		while (i < 4)
		{	
			count_1 = 0;
			count_n = 0;
			j = 0;
			while (j < n)
			{
				if (input_fixed[j + (i*4)] == '1')
					count_1 += 1;
				else if (input_fixed[j + (i*4)] == n + '0')
					count_n += 1;

				j++;
			}
			if (count_1 > x_1 || count_n > x_n)
			{
				ft_putstr("Error\n");
				ft_putstr("max number of 1 or n reached");
				return 0 ;
			}

			i++;
		}

		/* 	4. if we have 1 on edges the edge before  is also 1
		most be modified for each puzzle */
		char ones[8] = {clue[1][0], clue[0][1], clue[5][1],  clue[4][0],clue[4][5], clue[5][4],  clue[0][4], clue[1][5]};
		ones[8] = '\0';
		ft_putstr("\n");
		ft_putstr(ones);
		ft_putstr("\n");
		i = 0;
		while(ones[i] != '\0')
		{
			if (ones[i] == '1' && i % 2 == 0 )
			{
				if (ones[i + 1]!= '1')
				{
					ft_putstr("Error\n");
					ft_putstr("zoj");
					return 0 ;
				}
			}
			else if (ones[i] == '1' && i % 2 == 1 )
			{
				if (ones[i - 1 ]!= '1')
				{	
					char c = i + '0';
					ft_putstr("Error\n");
					write(1,&c,1);
					return 0 ;
				}
			}

			i++;
		}

	}
	else 
	{
		ft_putstr("Error\n");
		return 0 ;
	}	
}

