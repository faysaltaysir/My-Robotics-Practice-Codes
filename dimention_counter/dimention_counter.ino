#define echoPin 2 
#define trigPin 3
class dimention {
  private:
    float length;
    String obj_name;
    int i=0;long duration;int distance;
  public:
    void manu();
    void calculate();
    void display();
    void remove();
    void exit();
    float sensor();
    void input();
    void counter();
    void cube();
    void cuboid();
    void sphere();
    void cylinder();
    void cone();
};
void dimention :: manu(){
  while(1){
    int choice;
    String type;
    Serial.println("/t/t/t/t________________________/t/t/t/t");
    Serial.println("/t/t/t/t Auto Dimention Counter /t/t/t/t");
    Serial.println("/t/t/t/t________________________/t/t/t/t");
    Serial.println("1) Calculate My Object Dimention:-");
    Serial.println("2) Show previous Entry :-");
    Serial.println("3) Remove a Unwanted Entry:-");
    Serial.println("4) Exit:-");
    Serial.println("Make Your Choice");
    while(Serial.available()==0){ }
    choice=Serial.parseInt();

    if(choice==1){
      calculate();
    }
    else if(choice==2){
      display();
    }
    else if(choice==3){
      remove();
    }
    else if(choice==4){
      exit();
    }
    else{
      Serial.println("Make Your Choice from list");
    }
  }
}
void dimention :: calculate(){int choice;dimention x[10];
  Serial.print("Number of Objects:-\t");
  while(Serial.available()==0){}
  int n=Serial.parseInt();//int x=n;
  while(n--){
    Serial.println("Choose the Shape of Your Object:-");
    Serial.println("1) Cube");
    Serial.println("2) Cuboid");
    Serial.println("3) Cylinder");
    Serial.println("4) Cone");
    Serial.println("5) Sphere");
    
    if(choice==1){
      cube();
    }
    else if(choice==2){
      cuboid();
    }
    else if(choice==3){
      cylinder();
    }
    else if(choice==4){
      cone();
    }
    else if(choice==5){
      sphere();
    }
    else{
      Serial.println("Make Your Choice from list");
    }
  }
} 
float dimention :: sensor(){
    digitalWrite(trigPin, LOW);
  	delayMicroseconds(2);
  	digitalWrite(trigPin, HIGH);
  	delayMicroseconds(10);
  	digitalWrite(trigPin, LOW);
  	duration = pulseIn(echoPin, HIGH);
  	distance = duration * 0.034 / 2;
    return distance;
}
void dimention :: cube(){
  Serial.print("length");
  while(Serial.available()==0){}
  char y=Serial.parseInt();
  float length=sensor();Serial.println(length);
  float area=length*length;
  Serial.println(area);
}
void setup() {
  // put your setup code here, to run once:
  dimention a;
  Serial.begin(9600);
  a.manu();
}

void loop() {
  // put your main code here, to run repeatedly:
}
