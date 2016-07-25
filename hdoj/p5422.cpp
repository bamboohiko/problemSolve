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
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        int r = 0,a,b;
        for (int i = 1;i <= m; i++) {
            scanf("%d%d",&a,&b);
            if ((a == 1 && b == n) || (a == n && b == 1)) r = 1;
        }
        if (r) printf("%d %d\n",1,n*(n-1)/2);
        else printf("%d %d\n",1,1);
    }
	return 0;
}

