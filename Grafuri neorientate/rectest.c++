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
void afisare(int a[100][100],int n, int m)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
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

int main()
{
    int a[100][100],n,m;
    citire(a,n,m);
    afisare(a,n,m);
    cout<<endl;
    grafcomplet(a,n,m);
    return 0;
}


|
|
v
Constructie matrice, afisare grade, mat de adiacenta, v
^
|
|


#include <iostream>

using namespace std;

int n,m,i,j,a[10][10],d[20];

//citirea
void citire()
{
    int k;
    cout<<"Numarul de varfuri este: "<<endl;
    cin>>n;
    cout<<"Numarul de muchii este: "<<endl;
    cin>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            a[i][j]=0;

    for(k=1; k<=m; k++)
        d[k]=0;

    for(k=1; k<=m; k++)
    {
        cout<<"Muchia "<<k<<" este: "<<endl;
        cin>>i>>j;
        a[i][j]=1;
        a[j][i]=1;
        d[i]++;
        d[j]++;
    }
}

//afisarea gradelor fiecarui varf
void afisare_vector_grade()
{
    cout<<"Vectorul gradelor este:";
    for(i=1; i<=n; i++)
        cout<<d[i]<<" ";
    cout<<endl;
}

//afisarea matricii de adiacenta
void afisare_matrice()
{
    cout<<"Matricea de adiacenta este:";
    cout<<endl;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

//gradul maxim
int grad_max()
{
    int max;
    max=d[1];
    for(i=2; i<=n; i++)
        if(d[i]>max)
            max=d[i];
    return max;
}

//afisarea varfului care are gradul maxim
void afisare_grad_max()
{
    int k;
    cout<<"Varful care are gradul maxim este: "<<endl;
    for(k=1; k<=n; k++)
        if(d[k]==grad_max())
            cout<<k<<" "<<endl;
}

int grad(int x)
{
    int grad=0;
    for(j=1; j<=n; j++)
        if(a[x][j]==1)
            grad++;
    return grad;
}

//afisarea numarului nodurilor izolate
void noduri_izolate()
{
    int nr=0;
    for(i=1; i<=n; i++)
        if(grad(i)==0)
            nr++;
    cout<<"Numarul nodurilor izolate este"<<" "<<nr<<endl;
}

int main()
{
    citire();
    cout<<endl;
    afisare_vector_grade();
    cout<<endl;
    afisare_matrice();
    cout<<endl;
    cout<<"Gradul maxim este:"<<grad_max();
    cout<<endl;
    afisare_grad_max();
    cout<<endl;
    noduri_izolate();
    cout<<endl;
    return 0;
}






//problema cu subgraf si graf partial si parcurgerea BF si cu switch
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

void parcurgere_bf(int a[100][100], int n, int x)
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
    int problema, a[100][100],b[100][100],c[100][100],n,m,n2,m2,n1,m1,x=1;;
    do
    {
        cout<<"alegeti o problema:"<<" ";
        cin>>problema;
        cout<<endl;
    switch(problema)
    {
        case 1:
            cout<<"afisarea matricei grafului 1: "<<endl;
            citire(a,n,m);
            afisare(a,n,m);
            cout<<endl;
            cout<<"afisarea matricei grafului 2: "<<endl;
            citire2(b,n2,m2);
            afisare2(b,n2,m2);
            cout<<endl;
        break;

        case 2:
            cout<<endl;
            subgraf(a,b,n,m,n2,m2);
            cout<<endl;
        break;

        case 3:
            grafpartial(a, b, n,m, n2, m2);
            cout<<endl;
        break;

        case 4:
            cout<<"parcurgerea pe latime incepand cu nodul x: ";
            parcurgere_bf(a,n,x);
        break;

        case 5:
            cout<<endl;
            grafcomplet(a,n,m);
            cout<<endl;
        break;


        default:
            cout<< 0;
    }

    }
    while(problema!=8);
    return 0;


}
