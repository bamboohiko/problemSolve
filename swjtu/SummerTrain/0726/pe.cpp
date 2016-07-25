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
    int n;
    while (scanf("%d",&n) != EOF && n) {
        int ans = 0,x;
        for (int i = 1;i <= n; i++) {
            scanf("%d",&x);
            ans ^= x;
        }
        printf("%d\n",ans);
    }
	return 0;
}


