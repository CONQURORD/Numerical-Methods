#include<iostream>
#include <iomanip>
#include<math.h>
#include<stdlib.h>
#include<fstream>
#include<new>
#include<conio.h>

#define SQ(x) (x)*(x)
#define Resp(x) 1.0/(x)
#define free_arg char*
#define nr_end 1
#define Tiny 1.0e-20

#define ESP 0.000001

using namespace std;
typedef unsigned long int us;

double *dvector (long nl, long nh);
long *lvector (long nl, long nh);
double **matrix (long nrl, long nrh, long ncl, long nch);
long **lmatrix (long nrl, long nrh, long ncl, long nch);
double ***f3tensor(long nrl, long nrh, long ncl, long nch, long ndl, long ndh);
void free_vector (double *v, long nl, long nh);
void free_lvector (long *v, long nl, long nh);
void free_matrix (double **m, long nrl, long nrh, long ncl, long nch);
void free_lmatrix (long **m, long nrl, long nrh, long ncl, long nch);
void free_tensor(double ***t, long nrl, long nrh, long ncl, long nch, long ndl, long ndh);

int main()
{
    cout << "  Gauss Seidel Method  \n";
    cout << "\n";
    ifstream fin;
    fin.open("eqs.txt");


    int i,j,n,c=1;
    double k,k1;
    //n=3;
    fin >> n;

    cout<< "\n  The number of variables is = "<<n<<endl;
    float a[n][n+1];
    double r[n],r1[n];

    for(i=1;i<=n;i++)
    {
        r[i]=0;
        r1[i]=0;
    }


    if(!fin)
        cout<<"No such file";
    else
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n+1;j++)
                fin>>a[i][j];
        }
    }

    /*
    a[1][1] = 4; a[1][2] = 2; a[1][3] = 3; a[1][4] = 17;
    a[2][1] = 3; a[2][2] = 4; a[2][3] = 2; a[2][4] = 17;
    a[3][1] = 2; a[3][2] = 3; a[3][3] = 4; a[3][4] = 20;
    */

    cout<<"\n  equations are : \n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n+1;j++)
        {
            if(j<=n)
                cout<<"\t"<<a[i][j]<<"*x"<<j;
            else
                cout<<"\t=  "<<a[i][j];
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"  Maximum error allowed = "<<ESP <<"\n";

    cout<<" initial assumption:\n";
    for(i=1;i<=n;i++)
    {
        cout<<"\t" << "x"<<i<<" = "<<r[i];
    }

    cout << "\n";
    cout<<"\t" << "Iteration" << "\t";
    for(i=1;i<=n;i++)
    {
        cout<<"x"<<i<<"\t";
    }
    cout<<"Max Error"<<endl << "\n";
 
    k=0;k1=1;
    do
    {
        cout<<"\t"<<c<<"\t";
        k1=0;
        for(i=1;i<=n;i++)
        {
            r[i] = a[i][n+1]/a[i][i];
            for(j=1;j<=n;j++)
            {
                if(i!=j)
                    r[i] = r[i] - a[i][j]/a[i][i]*r[j];
            }
            k = fabs(r[i]-r1[i]);
            cout<<fixed;
            std::cout<< std::setprecision(6)<<"\t" <<r[i];
            if(k1<=k)
                k1 = k;
            r1[i]=r[i];

        }
        cout<<"\t"<<k1;
        cout<<endl;
        c++;

    }
	while(k1>ESP);

    cout<<"\n  The final solution is: \n";
    
    for(i=1;i<=n;i++)
    {
      cout<<"\tx"<<i<<" = "<<r[i]<<endl;
    }
    return 0;
}
