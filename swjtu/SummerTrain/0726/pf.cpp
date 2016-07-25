#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<cmath>
using namespace std;
int modexp(int a,int b,int m) {
    int t = 1;
    while (b)
		{if (b%2) t=t*a%m;
		a=a*a%m;
		b/=2;
		}
	return t;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",modexp(n%10,n,10));
    }
	return 0;
}


