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
    int t;
    scanf("%d",&t);
    while (t--) {
        long long n,s;
        scanf("%lld%lld",&n,&s);
        long long ans = 0,st = s;
        while (st > 0 && n >= st) {
            cout << n << " " << st << endl;
            ans += n/st;
            st *= s;
        }
        printf("%d\n",ans);
    }

	return 0;
}
