#include<iostream>  	//the answer is too big to longlong can't save the number.So what should I do?
using namespace std;
long long rec[110][110];
long long f(int a,int b)
{long long sum = 0;
	//cout << a << " " << b << endl;
	if (rec[a][b]) return rec[a][b];
	if (a > 0) sum+=f(a-1,b);
	if (b > 0) sum+=f(a+1,b-1);
	return rec[a][b] = sum;
}
int main()
{int n;
	rec[0][0] = 1;
	f(0,100);
	while (cin >> n)
		cout << f(0,n) << endl;
	return 0;
}
