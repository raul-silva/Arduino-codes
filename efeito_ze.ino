/* Efeito de rotação dos circulos de uma Rosácea de leds.
Autor: José Maria 4º ano de eletrônica
Disciplina: Microcontroladores e Microprocessadores
Professor: Cláudio Fleury */
int led0 = 5;  //Pino do led central.
int buffer = 2; //Pino 11 do 74HC595.
int clock = 3; //Pino 12 do 74HC595.
int led = 4; //Pino 14 do 74HC595.

int circuloA []={0x00, 0x00, 0xff};
int circuloB []={0x00, 0xff, 0x00};
int circuloC []={0xff, 0x00, 0x00};
int circulo0 []={0x00, 0x00, 0x00};

void setup() {
  // put your setup code here, to run once:
  pinMode(buffer,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(led0,OUTPUT);
}

void loop() {
  for (int j=0; j=24; j++){ 
    randomSeed(j);
   int i = random(500);
     if(i%500==0){
       enviadados(circulo0, (sizeof(circulo0)/2));
       digitalWrite(led0, HIGH);
       delay(500);
       digitalWrite(led0, HIGH);
     }
     if(i%500==1){
      enviadados(circuloA, (sizeof(circuloA)/2));
      delay(500);
     }
     if(i%500==2){
      enviadados(circuloB,(sizeof(circuloB)/2));
      delay(500);
     }
     if(i%500==3){
      enviadados(circuloC,(sizeof(circuloC)/2));
      delay(500);
     }
  }
     
}

void enviadados(int i[400], int y){//A função recebe um efeito(string) específico, seu tempo de delay e o tamanho da respectiva string.
     for (int x = 0; x <= y-3 ; x+=3) {
        digitalWrite(clock, LOW); 
        shiftOut(led, buffer, MSBFIRST, i[x]);   // escreve no "primeiro" 74HC595
        shiftOut(led, buffer, MSBFIRST, i[x+1]); // escreve no "segundo" 74HC595  
        shiftOut(led, buffer, MSBFIRST, i[x+2]); // escreve no "terceiro" 74HC595 
        delay(50);
        digitalWrite(clock, HIGH);
     }
}
