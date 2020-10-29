#include <iostream>

using namespace std;

int n, m, i, j, a[200][200], x, y,b=1,viz[200];

void cg()
{
    //n-varfuri
    //m-muchii
    cout << "Cititi n:";
    cin >> n;
    cout << "Cititi m:";
    cin >> m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            a[i][j] = 0;
    for (i = 1; i <= m; i++)
    {
        cout << "Dati extremitatile muchiei" << i << " ";
        do
        {
            cin >> x >> y;
        } while (x <= 0 || y <= 0 || x > n || y > n);
        a[x][y] = 1;
        a[y][x] = 1;
    }
}

void afisare()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void BF(int start)
{
   int c[20], v[20],pi,ps,k;
   for(int i=1;i<=20;i++)
     c[i]=0;
   for(int i=1;i<=20;i++)
     v[i]=0;

   ps=pi=1;
   c[pi]=start;
   v[start]=1;
   while(ps<=pi)
   {
    k=c[ps];
    for(int i=1;i<=n;i++)
      if(v[i]==0 && a[k][i]==1)
      {
        pi++;
        c[pi]=i;
        v[i]=1;
      }
    ps++;
  }
  for(int i=1;i<=n;i++)
    cout<<c[i]<<" ";
}

void DF(int k)
{
    int i;
    viz[k]=1;
    cout<<k<<" ";
    for(i=1;i<=n;i++)
        if(a[k][i]==1 && viz[i]==0)
    DF(i);
}



void DFBF()
{
    for(int i=1;i<=n;i++)
    {
        cout<<"BF("<<i<<")= ";
        BF(i);
        cout<<endl;
    }
    for(int j=1;j<=n;j++)
    {
        cout<<"DF("<<j<<")= ";
        DF(j);
        cout<<endl;
    }
}

int main()
{
    cg();
    afisare();
    cout<<endl;
    DFBF();
    return 0;
}
