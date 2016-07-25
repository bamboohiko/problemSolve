#include<iostream>
#include<cstdio>
using namespace std;
const int a[8]={1,2,0,2,2,1,0,1};
int main()
{int k;
	while (cin >> k)
		if (a[k%8]) printf("no\n");
		else printf("yes\n");
	return 0;
}
