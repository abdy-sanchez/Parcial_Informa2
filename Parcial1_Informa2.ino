//ARREGLO LETRA A
byte A[] = {B00011000,B00111100,B01100110,B01100110,B01111110,B01111110,B01100110,B01100110};
















//SER
int pinData = 5 ; 
//RCLK
int pinLatch = 6 ;
//SRCLK
int pinClock = 7 ;

#define TIEMPO 150
//Definimos una constante llamada tiempo, con 150 ms


//Funcion para administar los datos y encender o apagar los leds
void leds( int f1, int f2, int f3, int f4, int f5, int f6, int f7, int f8 ){

  shiftOut(pinData, pinClock, LSBFIRST, f8);
  shiftOut(pinData, pinClock, LSBFIRST, f7);
  shiftOut(pinData, pinClock, LSBFIRST, f6);
  shiftOut(pinData, pinClock, LSBFIRST, f5);
  shiftOut(pinData, pinClock, LSBFIRST, f4);
  shiftOut(pinData, pinClock, LSBFIRST, f3);
  shiftOut(pinData, pinClock, LSBFIRST, f2);
  shiftOut(pinData, pinClock, LSBFIRST, f1);
  digitalWrite(pinLatch, HIGH);
  digitalWrite(pinLatch, LOW);

}



void setup(){
  
  //Inicializacion de pines en modo OUTPUT
   pinMode(pinData, OUTPUT);
   pinMode(pinLatch, OUTPUT);
   pinMode(pinClock, OUTPUT); 

}

void loop(){
  

  leds(A[0] ,A[1] ,A[2] ,A[3] ,A[4] ,A[5] ,A[6] , A[7]);

}