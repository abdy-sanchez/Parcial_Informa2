
















//SER
int pinData = 5 ; 
//RCLK [Buffer de salida]
int pinLatch = 6 ;
//SRCLK
int pinClock = 7 ;

#define TIEMPO 150
//Definimos una constante llamada tiempo, con 150 ms


//Funcion para administar los datos y encender o apagar los leds
void leds( int f1, int f2, int f3, int f4, int f5, int f6, int f7, int f8 ){

  //Las funciones shiftOut nos sirven para despazar la informacion (1,0) por los diferentes Microcontroladores
  
  shiftOut(pinData, pinClock, LSBFIRST, f8);
  
  shiftOut(pinData, pinClock, LSBFIRST, f7);
  
  shiftOut(pinData, pinClock, LSBFIRST, f6);
  
  shiftOut(pinData, pinClock, LSBFIRST, f5);
  
  shiftOut(pinData, pinClock, LSBFIRST, f4);
  
  shiftOut(pinData, pinClock, LSBFIRST, f3);
  
  shiftOut(pinData, pinClock, LSBFIRST, f2);
  
  shiftOut(pinData, pinClock, LSBFIRST, f1);
  
  digitalWrite(pinLatch, HIGH);		//Con las siguientes dos lineas mostramos lo que hay almacenado en el registro
  digitalWrite(pinLatch, LOW);		//Se genera un pulso, basicamente

  //las variable f1 a f8 representan las filas de la matriz
  
}



void setup(){
  
  Serial.begin(9600);		//Iniciamos el Serial
  
  //Inicializacion de pines en modo OUTPUT
   pinMode(pinData, OUTPUT);
   pinMode(pinLatch, OUTPUT);
   pinMode(pinClock, OUTPUT);
  
  //IMPRIMIMOS EN ESERIAL LAS OPCIONES PARA EL USUARIO
  
  Serial.println(" ---BIENVENIDO---");
  Serial.println(" > Que desea hacer? ");
  Serial.println(" Opciones: [0] Verificar el Sistema de LEDS ; [1] Definir un patron  ; [2] Mostrar un patron completamente PERSONALIZADO ");
    

}

void loop(){
  
  //Ciclo que se repite indefinidamente hasta que se ingrese algo en el Monitor Serial
  while( Serial.available()==0 ){
  Serial.println(" Su Respuesta: ");
  delay(10000);
  
  }
  
  ////CUERPO DEL LOOP
  
  if(   ){			//Condicion #1 Si la respuesta del usuario es [0]
  
  
  
  }
  else if(   ){			//Condicion #2 Si la respuesta del usuario es [1]
  
  
  
  }
  else if(   ){			//Condicion #4 Si la respuesta del usuario es [2]
  
  
  
  
  }
  else{			//Condicion #4 Si la respuesta del usuario es diferente de lo que se pide	
  
  Serial.println(" CONSEJO: RE-LEE LAS OPCIONES...");
  delay(3000);		//Espera 3 segunos, para que el usuario lea :)
  
  }


}