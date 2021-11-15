#include "DF.h"
#include "RD.h"
#include "LSI.h"
#include "CN.h"

#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;
int main() {
    plt::plot({ 1,3,2,4 });
    plt::show();
}
//int main()
//{
//	DF test;
//	test.SetValue();
//	test.GetError();
//	LSI test2;
//	test2.SetValue();
//	test2.GetError();
//
//}