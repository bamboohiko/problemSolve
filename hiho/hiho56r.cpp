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
#include<cstdlib>
#include<ctime>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long LL;
int main() {
    freopen("in.txt","w",stdout);
    srand(time(NULL));
    int n = 4,m = 4;
    cout << n << " " << m << endl;
    for (int i =  1;i <= m; i++) {
        for (int j = 1;j <= n; j++) cout << (rand()%10) << " ";
        cout << rand()%10 << endl;
    }
	return 0;
}
