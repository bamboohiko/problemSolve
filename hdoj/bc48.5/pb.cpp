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
int f[110][20][10];
int main() {
    string b = " anniversary";
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(f,0,sizeof(f));
        string a;
        cin >> a;
        a = " " + a;
        bool ans = false;
        for (int i = 1;i < 10;i++)
            for (int j = 1;i + j < 11; j++) {
                string b1 = b.substr(1,i),b2 = b.substr(i+1,11-i-j),b3 = b.substr(11-j+1,j);
                int l,r;
                for (l = 1;l + b.size() <= a.size()+1; l++)
                    if (a.substr(l,i) == b1) break;
                for (r = a.size()-1;r + 1 >= b.size(); r--)
                    if (a.substr(r-j+1,j) == b3) break;
                for (int k = l + i;k + 11-i-j -1 <= r-j; k++)
                    if (a.substr(k,11-i-j) == b2) {
                        ans = true;
                        goto lambel;
                    }
            }
        lambel:
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}
