#include "pch.h"
#include "CppUnitTest.h"
#include "../task3/task3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int m = 2;
			int n = 3;
			vector<vector<int> > test_matrix_ex;
			vector <int> row1 = { 1, 2, 3 };
			test_matrix_ex.push_back(row1);
			vector <int> row2 = { 4, 5, 6 };
			test_matrix_ex.push_back(row2);
			vector <int> test_array;
			test_array = to1d(test_matrix_ex, m, n);
			vector <int> true_array = { 1, 2, 3, 4, 5, 6 };
			
			Assert::IsTrue(true_array == test_array);
		}

		TEST_METHOD(TestMethod2)
		{
			int m = 2;
			int n = 5;
			vector <int> test_array = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			vector <vector<int> > true_matrix = { {1, 2, 3, 4, 5},{6, 7, 8, 9, 10} };
			vector< vector<int> > test_matrix = to2d(test_array, m, n);

			Assert::IsTrue(test_matrix == true_matrix);
		}
	};
}
