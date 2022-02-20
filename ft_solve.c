int ft_valid_placement(int row, int col, char array[6][7], char digit);
int	ft_solve(int row, int col, char array[6][7])
{
	char digit;
	
	if (row < 5 && col < 5)
	{
		if (array[row][col] != '0')
		{
			if ((col + 1) < 5) // next column
				return ft_solve(row, col + 1, array);
			else if ((row + 1) < 5) // next row
				return ft_solve(row + 1, 1, array);
			else 
				return 1; // solved!
		}
		else
		{
			digit = '1';
			while (digit < '5')
			{
				
				if (ft_valid_placement(row, col, array, digit)) // why did he use i+1?
				{
					array[row][col] = digit;
					if ((col + 1) < 5)
					{
						if (ft_solve(row, col + 1, array))
							return 1;
						else
							array[row][col] = '0';
					}
					else if ((row + 1) < 5)
					{
						if (ft_solve(row + 1, 1, array))
							return 1;
						else
							array[row][col] = '0';
					}
					else
						return 1;
				}
				digit++;
			}
		}
		return 0;
	}
	else
		return 1;
}
