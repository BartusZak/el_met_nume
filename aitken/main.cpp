#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int n,k;
int const m=100;
vector<double> xw(m);
vector<double> yw(m);
double w[m] [m];
double x,z;
double aitken(int k, vector<double>xw1, vector<double>yw1, double x)
{
for (int i =1; i<= k; i++)
{
w[i][0]=(yw1[0]*(xw1[i]-x)-yw1[i]*(xw1[0]-x))/(xw1[i]-xw1[0]);
}
for(int j = 1; j<=k-1; j++)
{
for (int i = j+1; i<=k; i++)
{
w[i][j]=(w[j][j-1]*(xw1[i]-x)-w[i][j-1]*(xw1[j]-x))/(xw1[i]-xw1[j]);
}
}
return w[k][k-1];
}
int main()
{
cout<<"podaj n= ";
cin>>n;
cout<<""<<endl;
for(int i=0; i<=n; i++)
{
cout<<"podaj x("<<i<<")= ";
cin>>xw[i];
}
cout<<""<<endl;
for(int i = 0; i<=n; i++)
{
cout<<"podaj y("<<i<<")= ";
cin>>yw[i];
}
cout<<""<<endl;
cout<<"podaj x= ";
cin>>x;
z=aitken(n,xw,yw,x);
cout<<""<<endl;
cout<<"W(x)- "<<setprecision(12)<<z<<endl;
return 0;
}


