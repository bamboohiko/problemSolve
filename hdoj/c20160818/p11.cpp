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
int fir[20] = {0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,7};
int sec[10] = {0,0,6,6,5,5,5,7,6,6};
int base[1010],num[1010];
int main() {
    for (int i = 0;i < 100; i++) {
        if (i < 20) base[i] = fir[i];
        else base[i] = sec[i/10] +  fir[i%10];
        num[i] = num[i-1] + base[i];
    }
    for (int i = 100;i < 1000; i++) {
        if (i%100) base[i] = fir[i/100] + base[i%100] + 10;
        else base[i] = fir[i/100] + 7;
        num[i] = num[i-1] + base[i];
    }
    base[1000] = 11;num[1000] = num[999] + base[1000];
    int t,k;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&k);
        cout << "!" << base[k] << endl;
        //printf("%d\n",num[k]);
    }
	return 0;
}
