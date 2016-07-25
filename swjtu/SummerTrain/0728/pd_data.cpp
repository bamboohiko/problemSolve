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
#include<ctime>
using namespace std;
int main() {
    srand(time(NULL));
    for (int k = 1;k <= 5; k++) {
    int n = 5;
    cout << n << endl;
    for (int i = 1;i <= n; i++) {
        for (int j = 1;j <= n; j++)
            cout << (rand()%10) << " ";
        cout << endl;
    }
    }
	return 0;
}


