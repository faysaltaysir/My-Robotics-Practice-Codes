static int i=0,j=0,k;int n,x=1,q,p,t;
class read_value{
  protected:
  String name;float length,breadth,height,volume,inches,inches2,diameter;
	float duration,duration2;float distance,distance2;
  float read_val(int a,int b){
    int echoPin=a;int trigPin=b;
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT);
    digitalWrite(trigPin, LOW);   // Makes trigPin low
    delayMicroseconds(2);       // 2 micro second delay 
    digitalWrite(trigPin, HIGH);  // tigPin high 
    delayMicroseconds(10);      // trigPin high for 10 micro seconds
    digitalWrite(trigPin, LOW);   // trigPin low
    duration = pulseIn(echoPin, HIGH);   //Read echo pin, time in microseconds
    distance = duration*0.034/2;        //Calculating actual/real distance
    inches = distance / 2.54;
    return inches;
  }
  void read_name(){
    Serial.println("Name of the object: ");
    while(Serial.available()==0){}
    name=Serial.readString();
    Serial.println(name);
  }
  //friend class dimention;
};
class dimention:public read_value
{	
public:
	void cube_getter()
	{  
    read_name();
    for(int k=0;k<=4;k++)
      length=read_val(2,3);    //pinNumbers as perameters
    breadth=0;height=0;diameter=0;
	  volume=length*length*length;
    setter();
		i++;   
	}
	void cuboid_getter()
	{
		read_name();
    for(int k=0;k<=4;k++){
      length=read_val(2,3);           //pinNumber where sensor is attached
      breadth=read_val(4,5);          //pinNumber
      height=read_val(6,7);           //pinNumber
    }
		diameter=0;
		volume=length*breadth*height;
		i++;
    setter();
	}
	void cone_getter()
	{
		read_name();
    for(int k=0;k<=4;k++){
      diameter=read_val(2,3);
      height=read_val(6,7);
    }
		i++;length=0;breadth=0;
		volume=3.1416*(diameter/2)*(diameter/2)*(height/3);
    setter();
	}
	void cylinder_getter()
	{
		read_name();
    for(int k=0;k<=4;k++){
      diameter=read_val(2,3);
      height=read_val(6,7);
    }
		length=0;breadth=0;
		volume=3.1416*(diameter/2)*(diameter/2)*height;i++;
    setter();
	}
	void sphere_getter()
	{
    
		read_name();
    for(int k=0;k<=4;k++){
      diameter=read_val(2,3);
    }
		i++;length=0;breadth=0;height=0;
		volume=4*3.1416*(diameter/2)*(diameter/2)*(diameter/2)/3;
    setter();
	}



	void setter()
	{
    Serial.print(".........(");Serial.print(j+1);Serial.println(")..........");
    Serial.print("Name of the object:     ");Serial.println(name);
    Serial.print("Length of the object:   ");Serial.println(length);
    Serial.print("Breadth of the object:  ");Serial.println(breadth);
    Serial.print("Height of the object:   ");Serial.println(height);
    Serial.print("Diameter of the object: ");Serial.println(diameter);
    Serial.print("Volume of the object:   ");Serial.println(volume);
	}

  int largest(dimention a[]){
  int max=a[0].volume;int temp;
  for(int j=0;j<i;j++){
    if(a[j].volume>max){
      max=a[j].volume;temp=j;
    }
  }
  return temp;
}
  //friend void largest(dimention); 
	};
class display{
  public:
  static void print()
	{
		/*cout<<"\t\t\t\t________________________\t\t\t\t"<<endl;
		cout<<"\t\t\t\t Auto Dimention Counter \t\t\t\t"<<endl;
		cout<<"\t\t\t\t________________________\t\t\t\t"<<endl;
		cout<<"1) Calculate My Object Dimention:-"<<endl;
		cout<<"2) Show previous Entry :-"<<endl;
		cout<<"3) Remove a Unwanted Entry:-"<<endl;
		cout<<"4) Exit:-"<<endl<<endl<<endl;
		cout<<"Make Your Choice"<<endl;*/
    Serial.println("\t\t\t\t________________________\t\t\t\t");
    Serial.println("\t\t\t\t Auto Dimention Counter \t\t\t\t");
    Serial.println("\t\t\t\t________________________\t\t\t\t");
    Serial.println("1) Calculate My Object Dimention:-");
    Serial.println("2) Show previous Entry :-");
    Serial.println("3) Remove a Unwanted Entry:-");
    Serial.println("4) Exit:-");
    Serial.println("make your choice");
	}
	static void print_2()
	{/*
		cout<<".........("<<k<<").........."<<endl;
		cout<<"1) Cube"<<endl;
		cout<<"2) Cuboid"<<endl;
		cout<<"3) Cone"<<endl;
		cout<<"4) Cylinder"<<endl;
		cout<<"5) Sphere"<<endl<<endl<<endl;
		cout<<"Make Your Choice"<<endl;k++;*/
    Serial.print(".........(");Serial.print(k);Serial.println(")..........");
    Serial.println("1) Cube");
    Serial.println("2) Cuboid");
    Serial.println("3) Cone");
    Serial.println("4) Cylinder");
    Serial.println("5) Sphere");
    Serial.println("make your choice");k++;
	}

};
class adminLogin{
  private:
  int admin(){
    String username="faysal";String password="taysir",user,pass;
    Serial.println("UserName: ");
    while(Serial.available()==0){}
    user=Serial.readString();Serial.println(user);  
    Serial.println("Password: ");
    while(Serial.available()==0){}
    pass=Serial.readString();Serial.println(pass);  
    if(user==username && pass==password){
      Serial.print("s");
      return 5;
    }
    else return 0;  
  }
  int worker(){
    String username="worker";String password="123",user,pass;
    Serial.println("UserName: ");
    while(Serial.available()==0){}
    user=Serial.readString();Serial.println(user);  
    Serial.println("Password: ");
    while(Serial.available()==0){}
    pass=Serial.readString();Serial.println(pass);  
    if(user==username && pass==password){
      return 2;
    }
    else return 0;  
  }
  friend int admin_worker();// user and password will remain protected

};

void setup(){       // ***********************like void main()
  Serial.begin(9600);//int i=0;
	dimention a[10],b;
  int n_value();int q_value();
  p=admin_worker();
  if(p==5){  // ******************* admin
    while(x==1){
      display::print();
      t=t_value();
      if(t==2){
        Serial.print("int");
        for(int j=0;j<i;j++)
          a[j].setter();
      }
      else if(t==1){ 
			  n=n_value();
        while(n--){
				  display::print_2();
          q=q_value();
          input(q,a);   //*** sending the object array to the funtion  
		    }
      }
      else if(t==3){
        b.largest(a);
      }
      
		}
  }
  else if(p==2){ //************* Worker
    while(x==1){
      display::print();
      t=t_value();
      if(t==1){
			  n=n_value();
        while(n--){
				  display::print_2();
          q=q_value();
			    input(q,a);   //*** sending the object array to the funtion
       
        }
      }
    }
  }
  else if(p==3){//****************** 

  }
}



void input(int q,dimention a[]){
  if(q==1)
    a[i].cube_getter();
  else if(q==2)
    a[i].cuboid_getter();
  else if(q==3)
	  a[i].cone_getter();
	else if(q==4)
	  a[i].cylinder_getter();
	else if(q==5)
		a[i].sphere_getter();

    Serial.print(i);
} 

int admin_worker(){ //******************* friend funtion of adminLogin class
  adminLogin a;
  Serial.println("Who are You? Write your choise.");
  Serial.println("admin or worker");
  while(Serial.available()==0){}
  String s=Serial.readString();
  if(s=="admin")
    return a.admin();
  else if(s=="worker")
    return a.worker();
}
int n_value(){
  Serial.println("Number of Objects Wanna add: ");
	while(Serial.available()==0){}
  n=Serial.parseInt();Serial.println(n);Serial.println("");k=1;
  return n;
}
int q_value(){
  while(Serial.available()==0){}
	q=Serial.parseInt();Serial.println(q);Serial.println("");
  return q;
}
int t_value(){
  while(Serial.available()==0){}
	t=Serial.parseInt();Serial.println(t);Serial.println("");
  return t;
}

void loop(){

}





