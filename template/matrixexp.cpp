#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef int LL;
const LL mod = 10000;
struct Matrix{
	LL x1,x2,y1,y2;
	Matrix(LL x1 = 0,LL x2 = 0,LL y1 = 0,LL y2 = 0):x1(x1),x2(x2),y1(y1),y2(y2) {}
	Matrix operator *(const Matrix& rhs) {
		Matrix ans;
		ans.x1 = (x1*rhs.x1 + x2*rhs.y1)%mod;
		ans.x2 = (x1*rhs.x2 + x2*rhs.y2)%mod;
		ans.y1 = (y1*rhs.x1 + y2*rhs.y1)%mod;
		ans.y2 = (y1*rhs.x2 + y2*rhs.y2)%mod;
		return ans;
	}
	void output() {
		printf("%d %d\n%d %d\n\n",x1,x2,y1,y2);
	}
};
Matrix matrixexp(Matrix a,int n) {
		Matrix t(1,0,0,0);
		while (n) {
			if (n&1) t = t*a;
			a = a*a;
			n >>= 1;
            //a.output();
		}
		return t;
}
int main() {
	Matrix a(1,1,1,0);
	int k;
	while (scanf("%d",&k) != EOF){
		if (k == -1) break;
		if (k == 0) printf("0\n");
		else printf("%d\n",matrixexp(a,k-1).x1);
	}
	return 0;
}
