#include <iostream>
#include <fstream>

using namespace std;

int a[100][100], n, m, k, i, j,p[100],g[100];

void citire()
{
    ifstream f("gl.txt");
    f>>n;
    f>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            a[i][j]=0;
    for(k=1; k<=m; k++)
    {
        f>>i>>j;
        a[i][j]=1;
        a[j][i]=a[i][j];
    }
}

void afisare()
{
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

int verificareCiclu()
{
    ifstream c("ciclu.txt");
    int k, v[100];
    c>>k;
    for(i=1; i<=k; i++)
        c>>v[i];
    int ok=1;
    for(i=1; i<=k-1; i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok=0;
    }
    if(v[1]!=v[k])
    {
        ok=0;
    }
    return ok;
    c.close();
}

int verificareCiclu2()
{
    ifstream e("cicluE.txt");
    int k, v[100], ok3;
    e>>k;
    for(i=1; i<=k; i++)
        e>>v[i];
    int ok=1;
    for(i=1; i<=k-1; i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok=0;
    }
    if(v[1]!=v[k])
    {
        ok=0;
    }
    return ok;
    int ok2=1;
    for(int i=1; i<=k-1; i++)
        for(int j=i+1; j<=k; j++)
            if(v[i]==v[j])
                ok2=0;
    return ok2;

    if(ok=1 && ok2==1)
        ok3=1;
    else
        ok3=0;
}

int ciclupar()
{
    ifstream p("cicluP.txt");
    int k, v[100];
    p>>k;
    for(i=1; i<=k; i++)
        p>>v[i];
    int ok=1;
    for(i=1; i<=k-1; i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok=0;
    }
    if(v[1]!=v[k])
    {
        ok=0;
    }
    if(k>=4 && k%2==1)
        return 1;
    return 0;
    p.close();
}

int cicluhamiltonian()
{
    ifstream h("ham.txt");
    int k, v[100],n;
    h>>k;
    for(i=1; i<=k; i++)
        h>>v[i];
    int ok=1;
    for(i=1; i<=k-1; i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok=0;
    }
    if(v[1]!=v[k])
    {
        ok=0;
    }
    if(i==k)
        return 1;
    return 0;
    h.close();
}


int main()
{
    citire();
    cout<<endl;
    cout<<"Matricea de adiacenta este: "<<endl;
    afisare();
    cout<<endl;
    if(verificareCiclu()==1)
        cout<<"Este ciclu";
    else
        cout<<"Nu este ciclu";
    cout <<endl;

    if(verificareCiclu()==1)
        if(verificareCiclu2()==1)
            cout<<"Ciclu elementar";
        else
            cout<<"Ciclu neelementar";
    cout<<endl;

    if(ciclupar()==1)
        cout<<"Da";
    else
        cout<<"Nu";
    cout<<endl;

    if(cicluhamiltonian()==1)
        cout<<"Da";
    else
        cout<<"Nu";


    return 0;
}

