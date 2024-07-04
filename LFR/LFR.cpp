#include<bits/stdc++.h>
using namespace std;



void sieve(int n,int c)
{
	int total=0,x,y;
	int M_prime[5000];
	int prime[5000]={0};

	for(int i=2;i<=n;i++){
		if(prime[i]==0){
			for(int j=i*i;j<=n;j+=i){
				prime[j]=1;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(prime[i]==0){
			M_prime[total++]=i;
		}
	}
	if(c>=n){
		x=1;
		y=total;
	}
	else{
	if(n%2==0){
		if(total%2==0){
			x=(total/2)-c;
			y=(total/2)+c;
		}
		else{
			x=((total+1)/2)-c;
			y=(total/2)+c;
		}
	}
	else{
		if(total%2==0){
			x=(total/2)-((2*c-1)/2);
			y=(total/2)+((2*c-1)/2);
		}
		else{
			x=((total+1)/2)-((2*c-1)/2);
			y=(total/2)+((2*c-1)/2);
		}
	}
	}
	cout<<n<<" "<<c<<": ";
	for(int i=x-1;i<y;i++){
		cout<<M_prime[i]<<" ";
	}
	cout<<endl<<endl;


}


int main()
{
	int n,c;
	while(cin>>n>>c){
		sieve(n,c);
	}

}