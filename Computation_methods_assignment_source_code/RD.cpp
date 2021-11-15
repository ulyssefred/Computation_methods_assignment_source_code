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

void RD::ResultsOutput()
{
	SetValue();
	ofstream fs;
	fs.open("results.csv", ios::app);
	fs << "This is the Richardson scheme results." << endl;
	for (int i = 0; i < rows; i++)
	{
		if (int(i * deltaT * 100) % 10 == 0)
		{
			fs << "time " << "," << i * deltaT << endl;
			for (int j = 0; j < cols; j++)
			{
				fs << Matrix[i][j] << ",";
			}
			fs << endl;
		}
	}
	fs << "This is the Richardson scheme Error results." << endl;
	Exact_results = Analytical_Solution();
	for (int i = 0; i < rows; i++)
	{
		if (int(i * deltaT * 100) % 10 == 0)
		{
			fs << "time " << "," << i * deltaT << endl;
			for (int j = 0; j < cols; j++)
			{
				fs << Exact_results[i][j] - Matrix[i][j] << ",";
			}
			fs << endl;
		}
	}
}

