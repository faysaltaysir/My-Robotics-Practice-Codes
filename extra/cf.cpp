#include<bits/stdc++.h>
using namespace std;

int main()
{   long long int n1,j,add,a,k;
    cin>>a;
    while(a--){add=0;
        cin>>n1;
        long long int g[n1],f[n1];
        for(j=0;j<n1;j++){
            cin>>g[j];
            add+=g[j];
        }
        for( j=0;j<n1;j++){
            cin>>f[j];
            add+=f[j];
        }
        k=*max_element(f,f+n1);
        add=add-k;
        cout<<add<<endl;


    }
}
