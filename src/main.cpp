//*****************************************************************************
//****Programa para probar el ESP12E, realizando la conexión a una red Wifi****
//*****************************************************************************
#include "Arduino.h"      //Agregamos la librería de arduino
#include <ESP8266WiFi.h>  //Agregamos la librería del ESP8266

const char* ssid = "hw-get";    //Indicamos el nombre de la red
const char* password = "hw-get.com"; //Indicamos su contraseña

const int PIN_LED = 5;    //Definimos que el GPIO5 como "PIN_LED"

void setup_wifi();        //Declaramos que habrá una función setup_wifi();

void setup(){             //Declaramos la función de configuración "setup"
  pinMode(PIN_LED, OUTPUT);   //Indicamos que PIN_LED funcione como salida
  pinMode(BUILTIN_LED, OUTPUT); //Indicamos que el led integrado funcione como salida
  Serial.begin(115200);   //Seleccionamos la velocidad de la comunicación serial a 115200
  setup_wifi();           //Llamamos a la funcion de configuracion del WiFi
}

void setup_wifi(){        //Definimos lo que hará la función "setup_wifi"
  delay(10);              //Creamos un retardo de 10 ms
  Serial.println();       //Mandamos por comunicación serial un salto de línea
  Serial.print("Conectando a ");  //Mandamos el texto "Conectando a "
  Serial.println(ssid);   //Mandamos en nombre de la red

  WiFi.begin(ssid, password);   //llamamos a la función WiFi.begin indicando
                                //el nombre y la contraseña de la red
  while (WiFi.status()!=WL_CONNECTED){  //Mientras no esté conectado se realiza este ciclo
    delay(500);           //Un retardo de 500 ms
    Serial.print(".");    //En cada ciclo enviamos un punto para visualizar que lo está intentando
  }
              //Una vez conectado se sale del ciclo y envía lo siguiente
  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP());   //Indica la dirección IP actual asignada al módulo
}

void loop(){    //El ciclo principal que actualmente está vacío
}
