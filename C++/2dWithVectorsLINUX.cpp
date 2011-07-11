#include <iostream>
#include <vector>
#include <sys/time.h>
#include <stdlib.h>

using namespace std;

void manipulateVector(vector< vector<int> > &matrix, int rows, int cols)
{
    srand ( time(NULL) );

    for (int i = 0;  i < rows; i++)
       {
          for ( int j = 0; j < cols; j++)
          {
              matrix[i][j] = rand() % (rand() % 7 +3);
              cout << matrix[i][j];
          }
          cout << endl;
       }
}

int main(int argc, char *argv[])
{
    char buffer[256];
    int rows, cols;
    cout << "\nEnter number of rows:  ";
    cin >> buffer;
    rows = atoi(buffer);
    cout << "\nEnter number of cols: ";
    cin >> buffer;
    cols = atoi(buffer);

    vector<int> vcols;
    vcols.resize(cols);
    vector< vector<int> > matrix(rows,vcols);

    manipulateVector(matrix, rows, cols);

    return 0;
}
