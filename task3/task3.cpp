#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

vector <int> to1d(vector <vector <int> > matrix, int m, int n) {
    vector <int> ans(m * n);
    vector <vector <int> >::iterator it1;
    vector <int>::iterator it2;
    vector <int>::iterator it3 = ans.begin();
    for (it1 = matrix.begin(); it1 != matrix.end(); it1++) {
        for (it2 = (*it1).begin(); it2 != (*it1).end(); it2++) {
            *it3 = *it2;
            it3++;
        }
    }
    return ans;
}

vector <vector<int> > to2d(vector <int> array1d, int m, int n) {
    vector < vector <int> > matrix(m, vector <int>(n));
    vector <vector <int> >::iterator it1 = matrix.begin();
    vector <int>::iterator it2 = (*it1).begin();
    for (vector<int>::iterator it = array1d.begin(); it != array1d.end(); it++) {
        if ((it - array1d.begin()) % n == 0 && it - array1d.begin() != 0) {
            it1++;
            it2 = (*it1).begin();
        }
        *it2 = *it;
        it2++;
    }
    return matrix;
}

int main()
{
    int rows, cols;
    cout << "Rows: ";
    cin >> rows;
    cout << "Cols: ";
    cin >> cols;
    vector < vector <int> > matrix(rows, vector <int>(cols));
    vector <int> ans(rows * cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "1D transformation:\n";
    ans = to1d(matrix, rows, cols);
    for (vector <int>::iterator it = ans.begin(); it != ans.end(); it++)
        cout << (*it) << ' ';
    vector<vector <int> > array2d;
    cout << "\n2D transformation:\n";
    array2d = to2d(ans, rows, cols);
    for (vector<vector<int> >::iterator it1 = array2d.begin(); it1 != array2d.end(); it1++) {
        for (vector<int>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
            cout << (*it2) << ' ';
        cout << '\n';
    }
    return 0;
}
