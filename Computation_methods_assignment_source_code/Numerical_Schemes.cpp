#include "Numerical_Schemes.h"

vector<vector<double>> Numerical_Schemes::MatrixInitial(double deltax, double deltat)
{
	deltaT = deltat;
	deltaX = deltax;
	R = D * deltaT / (deltaX * deltaX);
	cols = 1 / deltaX + 1;
	rows = 0.5 / deltaT + 1;
	vector<vector<double>> _matrix(rows, vector<double>(cols));
	for (int i = 1; i < cols - 1; i++)
	{
		_matrix[0][i] = 100;
	}
	for (int j = 0; j < rows; j++)
	{
		_matrix[j][0] = 300;
		_matrix[j][cols - 1] = 300;
	}
	return _matrix;
}

vector<vector<double>> Numerical_Schemes::Analytical_Solution()
{
	vector<vector<double>> analytical_solution_matrix(rows, vector<double>(cols));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			double Temp = 0.;
			for (int m = 1; m < M + 1; m++)
			{
				Temp += exp(-D* (m * M_P/L) * (m * M_P/L) * 
					i * deltaT) * ((1 - pow(-1, m)) / 
						(m * M_P)) * sin(m * M_P * j * deltaX/L);

			}
			analytical_solution_matrix[i][j] = Tsur + 2*(Tin - Tsur)* Temp;
		}
	}
	return analytical_solution_matrix;
}

vector<double> Numerical_Schemes::thomas_algorithm(vector<double> a, vector<double> b, vector<double> c, int n, vector<double> d)
{
	int i;
	double p;
	vector<double>ans(n);
	vector<double>g(n);
	vector<double>w(n);
	g[0] = d[0] / b[0];
	w[0] = c[0] / b[0];
	for (i = 1; i < n; i++)
	{
		p = b[i] - a[i] * w[i - 1];
		g[i] = (d[i] - a[i] * g[i - 1]) / p;
		w[i] = c[i] / p;
	}
	ans[n - 1] = g[n - 1];
	i = n - 2;
	do
	{
		ans[i] = g[i] - w[i] * ans[i + 1];
		i = i - 1;
	} while (i >= 0);
	return ans;
}

void Numerical_Schemes::GetRerults()
{
	SetValue();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if(int (i*deltaT*100)%10 == 0)
				cout << setw(8) << Matrix[i][j] << ",";
		}
		cout << endl;
	}
	cout << endl;

}
void Numerical_Schemes::GetError()
{
	SetValue();
	Exact_results = Analytical_Solution();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (int(i * deltaT * 100) % 10 == 0)
				cout << setw(8) << Exact_results[i][j] - Matrix[i][j] << ",";
		}
		cout << endl;
	}
	cout << endl;
}




