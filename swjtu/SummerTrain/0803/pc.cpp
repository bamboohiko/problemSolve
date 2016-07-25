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
    int n;
    while (scanf("%d",&n) != EOF) {
        int p = 0,m = 0;
        while (n) {
            int p0;
            for (p0 = 1;(n*p0 + m)%10 != 1; p0++) ;
            cout << p0 << endl;
            m += n*p0/10;
            p = p*10 + p0;
        }
        printf("%d\n",log10(n)+log10(p));
    }
	return 0;
}
