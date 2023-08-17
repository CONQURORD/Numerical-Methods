#include<iostream>
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

using namespace std;
typedef unsigned long int us;

double F(float x)
{
	return x*x*x -x*x -x +1;
}

double F1(float x)
{
	return 3*x*x - 2*x -1;
}

double F2(float x)
{
	return 6*x-2;
}


int main()
{
	float x0, n, ep, x1, x2, i,f0, f1, f2;
	cout << "input the parameters\n";
	cin >> x0;
	cin >> n;
	cin >> ep;

	
	for(i=1;i<=n;i++)
	{
		f0=F(x0);
		f1=F1(x0);
		f2=F2(x0);
		

			cout << i << "\t" << x0 <<"\t" << f0 <<"\t" << f1<<"\n";
		
				x1=x0-2*(f0/f1);
	            x2=x0-(f1/f2);
			
			if(fabs(x1-x2) < ep)
			{
				cout << "convergent\t" << i << "\t" << x1 << "\t "  <<F(x1) ;  
				break;   
			}
			
			else
			x0=x1;
			
	
	}
	   
		
return 0;
}
