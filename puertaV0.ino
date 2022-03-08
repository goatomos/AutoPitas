#include "puerta.h"

#define DIA 1
#define NOCHE 0



#define AIN1 8
#define BIN1 2

#define PWMA 5

#define STBY 12

const int ledPin = 13;
const int HALLPinC = 6;
const int HALLPinA = 9;
const int ldrPin = A0;
const int waitTime = 200;   //espera entre fases
const int speed = 200;      //velocidad de 
const int daylight = 850;
const int histeresis = 80;

const int pulsadorVerde = 3;
const int pulsadorRojo = 4;

const int nightlight = daylight - histeresis;


// these constants are used to allow you to make your motor configuration 
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = 1;
const int offsetB = 1;

// Initializing motors.  The library will allow you to initialize as many
// motors as you have memory for.  If you are using functions like forward
// that take 2 motors as arguements you can either write new functions or
// call the function more than once.
Motor motor1 = Motor(AIN1, BIN1, PWMA, offsetA, STBY);

int estado;

boolean puertacerrada=false;

void setup()
{
Serial.begin(9600);

pinMode(ledPin, OUTPUT);
pinMode(HALLPinC, INPUT);
pinMode(HALLPinA, INPUT);
pinMode(ldrPin, INPUT);
pinMode(BIN1, OUTPUT);
pinMode(AIN1, OUTPUT);
pinMode(PWMA, OUTPUT);
pinMode(pulsadorVerde, INPUT);
pinMode(pulsadorRojo, INPUT);

estado = DIA;
puertacerrada=true;

   motor1.drive(-200,6000);
  
 
   
  
    

    motor1.brake();


    Serial.print("setup listo ");

 

  }

void loop() {
  // put your main code here, to run repeatedly:


  switch (estado)

  {
    case DIA: 

   /*   if ( (analogRead(ldrPin) > (daylight)) && (puertacerrada == true))


          

      {
          Serial.println("abriendo puerta ");
        
           motor1.drive(200); 
    
          if(digitalRead(HALLPinA)==LOW)
    
            {
            
              motor1.brake(); 
              puertacerrada= false;
          
            }
       
      }

      if (analogRead(ldrPin) < (nightlight)) 
        
        {

          Serial.println(" DIA > NOCHE ");
        
            estado = NOCHE;
        
        }
        */


    if( digitalRead(pulsadorRojo)== HIGH )
        {
      
          Serial.println("cerrar puerta manualmente - rojo");
          estado = NOCHE;


          
        Serial.println("cerrando puerta ");
        
          motor1.drive(-180); 


          if(digitalRead(HALLPinC)==LOW)
    
            {
            
              motor1.brake(); 
              puertacerrada=true;
          
            }
      
      
      
        }


      break;
      
    case NOCHE:

  /*    if( (analogRead(ldrPin) < (nightlight) ) && (puertacerrada == false) )

      {


        Serial.println("cerrando puerta ");
        
          motor1.drive(-180); 


          if(digitalRead(HALLPinC)==LOW)
    
            {
            
              motor1.brake(); 
              puertacerrada=true;
          
            }
        
        
      }*/


            /*if (analogRead(ldrPin) > (daylight)) 
        
        {

          
        
            estado = DIA;
        
        }

        */

            if( digitalRead(pulsadorVerde)== HIGH )
        {
      
      
      
          Serial.println("abrir puerta manualmente - verde");


          Serial.println("abriendo puerta ");
        
           motor1.drive(200); 
    
          if(digitalRead(HALLPinA)==LOW)
    
            {
            
              motor1.brake(); 
              puertacerrada= false;
          
            }

          
          estado=DIA;
        }
      
      break;    
    
  }
    




}
