#include<iostream>
using namespace std;

class Hero{
    int health;
    char level;
public:
    getHealth()
    {
        return health;
    }
    setHealth(int a,char name){
        if(name == 'A')
            health=a;
        else
            health=0;
    }
};
int main()
{
    Hero fahmi;
    int a;char b;
//  cout<< "size of"<< sizeof(fahmi);
    cin>>a;
    cin>>b;
    fahmi.setHealth(a,b);
    cout<<fahmi.getHealth()<<endl;

}
