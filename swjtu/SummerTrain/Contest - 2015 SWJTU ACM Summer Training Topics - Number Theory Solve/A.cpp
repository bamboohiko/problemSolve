#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

const int maxn = 100002;
int arr[maxn];

long long quick_mod(long long a, long long b) {
    long long ans = 1;
    while(b > 1) {
        if(b % 2 != 0) {
            ans = ans * a % 29;
            b--;
        } else {
            a = (a * a) % 29;
            b /= 2;
        }
    }
    return a * ans % 29;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF && n) {
        int cnt1 = quick_mod(2, 2 * n + 1);
        int cnt2 = quick_mod(3, n + 1);
        int cnt3 = quick_mod(22, n + 1);
        cout << (cnt1 - 1)*(cnt2 - 1) * 15 * (cnt3 - 1) * 18 % 29 << endl;
    }
    return 0;
}