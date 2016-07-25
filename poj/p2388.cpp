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
typedef long long LL;
int a[10100];
void updata(int k) {
    int rec = a[k];
    while (k > 1 && rec < a[k/2]) {
        a[k] = a[k/2];
        k /= 2;
    }
    a[k] = rec;
}
void down(int mid) {
    int rec = a[1],k = 1;
    while (k < mid) {
        if ((k << 1|1) <= mid && a[k << 1] > a[k << 1|1]) {
            if (rec > a[k << 1|1]) {
                a[k] = a[k << 1|1];
                k = k << 1|1;
            } else break;
        } else if ((k << 1) <= mid) {
            if (rec > a[k << 1]) {
                a[k] = a[k << 1];
                k <<= 1;
            } else break;
        } else break;
    }
    a[k] = rec;
}
int main() {
    int n;
    //while (scanf("%d",&n) != EOF) {
    scanf("%d",&n);
        int mid = n/2+1;
        for (int i = 1;i <= mid; i++) {
            scanf("%d",&a[i]);
            updata(i);
        }
        for (int i = 1;i < mid; i++) {
            scanf("%d",&a[mid+1]);
            updata(mid+1);
            a[1] = a[mid+1];
            down(mid);
            //for (int i = 1;i <= mid; i++ ) cout << a[i] << " ";cout << endl;
        }
        printf("%d\n",a[1]);
    //}
	return 0;
}

