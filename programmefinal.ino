#include <LiquidCrystal.h>// bib de lcd 
LiquidCrystal lcd(40,38,36,34,32,30);//declaration les pin de lcd
LiquidCrystal lcd2(28,26,24,22,53,51);
LiquidCrystal lcd3(33,31,29,27,25,23);
int sw1=11; int sw2=10; int sw3=9; int sw4=8; int sw5=7; int sw6=6;//declaration les pin des switch decircuit ouvert  les injecteur 
int swe=49;int swf=47; int swa=45;int swo=43;
int cc1=5; int cc2=4; int cc3=3; int cc4=2; int cc5=12; int cc6=13;//declaration les pin des switch de court cercuit de les injecteur
int cce=41; int ccf=39; int cca=37; int cco=35;
int injec1=52; int injec2=50;int injec3=48; int injec4=46;int injec5= 44; int injec6=42;//declaration des pin de les injecteur

int engine=A0;int crank1=A1;int oil=A2;int throttel1=A3;int Fuel=A4;int Atmospherique=A5;
int boost=A8; int Speed=A7;

int off=A9;int on =A10;int start= A11;

void setup() {
pinMode(sw1,INPUT);pinMode(sw2,INPUT);pinMode(sw3,INPUT);pinMode(sw4,INPUT);pinMode(sw5,INPUT);pinMode(sw6,INPUT);//declaration des switch comme input
pinMode(cc1,INPUT);pinMode(cc2,INPUT);pinMode(cc3,INPUT);pinMode(cc4,INPUT);pinMode(cc5,INPUT);pinMode(cc6,INPUT);//declaration des switch comme input
pinMode (swe,INPUT);pinMode (swf,INPUT);pinMode (swa,INPUT); pinMode (swo,INPUT);
pinMode (cce,INPUT);pinMode (ccf,INPUT);pinMode (cca,INPUT);pinMode (cco,INPUT);
pinMode (off, INPUT);pinMode (on, INPUT); pinMode(start,INPUT);
pinMode(injec1,OUTPUT);pinMode(injec2,OUTPUT);pinMode(injec3,OUTPUT);pinMode(injec4,OUTPUT);pinMode(injec5,OUTPUT);pinMode(injec6,OUTPUT);//declaration des injecteur comme output
pinMode(engine,INPUT);pinMode(crank1,INPUT);pinMode(oil,INPUT);pinMode(throttel1,INPUT);pinMode (Fuel,INPUT); pinMode(Atmospherique,INPUT);pinMode(boost,INPUT);//declaration de pot comme input
lcd.begin(20,4);lcd2.begin(20,4);lcd2.begin(16,2);
}

void loop() {
on1();
off1();
start1();
  }
void pot(){
lcd.setCursor(0,0);lcd.print("Cool Temp");lcd.setCursor(10,0);lcd.print("Crank");//affiche dans la colonne 0 ligne 0 cool temp ,affiche dans la colonne 10 ligne  crank
lcd.setCursor(0,2);lcd.print("Oil Press");lcd.setCursor(10,2);lcd.print("Throttel");//affiche dans la colonne 0 ligne 2 oil..,affiche dans la colonne 10 ligne 2 throttel
lcd2.setCursor(0,0);lcd2.print("Fuelpress");lcd2.setCursor(10,0);lcd2.print("Atmospress");
lcd2.setCursor(0,2);lcd2.print("boost press");lcd3.clear();lcd3.setCursor(0,0);lcd3.print("code erreur");
  float y=analogRead(engine);//lir la valeur de pot engine
  float b=map(y,0,1023,38,141);// convertie la valeur 
  float z=analogRead(oil);//lir la valeur de pot de oil
  float c=map(z,0,1023,0,100);//convertir la valeur 
  float k=analogRead(throttel1);//lir la valeur pot throttel
  float d=map(k,0,1023,0,100);//convertir la valeur 
  float x=analogRead(crank1);//lir la valeur de pot crank
  float a=map(x,0,1023,0,100);//convertir la valeur 
  float s=analogRead(Fuel);
  float e=map(s,0,1023,0,100);
  float q=analogRead(Atmospherique);
  float f=map(q,0,1023,0,100);
  float r=analogRead(boost);
  float g=map(r,0,1023,0,100);
lcd.setCursor(0,1); lcd.print(b);//affiche dans lcd la valeur convertir de engine colonne 0 ligne1
lcd.setCursor(10,1);lcd.print(a);//affiche dans lcd la valeur convertir de crank colonne 10 ligne1
lcd.setCursor(0,3); lcd.print(c);//affiche dans lcd la valeur convertir de oil colonne 0 ligne3
lcd.setCursor(10,3);lcd.print(d);//affiche dans lcd la valeur convertir de throttel colonne 10 ligne3
lcd2.setCursor(0,1);lcd2.print(e);
lcd2.setCursor(10,1);lcd2.print(f);
lcd2.setCursor(0,3);lcd2.print(g);
}
int throttel(){
   float x=analogRead(throttel1);//lir la valeur pot throttel
   float a=map(x,0,1023,0,100);//convertir la valeur 
  if ((a>=0)&&(a<=34)){// si la valeur de throtele entre 0 et 34 return 1000
      return 1000;}
  if ((a>=35)&&(a<=68)){//si la valeur de throtele entre 35 et 68 return 600
      return 600 ;}
  if ((a>=69)&&(a<=100)){//si la valeur de  throtele entre 69 et 100 return 100
      return 100; }
}
void Shutdown(){
  float x=analogRead(engine);
  float a=map(x,0,1023,38,141);
  float y=analogRead(oil);
  float b=map(y,0,1023,0,100);
  while ((a<=141)&&(a>=138)){// si la valeur de engine est tres haut il y a shutdown tous les valeur de pot se transforme en * est tous les injecteur s'éteindre 
   x=analogRead(engine);
   a=map(x,0,1023,38,141);
   lcd.setCursor(0,0);lcd.print("Cool Temp");lcd.setCursor(10,0);lcd.print("Crank");
   lcd.setCursor(0,2);lcd.print("Oil Press");lcd.setCursor(10,2);lcd.print("Throttel");
   lcd2.setCursor(0,0);lcd2.print("Fuelpress");lcd2.setCursor(10,0);lcd2.print("Atmospress");
   lcd2.setCursor(0,2);lcd2.print("boost press");lcd3.setCursor(0,1);lcd3.print("E361/E265");
   lcd.setCursor(0,1);lcd.print("******");//affiche le * colonne0 ligne1
   lcd.setCursor(10,1);lcd.print("*****");
   lcd.setCursor(0,3);lcd.print("*****");
   lcd.setCursor(10,3);lcd.print("*****");
   lcd2.setCursor(0,1);lcd2.print("******");
   lcd2.setCursor(10,1);lcd2.print("*****");
   lcd2.setCursor(0,3);lcd2.print("*****");
    digitalWrite(injec1,LOW);digitalWrite(injec2,LOW);digitalWrite(injec3,LOW);
    digitalWrite(injec4,LOW);digitalWrite(injec5,LOW);digitalWrite(injec6,LOW);}
    while ((b<=3)&&(b>=0)){//si la valeur de oil est tres faible il y a shutdown tous les valeur de pot se transforme en * est tous les injecteur s'éteindre 
     y=analogRead(oil);
     b=map(y,0,1023,0,100);
   lcd.setCursor(0,0);lcd.print("Cool Temp");lcd.setCursor(10,0);lcd.print("Crank");
   lcd.setCursor(0,2);lcd.print("Oil Press");lcd.setCursor(10,2);lcd.print("Throttel");
   lcd2.setCursor(0,0);lcd2.print("Fuelpress");lcd2.setCursor(10,0);lcd2.print("Atmospress");
   lcd2.setCursor(0,2);lcd2.print("boost press");lcd3.setCursor(0,1);lcd3.print("E360/E265");
   lcd.setCursor(0,1);lcd.print("******");
   lcd.setCursor(10,1);lcd.print("*****");
   lcd.setCursor(0,3);lcd.print("*****");
   lcd.setCursor(10,3);lcd.print("*****");
   lcd2.setCursor(0,1);lcd2.print("******");
   lcd2.setCursor(10,1);lcd2.print("*****");
   lcd2.setCursor(0,3);lcd2.print("*****");
    digitalWrite(injec1,LOW);digitalWrite(injec2,LOW);digitalWrite(injec3,LOW);
    digitalWrite(injec4,LOW);digitalWrite(injec5,LOW);digitalWrite(injec6,LOW);}

    }
    
    void cc(){//en peut faire un court circuit dans le simulateur si la position de switch est 0 'est ouvert'
      int y=throttel();
     while(digitalRead(cc1)==0){//tous les injecteur s'allume son le 1ere injecteur
      lcd3.setCursor(0,1);lcd3.print("0001/06");
  digitalWrite(injec1,LOW);
  digitalWrite(injec5,HIGH);delay(y); digitalWrite(injec5,LOW);
  digitalWrite(injec3,HIGH);delay(y); digitalWrite(injec3,LOW);
  digitalWrite(injec4,HIGH);delay(y); digitalWrite(injec4,LOW);
  digitalWrite(injec2,HIGH);delay(y); digitalWrite(injec2,LOW);
  digitalWrite(injec6,HIGH);delay(y); digitalWrite(injec6,LOW);
}
while(digitalRead(cc2)==0){
   lcd3.setCursor(0,1);lcd3.print("0002/06");
  digitalWrite(injec5,LOW);
  digitalWrite(injec1,HIGH);delay(y); digitalWrite(injec1,LOW);
  digitalWrite(injec3,HIGH);delay(y); digitalWrite(injec3,LOW);
  digitalWrite(injec4,HIGH);delay(y); digitalWrite(injec4,LOW);
  digitalWrite(injec2,HIGH);delay(y); digitalWrite(injec2,LOW);
  digitalWrite(injec6,HIGH);delay(y); digitalWrite(injec6,LOW);
  
}
while(digitalRead(cc3)==0){
   lcd3.setCursor(0,1);lcd3.print("0003/06");
  digitalWrite(injec3,LOW);
  digitalWrite(injec1,HIGH);delay(y);digitalWrite(injec1,LOW); 
  digitalWrite(injec5,HIGH);delay(y);digitalWrite(injec5,LOW); 
  digitalWrite(injec4,HIGH);delay(y);digitalWrite(injec4,LOW);   
  digitalWrite(injec2,HIGH);delay(y);digitalWrite(injec2,LOW);   
  digitalWrite(injec6,HIGH);delay(y);digitalWrite(injec6,LOW);
}
while(digitalRead(cc4)==0){
   lcd3.setCursor(0,1);lcd3.print("0004/06");
  digitalWrite(injec4,LOW);
  digitalWrite(injec1,HIGH);delay(y);digitalWrite(injec1,LOW); 
  digitalWrite(injec5,HIGH);delay(y);digitalWrite(injec5,LOW); 
  digitalWrite(injec3,HIGH);delay(y);digitalWrite(injec3,LOW);   
  digitalWrite(injec2,HIGH);delay(y);digitalWrite(injec2,LOW);   
  digitalWrite(injec6,HIGH);delay(y);digitalWrite(injec6,LOW);
}
while(digitalRead(cc5)==0){
   lcd3.setCursor(0,1);lcd3.print("0005/06");
  digitalWrite(injec2,LOW);
  digitalWrite(injec1,HIGH);delay(y);digitalWrite(injec1,LOW); 
  digitalWrite(injec5,HIGH);delay(y);digitalWrite(injec5,LOW); 
  digitalWrite(injec3,HIGH);delay(y);digitalWrite(injec3,LOW);   
  digitalWrite(injec4,HIGH);delay(y);digitalWrite(injec4,LOW);   
  digitalWrite(injec6,HIGH);delay(y);digitalWrite(injec6,LOW);
 
}
while(digitalRead(cc5)==0){
   lcd3.setCursor(0,1);lcd3.print("0006/06");
   digitalWrite(injec1,HIGH);delay(y);digitalWrite(injec1,LOW); 
  digitalWrite(injec5,HIGH);delay(y);digitalWrite(injec5,LOW); 
  digitalWrite(injec3,HIGH);delay(y);digitalWrite(injec3,LOW);   
  digitalWrite(injec4,HIGH);delay(y);digitalWrite(injec4,LOW);   
  digitalWrite(injec2,HIGH);delay(y);digitalWrite(injec2,LOW);}

   while (digitalRead(cce)==0){
     lcd3.setCursor(0,1);lcd3.print("0110/04");
     int y=throttel();
      digitalWrite(injec1,HIGH); delay(y);digitalWrite(injec1,LOW); Shutdown();
      digitalWrite(injec5,HIGH); delay(y);digitalWrite(injec5,LOW); Shutdown();
      digitalWrite(injec3,HIGH); delay(y);digitalWrite(injec3,LOW); Shutdown();
      digitalWrite(injec4,HIGH); delay(y);digitalWrite(injec4,LOW); Shutdown();
      digitalWrite(injec2,HIGH); delay(y);digitalWrite(injec2,LOW); Shutdown();
      digitalWrite(injec6,HIGH); delay(y);digitalWrite(injec6,LOW); Shutdown();
      lcd.setCursor(0,0);lcd.print("Cool Temp");lcd.setCursor(10,0);lcd.print("RPM");
lcd.setCursor(0,2);lcd.print("Oil Press");lcd.setCursor(10,2);lcd.print("Throttel");
lcd2.setCursor(0,0);lcd2.print("FuelPress");lcd2.setCursor(10,0);lcd2.print("AtmosPress");
lcd2.setCursor(0,2);lcd2.print("Boost Press");
  float z=analogRead(oil);
  float c=map(z,0,1023,0,100);
  float k=analogRead(throttel1);
  float d=map(k,0,1023,0,100);
  float x=analogRead(crank1);
  float a=map(x,0,1023,0,100);
  float s=analogRead(Fuel);
  float e=map(s,0,1023,0,100);
  float q=analogRead(Atmospherique);
  float f=map(q,0,1023,0,100);
  float r=analogRead(boost);
  float j=map(r,0,1023,0,100);
  lcd.setCursor(0,1);lcd.print("0.0000");
  lcd.setCursor(10,1);lcd.print(a);
lcd.setCursor(0,3); lcd.print(c);
lcd.setCursor(10,3);lcd.print(d);
lcd2.setCursor(0,1);lcd2.print(e);
lcd2.setCursor(10,1);lcd2.print(f);
lcd2.setCursor(0,3);lcd2.print(j);
    }
   while (digitalRead(ccf)==0){
    lcd3.setCursor(0,1);lcd3.print("0094/04");
     int y=throttel();
    digitalWrite(injec1,HIGH); delay(y);digitalWrite(injec1,LOW); Shutdown();
      digitalWrite(injec5,HIGH); delay(y);digitalWrite(injec5,LOW); Shutdown();
      digitalWrite(injec3,HIGH); delay(y);digitalWrite(injec3,LOW); Shutdown();
      digitalWrite(injec4,HIGH); delay(y);digitalWrite(injec4,LOW); Shutdown();
      digitalWrite(injec2,HIGH); delay(y);digitalWrite(injec2,LOW); Shutdown();
      digitalWrite(injec6,HIGH); delay(y);digitalWrite(injec6,LOW); Shutdown();
lcd.setCursor(0,0);lcd.print("Cool Temp");lcd.setCursor(10,0);lcd.print("RPM");
lcd.setCursor(0,2);lcd.print("Oil Press");lcd.setCursor(10,2);lcd.print("Throttel");
lcd2.setCursor(0,0);lcd2.print("FuelPress");lcd2.setCursor(10,0);lcd2.print("AtmosPress");
lcd2.setCursor(0,2);lcd2.print("Boost Press");
float z=analogRead(oil);
float c=map(z,0,1023,0,100);
float k=analogRead(throttel1);
float d=map(k,0,1023,0,100);
  float x=analogRead(crank1);
  float b=map(x,0,1023,0,100);
  float q=analogRead(Atmospherique);
  float f=map(q,0,1023,0,100);
  float r=analogRead(boost);
  float j=map(r,0,1023,0,100);
  float l=analogRead(engine);//lir la valeur de pot engine
  float a=map(l,0,1023,38,141);
 
lcd.setCursor(10,1);lcd.print(a);
lcd.setCursor(0,3); lcd.print(c);
lcd.setCursor(10,3);lcd.print(d);
lcd.setCursor(10,1);lcd.print(b);
lcd2.setCursor(0,1);lcd2.print(0.0000);
lcd2.setCursor(10,1);lcd2.print(f);
lcd2.setCursor(0,3);lcd2.print(j);



   }
    while (digitalRead(cca)==0){
      lcd3.setCursor(0,1);lcd3.print("0274/04");
       int y=throttel();
       digitalWrite(injec1,HIGH); delay(y);digitalWrite(injec1,LOW); Shutdown();
      digitalWrite(injec5,HIGH); delay(y);digitalWrite(injec5,LOW); Shutdown();
      digitalWrite(injec3,HIGH); delay(y);digitalWrite(injec3,LOW); Shutdown();
      digitalWrite(injec4,HIGH); delay(y);digitalWrite(injec4,LOW); Shutdown();
      digitalWrite(injec2,HIGH); delay(y);digitalWrite(injec2,LOW); Shutdown();
      digitalWrite(injec6,HIGH); delay(y);digitalWrite(injec6,LOW); Shutdown();
lcd.setCursor(0,0);lcd.print("Cool Temp");lcd.setCursor(10,0);lcd.print("RPM");
lcd.setCursor(0,2);lcd.print("Oil Press");lcd.setCursor(10,2);lcd.print("Throttel");
lcd2.setCursor(0,0);lcd2.print("FuelPress");lcd2.setCursor(10,0);lcd2.print("AtmosPress");
lcd2.setCursor(0,2);lcd2.print("Boost Press");
float z=analogRead(oil);
float c=map(z,0,1023,0,100);
float k=analogRead(throttel1);
float d=map(k,0,1023,0,100);
  float x=analogRead(crank1);
  float b=map(x,0,1023,0,100);
 float s=analogRead(Fuel);
  float e=map(s,0,1023,0,100);
  float r=analogRead(boost);
  float j=map(r,0,1023,0,100);
  float l=analogRead(engine);//lir la valeur de pot engine
  float a=map(l,0,1023,38,141);
 
lcd.setCursor(0,1);lcd.print(a);
lcd.setCursor(10,1);lcd.print(b);
lcd.setCursor(0,3); lcd.print(c);
lcd.setCursor(10,3);lcd.print(d);
lcd2.setCursor(0,1);lcd2.print(e);
lcd2.setCursor(10,1);lcd2.print(0.000);
lcd2.setCursor(0,3);lcd2.print(j);}

 while (digitalRead(cco)==0){
  lcd3.setCursor(0,1);lcd3.print("0100/04");
   int y=throttel();
       digitalWrite(injec1,HIGH); delay(y);digitalWrite(injec1,LOW); Shutdown();
      digitalWrite(injec5,HIGH); delay(y);digitalWrite(injec5,LOW); Shutdown();
      digitalWrite(injec3,HIGH); delay(y);digitalWrite(injec3,LOW); Shutdown();
      digitalWrite(injec4,HIGH); delay(y);digitalWrite(injec4,LOW); Shutdown();
      digitalWrite(injec2,HIGH); delay(y);digitalWrite(injec2,LOW); Shutdown();
      digitalWrite(injec6,HIGH); delay(y);digitalWrite(injec6,LOW); Shutdown();
lcd.setCursor(0,0);lcd.print("Cool Temp");lcd.setCursor(10,0);lcd.print("RPM");
lcd.setCursor(0,2);lcd.print("Oil Press");lcd.setCursor(10,2);lcd.print("Throttel");
lcd2.setCursor(0,0);lcd2.print("FuelPress");lcd2.setCursor(10,0);lcd2.print("AtmosPress");
lcd2.setCursor(0,2);lcd2.print("Boost Press");

float k=analogRead(throttel1);
float d=map(k,0,1023,0,100);
float x=analogRead(crank1);
float b=map(x,0,1023,0,100);
float s=analogRead(Fuel);
float e=map(s,0,1023,0,100);
float r=analogRead(boost);
float j=map(r,0,1023,0,100);
float l=analogRead(engine);//lir la valeur de pot engine
  float a=map(l,0,1023,38,141);
   float q=analogRead(Atmospherique);
  float f=map(q,0,1023,0,100);
 
lcd.setCursor(0,1);lcd.print(a);
lcd.setCursor(10,1);lcd.print(b);
lcd.setCursor(0,3); lcd.print(0.000);
lcd.setCursor(10,3);lcd.print(d);
lcd2.setCursor(0,1);lcd2.print(e);
lcd2.setCursor(10,1);lcd2.print(f);
lcd2.setCursor(0,3);lcd2.print(j);}
    }
    void co(){////en peut faire un circuit ouvert dans le simulateur si la position de switch est 0 'est ouvert'
       int y=throttel();
      while (digitalRead (sw1)==0){
        lcd3.setCursor(0,1);lcd3.print("0001/05");
         int y=throttel();
    digitalWrite(injec5,HIGH);delay(y);digitalWrite(injec5,LOW);  
  digitalWrite(injec3,HIGH);delay(y);digitalWrite(injec3,LOW);   
  digitalWrite(injec4,HIGH);delay(y);digitalWrite(injec4,LOW);  
  digitalWrite(injec2,HIGH);delay(y);digitalWrite(injec2,LOW); 
  digitalWrite(injec6,HIGH);delay(y);digitalWrite(injec6,LOW); }
  
  while (digitalRead (sw2)==0){
    lcd3.setCursor(0,1);lcd3.print("0002/05");
     int y=throttel();
  digitalWrite(injec1,HIGH);delay(y);digitalWrite(injec1,LOW); 
  digitalWrite(injec3,HIGH);delay(y);digitalWrite(injec3,LOW); 
  digitalWrite(injec4,HIGH);delay(y);digitalWrite(injec4,LOW);   
  digitalWrite(injec2,HIGH);delay(y);digitalWrite(injec2,LOW);   
  digitalWrite(injec6,HIGH);delay(y);digitalWrite(injec6,LOW);} 
  
while (digitalRead (sw3)==0){
  lcd3.setCursor(0,1);lcd3.print("0003/05");
   int y=throttel();
  digitalWrite(injec1,HIGH);delay(y);digitalWrite(injec1,LOW); 
  digitalWrite(injec5,HIGH);delay(y);digitalWrite(injec5,LOW); 
  digitalWrite(injec4,HIGH);delay(y);digitalWrite(injec4,LOW);   
  digitalWrite(injec2,HIGH);delay(y);digitalWrite(injec2,LOW);   
  digitalWrite(injec6,HIGH);delay(y);digitalWrite(injec6,LOW);}
  
  while (digitalRead (sw4)==0){
    lcd3.setCursor(0,1);lcd3.print("0004/05");
     int y=throttel();
  digitalWrite(injec1,HIGH);delay(y);digitalWrite(injec1,LOW); 
  digitalWrite(injec5,HIGH);delay(y);digitalWrite(injec5,LOW); 
  digitalWrite(injec3,HIGH);delay(y);digitalWrite(injec3,LOW);   
  digitalWrite(injec2,HIGH);delay(y);digitalWrite(injec2,LOW);   
  digitalWrite(injec6,HIGH);delay(y);digitalWrite(injec6,LOW);}
  
  while (digitalRead (sw5)==0){
    lcd3.setCursor(0,1);lcd3.print("0005/05");
     int y=throttel();
  digitalWrite(injec1,HIGH);delay(y);digitalWrite(injec1,LOW); 
  digitalWrite(injec5,HIGH);delay(y);digitalWrite(injec5,LOW); 
  digitalWrite(injec3,HIGH);delay(y);digitalWrite(injec3,LOW);   
  digitalWrite(injec4,HIGH);delay(y);digitalWrite(injec4,LOW);   
  digitalWrite(injec6,HIGH);delay(y);digitalWrite(injec6,LOW);}
  
  while (digitalRead (sw6)==0){
    lcd3.setCursor(0,1);lcd3.print("0006/05");
     int y=throttel();
  digitalWrite(injec1,HIGH);delay(y);digitalWrite(injec1,LOW); 
  digitalWrite(injec5,HIGH);delay(y);digitalWrite(injec5,LOW); 
  digitalWrite(injec3,HIGH);delay(y);digitalWrite(injec3,LOW);   
  digitalWrite(injec4,HIGH);delay(y);digitalWrite(injec4,LOW);   
  digitalWrite(injec2,HIGH);delay(y);digitalWrite(injec2,LOW);}

  while (digitalRead(swe)==0){
    lcd3.setCursor(0,1);lcd3.print("0110/03");
     int y=throttel();
      digitalWrite(injec1,HIGH); delay(y);digitalWrite(injec1,LOW); Shutdown();
      digitalWrite(injec5,HIGH); delay(y);digitalWrite(injec5,LOW); Shutdown();
      digitalWrite(injec3,HIGH); delay(y);digitalWrite(injec3,LOW); Shutdown();
      digitalWrite(injec4,HIGH); delay(y);digitalWrite(injec4,LOW); Shutdown();
      digitalWrite(injec2,HIGH); delay(y);digitalWrite(injec2,LOW); Shutdown();
      digitalWrite(injec6,HIGH); delay(y);digitalWrite(injec6,LOW); Shutdown();
      lcd.setCursor(0,0);lcd.print("Cool Temp");lcd.setCursor(10,0);lcd.print("RPM");
lcd.setCursor(0,2);lcd.print("Oil Press");lcd.setCursor(10,2);lcd.print("Throttel");
lcd2.setCursor(0,0);lcd2.print("FuelPress");lcd2.setCursor(10,0);lcd2.print("AtmosPress");
lcd2.setCursor(0,2);lcd2.print("Boost Press");
  float z=analogRead(oil);
  float c=map(z,0,1023,0,100);
  float k=analogRead(throttel1);
  float d=map(k,0,1023,0,100);
  float x=analogRead(crank1);
  float a=map(x,0,1023,0,100);
  float s=analogRead(Fuel);
  float e=map(s,0,1023,0,100);
  float q=analogRead(Atmospherique);
  float f=map(q,0,1023,0,100);
  float r=analogRead(boost);
  float j=map(r,0,1023,0,100);
  lcd.setCursor(0,1);lcd.print("0.0000");
  lcd.setCursor(10,1);lcd.print(a);
lcd.setCursor(0,3); lcd.print(c);
lcd.setCursor(10,3);lcd.print(d);
lcd2.setCursor(0,1);lcd2.print(e);
lcd2.setCursor(10,1);lcd2.print(f);
lcd2.setCursor(0,3);lcd2.print(j);
    }
   while (digitalRead(swf)==0){
        lcd3.setCursor(0,1);lcd3.print("0094/03");
     int y=throttel();
    digitalWrite(injec1,HIGH); delay(y);digitalWrite(injec1,LOW); Shutdown();
      digitalWrite(injec5,HIGH); delay(y);digitalWrite(injec5,LOW); Shutdown();
      digitalWrite(injec3,HIGH); delay(y);digitalWrite(injec3,LOW); Shutdown();
      digitalWrite(injec4,HIGH); delay(y);digitalWrite(injec4,LOW); Shutdown();
      digitalWrite(injec2,HIGH); delay(y);digitalWrite(injec2,LOW); Shutdown();
      digitalWrite(injec6,HIGH); delay(y);digitalWrite(injec6,LOW); Shutdown();
lcd.setCursor(0,0);lcd.print("Cool Temp");lcd.setCursor(10,0);lcd.print("RPM");
lcd.setCursor(0,2);lcd.print("Oil Press");lcd.setCursor(10,2);lcd.print("Throttel");
lcd2.setCursor(0,0);lcd2.print("FuelPress");lcd2.setCursor(10,0);lcd2.print("AtmosPress");
lcd2.setCursor(0,2);lcd2.print("Boost Press");
float z=analogRead(oil);
float c=map(z,0,1023,0,100);
float k=analogRead(throttel1);
float d=map(k,0,1023,0,100);
  float x=analogRead(crank1);
  float b=map(x,0,1023,0,100);
  float q=analogRead(Atmospherique);
  float f=map(q,0,1023,0,100);
  float r=analogRead(boost);
  float j=map(r,0,1023,0,100);
  float l=analogRead(engine);//lir la valeur de pot engine
  float a=map(l,0,1023,38,141);
 
lcd.setCursor(10,1);lcd.print(a);
lcd.setCursor(0,3); lcd.print(c);
lcd.setCursor(10,3);lcd.print(d);
lcd.setCursor(10,1);lcd.print(b);
lcd2.setCursor(0,1);lcd2.print(0.0000);
lcd2.setCursor(10,1);lcd2.print(f);
lcd2.setCursor(0,3);lcd2.print(j);



   }
    while (digitalRead(swa)==0){
          lcd3.setCursor(0,1);lcd3.print("0274/03");
       int y=throttel();
       digitalWrite(injec1,HIGH); delay(y);digitalWrite(injec1,LOW); Shutdown();
      digitalWrite(injec5,HIGH); delay(y);digitalWrite(injec5,LOW); Shutdown();
      digitalWrite(injec3,HIGH); delay(y);digitalWrite(injec3,LOW); Shutdown();
      digitalWrite(injec4,HIGH); delay(y);digitalWrite(injec4,LOW); Shutdown();
      digitalWrite(injec2,HIGH); delay(y);digitalWrite(injec2,LOW); Shutdown();
      digitalWrite(injec6,HIGH); delay(y);digitalWrite(injec6,LOW); Shutdown();
lcd.setCursor(0,0);lcd.print("Cool Temp");lcd.setCursor(10,0);lcd.print("RPM");
lcd.setCursor(0,2);lcd.print("Oil Press");lcd.setCursor(10,2);lcd.print("Throttel");
lcd2.setCursor(0,0);lcd2.print("FuelPress");lcd2.setCursor(10,0);lcd2.print("AtmosPress");
lcd2.setCursor(0,2);lcd2.print("Boost Press");
float z=analogRead(oil);
float c=map(z,0,1023,0,100);
float k=analogRead(throttel1);
float d=map(k,0,1023,0,100);
  float x=analogRead(crank1);
  float b=map(x,0,1023,0,100);
 float s=analogRead(Fuel);
  float e=map(s,0,1023,0,100);
  float r=analogRead(boost);
  float j=map(r,0,1023,0,100);
  float l=analogRead(engine);//lir la valeur de pot engine
  float a=map(l,0,1023,38,141);
 
lcd.setCursor(0,1);lcd.print(a);
lcd.setCursor(10,1);lcd.print(b);
lcd.setCursor(0,3); lcd.print(c);
lcd.setCursor(10,3);lcd.print(d);
lcd2.setCursor(0,1);lcd2.print(e);
lcd2.setCursor(10,1);lcd2.print(0.000);
lcd2.setCursor(0,3);lcd2.print(j);}

 while (digitalRead(swo)==0){
      lcd3.setCursor(0,1);lcd3.print("0100/03");
   int y=throttel();
       digitalWrite(injec1,HIGH); delay(y);digitalWrite(injec1,LOW); Shutdown();
      digitalWrite(injec5,HIGH); delay(y);digitalWrite(injec5,LOW); Shutdown();
      digitalWrite(injec3,HIGH); delay(y);digitalWrite(injec3,LOW); Shutdown();
      digitalWrite(injec4,HIGH); delay(y);digitalWrite(injec4,LOW); Shutdown();
      digitalWrite(injec2,HIGH); delay(y);digitalWrite(injec2,LOW); Shutdown();
      digitalWrite(injec6,HIGH); delay(y);digitalWrite(injec6,LOW); Shutdown();
lcd.setCursor(0,0);lcd.print("Cool Temp");lcd.setCursor(10,0);lcd.print("RPM");
lcd.setCursor(0,2);lcd.print("Oil Press");lcd.setCursor(10,2);lcd.print("Throttel");
lcd2.setCursor(0,0);lcd2.print("FuelPress");lcd2.setCursor(10,0);lcd2.print("AtmosPress");
lcd2.setCursor(0,2);lcd2.print("Boost Press");

float k=analogRead(throttel1);
float d=map(k,0,1023,0,100);
float x=analogRead(crank1);
float b=map(x,0,1023,0,100);
float s=analogRead(Fuel);
float e=map(s,0,1023,0,100);
float r=analogRead(boost);
float j=map(r,0,1023,0,100);
float l=analogRead(engine);//lir la valeur de pot engine
  float a=map(l,0,1023,38,141);
   float q=analogRead(Atmospherique);
  float f=map(q,0,1023,0,100);
 
lcd.setCursor(0,1);lcd.print(a);
lcd.setCursor(10,1);lcd.print(b);
lcd.setCursor(0,3); lcd.print(0.000);
lcd.setCursor(10,3);lcd.print(d);
lcd2.setCursor(0,1);lcd2.print(e);
lcd2.setCursor(10,1);lcd2.print(f);
lcd2.setCursor(0,3);lcd2.print(j);}
  }
   void on1(){
    boolean buttononIsUp = digitalRead(on);
    if (buttononWasUp && !buttononIsUp) {
      delay(10);
      buttononIsUp = digitalRead(on);
      if (!buttononIsUp) { digitalWrite(injec1,LOW);digitalWrite(fan,LOW);digitalWrite(injec2,LOW);digitalWrite(injec3,LOW);digitalWrite(injec4,LOW);digitalWrite(injec5,LOW);digitalWrite(injec6,LOW);
    lcd.setCursor(0,0);lcd.print("Cool Temp");lcd.setCursor(10,0);lcd.print("RPM");
    lcd.setCursor(0,2);lcd.print("Oil Press");lcd.setCursor(10,2);lcd.print("Throttel");
    lcd2.setCursor(0,0);lcd2.print("FuelPress");lcd2.setCursor(10,0);lcd2.print("AtmosPress");
    lcd2.setCursor(0,2);lcd2.print("Boost Press");lcd3.clear();lcd3.setCursor(0,0);lcd3.print("Codes erreurs");
    lcd.setCursor(0,3);lcd.print("0.000");lcd.setCursor(0,1);lcd.print("0.000");
    lcd.setCursor(10,3);lcd.print("0.000");lcd.setCursor(10,1);lcd.print("0.000");
    lcd2.setCursor(0,1);lcd2.print("0.000");lcd2.setCursor(10,1);lcd2.print("0.000");lcd2.setCursor(0,3);lcd2.print("0.000");}
   }
   buttononWasUp = buttononIsUp;
  }
  void start1(){
     boolean buttonstartIsUp = digitalRead(start);
     boolean buttononIsUp = digitalRead(on);
     boolean buttonoffIsUp = digitalRead(off);
     if (buttonstartWasUp && !buttonstartIsUp) {
      delay(10);
      buttonstartIsUp = digitalRead(start);
      if (!buttonstartIsUp) { crank(); }
   }}    
   void crank(){
    float x=analogRead(crank1);
    float a=map(x,0,1023,0,100);
    if (a<=30){
    digitalWrite(injec1,LOW);digitalWrite(injec2,LOW);digitalWrite(injec3,LOW);
    digitalWrite(injec4,LOW);digitalWrite(injec5,LOW);digitalWrite(injec6,LOW);
    lcd.clear();lcd2.clear();lcd3.clear();
    digitalWrite(diagnostic,HIGH);digitalWrite(fan,LOW);}
    else {
      
    int y=throttel();
    digitalWrite(diagnostic,LOW);
      digitalWrite(injec1,HIGH); delay(y);digitalWrite(injec1,LOW);digitalWrite(fan,HIGH); pot(); Shutdown();co();
      digitalWrite(injec5,HIGH); delay(y);digitalWrite(injec5,LOW);digitalWrite(fan,HIGH); pot(); Shutdown();co();
      digitalWrite(injec3,HIGH); delay(y);digitalWrite(injec3,LOW);digitalWrite(fan,HIGH); pot(); Shutdown();co();
      digitalWrite(injec4,HIGH); delay(y);digitalWrite(injec4,LOW);digitalWrite(fan,HIGH); pot(); Shutdown();co();
      digitalWrite(injec2,HIGH); delay(y);digitalWrite(injec2,LOW);digitalWrite(fan,HIGH); pot(); Shutdown();co();
      digitalWrite(injec6,HIGH); delay(y);digitalWrite(injec6,LOW);digitalWrite(fan,HIGH); pot(); Shutdown();co();
  }}
  
    
    
