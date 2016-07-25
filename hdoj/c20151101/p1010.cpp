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
struct node{
    int cnt;
	int next[2];
};
vector<node> trie;
int root, a[1010];
int newnode() {
	node k;
	k.cnt = 0;
	k.next[0] = k.next[1] = -1;
	trie.push_back(k);
	return trie.size()-1;
}
void build(int k) {
	int now = root;
	for (int i = 31;i >= 0; i--) {
        trie[now].cnt++;
        //cout << now << " ";
        int p = (k&(1<<i))?1:0;
        if (trie[now].next[p] == -1) {
            int loc = newnode();
            trie[now].next[p] = loc;
        }
        now = trie[now].next[p];
	}
	trie[now].cnt++;
	//cout << now << endl;
}
int query(int k) {
    int now = root,ans = 0;
    for (int i = 31;i >= 0; i--) {
        if (now == -1) return 0;
        int p = (k&(1<<i))?0:1;
        if (trie[now].next[p] != -1 && trie[trie[now].next[p]].cnt) {
            ans += 1 << i;
            now = trie[now].next[p];
        } else now = trie[now].next[1-p];
    }
    return ans;
}
void del(int k) {
    int now = root;
    for (int i = 31;i >= 0; i--) {
         trie[now].cnt--;
        //cout << now << " ";
        int p = (k&(1<<i))?1:0;
        now = trie[now].next[p];
    }
    trie[now].cnt--;
}
int main() {
    int t,n;
    scanf("%d",&t);
    while (t--) {
        trie.clear();
        scanf("%d",&n);
        root = newnode();
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
            build(a[i]);
        }
        int ans = 0;
        for (int i = 1;i < n; i++) {
            del(a[i]);
            for (int j = i+1;j <= n; j++) {
                del(a[j]);
                ans = max(ans,query(a[i]+a[j]));
                //cout << endl;
                build(a[j]);
            }
            build(a[i]);
        }
        printf("%d\n",ans);
    }
	return 0;
}

