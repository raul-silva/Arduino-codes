/* Efeito de rotação dos circulos de uma Rosácea de leds.
Autor: Raul Alfredo 4º ano de eletrônica
Disciplina: Microcontroladores e Microprocessadores
Professor: Cláudio Fleury */

int led0 = 5;  //Pino do led central.
int buffer = 2; //Pino 11 do 74HC595.
int clock = 3; //Pino 12 do 74HC595.
int led = 4; //Pino 14 do 74HC595.

int circulo[6] = {0x55, 0xaa, 0x55,  //acende alternadamente os leds 
                  0xaa, 0x55, 0xaa};

void setup() {  // declarando variáveis como saída
  pinMode(buffer,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(led0,OUTPUT);
}
  void loop (){
  enviadados(circulo, (sizeof(circulo)/2)/*Tamanho da string.*/);  // Executa o primeiro efeito.
  delay(100);
  // put your main code here, to run repeatedly: 
  
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
