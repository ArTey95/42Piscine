/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:22:48 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 19:22:48 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_add_row_values_one(char array[6][7], int row, int col)
{
	char	min;
	char	max;

	min = '1';
	max = '4';
	if (row == 0 && array[row][col] == max)
	{
		array[row + 1][col] = min;
		array[row + 2][col] = min + 1;
		array[row + 3][col] = min + 2;
		array[row + 4][col] = min + 3;
	}
	if (row == 0 && array[row][col] == min)
		array[row + 1][col] = max;
}

void	ft_add_row_values_two(char array[6][7], int row, int col)
{
	char	min;
	char	max;

	min = '1';
	max = '4';
	if (row == 5 && array[row][col] == max)
	{
		array[row - 1][col] = min;
		array[row - 2][col] = min + 1;
		array[row - 3][col] = min + 2;
		array[row - 4][col] = min + 3;
	}
	if (row == 5 && array[row][col] == min)
		array[row - 1][col] = max;
}

void	ft_add_column_values_one(char array[6][7], int row, int col)
{
	char	min;
	char	max;

	min = '1';
	max = '4';
	if (col == 0 && array[row][col] == max)
	{
		array[row][col + 1] = min;
		array[row][col + 2] = min + 1;
		array[row][col + 3] = min + 2;
		array[row][col + 4] = min + 3;
	}
	if (col == 0 && array[row][col] == min)
			array[row][col + 1] = max;
}

void	ft_add_column_values_two(char array[6][7], int row, int col)
{
	char	min;
	char	max;

	min = '1';
	max = '4';
	if (col == 5 && array[row][col] == max)
	{
			array[row][col - 1] = min;
			array[row][col - 2] = min + 1;
			array[row][col - 3] = min + 2;
			array[row][col - 4] = min + 3;
	}
	if (col == 5 && array[row][col] == min)
			array[row][col - 1] = max;
}

void	ft_pre_processing(char array[6][7], int total_size)
{
	int		row;
	int		col;

	row = 0;
	col = 0;
	while (row < total_size)
	{
		while (col < total_size)
		{
			ft_add_row_values_one(array, row, col);
			ft_add_row_values_two(array, row, col);
			ft_add_column_values_one(array, row, col);
			ft_add_column_values_two(array, row, col);
			col++;
		}
		col = 0;
		row++;
	}
}
