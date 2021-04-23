//Variables y Arreglos para el Codigo

//ARREGLO BIDIMENSIONAL QUE CONTIENE TODAS LAS LETRAS [una letra se representa con 8 bytes]

byte letras[26][8] = {{B00011000,B00111100,B01100110,B01100110,B01111110,B01111110,B01100110,B01100110},
{B01111100,B01100110,B01100110,B01111100,B01111110,B01100110,B01100110,B01111100},
{B00111110,B01111110,B01100000,B01100000,B01100000,B01100000,B01111110,B00111110},
{B01111000,B01111100,B01100110,B01100110,B01100110,B01100110,B01111100,B01111000},
{B01111110,B01111110,B01100000,B01111110,B01111110,B01100000,B01111110,B01111110},
{B01111110,B01111110,B01100000,B01111100,B01111100,B01100000,B01100000,B01100000},
{B00111000,B01111100,B01100100,B01100000,B01101110,B01100100,B01111100,B00111000},
{B01100110,B01100110,B01100110,B01111110,B01111110,B01100110,B01100110,B01100110},
{B01111110,B01111110,B00011000,B00011000,B00011000,B00011000,B01111110,B01111110},
{B01111110,B01111110,B00011000,B00011000,B00011000,B00011000,B01111000,B01110000},
{B01100110,B01101100,B01111000,B01110000,B01110000,B01111000,B01101100,B01100110},
{B01100000,B01100000,B01100000,B01100000,B01100000,B01100000,B01111110,B01111110},
{B01000010,B01100110,B01111110,B01011010,B01000010,B01000010,B01000010,B01000010},
{B01000110,B01100110,B01100110,B01110110,B01111110,B01101110,B01100110,B01100110},
{B00111100,B01111110,B01100110,B01100110,B01100110,B01100110,B01111110,B00111100},
{B01111000,B01111100,B01100110,B01100110,B01111100,B01111000,B01100000,B01100000},
{B00111100,B01000010,B01000010,B01000010,B01000010,B01001010,B00111100,B00000010},
{B01111100,B01100110,B01100110,B01101100,B01111000,B01111000,B01101100,B01100110},
{B00111100,B01111110,B01100000,B01111100,B00111110,B00000110,B01111110,B00111100},
{B01111110,B01111110,B00011000,B00011000,B00011000,B00011000,B00011000,B00011000},
{B01100110,B01100110,B01100110,B01100110,B01100110,B01100110,B01111110,B00111100},
{B01100110,B01100110,B01100110,B01100110,B01100110,B01100110,B00111100,B00011000},
{B01000010,B01000010,B01000010,B01000010,B01000010,B01011010,B01011010,B00100100},
{B01100110,B01100110,B01100110,B00111100,B00011000,B00111100,B01100110,B01100110},
{B01100110,B01100110,B01100110,B01111110,B00111100,B00011000,B00011000,B00011000},
{B01111110,B01111110,B00000110,B00001100,B00011000,B00110000,B01111110,B01111110}};

char num,letra_num ; //Almacenará el primer numero que se le pide al usuario para definir lo que quiere hacer

int n_patron, n_p, elementos_p, t_ms, num_e ; //Variable que guardará el tamaño del patron del usuario ; numero de elemntos y tiempo entre patrones

//ARREGLO PARA ENCENDER TODOS LOS LEDS
byte encender[] = {B11111111 ,B11111111 ,B11111111 , B11111111, B11111111,B11111111 ,B11111111 ,B11111111} ;

//ARREGLO PARA APAGAR TODOS LOS LEDS
byte apagar[] = {B00000000 ,B00000000 ,B00000000 , B00000000, B00000000,B00000000 ,B00000000 ,B00000000};













//SER [Entrada]
int pinData = 5 ; 
//RCLK [Buffer de salida]
int pinLatch = 6 ;
//SRCLK [Registro de Desplazamiento]
int pinClock = 7 ;

#define TIEMPO 150
//Definimos una constante llamada tiempo, con 150 ms


//Funcion para administar los datos y encender o apagar los leds
void leds( int f1, int f2, int f3, int f4, int f5, int f6, int f7, int f8 ){

  //Las funciones shiftOut nos sirven para despazar la informacion (1,0) por los diferentes Microcontroladores
  //LSBFIRST: leer el byte desde el bit menos significativo [el de toda la derecha]
  
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



/////FUNCION DE VERIFICACION

void verificacion(byte *v, byte*a){
  
  	
    //ENCENDEMOS TODOS LOS LEDS
    leds(*( v +0 ),*( v +1 ),*( v +2 ),*( v + 3),*( v +4 ),*( v +5 ),*( v + 6),*( v +7 ));
    
    //ESPERAMOS 2.5 SEGUNDOS
    delay(2500);
    
    //APAGAMOS TODOS LOS LEDS
    leds(*( a +0 ),*( a +1 ),*( a + 2),*( a +3 ),*( a + 4),*( a + 5),*( a +6 ),*( a +7 ));

}



///FUNCION PARA ALMACENAR CARACTERES DESEADOS

void almacenar( int n, char caracter, byte *letra, byte *ar ){
  
  int pletra; //Variable para movernos por las "columnas" del arreglo bidimensional
  
  pletra = n*8 ;
  
  switch( caracter ){   //Switch con los casos "letras" de la A a la Z
    
      
    
    case 'A':           //En cada caso (letra) va a haber un ciclo que vaya llenando el arreglo de los patrones
                        //del usuarion un byte a la vez. [una letra es representada con 8 bytes]
                        //Cada for tiene limites distintos debido a la forma en la que se manejan los arreglos multidimensionales con punteros
                        
    for(  int i = 0 ; i < 8 ; i++ ){
      
      *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    
    break;
    
    case 'B':
        for(  int i = 8 ; i < 16 ; i++ ){
      
       *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'C':
    for(  int i = 16 ; i < 24 ; i++ ){
          
       *(ar + pletra) = *( letra + i );
      
        pletra++ ;
        }
    break;
    
    case 'D':
        for(  int i = 24 ; i < 32 ; i++ ){
      
      
      *(ar + pletra) = *( letra + i );
      
        pletra++ ;
    }
    break;
    
    case 'E':
        for(  int i = 32 ; i < 40 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'F':
        for(  int i = 40 ; i < 48 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'G':
        for(  int i = 48 ; i < 56 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'H':
        for(  int i = 56 ; i < 64 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'I':
        for(  int i = 64 ; i < 72 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'J':
        for(  int i = 72 ; i < 80 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'K':
        for(  int i = 80 ; i < 88 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'L':
        for(  int i = 88 ; i < 96 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'M':
        for(  int i = 96 ; i < 104 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'N':
        for(  int i = 104 ; i < 112 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'O':
        for(  int i = 112 ; i < 120 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'P':
        for(  int i = 120 ; i < 128 ; i++ ){
      
           *(ar + pletra) = *( letra + i );
      
        pletra++ ; 
      
    }
    break;
    
    case 'Q':
        for(  int i = 128 ; i < 136 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'R':
        for(  int i = 136 ; i < 144 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'S':
        for(  int i = 144 ; i < 152 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'T':
        for(  int i = 152 ; i < 160 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'U':
        for(  int i = 160 ; i < 168 ; i++ ){
      
           *(ar + pletra) = *( letra + i );
      
        pletra++ ; 
      
    }
    break;
    
    case 'V':
        for(  int i = 168 ; i < 176 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'w':
        for(  int i = 176 ; i < 184 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'X':
        for(  int i = 184 ; i < 192 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'Y':
        for(  int i = 192 ; i < 200 ; i++ ){
      
            *(ar + pletra) = *( letra + i );
      
        pletra++ ;
      
    }
    break;
    
    case 'Z':
        for(  int i = 200 ; i < 208 ; i++ ){
           *(ar + pletra) = *( letra + i );
      
        pletra++ ; 
      
      
    }
    break;
    
    
  }
  
  
  
}



/////FUNCION IMAGEN


void imagen( byte *patron, int n  ){
  
    int indice;   //corresponde al numero de las "filas" en el arreglo bidimensional
    
    for( int v = 0  ; v < n ; v++ ){      //Ciclo que se repite el mismo numero de veces que el tamaño del patron ingresado por el usuario
      
      indice = v*8 ; //multiplicamos por 8 para irnos moviendo por las filas [debido a la forma en la que se manejan los arreglos multidimensionales]
      
      leds( *(patron + (indice)) , *(patron + (indice+1)) , *(patron + (indice+2)) , *(patron + (indice+3)) , *(patron + (indice+4)) , *(patron + (indice+5)) , *(patron + (indice+6)) ,  *(patron + (indice+7)) );
      
      delay(3000);   //Tiempo de espera entre cada patron
    }
  
}



/////FUNCION IMAGEN PERO CON DELAY INGRESADO

void publik( int *patron, int n, int ms  ){
  
    int indice;   //corresponde al numero de las "filas" en el arreglo bidimensional
    
    for( int v = 0  ; v < n ; v++ ){      //Ciclo que se repite el mismo numero de veces que el tamaño del patron ingresado por el usuario
      
      indice = v*8 ; //multiplicamos por 8 para irnos moviendo por las filas [debido a la forma en la que se manejan los arreglos multidimensionales]
      
      leds( *(patron + (indice)) , *(patron + (indice+1)) , *(patron + (indice+2)) , *(patron + (indice+3)) , *(patron + (indice+4)) , *(patron + (indice+5)) , *(patron + (indice+6)) ,  *(patron + (indice+7)) );
      
      delay(ms);   //Tiempo de espera entre cada patron [PERSONALIZADO]
    }
  
}



/////FUNCION PARA CREAR EL PATRON

void matriz( int *nums ){
  
    bool condicion = true ;
    
    int led, fil, col ;
    
    char opcion ;
  
    //RELLENAMOS LA MATRIZ CON CEROS (LED APAGADO POR DEFECTO)
    
    for( int f = 0 ; f<64 ; f++ ){
      
      *(nums+f) = 0 ;     //asignamos cero a cada posicion
      
    }
  
    /////CICLO EN EL QUE MODIFICAREMOS LA MATRIZ
    
    while(condicion == true){
      
      Serial.println("ilumine el LED que desee con un 1 :");
      
        while( Serial.available()==0 ){
        Serial.println(" Su Respuesta: ");
        delay(10000);
        }
        
        led = Serial.parseInt();		//Obtenemos lo ingresado como entero
        
        if(led == 1){
          
          Serial.println("En que posicion? [de 0 a 7] primero fila...");
          
        while( Serial.available()==0 ){
        Serial.println(" Su Respuesta: ");
        delay(10000);
        }
          
         fil =  Serial.parseInt();
         
         Serial.println("En que posicion? [de 0 a 7] Ahora Columna...");
         
        while( Serial.available()==0 ){
        Serial.println(" Su Respuesta: ");
        delay(10000);
        }
        
        col = Serial.parseInt();
        
        if(fil >= 0 && fil <= 7 && col >= 0 && col <= 7){
          
          int veces = 0, p_fila ;
          
          p_fila = (fil)*8;
          
          while(veces < col ){
            
            p_fila++ ;
            
            veces++ ;
            
          }
          
          *(nums + p_fila) = 1 ;      //LUEGO guardamos un 1 en el arreglo
          
          /////AHORA IMPRIMIMOS EL ARREGLO
          int bait = 0 ;
          
          for( int r = 0 ; r<64 ; r++  ){
            
              Serial.print( *(nums+r) );
              
              if(bait == 7){
                
                Serial.println(" ");
                bait = 0 ;
              }
              else{
                
                bait++;
              }
              
              
              
          }
          
        }
        else{
          
          Serial.println("FILA O COLUMNA INVALIDAS");
        }
          
        
          
        }
        else{
          
          Serial.println("INGRESE UNICAMENTE UN 1...");
          
        }
        
        
        //////PREGUNTAMOS AL USUARIO SI QUIERE ENCENDER MAS LEDS O TERMINAR EL PATRON
        
        Serial.println(" Desea cambiar mas leds? [0] SI ; [1] NO");
        
        while( Serial.available()==0 ){
        Serial.println(" Su Respuesta: ");
        delay(10000);
        }
        
        opcion = Serial.read();  	//La funcion .read lee el primer byte del monitor y se lo asigna a la variable opcion
        
        if( opcion == 48 ){
          
          condicion = true ;
        }
        else{
          
          condicion = false ;
        }
        
      
    }//fin while
  
  
  ///fin funcion
}



//////Funcion para convertir cada fila de 1s y 0s a un entero


void conversion( int *matriz, int *a_nums ){
  
  int a, convert ;
  
  for(int f = 0; f<8 ;f++){
    
    a = f*8 ;
    
    
    convert = ((*(matriz+a))*pow(2,7))+((*(matriz+(a+1)))*pow(2,6))+((*(matriz+(a+2)))*pow(2,5))+((*(matriz+(a+3)))*pow(2,4))+((*(matriz+(a+4)))*pow(2,3))+((*(matriz+(a+5)))*pow(2,2))+((*(matriz+(a+6)))*(2))+((*(matriz+(a+7)))*(1)) ;
    
    *(a_nums+f) = convert ;
    
  }
  
}///fin funcion




//////FUNCION PARA RELLENAR EL ARREGLO CON LOS PATRONES DEL USUARIO


void relleno( int inicio , int *ar, int *convert ){
  
  int pos ;
  
  pos = inicio ;
  
  for(int e = 0; e<8 ;e++){
    
      *(ar + pos )  = *( convert + e) ;
      
      pos++ ;
    
  }
  
}//fin funcion


//////FUNCION PUBLIK



/////SETUP Y LOOP

void setup(){
  
  Serial.begin(9600);		//Iniciamos el Serial
  Serial.setTimeout(10);	//Definimos esta funcion con 10 ms [NOS AYUDARA CON LA FUNCION PARSEINT]
  
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
  
  
  num = Serial.read();  	//La funcion .read lee el primer byte del monitor y se lo asigna a la variable num 
  
  
  if( num == 48  ){			//Condicion #1 Si la respuesta del usuario es [0]
  
  	Serial.println("---PROCESO DE VERIFICACION---");
    
	verificacion(&encender[0],&apagar[0]);			//Llamamos a la funcion VERIFICACION, con las direcciones de los arreglos encender y apagar como parametros
    
    Serial.println("---FIN DEL PROCESO DE VERIFICACION---");
    
    delay(1500);
  
  }
  else if( num == 49  ){			//Condicion #2 Si la respuesta del usuario es [1]
  
  	
    Serial.println("---GENERACION DE PATRON---");
    
    Serial.println(" Cuantos elementos contiene tu patron? ");		//El usuario ingesa el numero de elementos de su patron
    
    while( Serial.available()==0 ){       //Nuevamente, si no hay nada en el monitor, preguntac cada 10s al usuario que ingrese algo valido
  	  Serial.println(" Su Respuesta: ");
  	  delay(10000);
  
    }
    
    n_patron = Serial.parseInt();		//Obtenemos lo ingresado como entero
    
    n_p = n_patron ;      //Guardamos el numero en otra variable 
    
    byte *p_al ;
                    //Punteros que guardan la direccion de los primeros elementos del arreglo
    byte *p_pu ;
    
    int pos_letra = 0 ;   //Posicion letra. en esta variable, se almacenará la posicion en la 1ra dimension del arreglo (filas)
    
    p_al = &letras[0][0] ;    //p_al : puntero_arregloLetras ;;; p_pu : puntero_patronUsuario
    
    p_pu = new byte[n_patron*8];  //Genereamos un arreglo en el cual se guardaran los bytes que componen las imagenes del patron
    
    //el argumento byte[n_patron*8] es como tener un arreglo byte[n_patron][8]
    
    
    
    for( int i = 0 ; i < n_patron ; i++ ){    //Ciclo en el cual se ingreseran por el serial lo elemntos del patron [uno por uno]
    
    	pos_letra = i ;         //Guardamos la posicion de la letra en el arreglo bidimensional
    	
    	Serial.println(" Ingrese UNA letra [en mayuscula]: ");
    	
  	  while( Serial.available()==0 ){   //Nuevamente, si no hay nada en el monitor, preguntac cada 10s al usuario que ingrese algo valido
  	  Serial.println(" Su Respuesta: ");
  	  delay(10000);
  
    }
      
      letra_num =  Serial.read(); //Lee lo ingresado
      	
    	almacenar( pos_letra, letra_num, p_al, p_pu ); //Llamamos la funcion almacenar, que lo que hace basicamente es: meter en el arreglo de los patrones
                                                      //ingresados por el usuario, los bytes que conforman un caracter
    }
    
    
    while(true){      //Ciclo para mostrar el patron infinitamente
      
      
      imagen( p_pu , n_p );   //La funcion imagen muestra (en los leds del circuito) el numero de patrones ingresados por el usuario
      
    }
    
    delete p_pu;      //Liberamos el espacio de memoria
    
  
  }
  else if( num == 50  ){			//Condicion #4 Si la respuesta del usuario es [2]
  
  
    Serial.println("---GENERACION DE PATRON PERSONALIZADO---");
    
    Serial.println(" Cuantos elementos contiene tu patron? ");		//El usuario ingesa el numero de elementos de su patron PERSONALIZADO
    
      while( Serial.available()==0 ){       //Nuevamente, si no hay nada en el monitor, preguntac cada 10s al usuario que ingrese algo valido
  	  Serial.println(" Su Respuesta: ");
  	  delay(10000);
  
    }
    
    elementos_p = Serial.parseInt();		//Obtenemos lo ingresado como entero
    
    num_e = elementos_p ;     //guardamos el numero de elementos en otra variable
    
      Serial.println(" Cuanto tiempo desea que haya entre cada patron? [en milisegundos] ");		//El usuario ingesa el numero de elementos de su patron PERSONALIZADO
    
      while( Serial.available()==0 ){       //Nuevamente, si no hay nada en el monitor, preguntac cada 10s al usuario que ingrese algo valido
  	  Serial.println(" Su Respuesta: ");
  	  delay(10000);
  
    }
    
    t_ms = Serial.parseInt();     //Obtenemos el tiempo entre cada patron
    
    
    int *a_personalizado ;       //Puntero del arreglo del patron personalizado
    
    a_personalizado = new int[elementos_p*8] ;   //Arreglo en el que van a ir los patrones personalizados del usuario
  
    
    for(  int x = 0 ; x < num_e  ; x++  ){    //Ciclo que se repetira cuantos elemento quiera ingresar el usuario
      
      int index ;
      
      int *bin ;
      
      int *dec ;
      
      bin = new int[64];    //Arreglo que representará 1 byte en cada fila
      
      dec = new int[8];     //Arreglo en el que se almacenarán (con un numero decimal) las representaciones de una fila de leds
      
      index = x*8 ;
      
      matriz( bin );      //Modificamos la matriz que contiene la representacion de leds
      
      conversion(bin,dec);   //convertimos las filas de bin a numeros en el sistema decimal
      
      relleno( index , a_personalizado , dec );   //Llenamos el arreglo con el patron
      
      delete []bin ;
      
      delete []dec ;
      
    }
    
    while(true){      //Ciclo que se repetirá de forma indefinida mostrando los leds con el patron
      
      publik(a_personalizado,num_e,t_ms );
      
    }
    
    delete a_personalizado ;
  
  }
  else{			//Condicion #4 Si la respuesta del usuario es diferente de lo que se pide	
  
  Serial.println(" CONSEJO: RE-LEE LAS OPCIONES...");
  delay(3000);		//Espera 3 segunos, para que el usuario lea :)
  
  }


}