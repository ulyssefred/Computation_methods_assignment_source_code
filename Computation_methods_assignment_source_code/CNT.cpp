#include "CNT.h"

void CNT::SetValue()
{
    Matrix = MatrixInitial();
    vector<double>a(cols - 2);
    vector<double>b(cols - 2);
    vector<double>c(cols - 2);
    vector<double>d(cols - 2);
    vector<double>ans(cols - 2);
    for (int k = 0; k < rows - 1; k++)
    {
        for (int i = 0; i < cols - 2; i++)
        {
            a[i] = -R/2.;
            b[i] = 1. + R;
            c[i] = -R/2.;
			d[i] = R * Matrix[k][i]/2. + (1.0 - R)*Matrix[k][i+1] + R * Matrix[k][i + 2]/2.;
        }
        d[0] = d[0] + R * Matrix[k + 1][0]/2.;
        d[cols - 3] = d[cols - 3] + R * Matrix[k + 1][cols - 1]/2.;
        ans = thomas_algorithm(a, b, c, cols - 2, d);
        for (int j = 0; j < cols - 2; j++)
            Matrix[k + 1][j + 1] = ans[j];
    }
}

void CNT::ResultsOutput()
{
	SetValue();
	ofstream fs;
	fs.open("results.csv", ios::app);
	fs << "This is the Crank-Nicholson scheme results." << endl;
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
	fs << "This is the Crank-Nicholson scheme Error results." << endl;
	Exact_results = Analytical_Solution();
	for (int i = 1; i < rows; i++)
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