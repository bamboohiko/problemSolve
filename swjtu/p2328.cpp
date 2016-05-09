#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct State{
	char data[4];
	int step;
};
int m1[8][8][8][8],m2[8][8][8][8];
int ans=0;
void swap(char &ch1,char &ch2){
	char t = ch1;
	ch1 = ch2;
	ch2 = t;
}
int find(State t,int k){
	if(k==1)
		return m1[t.data[0]-'A'][t.data[1]-'A'][t.data[2]-'A'][t.data[3]-'A'];
	else
		return m2[t.data[0]-'A'][t.data[1]-'A'][t.data[2]-'A'][t.data[3]-'A'];
}
void mark(State t,int k){
	if(k==1)
		m1[t.data[0]-'A'][t.data[1]-'A'][t.data[2]-'A'][t.data[3]-'A'] = t.step;
	else
		m2[t.data[0]-'A'][t.data[1]-'A'][t.data[2]-'A'][t.data[3]-'A'] = t.step;
}
bool add1(queue<State> &q1,State t){
	int temp;
	if((temp = find(t,2))!=-1){
		ans = temp+t.step;
		return true;
	}else{
		mark(t,1);
		q1.push(t);
		return false;
	}
	return false;
}
bool add2(queue<State> &q2,State t){
	int temp;
	if((temp = find(t,1))!=-1){
		ans = temp+t.step;
		return true;
	}else{
		mark(t,2);
		q2.push(t);
		return false;
	}
	return false;
}
queue<State> q1,q2;
void bfs(State start,State end){
	State now;
	int temp1=0,temp2=0;	
	memset(m1,-1,sizeof(m1));
	memset(m2,-1,sizeof(m2));
	while(!q1.empty()){
		q1.pop();
	}
	while(!q2.empty()){
		q2.pop();
	}
	q1.push(start);
	q2.push(end);
	mark(start,1);
	mark(end,2);
	if(find(start,2)!=-1)
		cout<<0<<endl;
	else while(1){
		while(!q1.empty()&&q1.front().step==temp1){
			now = q1.front();
			q1.pop();
			for(int i=0;i<4;i++){
				State st = now;
				st.step++;
				st.data[i] = (st.data[i]-'A'+7)%8+'A';
				if(add1(q1,st)){
					cout<<ans<<endl;
					return;
				}
				st = now;
				st.step++;
				st.data[i] = (st.data[i]-'A'+1)%8+'A';
				if(add1(q1,st)){
					cout<<ans<<endl;
					return;
				}
				if(i<3){
					st = now;
					st.step++;
					swap(st.data[i],st.data[i+1]);
					if(add1(q1,st)){
						cout<<ans<<endl;
						return;
					}
				}
			}
		}
		temp1 = q1.front().step;
		//逆向
		while(!q2.empty()&&q2.front().step==temp2){
			now = q2.front();
			q2.pop();
			for(int i=0;i<4;i++){
				State st = now;
				st.step++;
				st.data[i] = (st.data[i]-'A'+7)%8+'A';
				if(add2(q2,st)){
					cout<<ans<<endl;
					return;
				}
				st = now;
				st.step++;
				st.data[i] = (st.data[i]-'A'+1)%8+'A';
				if(add2(q2,st)){
					cout<<ans<<endl;
					return;
				}
				if(i<3){
					st = now;
					st.step++;
					swap(st.data[i],st.data[i+1]);
					if(add2(q2,st)){
						cout<<ans<<endl;
						return;
					}
				}
			}
		}
		temp2 = q2.front().step;
	}
}
int main(){
	char str1[10],str2[10];
	int t;
	cin>>t;
	while(t--){
		cin>>str1>>str2;
		State start,end;
		for(int i=0;i<4;i++){
			start.data[i] = str1[i];
			end.data[i] = str2[i];
		}
		start.step = 0;
		end.step = 0;
		bfs(start,end);
	}
	return 0;
}
