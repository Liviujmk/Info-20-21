#include <iostream>
#include <fstream>

using namespace std;

ifstream f("muchii.txt");

int a[100][100], m, n, x, y;

void citire()
{
    f>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            a[i][j]=0;
    f>>m;
    for(int k=1; k<=m; k++)
    {
        f>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }
}

void afisare()
{
    int ok=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
        if(a[i][i]!=0)
            ok=0;
    }
    cout<<endl;
    if(ok=1)
        cout<<"Matricea de adiacenta este matrice pentru graf neorientat";
    else
        cout<<"Matricea de adiacenta nu este matrice pentru graf neorientat";
}

int grad(int x)
{
    int grad=0;

    for(int j=1; j<=n; j++)
        if(a[x][j]==1)
            grad++;
    return grad;
}

void noduri_izolate()
{
    int nr_i=0;
    for(int i=1; i<=n; i++)
        if(grad(i)==0)
            nr_i++;
    cout<<"Numarul nodurilor izolate este: "<<nr_i<<endl;
}


void noduri_terminale()
{
    int nr_t=0;
    for(int i=0;i<=n;i++)
        if(grad(i)==1)
            nr_t++;
    cout<<"Numarul nodurilor terminale este: "<<nr_t<<endl;
}

void vecini(int y)
{
    for(int j=1;j<=n;j++)
        if(a[y][j]!=0)
        cout<<j<<" ";

}



int main()
{
    citire();
    afisare();
    cout<<endl;
    cout<<"Nodul pentru care vreti sa aflati gradul este: ";
    cin>>x;
    cout<<grad(x);
    cout<<endl;
    noduri_izolate();
    cout<<endl;
    noduri_terminale();
    cout<<endl;
    cin>>y;
    vecini(y);
    return 0;
}

