/* Codigo recepção MCMP*/

/*OBSERVAÇÕES:
Este é o codigo dos receptores RF e dos atuadores LEMBREM-SE SÃo NECESSÁRIOS 2 ARDUINOS!!!!!!!

O receptor RF será alimentado (VCC e GND) e o pino data será ligado ao pino 0
do Arduino (setinha pra dentro '<-').

Os atuadores são os pinos de 2 à 5 mas só os tres primeiro vão ligar.

O pino 2 liga quando a luz apagar (ou vc por a mão no LDR).
O pino 3 liga quando a umidade abaixa (< 30).
O pino 4 liga quando esquenta (> 35).

Acho que no dia vou poder falar, então liguem se precisarem.
*/
int i,nbytes;
int atuador[]={2,3,4,5};
char dados[50];


void setup()   {
  Serial.begin(9600);
  for(i=0;i<=4;i++)
    pinMode(atuador[i], OUTPUT);
}
 
 
void loop(){
  if (Serial.available()){
    while(Serial.available()){
      nbytes = Serial.available();
      Serial.println("Recebido: ");
      for(i=0; i < nbytes; i++)
        dados[i] = Serial.read();
      for(i=0; i < nbytes; i++)  
        Serial.print(dados[i]);
      Serial.println("\n Fim da mensagem");
      interpretacao();
    }
  }
  else
    delay(1000);
}


void interpretacao(){
  Serial.println("\n Iniciando...");
  int data[5],n,j=0;
  for (i = 0; i < nbytes; i++){
      if((dados[i]-48) >= 0 && (dados[i]-48) <= 9){
        data[j] = dados[i] - 48;
        j++;
      }
  }
  Serial.println("\n Acionado atuadores...");
  n = data[0];
    if (data[1]==0){
      digitalWrite(atuador[n],LOW);
      Serial.println("Atuador desligado");
      Serial.println(n);
    }
    if (data[1]==1){
      digitalWrite(atuador[n],HIGH);
      Serial.println("Atuador ligado");
      Serial.println(n);
    }
}
