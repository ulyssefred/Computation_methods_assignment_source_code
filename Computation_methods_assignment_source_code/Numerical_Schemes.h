////////////////////////
//Numerical_Schemes.h///
////////////////////////

#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <fstream>
/// Pi value define
#define M_P 3.14159265358979323846
using namespace std;

/**
 * @file Numerical_Schemes.h
 * @brief Abstruct Class, provides public parameters and methods
 * @author Xiao Wen
 */


 /**
 * @brief Abstruct Class, provides public parameters and methods
 * 1.Provide Tin, Tsur, D, M, PT(Temperature before time 0)
 * 2.Provide MatrixInitial function (Initialize vector value when time = 0)
 * 3.Provide thomas_algorithm function 
 * 4.Provide virtual function (ResultsOutput())
 */
class Numerical_Schemes
{	
public:
	/// <summary>
	/// Set Tin = 100.0
	/// </summary>
	const double Tin = 100.;
	/// <summary>
	/// Set Tsur = 300.0
	/// </summary>
	const double Tsur = 300.;
	/// <summary>
	/// Set D = 0.1
	/// </summary>
	const double D = 0.1;
	/// <summary>
	/// Set m = 2000
	/// </summary>
	const int M = 2000;
	double L = 1.;
	double T = 0.5;
	double deltaT = 0.05;
	double deltaX = 0.01;
	/// <summary>
	/// Set Temperature(PT) before time 0, PT=100.0
	/// </summary>
	const double PT = 100.;
	double R;
	int cols;
	int rows;
	/// <summary>
	/// vector(time = 0)
	/// </summary>
	vector<double> InitialArray;
	/// <summary>
	/// vector(time = n -1
	/// </summary>
	vector<double> PreviousArray;
	/// <summary>
	/// vector(time = n-2
	/// </summary>
	vector<double> PrePreviousArray;
	/// <summary>
	/// vector(need to be computed now)
	/// </summary>
	vector<double> CurrentArray;
	/// <summary>
	/// Analytical solution results
	/// </summary>
	vector<double> Exact_results;
	vector<double> MatrixInitial(double deltax = 0.05, double deltat = 0.01);
	vector<double>thomas_algorithm(vector<double> a, vector<double> b,
		vector<double> c, int n, vector<double>d);
	virtual void ResultsOutput() = 0;
};

