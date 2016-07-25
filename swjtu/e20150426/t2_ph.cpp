#include<iostream>
using namespace std;
bool f[26];
void init(){
	for(int i=0;i<26;i++)
		f[i] = false;
}
int main(){
	int n;
	bool flag;
	char ch;
	while(cin>>n){
		init();
		flag = false;
		for(int i = 0; i < n; i++){
			cin>>ch;
			if((ch>='A')&&(ch<='Z'))
				ch+=32;
			if(!f[ch-97])
				f[ch-97] = true;
		}
		for(int i = 0; i < 26; i++){
			if(f[i] == false){
				flag = true;
				break;
			}
		}
		if(flag)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
