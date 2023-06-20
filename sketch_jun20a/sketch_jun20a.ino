#include <Ultrasonic.h>

#define trig 9
#define echo 8

#define ENA 2
#define ENB 7
//motor A
int IN1 = 3;
int IN2 = 4;

//motor B
int IN3 = 5;
int IN4 = 6;

int cmMsec;
Ultrasonic ultrassonic(trig, echo);

void setup() {
  Serial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

//  ==  Igual a
//  >=  Maior ou igual
//  > Maior que
//  < Menor que
//  <=  Menor ou igual


/*void inicial(){
  //atribuiir valor do ultrassonico
  paraCarro();
  delay(2000);
  carroEsquerda();
  delay(2000);
  paraCarro();
  delay(2000);
   //atribuiir valor do ultrassonico á variavel ok
  
  }

  void segunda(){
    //atribuiir valor do ultrassonico
    carroDireita();
    delay(2000);
    paraCarro();
    delay(2000);
    //atribuiir valor do ultrassonico á variavel ok
    }

 void terceiro(){
  //atribuiir valor do ultrassonico
   carroDireita();
    delay(2000);
    paraCarro();
    delay(2000);
    //ok
  }
  
void finall(){
  carroFrente();
  //ok
  }
*/

void convert(){
  long microsec = ultrassonic.timing();
  cmMsec = ultrassonic.convert(microsec, Ultrasonic::CM); 

}

void loop() {
 
  convert();
  Serial.println(cmMsec);
  
  if (cmMsec < 30){
    //atribuiir valor do ultrassonico
    paraCarro();
    delay(2000);
    carroEsquerda();
    delay(2000);
    paraCarro();
    delay(2000);
    convert();
   //atribuiir valor do ultrassonico á variavel
   if (cmMsec < 30 ){
    //atribuiir valor do ultrassonico
    carroDireita();
    delay(2000);
    paraCarro();
    delay(2000);
    convert();
    //atribuiir valor do ultrassonico á variavel
    if( cmMsec < 30){
      //atribuiir valor do ultrassonico
      carroDireita();
      delay(2000);
      paraCarro();
      delay(2000);
      convert();
  
    }
    }  
   }
   else{
    carroFrente();
    delay(2000);

   }
  }



void paraCarro() {
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);  
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
}

void carroEsquerda(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);

}

void carroDireita(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
}

void carroFrente(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
}
void carroRe(){
digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
}
