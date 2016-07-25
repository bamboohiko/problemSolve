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
int a[100100];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l = 0,r = INF;
    while (r-l > 1) {
        int mid = l + ((r-l) >> 1);
        int loc = -1,cou = 0;
        for (int i = 1;i <= n; i++) {
            if (a[i] >= loc) {
                cou++;
                loc = a[i] + mid;
                if (cou >= m) break;
            }
        }
        //cout << mid << " " << cou << endl;
        if (cou >= m) l = mid;
        else r = mid;
    }
    printf("%d\n",l);
	return 0;
}

