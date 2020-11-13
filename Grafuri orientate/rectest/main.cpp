#include <iostream>
#include <fstream>

using namespace std;

int a[100][100], n, m, k, v[100], viz[100], nrC, problema, nBF, nDF,x;

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
        cout<<j<<", ";

   }
}

void predecesori(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i][x]==1)
            cout<<i<<", ";
    }
}

void toate_gi_ge()
{
    for(int i=1;i<=n;i++)
    {
        cout<<"D+("<<i<<"): "<<grad_exterior(i)<<"   ";
        cout<<"D-("<<i<<"): "<<grad_interior(i)<<"   ";
        cout<<endl;
    }
}

void toate_arcele()
{
    for(int i=1;i<=n;i++)
    {
        cout<<"Arcurile ce ies din nodul "<<i<<"+: ";arce_out(i);cout<<"   ";
        cout<<endl;
        cout<<"Arcurile ce intra din nodul "<<i<<"-: ";arce_in(i);cout<<"   ";
        cout<<endl;
    }
}

void toti_suc_pred()
{
    for(int i=1;i<=n;i++)
    {
        cout<<"w+("<<i<<"): ";succesori(i);cout<<"   ";
        cout<<endl;
        cout<<"w-("<<i<<"): ";predecesori(i);cout<<"   ";
        cout<<endl;
    }
}

void DFS(int k, int val)
{
    v[k] = val;
    cout<<k<<" ";
    for(int i = 1 ; i <= n ; i++)
        if(v[i]==0 && a[k][i] == 1)
        {
            DFS(i, val);
            v[i] = val;
        }
}

void ComponenteConexe()
{
    for(int i = 1 ; i <= n ; i++)
        if(v[i] == 0)
        {
            cout<<"DF("<<i<<")= ";
            DFS(i, nrC + 1);
            cout<<endl;
            nrC++;
        }
    cout<<"Numarul de componente conexe este: ";
    cout << nrC <<" ";
    cout<<endl;
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

void BF(int start)
{
   int c[20], v2[20],pi,ps,k2;
   for(int i=1;i<=20;i++)
     c[i]=0;
   for(int i=1;i<=20;i++)
     v2[i]=0;

   ps=pi=1;
   c[pi]=start;
   v2[start]=1;
   while(ps<=pi)
   {
    k2=c[ps];
    for(int i=1;i<=n;i++)
      if(v2[i]==0 && a[k2][i]==1)
      {
        pi++;
        c[pi]=i;
        v2[i]=1;
      }
    ps++;
  }
  for(int i=1;i<=n;i++)
    cout<<c[i]<<" ";
}

/*
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
}*/

void citireLant()
{
    cout<<"Numarul de noduri: ";
    cin>>k;
    cout<<"Elementele lantului: ";
    for(int i=1; i<=k; i++)
        cin>>v[i];
}

int verificareLant()
{
    bool ok=1;
    for(int i=1; i<=k-1; i++)
        if(a[v[i]][v[i+1]]==0)
            ok=0;
    return ok;
}

void verificareLantElementar()
{
    bool ok1=1, ok2=1;
    for(int i=1; i<=k-1; i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok1=0;
    }
    for(int i=1; i<=k; i++)
        for(int j=i+1; j<=n-1; j++)
        {
            if(v[i]==v[j])
                ok2=0;
        }
    if(ok1==1 && ok2==1)
        cout<<"Lantul este elementar";
    else if(ok1==1 && ok2==0)
        cout<<"Lantul nu este elementar";
    else
        cout<<"Nu este Lant";
}

void citireCircuit()
{
    cin>>k;
    for(int i=1; i<=k; i++)
        cin>>v[i];
}

void verificareCircuit()
{
    bool ok1=1, ok2=1;
    for(int i=1; i<=k-1; i++)
    {
        if(a[v[i]][v[i+1]]==0)
            ok1=0;
    }
    if(v[1]!=v[k])
        ok2=0;
    if(ok1==1 && ok2==1)
        cout<<"Este Circuit";
    else
        cout<<"Nu este Circuit";
}

void verificareCircuitElementar()
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

void graf_turneu()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(a[i][j]==1 && a[j][i]==1)
                a[j][i]=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    cout<<"1-citire cu arce";cout<<endl;
    cout<<"2-citire cu matrice";cout<<endl;
    cout<<"3-afisati matricea de adiacenta";cout<<endl;
    cout<<"4-aflati d+ si d- al nodului cicit de la tastatura";cout<<endl;
    cout<<"5-aflati multimea arcelor ce ies si intra in nodul citit de la tastatura ";cout<<endl;
    cout<<"6-aflati multimea succesorilor si redecesorilor nodului citit de la tastatura";cout<<endl;
    cout<<"7-aflati toate d+ si d- ale tuturor nodurilor";cout<<endl;
    cout<<"8-aflati toate multimile arcelor ce ies si intra din toate nodurie";cout<<endl;
    cout<<"9-aflati toti succesorii si predecesorii ai tuturor nodurilor";cout<<endl;
    cout<<"10-aflati BF cu nodul de start citit de la tastatura";cout<<endl;
    cout<<"11-aflati DF cu nodul de start citit de la tastatura";cout<<endl;
    cout<<"12-aflati numarul de componente conexe ale grafului";cout<<endl;
    cout<<"13-verificati daca secventa citita este lant, iar daca este lant aflati tipul lantului";cout<<endl;
    cout<<"14-verificati daca secventa citita este circuit, iar daca este circuit aflati tipul circuitului";cout<<endl;
    cout<<"15-transformati graful, daca e complet, in graf turenu";cout<<"\n";

    do
    {
        cout<<"alegeti o problema:"<<" ";
        cin>>problema;
        cout<<endl;
        switch(problema)
        {
            case 1:
                cout<<"1-citire cu arce";cout<<endl;
                citire_arce();
            break;

            case 2:
                cout<<"2-citire cu matrice";cout<<endl;
                citire_matrice();
                cout<<endl;
            break;

            case 3:
                cout<<"3-afisati matricea de adiacenta";cout<<endl;
                cout<<"Matricea de adiacenta este: "<<endl;
                cout<<"\n";
                afisare();
                cout<<endl;
            break;

            case 4:
                cout<<"4-aflati d+ si d- al nodului cicit de la tastatura";cout<<endl;
                cout<<"Dati nodul pentru care vreti sa aflat d+ si d-: ";
                cin>>x;
                cout<<endl;
                cout<<"Gradul exterior al nodului "<<x<<" este: ";
                cout<<grad_exterior(x);
                cout<<endl;
                cout<<"Gradul interior al nodului "<<x<<" este: ";
                cout<<grad_interior(x);
                cout<<endl;
            break;

            case 5:
                cout<<"5-aflati multimea arcelor ce ies si intra in nodul citit de la tastatura ";cout<<endl;
                cout<<"\n";
                cout<<"Multimea arcelor ce ies din "<<x<<" este: ";
                arce_out(x);
                cout<<endl;
                cout<<"Multimea arcelor ce intra in "<<x<<" este: ";
                arce_in(x);
                cout<<endl;
                cout<<"\n";
            break;

            case 6:
                cout<<"6-aflati multimea succesorilor si predecesorilor nodului citit de la tastatura";cout<<endl;
                cout<<"Multimea succesorilor nodului "<<x<<" este: ";
                succesori(x);
                cout<<endl;
                cout<<"Multimea predecesorilor nodului "<<x<<" este: ";
                predecesori(x);
                cout<<endl;
                cout<<"\n";
            break;

            case 7:
                cout<<"7-aflati toate d+ si d- ale tuturor nodurilor";cout<<endl;
                toate_gi_ge();
                cout<<endl;
            break;

            case 8:
                cout<<"8-aflati toate multimile arcelor ce ies si intra din toate nodurie";cout<<endl;
                toate_arcele();
                cout<<endl;
            break;

            case 9:
                cout<<"9-aflati toti succesorii si predecesorii ai tuturor nodurilor";cout<<endl;
                toti_suc_pred();
                cout<<endl;
                cout<<"\n";
            break;

            case 10:
                cout<<"10-aflati BF cu nodul de start citit de la tastatura";cout<<endl;
                cout<<"Dati nodul de start: ";cin>>nBF;
                BF(nBF);
                cout<<endl;
            break;

            case 11:
                cout<<"11-aflati DF cu nodul de start citit de la tastatura";cout<<endl;
                cout<<"Dati nodul de start: ";cin>>nDF;
                DF(nDF);
                cout<<endl;
            break;

            case 12:
                cout<<"12-aflati numarul de componente conexe ale grafului";cout<<endl;
                ComponenteConexe();
                cout<<endl;
            break;

            case 13:
                cout<<"13-verificati daca secventa citita este lant, iar daca este lant aflati tipul lantului";cout<<endl;
                citireLant();
                verificareLantElementar();
                cout<<endl;
            break;

            case 14:
                cout<<"14-verificati daca secventa citita este circuit, iar daca este circuit aflati tipul circuitului";cout<<endl;
                citireCircuit();
                verificareCircuitElementar();
                cout<<endl;
            break;

            case 15:
                cout<<"15-transformati graful, daca e complet, in graf turenu";cout<<endl;
                graf_turneu();
                cout<<endl;
            break;

            default:
                cout<<"Nu exista acest caz: incearca alt numar :((";
                cout<<endl;

        }
    }
    while(problema<=15);

    return 0;
}
