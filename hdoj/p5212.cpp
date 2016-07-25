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
int gcd(int a,int b) {
	while (b) {
		int t = a;a = b;b = t%b;
	}
	return a;
}
int a[10010];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i = 1;i <= n; i++) 
			scanf("%d",&a[i]);
		int res=0;
  		for(int i=1;i<=n;i++)
  	    	for(int j=1;j<=n;j++) {      
  	    		int sav = gcd(a[i],a[j])*(gcd(a[i],a[j])-1);
  	    		cout << a[i] << " " << a[j] << " " << sav << endl;
  		 		res+=sav;     
  		 		res%=10007;    
  		  		}
		printf("%d\n",res);
	}
	return 0;
}
