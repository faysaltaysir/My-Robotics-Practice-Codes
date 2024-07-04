#include<bits/stdc++.h>
using namespace std;
//const int N=1000;

int main(){
    int n,c;
    while(cin>>n>>c){
        bool prime[n+1];
        memset(prime,true,sizeof(prime));
        vector<int>x;
        for(int i=2;i*i<=n;i++){
            if(prime[i]==true){
                for(int j=2*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
        }

        for(int i=1;i<=n;i++){
            if(prime[i]==true) x.push_back(i);
        }
        //for(int i=0;i<x.size();i++){
          //  cout<<x[i]<<" ";
        //}
        //cout<<endl;
        if((x.size())%2==0){
            int a=2*c;
            int b=x.size()-a;
            int g=b/2;
            cout<<n<<" "<<c<<":";
            if(a>x.size()){
                for(int i=0;i<x.size();i++) cout<<" "<<x[i];
            }
            else{
                for(int i=g;i<a+g;i++) cout<<" "<<x[i];
            }
            cout<<endl<<endl;
        }
        else{
            int d=2*c-1;
            int e=x.size()-d;
            int f=e/2;
            cout<<n<<" "<<c<<":";
            if(d>x.size()){
                for(int i=0;i<x.size();i++) cout<<" "<<x[i];
            }
            else{
                for(int i=f;i<f+d;i++) cout<<" "<<x[i];
            }
            cout<<endl<<endl;
        }
    }
    return 0;
}