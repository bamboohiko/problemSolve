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
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long LL;
int a[100],m;
void init() {
    for (int i = 1;a[i] <= 1000; i++) {
        a[i] = a[i-1] + i;
        m = i;
    }
}
int main() {
    init();
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,cou = 0;
        scanf("%d",&n);
        while (n) {
            int loc = upper_bound(a,a+m,n) - a;
            //cout << n << " " << a[loc] << endl;
            if (loc > 1) {
                n -= a[loc-1];
                cou++;
            } else break;
        }
        printf("%d\n",cou);
    }
	return 0;
}
