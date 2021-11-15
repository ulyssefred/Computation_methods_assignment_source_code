#include "LSI.h"

void LSI::SetValue()
{
	Matrix = MatrixInitial();
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
