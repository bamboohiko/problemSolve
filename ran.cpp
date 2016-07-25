#include<ctime>
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{int t,n;
	freopen("test.in","w",stdout);
 	srand(time(NULL));
	cout << (t = 2) << endl;
	for (int i = 1;i <= t; i++)
		{cout << (n = rand()%1000) << endl;
		for (int i = 1;i <= n; i++)
			cout << rand()*rand() << " ";
		cout << endl;
		}
	return 0;
}
