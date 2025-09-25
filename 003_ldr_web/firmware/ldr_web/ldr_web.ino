const int LDR_PIN = A0; // LDR no pino A0
void setup() {
  Serial.begin(9600); // Inicia a comunicação serial com 9600 de velocidade
}

void loop() {
  int ldr = analogRead(LDR_PIN);  // Leitura e atribuição do valor de ldr
  Serial.println(ldr); // Informação enviada automaticamente para o web
  delay(2000); // Envia a cada 2s
}
