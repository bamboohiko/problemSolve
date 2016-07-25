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
int a[510],b[510];
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n; i++) scanf("%d",&a[i]);
        for (int i = 0;i < n; i++) scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        int s1 = 0,s2 = 0;
        for (int i = 0;i < m; i++) s1 += a[i];
        for (int i = n-1;i >= n-m; i--) s2 += b[i];
        //cout << s1 << " " << s2 << endl;
        if (s1 > s2) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}

