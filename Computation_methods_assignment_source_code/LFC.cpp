#include "LFC.h"

void LFC::ResultsOutput()
{
	cout << "please input deltaT" << endl;
	double t;
	cin >> t;
	InitialArray = MatrixInitial(0.05, t);
	CurrentArray = InitialArray;
	vector<double>a(cols - 2);
	vector<double>b(cols - 2);
	vector<double>c(cols - 2);
	vector<double>d(cols - 2);
	vector<double>ans(cols - 2);
	ofstream fs, fe;
	fs.open("results.csv", ios::app);
	fe.open("error.csv", ios::app);
	cout<< "This is the Laasonen Simple Implicit scheme results." << "deltaT = " << deltaT << endl;
	fs << "This is the Laasonen Simple Implicit scheme results." << "deltaT = " << deltaT << endl;
	fe << "This is the Laasonen Simple Implicit scheme Error results." << "deltaT = " << deltaT << endl;
	for (int k = 1; k < rows; k++)
	{
		PreviousArray = CurrentArray;
		for (int i = 0; i < cols - 2; i++)
		{
			a[i] = -R;
			b[i] = 1.0 + 2 * R;
			c[i] = -R;
			d[i] = PreviousArray[i + 1];
		}
		d[0] = d[0] + R * PreviousArray[0];
		d[cols - 3] = d[cols - 3] + R * PreviousArray[cols - 1];
		ans = thomas_algorithm(a, b, c, cols - 2, d);
		for (int j = 0; j < cols - 2; j++) {
			CurrentArray[j + 1] = ans[j];
			fs << CurrentArray[j + 1] << ",";
			cout<< CurrentArray[j + 1] << ",";
			double Temp = 0.;
			for (int m = 1; m < M + 1; m++)
			{
				Temp += exp(-D * (m * M_P / L) * (m * M_P / L) *
					k * deltaT) * ((1 - pow(-1, m)) /
						(m * M_P)) * sin(m * M_P * (j + 1) * deltaX / L);

			}
			Exact_results[j + 1] = Tsur + 2 * (Tin - Tsur) * Temp;
			fe << Exact_results[j + 1] - CurrentArray[j + 1] << ",";
		}
		cout << endl;
		fs << endl;
		fe << endl;
	}
}