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
    int h,a,b;
    while (scanf("%d%d%d",&h,&a,&b) != EOF && (h || a || b)) {
        int t = 0,m = 0;
        while (m < h) {
            if (m + a >= h) {
                t++;
                break;
            }
            m += a-b;t += 2;
        }
        printf("%d\n",t);
    }
	return 0;
}


