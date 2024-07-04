	#include<iostream>
using namespace std;
int main()
{
	string s,c;int x=0;
	for(int i=0;;i++){
		cin>>s[i];
		if(s[i]=='f') break;
	}
	for(int i=0;s[i]!='f';i++){
		cout<<s[i];
	}
	for(int i=0;s[i]!='f';i++){
		if(s[i-1]=='L' &&s[i]=='B' &&  s[i+1]=='L'){
			c[x-1]='S';i=i+1;
		}
		else{
			c[x]=s[i];x++;
		}
		c[x+1]='f';
	}
	for(int i=0;c[i]!='f';i++){
		cout<<c[i];
	}



}