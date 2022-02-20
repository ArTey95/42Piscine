/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateymour <ateymour@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:44:07 by ateymour          #+#    #+#             */
/*   Updated: 2022/02/20 17:44:07 by ateymour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_clue(char clue[6][7], char *input_fixed)
{	
	int	i;
	int	j;

	i = 0;
	while (i < 2)
	{
		j = 1;
		while (j < 5)
		{
			clue[j][i * 5] = input_fixed[j - 1 + (i * 4)];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 2)
	{
		j = 1;
		while (j < 5)
		{
			clue[i * 5][j] = input_fixed[j + 7 + (i * 4)];
			j++;
		}
		i++;
	}
}

void	fill_zero(char clue[6][7])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			clue[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	fill_array(char *ones, char clue[][7])
{
	ones[0] = clue[1][0];
	ones[1] = clue[0][1];
	ones[2] = clue[5][1];
	ones[3] = clue[4][0];
	ones[4] = clue[4][5];
	ones[5] = clue[5][4];
	ones[6] = clue[0][4];
	ones[7] = clue[1][5];
	ones[8] = '\0';
}
