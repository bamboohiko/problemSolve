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
struct proj{
    string nam;
    int dt,st;
};
const int maxn = (1 << 15) + 10;
const int inf = 1e9 + 10;
proj a[20];
int f[maxn],sumt[maxn],path[maxn];
void print(int t) {
    if (t == 0) return;
        print(path[t]);
        int loc = floor(log2(t - path[t]));
        cout << a[loc].nam << endl;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(sumt,0,sizeof(sumt));
        int n;
        scanf("%d",&n);
        for (int i = 0;i < n; i++) {
            cin >> a[i].nam;
            scanf("%d%d",&a[i].dt,&a[i].st);
        }
        for (int i = 0;i < (1 << n); i++) {
            for (int j = 0;j < n; j++)
                if (i & (1 << j)) sumt[i] += a[j].st;
            f[i] = inf;
        }
        f[0] = 0;
        for (int i = 1;i < (1 << n); i++)
            for (int j = n-1;j >= 0; j--)
                if (i & (1 << j)) {
                    if (f[i - (1 << j)] + max(sumt[i]-a[j].dt,0) < f[i]) {
                        f[i] = f[i - (1 << j)] + max(sumt[i]-a[j].dt,0);
                        path[i] = i - (1 << j);
                    }
                }
        printf("%d\n",f[(1 << n)-1]);
        print((1 << n)-1);
    }
	return 0;
}

