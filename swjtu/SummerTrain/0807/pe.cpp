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
const int maxl = 1e5 + 100;
int main() {
    char a[maxl],b[maxl];
    while (scanf("%s%s",a,b) != EOF) {
        int n = strlen(a),m = strlen(b);
        if (n != m) {
            printf("no\n");
            continue;
        }
        bool ans = false;
        for (int i = 1;i < n; i++) {
            ans = true;
            for (int j = 0;j < n; j++)
                if (a[(j+i)%n] != b[j]) {
                    ans = false;
                    break;
                }
            if (ans) break;
        }
        if (ans) printf("yes\n");
        else printf("no\n");
    }
	return 0;
}
