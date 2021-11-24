//////////////
////DFF.cpp///
//////////////
#include "DFF.h"

/**
 * @brief Compute and output DFF scheme method results and error results to error.csv and results csv file, 
 * and display the results on terminal
 * @return void
 */
void DFF::ResultsOutput()
{
	InitialArray = MatrixInitial();
	PreviousArray = PrePreviousArray;
	CurrentArray = InitialArray;
	ofstream fs,fe;
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
	cout << "This is the DuFort-Frankel scheme results " << endl;
	fs << "This is the DuFort-Frankel scheme results " << endl;
	fe << "This is the DuFort-Frankel scheme error results." << endl;
	for (int i = 1; i < rows; i++)
	{
		PrePreviousArray = PreviousArray;
		PreviousArray = CurrentArray;
		for (int j = 1; j < cols - 1; j++) {
			/// <summary>
			/// Compute scheme methods results
			/// </summary>
			CurrentArray[j] = (PrePreviousArray[j] +
				2 * R * (PreviousArray[j + 1] - PrePreviousArray[j] + PreviousArray[j - 1]))
				/ (1 + 2 * R);
			if (int(i * deltaT * 100) % 10 == 0) {
				fs << CurrentArray[j] << ",";
				cout << CurrentArray[j] << ",";
				double Temp = 0.;
				/// <summary>
				/// compute current analytical solution results
				/// </summary>
				for (int m = 1; m < M + 1; m++)
				{
					Temp += exp(-D * (m * M_P / L) * (m * M_P / L) *
						i * deltaT) * ((1 - pow(-1, m)) /
							(m * M_P)) * sin(m * M_P * j * deltaX / L);

				}
				Exact_results[j] = Tsur + 2 * (Tin - Tsur) * Temp;
				fe << Exact_results[j] - CurrentArray[j] << ",";
			}
			
		}
		if (int(i * deltaT * 100) % 10 == 0) {
			cout << endl;
			fs << endl;
			fe << endl;
		}
			
	}
	fs.close();
	fe.close();
}




