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
long long palind(int k,int d) {
    long long ans = k;
    if (!d) k /= 10;
    while (k) {
        ans = ans*10 + k%10;
        k /= 10;
    }
    return ans;
}
double fig(long long k) {
    double x = k;
    return x/log(x);
}
int main() {
    int p,q;
    scanf("%d%d",&p,&q);

	return 0;
}

