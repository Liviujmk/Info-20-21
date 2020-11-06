#include <iostream>
#include <fstream>
using namespace std;

int a[100][100], n, m, k,i,j,s[100],l,poz;
bool gata;

void citire()
{
    int i, j;
    cout<<"Numarul de noduri este: "<<endl;
    cin>>n;
    cout<<"Numarul de arce este: "<<endl;
    cin>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            a[i][j]=0;
        }
    for(k=1; k<=m; k++)
    {
        cout<<"Muchia "<<k<<" este: ";
        cin>>i>>j;
        a[i][j]=1;
    }
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

void roy_warshall()
{
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][j]==0 && k!=i && k!=j)
                    a[i][j]=a[i][k] * a[k][j];
    cout<<endl;
}

void generare_drum()
{
    int i,j,k,poz,gata,L;
    if(a[1][2]==1)
    {
        s[1]=1;
        s[2]=2;
    }
    else
      {
        s[1]=2;
        s[2]=1;
      }
      L=2;
      for(k=3; k<=n; k++)
      {
          if(a[k][s[1]]==1)
        {
                poz=1;
                i=1;
        }
          else
          {
              i=1;
              gata=0;
              while(i<L && !gata)
              {
                  if(a[s[i]][k]==1 && a[k][s[i+1]])
                    gata=1;
                  else
                    i++;

              }
              poz=i+1;
          }
          for(j=L; j>=poz; j--)
            s[j+1]=s[j];
          s[poz]=k;
          L++;
      }
}

void afisare_vector()
{
    for(i=1;i<=n;i++)
        cout<<s[i]<<" ";
}

void transformaregraf()
{
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[j][i]+a[i][j]==2)
                a[j][i]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    citire();
    afisare();
    roy_warshall();
    afisare();
    cout<<endl;
    cout<<endl;
    generare_drum();
    cout<<endl;
    cout<<endl;
    afisare_vector();
    cout<<endl;
    transformaregraf();
    cout<<endl;

    return 0;
}
se da un g o si 2 vf distincte k si l, det daca vk k si l se afla in aceeasi componenta conexa
