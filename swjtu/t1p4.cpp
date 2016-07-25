/*#include<iostream>
#include<string>
using namespace std;
bool cmp(string& a,string& b)
{
	if (a.length() != b.length()) return a.length() < b.length();
	for (int i = 0;i <a.length(); i++)
		if (a[i] != b[i]) return a[i] < b[i];
	return false;
}
int main()
{int n;
	while (cin >> n)
		{string ans,s;
		cin >> ans;
		for (int i = 1;i < n; i++)
			{cin >> s;
			if (cmp(s,ans)) ans = s;
			}
		cout << ans << endl;
		}
	return 0;
}*/
#include<stdio.h>
#include<string.h>
int cmp(char a[],char b[])
{int lena = strlen(a),lenb = strlen(b);
	if (lena != lenb) return (lena < lenb);
	for (int i = 0;i < lena; i++)
		if (a[i] != b[i]) return (a[i] < b[i]);
	return 1;	
}
int main()
{int n;
	while (scanf("%d",&n) != EOF)
		{char s[110],ans[110];
		scanf("%s",ans);
		for (int i = 1;i < n; i++)
			{scanf("%s",s);
			if (cmp(s,ans))
				sscanf(s,"%s",ans); 
			}
		printf("%s\n",ans);
		}
	return 0;
}
