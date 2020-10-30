#include<iostream>

#include<fstream>

using namespace std;

int a[20][20],c[20],v[20],ns,n,comp;

int prim;

int ultim;

// citirea grafului din fisier text si construirea matricei de adiacenta

void citire(int a[20][20], int &n)

{   ifstream f("graf.txt");

    int x,y;

    f>>n;

    while(f>>x>>y)

        a[x][y]=a[y][x]=1;

     f.close();

}

// afisarea pe ecran a matricei de adiacenta

void afisare(int a[20][20],int n)

{    cout<<"Matricea de adiacenta este : "<<endl;

     for( int i=1;i<=n;i++)

        { for(int j=1;j<=n;j++)

              cout<<a[i][j]<<" ";

          cout<<endl;

        }

}

// returnează primului nod nevizitat

int exista_nod_nevizitat(int v[20], int n)

{   for(int i=1;i<=n;i++)

      if(v[i]==0)

         return i; // primul nod nevizitat

      return 0;   // nu mai exista noduri nevizitate

}

// parcurgerea în latime a unei componente conexe, plecând din nodul de start ns

void parcurgere_latime(int a[20][20], int n,int ns)

    { comp++;

      v[ns]=1;

      cout<<"Componenta conexa : "<<comp<<" este formata din nodurile : ";

      cout<<ns<<" ";

      prim=ultim=1;

      c[ultim]=ns;

      while(prim<=ultim)

          {for(int i=1;i<=n;i++)

             if(a[c[prim]][i]==1)

               if(v[i]==0)

                 { ultim++;

                   c[ultim]=i;

                   cout<<i<<" ";

                   v[i]=1;

                 }

             prim++;

          }

       cout<<endl;

    }

// functia principala main()

int main()
{
  citire(a,n);
  afisare(a,n);
  cout<<"Dati nodul de start : ";
  cin>>ns;
  parcurgere_latime(a,n,ns);

  while(exista_nod_nevizitat(v,n)!=0)

     {ns=exista_nod_nevizitat(v,n);

      parcurgere_latime(a,n,ns);

      }

  cout<<"Graful este alcatuit din "<<comp <<" componente conexe. ";
return 0;
}
