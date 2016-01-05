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
typedef unsigned int LL;
LL a[250000],m;
void add(int k) {
    LL val = a[k];
    while (k > 1) {
        if (val > a[k >> 1]) {
            a[k] = a[k >> 1];
            k >>= 1;
        } else break;
    }
    a[k] = val;
}
void del() {
    LL val = a[m--],k = 1;
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
    int n,k,mid;
    scanf("%d",&n);mid = n/2 + 1;
    for (int i = 1;i <= mid; i++) {
        scanf("%ud",&a[++m]);
        add(m);
    }
    for (int i = mid+1;i <= n; i++) {
        scanf("%ud",&a[++m]);
        add(mid+1);
        del();
    }
    //for (int i = 1;i <= mid; i++) cout << a[i] << " ";cout << endl;
    if ((n&1) == 0) {
        int k = a[1];del();
        printf("%.1lf\n",(k+a[1])/2.0);
    } else {
        printf("%.1lf\n",(double)a[1]);
    }
	return 0;
}
