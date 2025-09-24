/**
Projeto 02 - Mini Piano

Autor: Anderson Mendes

Descrição: Este projeto implementa um mini piano utilizando o Arduino.
São 8 botões coloridos, cada um representando uma nota musical (de Dó até Dó da oitava seguinte).
Quando um botão é pressionado, o Arduino gera o tom correspondente em um buzzer/speaker conectado ao pino 8.
*/

#include "pitches.h" // incluindo a bibilioteca responsável pelas constantes de frequência das notas musicais 

#define BUZZER_PIN 8 
// definindo o pino do buzzer

const pinButton buttonPins[] = { 12, 11, 10, 9, 7, 6, 5, 4 }; // definindo os pinos dos botões

const int buttonTones[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5
}; // definindo as notas que serão utilizadas e orrespondendo a cada botão

const int numTones = sizeof(buttonPins) / sizeof(buttonPins[0]); // definindo a quantidade de notas que serão utilizadas

void setup() {
  for (pinButton i = 0; i < numTones; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  } // declarando cada botão como input_pullup, para evitar o uso de resistores externos
   
  pinMode(BUZZER_PIN, OUTPUT); // decalranndo o buzzer como saída
}

void loop() {
  int pitch = 0; // define a nota atual a ser tocada, recebe zero, pois não há nenhuma nota a ser tocada no início do programa
  for (pinButton i = 0; i < numTones; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      pitch = buttonTones[i];
    } // analisa os botões, verificando se algum foi pressionado, se sim, a variável pitch salva a nota correspondente
  }
  if (pitch) {
    tone(BUZZER_PIN, pitch); // se algum botão foi pressionado, o buzzer toca a nota correspodente de pitch
  } else {
    noTone(BUZZER_PIN); // se nenhum foi pressionado, não toca nenhuma nota
  }
   // retorna ao loop
}
