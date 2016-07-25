#include<iostream>
#include<string>
using namespace std;
string a,b;
int main()
{int t;
	while (cin >> a >> b) 
		{t=a.find("_")+1;
		 a.assign(a,t,a.length()-t);
		 t=b.find("_")+1;
		 b.assign(b,t,b.length()-t);
		 cout << a << "_small_" << b << endl;
		}
	return 0;
}
