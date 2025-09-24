# 🎹 Projeto 02 - Mini Piano com Arduino

## 📖 Descrição
Este projeto implementa um **mini piano** utilizando o Arduino.  
São **8 botões coloridos**, cada um representando uma nota musical (de **Dó** até **Dó da oitava seguinte**).  
Quando um botão é pressionado, o Arduino gera o tom correspondente em um **buzzer/speaker** conectado ao pino **8**.  


---

## 🔧 Hardware necessário
- 1 Arduino UNO (ou compatível)  
- 1 buzzer (ativo ou passivo)  
- 8 botões (push buttons)  
- 8 resistores de 10kΩ (para pull-down, caso não use `INPUT_PULLUP`)  
- Jumpers e protoboard  

---

## ⚡ Ligações
- **Pino 8 → buzzer**  
- **Pinos 12, 11, 10, 9, 7, 6, 5, 4 → botões**  
- Outro terminal de cada botão vai ao **GND** (usando `INPUT_PULLUP`)  

---

## 🎵 Notas musicais
Cada botão dispara um tom específico:

| Botão | Pino | Nota  |
|-------|------|-------|
| 1     | 12   | Dó (C4) |
| 2     | 11   | Ré (D4) |
| 3     | 10   | Mi (E4) |
| 4     | 9    | Fá (F4) |
| 5     | 7    | Sol (G4) |
| 6     | 6    | Lá (A4) |
| 7     | 5    | Si (B4) |
| 8     | 4    | Dó (C5) |

---

## 💻 Código principal
O código está disponível em `firmware/mini_piano.ino`.  
Trecho principal:

```cpp
const uint8_t buttonPins[] = { 12, 11, 10, 9, 7, 6, 5, 4 };
const int buttonTones[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5
};

