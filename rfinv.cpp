// http://www.infoarena.ro/problema/rfinv

#include <fstream>
using namespace std;

int se[1300];
int ee[1300];
int d[50][50];
int rd[50][50];
int n,m;
	
bool equal()
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			if(d[i][j] != rd[i][j])
				return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	ifstream in("rfinv.in");
	ofstream out("rfinv.out");

	int t;
	in >> t;

	while(t--)
	{
		in >> n >> m;
		for(int i=0;i<m;++i)
		{
			int a,b;
			in >> a;
			in >> b;
			se[i] = a-1;
			ee[i] = b-1;
		}
		for(int i=0;i<n;++i)
		{
			for(int j=0; j<n; ++j)
			{	
				in >> rd[i][j];
				d[i][j] = 0;
			}
		}

		for(int i=0; i<m;++i) 
		{
			d[se[i]][ee[i]] = rd[se[i]][ee[i]];
			d[ee[i]][se[i]] = rd[ee[i]][se[i]];	
		}

		for(int k=0;k<n;++k)
		{
			for(int i=0;i<n;++i)
			{
				for(int j=0;j<n;++j)
				{
					if(i!=j && d[i][k] != 0 && d[k][j] != 0
						&& (d[i][k] + d[k][j] < d[i][j] || d[i][j] == 0))
					{
						d[i][j] = d[i][k] + d[k][j];
					}
				}
			}
		}

		if(equal())
			out << "DA\n";
		else
			out << "NU\n";

	}
	return 0;
}
