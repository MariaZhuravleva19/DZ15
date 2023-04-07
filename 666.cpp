#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream inp;
	inp.open("666(input).txt");
	fstream out;
	out.open("666(output).txt");

	int n;
	inp >> n;


	for (int i = 26; i >= 1; i--)
	{
		int half = (1 << (i - 1)) - 1;

		if (n == 1)
		{
			out << char('a' + i - 1);
			return 0;
		}
		else
		{
			if (n <= 1 + half)
				n--;

			else
				n -= 1 + half;
		}

	}

	inp.close();
	out.close();
}