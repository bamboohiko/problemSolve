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
const int maxn = 1e5;
vector<int> d;
set<int> s;
bool vis[100100];
int a[100100];
int main() {
    int n,x;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%d",&x);
        if (x <= n && !s.count(x)) {
            a[i] = x;
            s.insert(x);
            vis[x] = true;
        }
        else d.push_back(i);
    }
    int l = 1;
    for (int i = 0;i < d.size(); i++) {
        while (vis[l]) l++;
        a[d[i]] = l++;
    }
    for (int i = 1;i < n; i++) printf("%d ",a[i]);
    printf("%d\n",a[n]);
	return 0;
}

