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
const int pri[44] = {2,3,5,7,13,17,19,31,6l,89,107,127,521,607,1279,2203,2281,
3217,4253,4423,9689,9941,11213,19937,21701,23209,44497,86243,
110503,132049,216091,756839,859433,1257787,1398269,2976221,
3021377,6972593,13466917,20996011,24036583,25964951,30402457,
32582657};
int main() {
    int p;
    while (scanf("%d",&p) != EOF) {
        bool ans = false;
        for (int i = 0;i < 44; i++)
            if (p == pri[i]) {
                ans = true;
                break;
            }
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}
