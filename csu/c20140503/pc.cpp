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
	Matrix mod(LL p) {
		Matrix ans;
		ans.x1 = x1%p;
		ans.x2 = x2%p;
		ans.y1 = y1%p;
		ans.y2 = y2%p;
		return ans;
	}
	void output() {
		printf("%lld %lld\n%lld %lld\n\n",x1,x2,y1,y2);
	}
	Matrix exp(LL n,LL p) {
		Matrix t(1,0,0,1);
		Matrix a(x1,x2,y1,y2);
		while (n) {
			if (n%2) t = (t*a).mod(p);
			a = (a*a).mod(p);
			n /= 2;
		}
		return t;
	}
};
int main()
{
	int t;
	scanf("%d",&t);
	while (t--) {
		LL x,y,a,b,p,n;
		scanf("%d%d%d%d%d%d",&x,&y,&a,&b,&p,&n);
		Matrix mat1(a,b,1,0);
		Matrix mat2 = mat1.exp(n,p);
		printf("%d\n",(y*mat2.x1 + x*mat2.x2)%p);
	}
	return 0;
}
