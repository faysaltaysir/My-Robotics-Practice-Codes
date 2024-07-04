#include<iostream>
using namespace std;
class complex
{
private:
    int x,y,p,q;
public:
    void getdata()
    {
        cin>>x>>y;
    }
    void display_complex()
    {
        cout<<x<<"+"<<y<<"i"<<endl;
    }
    friend class sum_complex;
};
class sum_complex
{
public:
    void sum(complex a,complex b){
    int sum1,sum2;
    sum1=a.x+b.x;
    sum2=a.y+b.y;
    cout<<"Summation:\n";
    cout<<sum1<<"+"<<sum2<<"i"<<endl;
    }
};
int main()
{
    complex c1,c2;
    c1.getdata();
    c2.getdata();
    c1.display_complex();
    c2.display_complex();
    sum_complex c3;
    c3.sum(c1,c2);
}
