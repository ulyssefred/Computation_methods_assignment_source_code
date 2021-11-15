#include "DF.h"


void DF::SetValue()
{
	Matrix = MatrixInitial();
	for (int i = 1; i < rows; i++)
	{
		for (int j = 1; j < cols - 1; j++)
		{
			if (i == 1)
			{
				Matrix[i][j] = Matrix[i - 1][j];
			}
			else
			{
				Matrix[i][j] = (Matrix[i - 2][j] + 
					2 * R * (Matrix[i - 1][j + 1] - Matrix[i - 2][j] + Matrix[i - 1][j - 1]))
					/ (1 + 2 * R);
			}
		}
	}
}



