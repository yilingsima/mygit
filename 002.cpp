#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int lcs(int a[], int n)
{
    int b[10];
    b[0] = a[0];
    int maxn = b[0];
    for (int i = 1; i < n; i++)
    {
        if (b[i - 1] > 0)
        {
            b[i] = b[i - 1] + a[i];
        }
        else
        {
            b[i] = a[i];
        }
        if (b[i] > maxn)
        {
            maxn = b[i];
        }

    }
    return maxn;
}

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int arr[] = { -5,3,4,-2,10 };
            int n = 5;
            int k = lcs(arr, 5);
            Assert::AreEqual(k, 15);
		}
        TEST_METHOD(TestMethod2)
        {
            int arr[] = { 2,6,8,4,3 };
            int n = 5;
            int k = lcs(arr, 5);
            Assert::AreEqual(k, 23);
        }

	};
}
