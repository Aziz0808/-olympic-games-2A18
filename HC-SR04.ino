#include <Servo.h>
Servo myservo; 
const int trigPin = 5;
const int echoPin = 13;
int pos = 0;
char data;
int x = 0;         // variable for reading the pushbutton status


//definir sound speed en cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

int angle_initial = 0;   //angle initial
int angle_final = 180;   //angle final
int increment = 5;       //incrément entre chaque position
//bool angle_actuel = false;//Envoi sur le port série la position courante du servomoteur

void setup() {
Serial.begin(9600); 
 while(!Serial){;} 
  myservo.attach(7);
  myservo.write(pos);
 
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {
  // initialiser le trigPin à 0
 /* digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  //Définit le trigPin sur l'état ÉLEVÉ pendant 10 microsecondes
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Lire l'echoPin, renvoie le temps de parcours de l'onde sonore en microsecondes
  duration = pulseIn(echoPin, HIGH);
  
  // Calculer la distance
  distanceCm = duration * SOUND_SPEED/2;
  
  // Convertion de Cm à inches
  distanceInch = distanceCm * CM_TO_INCH;
  
  
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
  delay(1000);

  
                              // condition pour le moteur
*/ 
/*if (distanceCm < 10)
  {*/
  /* for (pos = angle_initial; pos <= angle_final; pos += increment) { // Déplace le servo de 0 à 180 degréespar pas de 1 degrée 
    myservo.write(pos);              // Demande au servo de se déplacer à cette position angulaire
    delay(5);     
    Serial.println(myservo.read());

  }
  //}
 /* else 
  {
      myservo.write(pos);
  }*/
  //delay(300);
   // read the state of the pushbutton value:
 

  
  

 data= Serial.read();
  /*  if( data == '1' )
    { myservo.write(pos);
    Serial.write('0');
    x=1 ;
    
    }*/
    
    if(x== 0)
    { if (data == '0')
    {
      // myservo.write(pos);              // Demande au servo de se déplacer à cette position angulaire
   // delay(100);  
      
       for (pos = angle_initial; pos <= angle_final; pos += increment)
       { // Déplace le servo de 0 à 180 degréespar pas de 1 degrée 
    myservo.write(pos);              // Demande au servo de se déplacer à cette position angulaire
    //delay(5);     
    Serial.println(myservo.read());
    delay(100);
   //// if (angle_actuel) {
       // Serial.println(myservo.read());
    
    
       
    Serial.write('1');
    delay(5);
    }
    }
    else 
    {
       myservo.write(pos);
       Serial.write('0');
       delay(1000);
       
      }
    
}
}
