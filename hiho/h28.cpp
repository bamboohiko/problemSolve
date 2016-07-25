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
int a[250000],m;
void add(int k) {
    int val = a[k];
    while (k > 1) {
        if (val > a[k >> 1]) {
            a[k] = a[k >> 1];
            k >>= 1;
        } else break;
    }
    a[k] = val;
}
void del() {
    int val = a[m--],k = 1;
    while (k < m) {
        if ((k << 1) > m) break;
        if ((k << 1) == m || a[(k << 1)|1] < a[k << 1]) {
            if (a[(k << 1)] > val) {
                a[k] = a[(k << 1)];
                k = (k << 1);
            } else break;
        } else {
            if (a[(k << 1)|1] > val) {
                a[k] = a[(k << 1)|1];
                k = (k << 1)|1;
            } else break;
        }
    }
    a[k] = val;
}
int main() {
    int n,k;char ch;
    scanf("%d%*c",&n);
    for (int i = 1;i <= n; i++) {
        scanf("%c",&ch);
        if (ch == 'T') {
            printf("%d\n",a[1]);
            del();
        } else {
            scanf("%d",&a[++m]);
            add(m);
        }
        getchar();
        //for (int i = 1;i <= m; i++) cout << a[i] << " ";cout << endl;
    }
	return 0;
}

