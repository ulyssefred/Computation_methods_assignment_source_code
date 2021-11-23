#include "DFF.h"
#include "RCC.h"
#include "LFC.h"
#include "CNT.h"

int main()
{
	DFF test1;
	RCC test2;
	LFC test3;
	CNT test4;
	//Rerults display test
	test1.ResultsOutput();
	test2.ResultsOutput();
	for(int i =0; i<4; i++) 
		test3.ResultsOutput();
	test4.ResultsOutput();
}