#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		long long int s[n],a[n],i,x[n];
		for(i=0;i<n;i++){
			cin>>s[i];
			a[i]=s[i];
		}
		sort(a,a+n);
		for(i=0;i<n;i++){
			if(s[i]!=a[n-1]){
				x[i]=s[i]-a[n-1];
			}
			else{
				x[i]=s[i]-a[n-2];
			}
		}
		for(i=0;i<n;i++){
			cout<<x[i]<<" ";
		}
		cout<<endl;

	}
}