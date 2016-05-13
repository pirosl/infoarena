// http://www.infoarena.ro/problema/royfloyd

#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char* argv[]) 
{
	ifstream in("royfloyd.in");
	ofstream out("royfloyd.out");
	int n;
	in >> n;
	int* d = new int[n*n];
	for(int i = 0; i < n; ++i) 
	{
		for(int j = 0; j < n; ++j)
		{
			in >> d[i * n + j];
		}
	}

	for(int k = 0; k < n; ++k) 
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(i != j && d[i * n + k] > 0 && d[k * n + j] > 0 && 
					(d[i * n + k] + d[k * n + j] < d[i * n + j] || d[i * n + j] == 0))
					d[i * n + j] = d[i * n + k] + d[k * n + j];	
			}
		}
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			out << d[i * n + j] << " ";
		}
		out << "\n";
	}
	return 0;
}
