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
        printf("Case #%d: ",ca);
        string p,q;
        cin >> p >> q;
        int cou = 0;
        if (p.size() >= q.size())
            for (int i = 0;i < p.size() - q.size() + 1; i++) {
                if (p.substr(i,q.size()) == q) cou++;
            }
        printf("%d\n",cou);
    }
	return 0;
}
