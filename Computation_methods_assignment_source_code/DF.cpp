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

void DF::ResultsOouput()
{
	SetValue();
	ofstream fs;
	fs.open("results.csv", ios::app);
	fs << "This is the DuFort-Frankel scheme results."<<endl;
	for (int i = 0; i < rows; i++)
	{
		if (int(i * deltaT * 100) % 10 == 0)
		{
			fs << "time " << "," << i * deltaT << endl;
			for (int j = 0; j < cols; j++)
			{
				fs <<Matrix[i][j] << ",";
			}
			fs << endl;
		}
	}
	fs << "This is the DuFort-Frankel scheme Error results."<<endl;
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



