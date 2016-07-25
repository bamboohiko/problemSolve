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
int gcd(int a,int b) {
    while (b) {
        int t = a;a = b;b = t%b;
    }
    return a;
}
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t;ca++) {
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        int k = gcd(a,b);
        printf("Case #%d: ",ca);
        //cout << (n/k-2) << endl;
        if ((n/k - 2)%2 == 0) printf("Iaka\n");
        else printf("Yuwgna\n");
    }
	return 0;
}

