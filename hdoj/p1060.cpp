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
int main() {
    int t;long long n;
    scanf("%d",&t);
    while (t--) {
        scanf("%lld",&n);
        double m = n*log10(n);
        double k = m - (long long)m;
        printf("%d\n",(int)pow(10.0,k));
    }
	return 0;
}
