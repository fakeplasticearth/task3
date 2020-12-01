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
			bool flag = 1;

			if (test_array.size() != m * n)
				flag = 0;
			for (int i = 0; i < m * n; i++)
				if (true_array[i] != test_array[i])
					flag = 0;
			Assert::IsTrue(flag);
		}

		TEST_METHOD(TestMethod2)
		{
			int m = 2;
			int n = 5;
			vector <int> test_array = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			vector <vector<int> > true_matrix = { {1, 2, 3, 4, 5},{6, 7, 8, 9, 10} };
			vector< vector<int> > test_matrix = to2d(test_array, m, n);

			bool flag = 1;
			
			if (test_matrix.size() != m)
				flag = 0;
			if (flag) {
				for (vector<vector<int> >::iterator it = test_matrix.begin(); it != test_matrix.end(); it++) {
					if ((*it).size() != n) {
						flag = 0;
						break;
					}
				}
			}
			if (flag) {
				for (int i = 0; i < m; i++) {
					for (int j = 0;j < n;j++)
						if (test_matrix[i][j] != true_matrix[i][j]) {
							flag = 0;
							break;
						}
				}
			}
			Assert::IsTrue(flag);
		}
	};
}
