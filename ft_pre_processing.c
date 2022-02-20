int ft_valid_placement(int row, int col, char array[6][7], char digit)
{
	int		i;

	i = 1; // changed 0 to 1
	
	// Sudoku rules
	while (i < 5)
	{
		if (array[row][i] == digit)
			return 0;
		if (array[i][col] == digit)
			return 0;
		i++;
	}

	// could also do visible=array[x][y] and than visible--;
	// first turn
	int temp_max = '0';
	int visible = '0';
	i = 1;
	while (i < 5)
	{
		if (array[row][i] > temp_max)
		{
			temp_max = array[row][i];
			visible++;
		}
		i++;
	}
	if (array[row][0] < visible) // check against clue
	{
		//if(digit > temp_max)
			return 0;
	}
	// second turn
	temp_max = '0';
	visible = '0';
	i = 1;
	while (i < 5)
	{
		if (array[i][col] > temp_max)
		{
			temp_max = array[i][col];
			visible++;
		}
		i++;
	}
	if (array[0][col] < visible) // check against clue
	{		
		//if(digit > temp_max)
			return 0;
	}

	// third turn (check if it works backwards correctly?)
	temp_max = '0';
	visible = '0';
	i = 5;
	while (i > 5)
	{
		if (array[row][i] > temp_max)
		{
			temp_max = array[row][i];
			visible++;
		}
		i--;
	}
	if (array[row][5] < visible) // check against clue
	{
		//if(digit > temp_max)
			return 0;
	}
	// fourth turn
	temp_max = '0';
	visible = '0';
	i = 5;
	while (i > 5)
	{
		if (array[i][col] > temp_max)
		{
			temp_max = array[i][col];
			visible++;
		}
		i--;
	}
	if (array[0][col] < visible) // check against clue
	{		
		//if(digit > temp_max)
			return 0;
	}
	// temp_max = '0';
	// visible = '0';
	// i = 1;
	// while (i < 5)
	// {
	// 	if (array[i][col] > temp_max)
	// 	{
	// 		temp_max = array[i][col];
	// 		visible++;
	// 	}
	// 	i++;
	// }
	// if (array[0][col] > visible) // check against clue
	// 		return 0;

	return 1;
}
void ft_pre_processing(char array[6][7], int total_size)
{
	int row;
	int col;
	char min = '1';
	char max = total_size - 2 + '0'; //because we have 5 instead of 3
	row = 0;
	col = 0;
	while (row < total_size)
	{
		while (col < total_size)
		{
			// //if (row != 0 && col != 0)
			// printf("%d", array[row][col]);
			// if (row == 0 || row == 4)
			// 	col++;
			// else
			// 	col+=3;

			// deal with 0th and 4th (last) row
			if (row == 0 && array[row][col] == max)
			{
				array[row + 1][col] = min; // while loop instead
				array[row + 2][col] = min + 1;
				array[row + 3][col] = min + 2;
				array[row + 4][col] = min + 3;
			}
			if (row == 0 && array[row][col] == min)
				array[row + 1][col] = max;

			if (row == 5 && array[row][col] == max)
			{
				array[row - 1][col] = min; // while loop instead
				array[row - 2][col] = min + 1;
				array[row - 3][col] = min + 2;
				array[row - 4][col] = min + 3;
			}
			if (row == 5 && array[row][col] == min)
				array[row - 1][col] = max;

			if (col == 0 && array[row][col] == max)
			{
				array[row][col + 1] = min; // while loop instead
				array[row][col + 2] = min + 1;
				array[row][col + 3] = min + 2;
				array[row][col + 4] = min + 3;
			}
			if (col == 0 && array[row][col] == min)
					array[row][col + 1] = max;
			
			if (col == 5 && array[row][col] == max)
			{
					array[row][col - 1] = min; // while loop instead
					array[row][col - 2] = min + 1;
					array[row][col - 3] = min + 2;
					array[row][col - 4] = min + 3;
			}
			if (col == 5 && array[row][col] == min)
					array[row][col - 1] = max;
			col++;
		}
		col = 0;
		row++;
	}
}