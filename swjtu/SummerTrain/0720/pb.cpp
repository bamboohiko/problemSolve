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
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,x,sum = 0;
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) {
            scanf("%d",&x);
            sum += x;
        }
        if (t) printf("%d\n\n",sum);
        else printf("%d\n",sum);
    }
	return 0;
}
