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
    int t,s,q;
    scanf("%d%d%d",&t,&s,&q);
    int ans = 1;
    while (true) {
        if (t <= s*q) break;
        s = s*q;
        ans++;
    }
    printf("%d\n",ans);
	return 0;
}
