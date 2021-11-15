#include "LSI.h"

void LSI::SetValue()
{
	cout << "please input deltaT" << endl;
	double t;
	cin >> t;
	Matrix = MatrixInitial(0.05, t);
    vector<double>a(cols - 2);
    vector<double>b(cols - 2);
    vector<double>c(cols - 2);
    vector<double>d(cols - 2);
    vector<double>ans(cols - 2);
    for (int k = 1; k < rows ; k++)
    {
        for (int i = 0; i < cols - 2; i++)
        {
            a[i] = -R;
            b[i] = 1.0 + 2 * R;
            c[i] = -R;
            d[i] = Matrix[k - 1][i + 1];   
        }
        d[0] = d[0] + R * Matrix[k][0];
        d[cols - 3] = d[cols - 3] + R * Matrix[k][cols - 1];
        ans = thomas_algorithm(a, b, c, cols - 2, d);
        for (int j = 0; j < cols - 2; j++)
            Matrix[k][j + 1] = ans[j];
    }
}

void LSI::ResultsOutput()
{
	SetValue();
	ofstream fs;
	fs.open("results.csv", ios::app);
	fs << "This is the Laasonen Simple Implicit scheme results. deltat = 0.1" << endl;
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
	fs << "This is the Laasonen Simple Implicit scheme Error results." << endl;
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
