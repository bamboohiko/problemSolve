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
const int inf = 1e9 + 7;
map<int,int> dic;
int a[100100],q[100100];
int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        dic.clear();
        int x;
        for (int i = 1;i <= n; i++) {
            scanf("%d",&x);
            dic[x] = i;
        }
        int cou = 0;
        for (int i = 1;i <= n; i++) {
            scanf("%d",&x);
            if (dic.count(x)) a[++cou] = dic[x];
        }
        n = cou;
        for (int i = 1;i <= n; i++) q[i] = inf;
        for (int i = 1 ;i <= n; i++) {
            int loc = lower_bound(q+1,q+n+1,a[i]) - q;
            q[loc] = a[i];
        }
        for (int i = n;i >= 0;i--)
            if (q[i] != inf) {
                printf("%d\n",i);
                break;
            }
    }
	return 0;
}
