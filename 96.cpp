#include <iostream>
#include <fstream>

using namespace std;



int main()
{
    fstream input;
    input.open("96(input).txt");
    fstream output;
    output.open("96(output).txt");


    int n, m, x, y;
    input >> n >> m >> x >> y;



    int** field = new int* [n];
    for (int i = 0; i < n; i++)
        field[i] = new int[m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            field[i][j] = 1;
        }
    }

    x -= 1;
    y -= 1;
    int i = 0, j = 0;
    int direct = 1;
    int sum = 0;

    while (i >= 0 && i < n && j >= 0 && j < m && field[i][j] != 0)
    {

        sum += field[i][j];

        if (i == x && j == y)
            break;


        if (direct == 1) {
            if (j == m - 1 || field[i][j + 1] == 0)
            {
                field[i][j] = 0;
                direct = 2;
                i++;
            }
            else {
                field[i][j] = 0;
                j++;
            }
        }
        else if (direct == 2)
        {
            if (i == n - 1 || field[i + 1][j] == 0)
            {
                field[i][j] = 0;
                direct = 3;
                j--;
            }
            else {
                field[i][j] = 0;
                i++;
            }
        }
        else if (direct == 3)
        {
            if (j == 0 || field[i][j - 1] == 0) {
                field[i][j] = 0;
                direct = 4;
                i--;
            }
            else
            {
                field[i][j] = 0;
                j--;
            }
        }
        else if (direct == 4)
        {
            if (i == 0 || field[i - 1][j] == 0)
            {
                field[i][j] = 0;
                direct = 1;
                j++;
            }
            else
            {
                field[i][j] = 0;
                i--;
            }
        }
    }

    output << sum << endl;

    input.close();
    output.close();

    return 0;
}