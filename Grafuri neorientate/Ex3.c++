#include <iostream>
#include <fstream>
using namespace std;

void citire(int a[][100],int &n, int &m)
{
    ifstream f("graf.txt");
    f>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
    f>>a[i][j];
    f.close();
}
void citire2(int b[][100],int &n2, int &m2)
{
    ifstream f("graf-prim.txt");
    f>>n2>>m2;
    for(int i=1; i<=n2; i++)
        for(int j=1; j<=n2; j++)
    f>>b[i][j];
    f.close();
}
void citire3(int c[][100],int &n, int &m)
{
    ifstream f("graf-complet.txt");
    f>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
    f>>c[i][j];
    f.close();
}

void afisare(int a[100][100],int n, int m)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}


void afisare2(int b[100][100],int n2, int m2)
{
    for(int i=1; i<=n2; i++)
    {
        for(int j=1; j<=n2; j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
}
void afisare3(int c[100][100],int n2, int m2)
{
    for(int i=1; i<=n2; i++)
    {
        for(int j=1; j<=n2; j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }
}

void subgraf(int a[100][100],int b[100][100], int n,int m,int n2 ,int m2)
{

    if(n2<n)
    {
        int ok1=1;

        for(int i=1; i<=n2; i++)
            if(b[i][i]==1)
            ok1=0;
            int ok2=1;
        for(int i=1; i<=n2; i++)
            for(int j=1; j<=n2; j++)
                if(b[i][j]!=b[j][i])
        {
            ok2=0;
            break;
        }
        if(ok1==1 && ok2==1)
            {
                cout<<"da"<<endl;
            }
        else
           {
               cout<<"nu"<<endl;
           }
    }
}

void grafpartial(int A[][100], int B[][100], int n1, int m1, int n2, int m2)
{
    if(m2<m1)
    {
        int ok1=1;
        for(int i=1; i<=n2; i++)
            if(B[i][i]==1)
                ok1=0;
        int ok2=1;
        for(int i=1; i<=n2; i++)
            for(int j=1; j<=n2; j++)
                if(B[i][j]!=B[j][i])
                    ok2=0;
        if(ok1==1 && ok2==1)
            cout<<"da"<<endl;
        else
            cout<<"nu"<<endl;
    }
}
void grafcomplet(int A[10][10], int n, int m)
{
    cout<<endl;
    int ok1=1,ok2;
    for(int i=1; i<=n; i++)
        if(A[i][i]==1)
            {ok1=0;break;}


    ok2=1;
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            if(A[i][j]==0)
                {ok2=0;break;}

    if(ok1==1&&ok2==1)
        cout<<"!!Este graf complet";
    else
        cout<<"NU este graf complet";


}

/*
void grafcomplet(int a[][100], int &n, int &m)
{
    {
    if(m==n*(n-1)/2)
            cout<<"Graful este complet";
    else
            cout<<"Graful nu este complet";
        cout<<endl;
    }
}
/*
void grafcomplet(int a[][100], int &n, int &m)
{
        int ok=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            if(a[i][i]==0 && a[i][j]==1)
            {
                ok =1;
            }
            else
            {
                ok=0;
                break;
            }
        }
    if(ok==1)
        cout<<"Este graf complet";
    else
        cout<<"Nu este graf complet";
}*//*
void grafcomplet(int a[100][100], int n, int m)
{
    int ok=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            if(m==2*n)
                ok=1;
        }
    if(ok==1)
        cout<<"Este graf complet";
    else
        cout<<"Nu este graf complet";


}*/

int totEdge(int n)
{
    int result = 0;

    result = (n * (n - 1)) / 2;

    return result;
}

void pbf(int a[100][100], int n, int x)
{
    int c[50], viz[50], i, p, u, v;
    for(i=1;i<=n;i++)
    viz[i]=0;
    viz[x]=1;c[1]=x;
    p=1;u=1;
    while(p<=u)
    {
        v=c[p++];
        for(i=1;i<=n;i++)
            if(a[v][i]==1 && viz[i]==0)
            {
                c[++u]=i;
                viz[i]=1;
            }
    }
    for(i=1;i<=u;i++)
        cout<<c[i]<<" ";
}

int main()
{
    int a[100][100],b[100][100],c[100][100],n,m,n2,m2,n1,m1,x=1;
    citire(a,n,m);
    citire2(b,n2,m2);
    citire3(c,n1,m1);
    afisare(a,n,m);
    cout<<endl;
    afisare2(b,n2,m2);
    cout<<endl;
    afisare3(c,n1,m1);
    cout<<endl;
    subgraf(a,b,n,m,n2,m2);
    cout<<endl;
    grafpartial(a, b, n,m, n2, m2);
    grafcomplet(c,n1,m1);
    cout<<endl;
    /*cout<<"Cititi nodul-start: ";cin>>x;*/
    pbf(a,n,x);
    /*
    totEdge
    int n = 6;

    cout << totEdge(n);
*/
    return 0;
}
