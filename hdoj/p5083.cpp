#include<iostream>
#include<string>
#include<cstdio>
#include<map>
#include<stack>
using namespace std;
string dic[7]={"","ADD","SUB","DIV","MUL","MOVE","SET"};
const int pow[]={1,2,4,8,16};
char a[5];
map<string,int> op;
void difin()
{
	op["ADD"]=1;
	op["SUB"]=2;
	op["DIV"]=3;
	op["MUL"]=4;
	op["MOVE"]=5;
	op["SET"]=6;
}
int bi(int a)
{int t=0;
	for (int i = 1;i <= 5; i++)
		{t+=(a%10)*pow[i-1];
		 a/=10;
		}
	return t;
}
void print(int a,int len)
{stack<int> s;
	while (a) 
		{s.push(a%2);
		 a/=2;
		}
	for (int i = 1;i <= len-s.size(); i++) 
		cout << 0;
	while (!s.empty()) 
		{cout << s.top();
		 s.pop();
		}	
}
void binary(int x,int a,int b)
{
	if ((x == 6) && (a) && !(b)) 
		{cout << dic[x] << " R" << a;
		return;
		}
	if ((x > 0) && (x < 6) && (a) && (b))
		{cout << dic[x] << " R" << a << ",R" << b;
		return;
		}
	cout << "Error!";
	return;
}
int main()
{freopen("test.in","r",stdin);
freopen("test.out","w",stdout);
int x,t,r1,r2;
char ch;
long long code;
	difin();
	while (cin >> t)
		{if (t) 
			{cin >> a >> ch >> r1;
			 print(op[a],6);
			 print(r1,5);
			 if (op[a] != 6) 
			 	{cin >> ch >> ch >> r2;
			 	 print(r2,5);
				 }
			 else cout << "00000";
			 cout << endl;
			}
		else 
			{cin >> code;
			 r2=bi(code%100000);code/=100000;
			 r1=bi(code%100000);code/=100000;
			 x=bi(code);
			 binary(x,r1,r2);
			 cout << endl;
			}
		}
	return 0;
}
