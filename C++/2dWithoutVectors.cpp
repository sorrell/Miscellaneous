#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

void manipulateMatrix(double **matrix, int rows, int cols)
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

    /* Here, we declare matrix to be a pointer to a pointer to an dbl - why is this?
     * Well, in C and C++, arrays and pointer share a lot in common.
     */
    double **matrix = 0;       // set it to null so there's no undefined behavior

    matrix = new double *[rows];    // each row item is a pointer to a column, or an array

    for (int i=0; i < rows; i++)
    {
        matrix[i] = new double [cols];  // each column is an array of indexes
    }

    manipulateMatrix(matrix, rows, cols);


    for (int i=0; i < rows; i++)        //free the memory
    {
        delete [] matrix[i];
    }
    delete [] matrix;

    return 0;
}
