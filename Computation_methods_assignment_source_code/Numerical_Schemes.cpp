//////////////////////////
//Numerical_Schemes.cpp///
//////////////////////////

#include "Numerical_Schemes.h"

/**
 * @brief Vector initial function, set vector value when time = 0.
 * @param deltax Input deltaT
 * @param deltat Input deltaT
 * @return vector(when time = 0)
 */
vector<double> Numerical_Schemes::MatrixInitial(double deltax, double deltat)
{
	deltaT = deltat;
	deltaX = deltax;
	R = D * deltaT / (deltaX * deltaX);
	cols = 1 / deltaX + 1;
	rows = 0.5 / deltaT + 1;
	vector<double> _matrix(cols);
	for (int i = 0; i < cols; i++)
	{
		if (i == 0 || i == cols - 1) {
			_matrix[i] = Tsur;
		}
		else {
			_matrix[i] =Tin;
		}
		PrePreviousArray.push_back(Tin);
		Exact_results.push_back(0.0);
	}

	return _matrix;
}
/**
 * @brief thomas_algorithm function, transfer vector value from time = n to time = n+1.
 * @param a coefficient vector
 * @param b coefficient vector
 * @param c coefficient vector
 * @param n vector size
 * @param d vector(time = n)
 * @return vector(time = n+1)
 */
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




