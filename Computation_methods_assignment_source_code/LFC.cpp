//////////////
////LFC.cpp///
//////////////
#include "LFC.h"

/**
 * @brief Compute and output LFC scheme method results and error results to error.csv and results csv file,
 * and display the results on terminal
 * @return void
 */
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
	/// <summary>
	/// Catch possible file open exception, if open file fail, print Warning message.
	/// </summary>
	try
	{
		fs.open("results.csv", ios::app);
	}
	catch (ofstream::failure& writeErr)
	{
		cout << "fs file open fail" << endl;
	}
	try
	{
		fe.open("error.csv", ios::app);
	}
	catch (ofstream::failure& writeErr)
	{
		cout << "fe file open fail" << endl;
	}
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
		/// <summary>
		/// Using thomas_algorithm compute scheme methods results
		/// </summary>
		ans = thomas_algorithm(a, b, c, cols - 2, d);
		for (int j = 0; j < cols - 2; j++) {
			CurrentArray[j + 1] = ans[j];
			if (int(k * deltaT * 100) % 10 == 0) {
				fs << CurrentArray[j + 1] << ",";
				cout<< CurrentArray[j + 1] << ",";
				double Temp = 0.;
				/// <summary>
				/// compute current analytical solution results
				/// </summary>
				for (int m = 1; m < M + 1; m++)
				{
					Temp += exp(-D * (m * M_P / L) * (m * M_P / L) *
						k * deltaT) * ((1 - pow(-1, m)) /
							(m * M_P)) * sin(m * M_P * (j + 1) * deltaX / L);

				}
				Exact_results[j + 1] = Tsur + 2 * (Tin - Tsur) * Temp;
				fe << Exact_results[j + 1] - CurrentArray[j + 1] << ",";
			}
		}
		if (int(k * deltaT * 100) % 10 == 0){
			cout << endl;
			fs << endl;
			fe << endl;
		}
	}
	fs.close();
	fe.close();
}