#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<fstream>
#include<new>
#include<conio.h>


using namespace std;
typedef unsigned long int us;

double func(float x)
{
	double k = 1.3;
	return (pow((k+1)/2,1/(k-1)) * pow(x,1/k) * pow(((k+1)/(k-1))*(1-pow(x,(k-1)/k)),.5))-.125 ;
}

int main()
{
	float i=0,x1,x2,x0;
	cout << "enter lower limit\n";
	cin >> x1;
	cout << "enter upper limit\n";
	cin >> x2;
	

	if (func(x1)*func(x2)<0)
	{
	 while(x2-x1>=.00000001)
	{
	x0=(x2+x1)/2;
	
	if (func(x1)*func(x0)<=0)	
	x2=x0;
	else		
	x1=x0;

i++;
}
cout <<"root" << "\t" << x0 <<"\n";
cout << "iteration "<< "\t" <<i;
}
else

cout << "error";
	
return 0;	
}
