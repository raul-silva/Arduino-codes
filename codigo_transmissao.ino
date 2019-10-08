/* Codigo do Projeto Final MCMP
Aluno: Raul Alfredo de Sousa Silva
Prof: Cláudio
Objetivo: Controlar os dados recebidos relativos à temperatura, umidade e luminosidade a fim de criar um ambiente agradável em uma sala
*/
/*OBSERVAÇÕES
Este é o código do Arduino que levará o transmissor RF e os sensores DHT 11 e LDR.

O DHT11 será ligado assim:
1- VCC (+5V do Arduino)
2- DATA (Pino 2 do Arduino)
3- NÃO CONECTADO(EM NADA!!!)
4- GND (GND do Arduino)

O LDR será ligado em série com um resistor (470) de forma que o VCC fique no resistor e GND no LDR.
Entao o ponto entre o resistor e o LDR deve ser ligado ao pino A0 (ANALOG 0).

O transmissor RF deve ser alimentado (VCC e GND) e o data vai no pino 1 (setinha pra fora '->').
*/



#include "DHT.h"
#define DHTPIN 2 // pino que estamos conectado o DHT no caso o pino 2
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);
// o pino 1 fica com o data do RF

//Variaveis
int recebelum = A0;  //Pino que recebe o dado de luminosidade
unsigned long TEMPO;  // Regula o tempo de leitura para 5s


void setup(){
  Serial.begin(9600);
  pinMode(recebelum,INPUT);
  dht.begin();
}


void loop(){
  TEMPO = millis();
  if(TEMPO - millis() >= 5000)
  conferedados();
}


void conferedados(){
  int umidade,temperatura;
  analogRead(recebelum);
  umidade = dht.readHumidity();
  temperatura = dht.readTemperature();
  if (recebelum < 310)// 0,1 e 2 são os numeros dos atuadores que vão ser ligados e o 1 indica a ação de ligar(no caso de 0, desligar)
    enviaacao(0,1);
  if (recebelum > 950)
    enviaacao(0,0);
  if (umidade < 30)
    enviaacao(1,1); 
  if (umidade > 90)
    enviaacao(1,0);  
  if (temperatura > 35)
    enviaacao(2,1);
  if (temperatura < 20)
    enviaacao(2,0);  
  if (temperatura > 30 && umidade < 45)
    enviaacao(2,1);
    enviaacao(1,1);
}


void enviaacao(byte s, byte e){
  byte sensor, estado;
  sensor = s + 48;
  estado = e + 48;    
  Serial.print("Sensor: ");
  Serial.print(sensor);
  Serial.print("Estado: ");
  Serial.println(estado);  
}

