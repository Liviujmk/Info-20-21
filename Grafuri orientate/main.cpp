#include <iostream>
#include <fstream>
using namespace std;

int a[100][100],v[100],n,m,k,x,i,j,nc,problema;

void citire()
{
    cout<<"Dati nr de noduri si arce";cout<<endl;cout<<"\n";
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j]=0;

    for(k=1;k<=m;k++)
    {
        cin>>i>>j;
        a[i][j]=1;
    }
}

void afisare()
{
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

void transformare_in_grafTurneu()
{
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[i][j]==a[j][i]==1)
                a[i][j]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

void DF(int k, int x)
{
    v[k]=x;
    cout<<k<<" ";
    for(i=1;i<=n;i++)
        if(a[k][i]==1 && v[i]==0)
        {
            DF(i, x);
            v[i]=x;
        }
}

void componente_Conexe()
{
    for(i=1;i<=n;i++)
        if(v[i]==0)
        {
            cout<<"DF("<<i<<")= ";
            DF(i,nc+1);
            cout<<endl;
            nc++;
        }
        cout<<"Graful are "<<nc<<" componente conexe";cout<<endl;

}

int grad_exterior(int e)
{
    int nr=0;
    for(j=1;j<=n;j++)
        if(a[e][j]==1)
        {
            nr++;
        }
    return nr;
}

void afisare_noduri_cu_grad_maxim()
{
    int maxx=0;
    for(int d=1; d<=n; d++)
    {
        int nr=0;
        for(int j=1; j<=n; j++)
            if(a[d][j]==1)
                nr++;
        if(nr>=maxx)
            maxx=nr;
    }
    cout<<"Gradul maxim este: "<<maxx<<" ";
    cout<<endl;
    cout<<"Nodul cu gradul maxim este: ";
    for(i=1;i<=n;i++)
        if(grad_exterior(i)==maxx)
        {
            cout<<i<<" ";
        }
}

void citire_Circuit()
{
    cout<<"Dati nr de noduri";cin>>k;cout<<endl;
    for(int i=1; i<=k; i++)
        cin>>v[i];
}

void verificare_CircuitElementar()
{
    bool ok1=1, ok2=1, ok3=1;
    for(int i=1; i<=k-1; i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok1=0;
    }
    for(int i=1; i<=k; i++)
        for(int j=i+1; j<=k-1; j++)
        {
            if(v[i]==v[j])
                ok2=0;
        }
    if(v[1]!=v[k])
    {
        ok3=0;
    }
    if(ok1==1 && ok2==1 && ok3==1)
        cout<<"Este Circuit Elementar";
    else if(ok1==1 && ok2==0 && ok3==1)
        cout<<"Este Circuit Neelementar";
    else
        cout<<"Nu este Circuit";
}

int main()
{
    cout<<"1-citire prin construirea cu arce";cout<<endl;
    cout<<"2-afisarea grafului";cout<<endl;
    cout<<"3-CERINTA 1: Sa se transforme un graf complet in graf turneu";cout<<endl;
    cout<<"4-CERINTA 2: Sa se afle numarul de componente conexe din graf";cout<<endl;
    cout<<"5-CERINTA 3: Sa se afiseze nodurile cu proprietatea ca nr arcelor ce ies din nod  este maxim";cout<<endl;
    cout<<"6-CERINTA 4: Sa se verifice daca o succesiune de noduri citita din fisier poate fi circuit elementar in graf";cout<<endl;cout<<"\n";
    do
    {
        cout<<"alegeti o problema:"<<" ";
        cin>>problema;
        cout<<endl;
        switch(problema)
        {
            case 1:
                cout<<"1-citire prin construirea cu arce";cout<<endl;
                citire();
                cout<<endl;
            break;

            case 2:
                cout<<"2-afisarea grafului";cout<<endl;
                afisare();
                cout<<endl;
            break;

            case 3:
                cout<<"4-CERINTA 1: Sa se afle numarul de componente conexe din graf";cout<<endl;
                componente_Conexe();
                cout<<endl;
            break;

            case 4:
                cout<<"5-CERINTA 2: Sa se afiseze nodurile cu grad maxim";cout<<endl;
                afisare_noduri_cu_grad_maxim();
                cout<<endl;
            break;

            case 5:
                cout<<"6-CERINTA 3: Sa se verifice daca o succesiune de noduri citita din fisier poate fi circuit elementar in graf";cout<<endl;
                citire_Circuit();
                verificare_CircuitElementar();
                cout<<endl;
            break;

            case 6:
                cout<<"3-CERINTA 4: Sa se transforme un graf complet in graf turneu";cout<<endl;
                transformare_in_grafTurneu();
                cout<<endl;
            break;

            default:
                cout<<"Nu exista acest caz: incearca alt numar :((";
                cout<<endl;
        }
    }
    while(problema<=6);
    return 0;
}
