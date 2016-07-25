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
const int maxn = 1e7;
struct node {
    int cou,s[2];
    node() {
        cou = 0;
        s[1] = s[0] = -1;
    }
};
vector<node> V;
int root,nodesum = 0;
int newnode() {
    V.push_back(node());
    return nodesum++;
}
void add(int x) {
    int p = root;
    for (int i = 30;i >= 0; i--) {
        int b = (x & (1 << i))?1:0;
        if (V[p].s[b] == -1) {
            int loc = newnode();
            V[p].s[b] = loc;
        }
        V[p].cou++;
        //cout << p << " " <<  b << " " << V[p].s[b] << endl;
        p = V[p].s[b];
    }
    V[p].cou++;
}
LL query(int x,int m) {
    int p = root,sum = 0;
    LL ans = 0;
    for (int i = 30;i >= 0; i--) {
        int b = (x & (1 << i))?1:0;
        if (sum + (1 << i) >= m) {
            if (V[p].s[1-b] != -1) {
                ans += V[V[p].s[1-b]].cou;
                //cout << x << " " << p << " " << ans << endl;
            }
            p = V[p].s[b];
        } else {
            p = V[p].s[1-b];
            sum += (1 << i);
        }
        if (p == -1) break;
    }
    return ans;
}
int main() {
    root = newnode();
    int n,m,k,sum = 0;
    scanf("%d%d",&n,&m);
    LL ans = 0;
    add(0);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&k);
        sum ^= k;
        ans += query(sum,m);
        add(sum);
    }
    printf("%I64d\n",ans);
	return 0;
}

