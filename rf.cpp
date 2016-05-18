//http://www.infoarena.ro/problema/rf

#include <stdio.h>

int d[256][256];
int mr[256][256];

int main()
{
    freopen("rf.in", "r", stdin);
    freopen("rf.out", "w", stdout);
    //ifstream in("rf.in");
    //ofstream out("rf.out");

    int n;
  //  in >> n;
  scanf("%d", &n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
         //   in >> d[i][j];
            scanf("%d", &d[i][j]);
            mr[i][j] = ((i!=j)?1:0);
        }
    }

    for(int k=0;k<n;++k)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i!=j && d[i][k] + d[k][j] == d[i][j])
                {
                    if(mr[i][j] < mr[i][k] + mr[k][j])
                        mr[i][j] = mr[i][k] + mr[k][j];
                }
                if(i!=j && d[i][k] > 0 && d[k][j] > 0 && (d[i][k] + d[k][j] < d[i][j] || d[i][j] == 0))
                {
                    d[i][j] = d[i][k] + d[k][j];
                    mr[i][j] = mr[i][k] + mr[k][j];
                }
            }
        }
    }

    //print(n,d,out);
    //print(n,mr,out);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            //out << d[i][j] << " ";
            printf("%d ", d[i][j]);
        }
        //out << "\n";
        printf("\n");
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            //out << mr[i][j] << " ";
            printf("%d ", mr[i][j]);
        }
        //out << "\n";
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
