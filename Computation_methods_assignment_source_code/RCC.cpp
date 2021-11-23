#include "RCC.h"

void RCC::ResultsOutput()
{
	InitialArray = MatrixInitial();
	PreviousArray = PrePreviousArray;
	CurrentArray = InitialArray;
	ofstream fs, fe;
	fs.open("results.csv", ios::app);
	fe.open("error.csv", ios::app);
	cout<< "This is the Richardson scheme results " << endl;
	fs << "This is the Richardson scheme results " << endl;
	fe << "This is the Richardson scheme error results." << endl;
	for (int i = 1; i < rows; i++)
	{
		PrePreviousArray = PreviousArray;
		PreviousArray = CurrentArray;
		for (int j = 1; j < cols - 1; j++) {
			CurrentArray[j] = 2 * R * (PreviousArray[j + 1] - 2*PreviousArray[j] + PreviousArray[j - 1]) + PrePreviousArray[j];
			fs << CurrentArray[j] << ",";
			cout<< CurrentArray[j] << ",";
			double Temp = 0.;
			for (int m = 1; m < M + 1; m++)
			{
				Temp += exp(-D * (m * M_P / L) * (m * M_P / L) *
					i * deltaT) * ((1 - pow(-1, m)) /
						(m * M_P)) * sin(m * M_P * j * deltaX / L);

			}
			Exact_results[j] = Tsur + 2 * (Tin - Tsur) * Temp;
			fe << Exact_results[j] - CurrentArray[j] << ",";
		}
		cout << endl;
		fs << endl;
		fe << endl;
	}
}

