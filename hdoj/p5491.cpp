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
typedef long long LL;
int main() {
    int t;
    scanf("%d",&t);
    LL d;int s1,s2,s;
    for (int ca = 1;ca <= t; ca++) {
        scanf("%d%d%d",&s,&s1,&s2);
        d = s;
        s = (s & 0x55555555) + ((s >> 1) & 0x55555555);
        s = (s & 0x33333333) + ((s >> 2) & 0x33333333);
        s = (s & 0x0f0f0f0f) + ((s >> 4) & 0x0f0f0f0f);
        s = (s & 0x00ff00ff) + ((s >> 8) & 0x00ff00ff);
        s = (s & 0x0000ffff) + ((s >> 16) & 0x0000ffff);
        //cout << s << endl;
        for (LL i = 1; ;i <<= 1) {
            if (i&d) {d -= i;s--;}
            else if (s < s2 && (s+1 >= s1 || (i >= 1 << (s1-s-1)))) {
                d |= i;s++;
                if (s < s1) d |= (1 << (s1 - s)) - 1;
                break;
            }
        }
        printf("Case #%d: %lld\n",ca,d);
    }
    return 0;
}
