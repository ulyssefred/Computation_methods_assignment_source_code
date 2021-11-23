#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <fstream>
#define M_P 3.14159265358979323846
using namespace std;
/**
 * @file example.c
 * @brief 文件简要说明
 *
 * 详细说明
 *
 * @author 作者信息
 */


class Numerical_Schemes
{	
public:
	const double Tin = 100.;
	const double Tsur = 300.;
	const double D = 0.1;
	const int M = 2000;
	double L = 1.;
	double T = 0.5;
	double deltaT = 0.05;
	double deltaX = 0.01;
	const double PT = 100.;
	double R;
	int cols;
	int rows;
	vector<double> InitialArray;
	vector<double> PreviousArray;
	vector<double> PrePreviousArray;
	vector<double> CurrentArray;
	vector<double> Exact_results;
	vector<double> MatrixInitial(double deltax = 0.05, double deltat = 0.01);
	vector<double>thomas_algorithm(vector<double> a, vector<double> b,
		vector<double> c, int n, vector<double>d);
	virtual void ResultsOutput() = 0;
};

