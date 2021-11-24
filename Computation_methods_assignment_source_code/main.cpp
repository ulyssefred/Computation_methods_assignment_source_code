///////////////
////main.cpp///
///////////////

#include "DFF.h"
#include "RCC.h"
#include "LFC.h"
#include "CNT.h"

/**
 * @file main.cpp
 * @brief Program function test file
 * @email W.Xiao@cranfield.ac.uk
 * @author Xiao Wen
 * @date 2021-11-24
 */
int main()
{
	DFF test1;
	RCC test2;
	LFC test3;
	CNT test4;
	//Rerults display test
	test1.ResultsOutput();
	test2.ResultsOutput();
	//Input four different DeltaT
	for(int i =0; i<4; i++) 
		test3.ResultsOutput();
	test4.ResultsOutput();
}