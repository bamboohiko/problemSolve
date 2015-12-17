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
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
set<int> Sinc,Sdec;
int main() {
    int n,m;
    int act,k;
    while (scanf("%d%d",&n,&m) != EOF) {
        Sinc.clear();Sdec.clear();
        Sinc.insert(n+1);
        Sdec.insert(0);
        while (m--) {
            scanf("%d%d",&act,&k);
            if (act == 0) {Sinc.insert(k);Sdec.insert(-k);}
            if (act == 1) {Sinc.erase(k);Sdec.erase(-k);}
            if (act == 2) {
                set<int>::iterator st = Sinc.lower_bound(k);
                set<int>::iterator ed = Sdec.lower_bound(-k);
                if (*st == k) puts("0");
                else printf("%d\n",(*st)+(*ed)-1);
            }
        }
    }
	return 0;
}
