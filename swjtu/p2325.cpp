#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cmath>
using namespace std;

class Speed{
public:
    void initinumlizeDnumtnum(int n,int m){
        for(int i = 0;i < n;i++){
            cin >> num[i];
            num[i] = m / num[i];
        }
        sort(num,num+n);
    }
    double solve(int n,double ret){
        if(n == 3){
            return num[0] + num[1] + num[2] + ret;
        }else if(n == 2) return num[1] + ret;
                else if(n == 1) return ret + num[0];

        if(num[0] * 2 + num[n-1] + num[n-2] > num[n-1] + num[1] * 2 + num[0]){
            return solve(n-2,ret + num[n-1] + num[1] * 2 + num[0]);
        }
        else return solve(n-2,ret + num[0] * 2 + num[n-1] + num[n-2]);
    }
private:
    double num[10005];
};

int main(){
    //freopen("data.in","r",stdin);
    Speed test;
    int n,m;
    while(cin >> n >> m){
        test.initinumlizeDnumtnum(n,m);
        cout << ceil(test.solve(n,0)) << endl;
    }
    return 0;
}
