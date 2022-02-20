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
#include <stdlib.h>

void	fill_clue(char clue[6][7], char *input_fixed);

void	fill_zero(char clue[6][7]);

int		check_input(int n, char *input_fixed, char **argv);

int		opposite_side(char *input_fixed, int n, int i);

int		max_num(int n, char *input_fixed, int i);

int		max_one_n(int n, char *input_fixed, int i);

int		edges(char clue[][7]);

int		ft_solve(int row, int col, char array[6][7]);

void	ft_pre_processing(char array[6][7], int total_size);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{	
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_putmat(char *input_fixed)
{
	int		i;
	int		j;
	char	clue[6][7];

	fill_zero(clue);
	fill_clue(clue, input_fixed);
	ft_pre_processing(clue, 6);
	ft_solve(1, 1, clue);
	i = 1;
	j = 1;
	while (j < 5)
	{	
		while (i < 5)
		{
			write(1, &clue[i][j], 1);
			if (i != 4)
				write(1, " ", 1);
			i++;
		}
		i = 1;
		j++;
		write(1, "\n", 1);
	}
	return (edges(clue));
}

int	check_error(int n, char *input_fixed, char **argv, int i)
{
	if (ft_putmat(input_fixed) == 0
		|| check_input(n, input_fixed, argv) == 0
		|| opposite_side(input_fixed, n, i) == 0
		|| max_num(n, input_fixed, i) == 0
		|| max_one_n(n, input_fixed, i) == 0)
		return (0);
	else
		return (1);
}

/* for four x four puzzle 
 */
int	main(int argc, char **argv)
{
	int					n;
	int					i;
	char				input_fixed[17];

	if (argc == 2)
	{
		n = 4;
		i = 0;
		while (i < 16)
		{
			input_fixed[i] = argv[1][2 * i];
			i++;
		}
		input_fixed[i] = '\0';
		if (check_error(n, input_fixed, argv, i) == 0)
		{
			ft_putstr("Error\n");
			return (0);
		}
	}
	else
	{
		ft_putstr("Error\n");
		return (0);
	}	
}
