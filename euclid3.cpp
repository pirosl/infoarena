// http://www.infoarena.ro/problema/euclid3

#include <iostream>
#include <fstream>

using namespace std;

void cmmdc(int a, int b, int *d, int *x, int *y)
{
	if(a == 0)
	{
		*d = b;
		*x = 0;
		*y = 1;
		return;
	}
	if(b == 0)
	{
		*d = a;
		*x = 1;
		*y = 0;
		return;
	}

	int x0, y0;
	cmmdc(b, a % b, d, &x0, &y0);
	*x = y0;
	*y = x0 - (a/b)*y0; 
}

int main(int argc, char* argv[])
{
	ifstream in("euclid3.in");
	ofstream out("euclid3.out");
	int t;
	in >> t;
	while(t--) 
	{
		int a,b,c;
		in >> a >> b >> c;
		int x, y, d;
		cmmdc(a,b, &d, &x, &y);
		if(c % d != 0)
		{
			out << "0 0\n";
		}
		else
		{
			c /= d;
			out << x*c << " " << y*c << "\n";
		}
	}
	return 0;
}
