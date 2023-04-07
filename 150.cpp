#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    fstream input;
    input.open("150(input).txt");
    fstream output;
    output.open("150(output).txt");


    int n, s;
    input >> n >> s;

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            input >> matrix[i][j];
        }

    }


    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (i != s - 1 && matrix[s - 1][i])
            count++;
    }

    output << count << endl;

    input.close();
    output.close();

    return 0;
}
