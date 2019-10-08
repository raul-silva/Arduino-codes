/* Efeito de rotação dos circulos de uma Rosácea de leds.
Autor: Eduardo Oliveira 4º ano de eletrônica
Disciplina: Microcontroladores e Microprocessadores
Professor: Cláudio Fleury */
int LED0=0;
int LED=1;
int BUFFER=2;
int CLOCK=3;

int circulo [] = {0x00, 0x00, 0x01,
                  0x00, 0x00, 0x03,
                  0x00, 0x00, 0x07,
                  0x00, 0x00, 0x0f,
                  0x00, 0x00, 0x1f,
                  0x00, 0x00, 0x3f,
                  0x00, 0x00, 0x7f,
                  0x00, 0x00, 0xff};
int total []   = {0xff, 0xff, 0xff};


void setup()  {
 pinMode (CLOCK,OUTPUT);
 pinMode (BUFFER,OUTPUT);
 pinMode (LED,OUTPUT);
 pinMode (LED0,OUTPUT); 
 
}
void loop() {
  enviadados(circulo,(sizeof(circulo)/2));
  delay(500);
  digitalWrite(LED0, HIGH);
  enviadados(total,(sizeof(total)/2));
  delay(500);
  digitalWrite(LED0, LOW);
}
void enviadados(int i[400], int y){//A função recebe um efeito(string) específico, seu tempo de delay e o tamanho da respectiva string.
     for (int x = 0; x <= y-3 ; x+=3) {
        digitalWrite(CLOCK, LOW); 
        shiftOut(LED, BUFFER, MSBFIRST, i[x]);   // escreve no "primeiro" 74HC595
        shiftOut(LED, BUFFER, MSBFIRST, i[x+1]); // escreve no "segundo" 74HC595  
        shiftOut(LED, BUFFER, MSBFIRST, i[x+2]); // escreve no "terceiro" 74HC595 
        delay(80);
        digitalWrite(CLOCK, HIGH);
     }
}
