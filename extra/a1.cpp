#include<bits/stdc++.h>
using namespace std;
class book_shop{
	string title,author,publ;
	double price;
	int stock;
public:
	book_shop(string title,string author,string publ,double price,int stock){
		this->title=title;
		this->author=author;
		this->publ=publ;
		this->price=price;
		this->stock=stock;
	}
	bool finding(string x,string y){
		if(x==title&&y==author){
			cout<<"\nThe Book is Found.";
			show();
			display();
			return true;
		}
		else return false;
	}
 double buy(string x,string y,int s)
 {
 if(x==title&&y==author)
 {
 if(s>stock)return -1;
 else
 {
 stock-=s;
 return s*price;
 }
 }
 else return 0;
 }
 void display()
 {
 cout<<setw(20)<<title;
 cout<<setw(20)<<author;
 cout<<setw(20)<<publ;
 cout<<setw(20)<<price;
 cout<<setw(20)<<stock;
 }
 void show()
 {
 cout<<"\nDisplaying Books Details >> \n\n";
 cout<<setw(20)<<"Book Title";
 cout<<setw(20)<<"Author";
 cout<<setw(20)<<"Publisher";
 cout<<setw(20)<<"Price";
 cout<<setw(20)<<"Stock";
 cout<<endl;
 }
};
int main()
{
 vector<book_shop>v;
 while(1)
 {
 int i,n,b;
 double a;
 string author,title,publr;
 cout<<"Press : "<<endl;
 cout<<"1.book updating"<<endl;
 cout<<"2.want to buy"<<endl;
 cout<<"3.available books"<<endl;
 cout<<"4.Exit."<<endl;
 cout<<"Enter Your Choice : "<<endl;
 cin>>n;
 if(n==1)
 {
 cout<<"update Books \n";
 cout<<"Enter Book Title : ";
 getchar();
 getline(cin,title);
 cout<<"Enter Author Name : ";
 getchar();
 getline(cin,author);
 cout<<"Enter name of Publisher's : ";
 getchar();
 getline(cin,publr);
 cout<<"Enter Price : ";
 cin>>a;
 cout<<"Enter Number of Stock : ";
 cin>>b;
 book_shop bp(title,author,publr,a,b);
 v.push_back(bp);
 }
 else if(n==2)
 {
 cout<<"\nBuying....\n";
 cout<<"Enter Book Title : ";
 getchar();
 getline(cin,title);
 cout<<"Enter Author Name : ";
 getchar();
 getline(cin,author);
 cout<<"Enter number of books : ";
 cin>>b;
 n=v.size();
 for(i=0;i<n;i++)
 {
 double d=v[i].buy(title,author,b);
 if(d==-1)
 {
 cout<<"stock out"<<endl;
 break;
 }
 else if(d)
 {
 cout<<"\nTotal Price = "<<d<<endl;
 break;
 }
 else continue;
 }
 if(i==n)cout<<"\nThis Book is not available.\n";
 }
 else if(n==3)
 {
 v[0].show();
 n=v.size();
 for(i=0;i<n;i++)
 {
 v[i].display();
 cout<<endl;
 }
 }
 else if(n==4)
 {
 cout<<"................BYE";
 break;
 }
 }
 return 0;
}
