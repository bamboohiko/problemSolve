#include<iostream>
using namespace std;
int main()
{int n;
int a[6] = {0,1,2,4,7,15};
	while (cin >> n)
		{int k;
		for (int i = 1;i <= 5; i++)
			if (n > a[i]) k = i;
		for (int i = k;i > 1; i--)
			cout << n - a[i] << " ";
		cout << n - a[1] << endl; 
		}
}
