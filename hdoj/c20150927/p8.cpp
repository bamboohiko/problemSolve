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
    for (int ca = 1;ca <= t; ca++) {
        int d,s1,s2,s;
        scanf("%d%d%d",&d,&s1,&s2);
        for (int j = 1;j <= d;j <<= 1) if (j&d) s++;
        for (int i = 1;i <= d;i <<= 1) {
            if (!(i&d) && (s == s2)) continue;
            d += i;
            for (int j = (i >> 1);j > 0;j >>= 1) if (j&d) d -= j;
            int j = 0;
            while (s < s1) {
                d += (1 << j);
                s++;j++;
            }
            break;
        }
        printf("Case #%d: %d\n",ca,d);
    }
	return 0;
}
