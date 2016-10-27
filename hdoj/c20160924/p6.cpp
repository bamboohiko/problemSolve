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
#include<ctime>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long LL;
const int tle = 1e8/40;
LL a[60100],b[120100];
int main() {
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        LL ans = 0;
        for (int i = 0;i < n; i++) scanf("%I64d",&a[i]);
        for (int i = 0;i < n; i++) {
            scanf("%I64d",&b[i]);b[i+n] = b[i];
            ans += (a[i]-b[i])*(a[i]-b[i]);
        }
        srand(time(NULL));
        int ca = tle/n;
        while (ca--) {
            int k = rand()%n;
            LL sum = 0;
            bool pass = true;
            for (int i = 0;i < n; i++) {
                sum += (a[i]-b[i+k])*(a[i]-b[i+k]);
                if (sum > ans) {
                    pass = false;
                    break;
                }
            }
            if (pass) ans = sum;
        }
        printf("%I64d\n",ans);
    }
	return 0;
}
