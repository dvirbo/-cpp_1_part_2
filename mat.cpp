#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include "mat.hpp"
#include <vector>


using namespace std;
using namespace ariel;
/*
This method check if the components of the mat are valid by defenition
return "Good input" if the data is valid, else- return the correct message 
 */
string check_validity(int col, int row, char a, char b)
{
    string ans = "Good input";

    if (col % 2 == 0 || row % 2 == 0)
    {
        return "Mat size is always odd";
    }

    if (col < 0)
    {
        return "column num is negetive-must be positive";
    }

    if (row < 0)
    {
        return "row num is negetive-must be positive";
    }
    return ans;
}
/*
this method fill the matrix in a way that similar to spiral form
for more info: https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
*/
string fill(int row, int col, char a, char b)
{

    int i = 0;
    int j = 0;   
    int sRow = 0; // starting row index
    int sCol = 0; // starting column index

    // Store given number of rows and columns for the printing:
    int tRow = row; // temp val that contain row num 
    int tCol = col; // temp val that contain col num

    vector<vector<char>> vec( a , vector<char> (b)); 

    char sigh = a;    // init the char
    string str;         // the final string that we're return

    while (sRow < row && sCol < col)
    {
        // Fill the first row:
        for (i = sCol; i < col; i++)
        {
            vec[sRow][i] = sigh;
        }
        sRow++;

        // Fill the last column:
        for (i = sRow; i < row; i++)
        {
            vec[i][col - 1] = sigh;
        }
        col--;

        // Fill the last row:
        if (sRow < row)
        {
            for (i = col - 1; i >= sCol; i--)
            {
                vec[row - 1][i] = sigh;
            }
            row--;
        }

        // Fill the first column:
        if (sCol < col)
        {
            for (i = row - 1; i >= sRow; i--)
            {
                vec[i][sCol] = sigh;
            }
            sCol++;
        }

        // change the char for next iteration:

        sigh = (sigh == b) ? a : b;
    }
    // create the string of the mat
    for (i = 0; i < tRow; i++)
    {
        for (j = 0; j < tCol; j++)
        {
            str += vec[i][j];
        }
        str += '\n';
    }
    return str;
}

namespace ariel
{

    string mat(int col, int row, char a, char b)
    {
        string check = check_validity(col, row, a, b);
        if (check != "Good input")
        {
            throw invalid_argument(check);
        }
        string ans = fill(row, col, a, b);
        return ans;
    }

}