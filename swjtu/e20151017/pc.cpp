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
const int mod = 2017;
using namespace std;
int main() {
    int n;
    while (scanf("%d",&n) != EOF && n) {
        int ans = 1;
        if (n >= mod) printf("0\n");
        else {
            for (int i = 1;i <= n; i++) {
                ans = ans*i%mod;
            }
            printf("%d\n",ans);
        }
    }
	return 0;
}

