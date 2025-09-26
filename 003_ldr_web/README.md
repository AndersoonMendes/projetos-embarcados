# 💡 Gráfico de Luminosidade com Arduino

Este projeto monitora a **luminosidade ambiente** usando um **sensor LDR** conectado ao **Arduino UNO** e exibe os valores em **tempo real** em um **gráfico web**. A comunicação entre Arduino e navegador é feita usando a **Web Serial API** e o gráfico é desenhado com **Chart.js**.

---

## 📂 Estrutura do projeto
/003_ldr_web   
├─ index.html #*Página principal com o gráfico*  
├─ style.css #*Estilos da página*  
└─ script.js #*Código JS para conexão com Arduino e atualização do gráfico*   

---

## 🔧 Componentes necessários

- Arduino UNO  
- Sensor LDR  
- Cabo USB para conectar Arduino ao computador  

---
## ⚙️ Montagem do circuito

- Conecte o pino central do LDR ao **A0 do Arduino**.
- Alimente o sensor corretamente, conectando ao 5V e ao GND

---

## 📌 Código Arduino (UNO)

```cpp
const int LDR_PIN = A0; // LDR no pino A0
void setup() {
  Serial.begin(9600); // Inicia a comunicação serial com 9600 de velocidade
}

void loop() {
  int ldr = analogRead(LDR_PIN);  // Leitura e atribuição do valor de ldr
  Serial.println(ldr); // Informação enviada automaticamente para o web
  delay(2000); // Envia a cada 2s
}
```
---
## 🚀 Como usar a página web

- Abra o arquivo index.html no Chrome ou Edge.

- Clique no botão Conectar Arduino.

- Selecione a porta em que o Arduino está conectado.

- O gráfico começará a atualizar em tempo real mostrando a luminosidade (%) baseada no LDR.

---

## 📊 Explicação

- O Arduino envia os valores do LDR via Serial.println().

- O JavaScript lê essas linhas usando a Web Serial API.

- Cada valor é convertido em percentual de luminosidade:

- O gráfico mostra os últimos 10 valores em tempo real usando Chart.js.

---
## ⚠️ Observações

Funciona apenas em navegadores que suportam a Web Serial API (Chrome e Edge).

Certifique-se de que o Arduino está enviando cada valor em uma linha separada com Serial.println().

