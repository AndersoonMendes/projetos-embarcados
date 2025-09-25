const ctx = document.getElementById('grafico').getContext('2d'); // Pega o contexto do canvas para desenhar o gráfico

const dados = { // Dados que serão plotados no gráfico
  labels: [], // Tempo(Eixo X)
  datasets: [{
    label: 'Luminosidade (%)',
    data: [],
    borderColor: '#ffeb3b',
    backgroundColor: 'rgba(255,235,59,0.3)',
    fill: true,
    tension: 0.2
  }]
};

const config = { // Configurações do gráfico
  type: 'line',
  data: dados,
  options: {
    responsive: false,
    maintainAspectRatio: false,
    scales: {
      y: { 
        min: 0,
        max: 100,
        ticks: { stepSize: 10 },
        title: { display: true, text: 'Luminosidade (%)' }
      }
    },
    plugins: { legend: { display: false } }
  }
};

const grafico = new Chart(ctx, config); // Controla o gráfico, recebendo como parâmetros, as configurações e definições dos gráficos 

function atualizarGrafico(pct) { 
  dados.labels.push(new Date().toLocaleTimeString()); // Envia as labels do eixo X(tempo)
  dados.datasets[0].data.push(pct); // Envia o valor da luminosidade
  if (dados.labels.length > 10) { // Se passar de 10 valores de tempo, o mais antigo será apagado
    dados.labels.shift();
    dados.datasets[0].data.shift();
  }
  grafico.update();
}

let buffer = '';

async function conectarArduino() {
  try {
    const porta = await navigator.serial.requestPort();
    await porta.open({ baudRate: 9600 });

    const decoder = new TextDecoderStream();
    porta.readable.pipeTo(decoder.writable);
    const reader = decoder.readable.getReader();

    while (true) {
      const { value, done } = await reader.read();
      if (done) break;
      if (value) {
        buffer += value;
        let linhas = buffer.split('\n');
        buffer = linhas.pop(); // mantém o último fragmento incompleto
        linhas.forEach(linha => {
          const valorLDR = parseInt(linha.trim());
          if (!isNaN(valorLDR)) {
            const pct = Math.round(((1023 - valorLDR) / 1023) * 100);
            atualizarGrafico(pct);
          }
        });
      }
    }
  } catch (erro) {
    console.error("Erro ao conectar com o Arduino:", erro);
  }
}

document.getElementById('conectar').addEventListener('click', conectarArduino);
