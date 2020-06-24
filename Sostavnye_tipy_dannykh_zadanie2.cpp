#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>

using namespace std;

void CompressStr(char* m)
{
	char i = 0, p, z, h;
	while (i < 20)
	{
		p = 0;
		while ((i < 19) && m[i] == m[i + 1])
		{
			p++; i++;
		}
		if (p > 2) {
			z = i - (p - 1);
			m[z] = '{'; z++;
			m[z] = '0' + p + 1; z++;
			m[z] = '}'; h = z; z++;

			if (p > 3)
			{
				i++;
				while (i < 20)
				{
					m[z] = m[i]; z++; i++;
				}
				m[z] = '\0';
			}
			i = h;
		}
		i++;
	}
}

int main() {
	char a[] = "bbbccccce";
	char b[] = "bbbbaaaae";
	char c[] = "bbbdddeee";
	char d[] = "aaaaaaaabbbbcccc";
	char e[] = "aabbbcccc";


	CompressStr(a);
	CompressStr(b);
	CompressStr(c);
	CompressStr(d);
	CompressStr(e);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
	cout << "e: " << e << endl;

	return 0;
}
