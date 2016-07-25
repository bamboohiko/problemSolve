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
typedef long long LL;
struct Matrix{
	LL x1,x2,y1,y2;	
	Matrix(LL x1 = 0,LL x2 = 0,LL y1 = 0,LL y2 = 0):x1(x1),x2(x2),y1(y1),y2(y2) {}
	Matrix operator *(const Matrix& rhs) {
		Matrix ans;
		ans.x1 = x1*rhs.x1 + x2*rhs.y1;
		ans.x2 = x1*rhs.x2 + x2*rhs.y2;
		ans.y1 = y1*rhs.x1 + y2*rhs.y1;
		ans.y2 = y1*rhs.x2 + y2*rhs.y2;
		return ans;
	}
	void output() {
		printf("%lld %lld\n%lld %lld\n\n",x1,x2,y1,y2);
	}
	Matrix exp(int n) {
		Matrix t(1,0,0,1);
		Matrix a(x1,x2,y1,y2);
		while (n) {
			if (n%2) t = t*a;
			a = a*a;
			n /= 2;
		}
		return t;
	}
};
int main()
{
	Matrix a(1,1,1,0);
	printf("%lld\n",a.exp(10).x1);
	return 0;
}
