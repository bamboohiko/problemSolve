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
const int n = 437338199;
int main() {
    vector<int> a;
    for (int i = 2;i*i <= n; i++) {
        if (n%i == 0) a.push_back(i);
    }
    for (int i = 0;i < a.size(); i++)
        cout << a[i] << " ";cout << endl;
    return 0;
}
