#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

double s(const double x)
{
    if (abs(x) >= 1 || x == 0)
        return (pow(cos(x), 2) + 1) / exp(x);
    else
    {
        double S = 1;
        double a = 1;
        for (int k = 0; k <= 4; k++)
        {
            a *= pow(2 * x, 2 * k + 1) / (2 * k + 1);
            S += a / sin(2 * x);
        }
        return S;
    }
}

namespace UnitTest1
{
    TEST_CLASS(FunctionSTest)
    {
    public:

        TEST_METHOD(TestSForXGreaterThanOrEqualToOne)
        {
            double x = 1.5;
            double expected = (pow(cos(x), 2) + 1) / exp(x);
            double actual = s(x);
            Assert::AreEqual(expected, actual, 0.000001);
        }

        TEST_METHOD(TestSForXEqualToZero)
        {
            double x = 0;
            double expected = 2.0;
            double actual = s(x);
            Assert::AreEqual(expected, actual, 0.000001);
        }

        TEST_METHOD(TestSForXLessThanOne)
        {
            double x = 0.5;
            double expected = 1.0;
            double a = 1;
            for (int k = 0; k <= 4; k++)
            {
                a *= pow(2 * x, 2 * k + 1) / (2 * k + 1);
                expected += a / sin(2 * x);
            }
            double actual = s(x);
            Assert::AreEqual(expected, actual, 0.000001);
        }
    };
}