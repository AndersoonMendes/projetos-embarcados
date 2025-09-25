// Projeto 01 - Blink LED
// Autor: Anderson Mendes
// Descrição: Pisca um LED a cada 5500 ms conectado ao pino 12 do Arduino UNO

#define LED 13  // Define o pino onde o LED está conectado

void setup() {
  pinMode(LED, OUTPUT); // Configura o pino como saída
}

void loop() {
  digitalWrite(LED, HIGH);  // Liga o LED
  delay(500);               // Aguarda 500 ms
  digitalWrite(LED, LOW);   // Desliga o LED
  delay(500);               // Aguarda 500 ms


  //retorna ao loop
}
