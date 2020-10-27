#include <iostream>

using namespace std;

int n, m, i, j, a[20][20], x, y,viz[100],b;

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
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void df(int k)
{
    viz[k]=1;
    cout<<k;
    for(i=1;i<=n;i++)
        if(a[k][i]==1)
            if(viz[i]==0)
                df(i);
}

int main()
{
    cg();
    afisare();
    cout<<endl;
    cout<<"Nodul de start pentru DF este: ";cin>>b;
    df(b);
    return 0;
}
