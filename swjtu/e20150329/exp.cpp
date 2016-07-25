#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
class A{
	public:
	int  f(); 
	int  f(int x=0); 
	int  f(int x=0,int y=0)
	{
		cout << "A" << endl;
	} 
	int  f(double  x); 
	int  f(double  x=0.0,double  y=0.0)
	{
		cout << "B" << endl;
	}
};
int main()
{
	A a;
	a.f(1,1);
	a.f(1,1.0);
	return 0;
}
