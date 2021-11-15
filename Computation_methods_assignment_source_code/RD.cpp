#include "RD.h"

void RD::SetValue()
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
				Matrix[i][j] = 2 * R *
					(Matrix[i - 1][j + 1] - 2 * Matrix[i - 1][j] + Matrix[i - 1][j - 1])
					+ Matrix[i - 2][j];
			}
		}
	}
}

