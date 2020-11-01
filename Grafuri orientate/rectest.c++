#include <iostream>
#include <fstream>

using namespace std;

int a[100][100], n, m, i, j, k, nr, x;

void citire_arce()
{
    ifstream f("arce.txt");
    int i, j;
    f>>n>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            a[i][j]=0;
        }
    for(k=1; k<=m; k++)
    {
        f>>i>>j;
        a[i][j]=1;
    }
}

void citire_matrice()
{
    ifstream f("matrice.txt");
    f>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            f>>a[i][j];
}

void afisare()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

int grad_exterior(int x)
{
    int nr=0;
    for(int j=1; j<=n; j++)
        if(a[x][j]==1)
        {
            nr++;
        }
    return nr;
}

int grad_interior(int x)
{
    int nr=0;
    for(int i=1; i<=n; i++)
        if(a[i][x]==1)
        {
            nr++;
        }
    return nr;
}

void arce_out(int x)
{
    for(int j=1; j<=n; j++)
        if(a[x][j]==1)
        {
            cout<<"("<<x<<","<<j<<")"<<" ";
        }
}

void arce_in(int x)
{
    for(int i=1; i<=n; i++)
        if(a[i][x]==1)
        {
            cout<<"("<<i<<","<<x<<")"<<" ";
        }
}

void succesori(int x)
{
   for(int j=1;j<=n;j++)
   {
       if(a[x][j]==1)
        cout<<j<<" ";

   }
}

void predecesori(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i][x]==1)
            cout<<i<<" ";
    }
}

void toate_gi_ge()
{
    for(i=1;i<=n;i++)
    {
        cout<<"D+("<<i<<"): "<<grad_exterior(i)<<"   ";
        cout<<"D-("<<i<<"): "<<grad_interior(i)<<"   ";
        cout<<endl;
    }
}

void toate_arcele()
{
    for(i=1;i<=n;i++)
    {
        cout<<"Arcul "<<i<<"+: ";arce_out(i);cout<<"   ";
        cout<<endl;
        cout<<"Arcul "<<i<<"-: ";arce_in(i);cout<<"   ";
        cout<<endl;
    }
}



int main()
{
    citire_arce();
    cout<<endl;
    cout<<"Matricea de adiacenta este: "<<endl;
    cout<<"\n";
    afisare();

    cout<<endl;
    cout<<"Dati nodul pentru care vreti sa aflat gradul: ";
    cin>>x;
    cout<<endl;

    cout<<"Gradul exterior al nodului "<<x<<" este: ";
    cout<<grad_exterior(x);
    cout<<endl;
    cout<<"Gradul interior al nodului "<<x<<" este: ";
    cout<<grad_interior(x);
    cout<<endl;
    cout<<"\n";
    cout<<"Multimea arcelor ce ies din "<<x<<" este: ";
    arce_out(x);
    cout<<endl;
    cout<<"Multimea arcelor ce intra in "<<x<<" este: ";
    arce_in(x);
    cout<<endl;
    cout<<"\n";

    cout<<"Multimea succesorilor nodului "<<x<<" este: ";
    succesori(x);
    cout<<endl;
    cout<<"Multimea predecesorilor nodului "<<x<<" este: ";
    predecesori(x);
    cout<<endl;
    cout<<"\n";

    toate_gi_ge();
    cout<<endl;
    toate_arcele();

    return 0;
}
