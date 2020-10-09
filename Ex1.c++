#include <iostream>

using namespace std;

int n, m, i, j, a[20][20], x, y;

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

int sumagradelorsaunumaruldegradedepelinie(int l)
{
    int nr = 0;
    for (j = 1; j <= n; j++)
        if (a[l][j] == 1)
            nr++;
    return nr;
}

int sumagradelorsaunumaruldegradedepecoloana(int c)
{
    int nr1 = 0;
    for (i = 1; i <= n; i++)
        if (a[i][c] == 1)
            nr1++;
    return nr1;
}

int main()
{
    cg();
    afisare();
    cout << endl;
    cout << sumagradelorsaunumaruldegradedepelinie(3) << endl;
    cout << sumagradelorsaunumaruldegradedepecoloana(2) << endl;
    return 0;
}
