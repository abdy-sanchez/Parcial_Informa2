//Definicion Pines principales
int ser = 5,rclk = 6, srclk = 7 ;


//Funcion que genera la señal 010
void func1( int pin ){
  
  digitalWrite(pin,0);
  digitalWrite(pin,1);
  digitalWrite(pin,0);

}


void setup(){
 
 //Inicializacion de pines en modo OUTPUT
 pinMode(ser, OUTPUT);
 pinMode(rclk, OUTPUT);
 pinMode(srclk, OUTPUT); 
  
}

void loop(){
  

}