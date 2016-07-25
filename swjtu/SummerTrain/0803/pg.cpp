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
        long long ans = 0;
        while (n && m) {
            ans += n*m;
            n--,m--;
        }
        printf("%lld\n",ans);
    }
	return 0;
}
