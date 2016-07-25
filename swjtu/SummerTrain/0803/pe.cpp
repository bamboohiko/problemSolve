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
    while (scanf("%d",&n) != EOF) {
        int ans = 0;
        double d = sqrt(n/2.0);
        int k = trunc(sqrt(n) + 0.5);
        if (k*k == n) ans += 4;
        for (int i = 1;i <= d; i++) {
            int k = floor(sqrt(n-i*i)+0.5);
            //cout << i << ":" << k << endl;
            if (i*i + k*k == n)
                if (i == k) ans += 4;
                else ans += 8;
        }
        printf("%d\n",ans);
    }
	return 0;
}
