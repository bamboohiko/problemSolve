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
char a[100100];
int next[100100];
int main() {
    int t,ca = 1;
    scanf("%d",&t);
    while (t--) {
        scanf("%s",a);
        int len = strlen(a),j;
        j = next[0] = -1;
        for (int i = 1;i <= len; i++) {
            while (j >= 0 && a[i-1] != a[j]) j = next[j];
            next[i] = ++j;
        }
        int k = next[len];
        while (k > 0) {
            for (int i = 1;i+k < len; i++)
                if (next[i+k] == k) goto lambel;
            k = next[k];
        }
        lambel:
            printf("Case #%d: ",ca++);
            if (k <= 0) printf("-1\n");
            else printf("%s\n",a+len-k);
    }
	return 0;
}
