# Sistema de Monitoramento de Distância Inteligente – SAFE ORBIT 🚀

## 👨‍💻 Integrantes do Projeto

* Felipe Pedrol (RM: 569631)
* Ricardo Salmeron Paulino de Souza (RM: 572916)
* Daniel Roberto (RM: 571746)
* Leonardo Ferreira Barbosa (RM: 569631)
* Jecky Cossio (RM: 572226)

---

## 🎥 Link para os vídeos no Youtube

* A ser produzido

---

## 🔗 Link para acesso do Projeto no Tinkercad

* https://www.tinkercad.com/things/eSzPrlO7Uxw-global-solution-espi1/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=p4yf_emXBDXeO0k2OVraEKoNhDgM6P90aRoYAVM6mvk

---

# 📝 Descrição do Projeto

O SAFE ORBIT foi desenvolvido como parte da solução SpaceClean, uma iniciativa voltada para o monitoramento e mitigação de riscos relacionados à presença de objetos em órbita terrestre.

O crescimento da quantidade de satélites desativados, fragmentos de foguetes e detritos espaciais aumenta significativamente o risco de colisões no ambiente orbital. Essas colisões podem gerar ainda mais fragmentos, comprometendo missões espaciais, sistemas de comunicação, navegação e observação da Terra.

Pensando nesse cenário, o projeto simula um sistema inteligente de monitoramento de proximidade capaz de identificar objetos que estejam se aproximando de uma estrutura espacial. Utilizando sensores de distância, indicadores visuais, alertas sonoros e exibição em display LCD, a solução fornece informações em tempo real sobre o nível de risco detectado.

Embora o protótipo utilize um sensor ultrassônico para fins didáticos, a lógica empregada representa conceitos semelhantes aos utilizados em sistemas reais de monitoramento de objetos espaciais.

---

# 🎯 Objetivos da Solução

O sistema foi projetado para:

* Monitorar continuamente a distância de objetos próximos.
* Identificar situações de risco com base na proximidade detectada.
* Informar o operador por meio de alertas visuais e sonoros.
* Exibir informações em tempo real através de um display LCD.
* Simular mecanismos de prevenção de colisões aplicados ao contexto espacial.

---

# 🧩 Componentes Utilizados

| Componente                | Quantidade |
| ------------------------- | ---------- |
| Arduino Uno               | 1          |
| Sensor Ultrassônico (SIG) | 1          |
| Display LCD 16x2 I2C      | 1          |
| LED Verde                 | 1          |
| LED Amarelo               | 1          |
| LED Vermelho              | 1          |
| Buzzer Piezoelétrico      | 1          |
| Resistores 220Ω           | 3          |
| Protoboard                | 1          |
| Jumpers                   | Diversos   |

---

# ⚙️ Funcionamento Geral do Sistema

O sensor ultrassônico realiza leituras constantes da distância entre o dispositivo e um possível obstáculo.

Com base nos valores obtidos, o Arduino classifica automaticamente a situação em três níveis de segurança:

* Segurança OK
* Alerta
* Alerta Crítico

Cada estado possui uma combinação específica de LEDs, mensagens no display e comportamento do buzzer, permitindo uma rápida interpretação da situação pelo usuário.

---

# 🟢 Estado Segurança OK

Condições em que o obstáculo está distante e o ambiente está seguro.

### Comportamento

* LED Verde ligado
* LED Amarelo desligado
* LED Vermelho desligado
* LCD indicando "SEGURANCA OK"
* Buzzer desligado

### Faixa de Distância

* Acima de 100 cm

---

# 🟡 Estado de Alerta

Condição que exige atenção devido à aproximação de um objeto.

### Comportamento

* LED Verde desligado
* LED Amarelo ligado
* LED Vermelho desligado
* LCD exibindo "ALERTA"
* Buzzer desligado

### Faixa de Distância

* Entre 51 cm e 100 cm

---

# 🔴 Estado Crítico

Condição considerada de perigo iminente ou colisão.

### Comportamento

* LED Verde desligado
* LED Amarelo desligado
* LED Vermelho ligado
* Buzzer ativado continuamente
* LCD exibindo "ALERTA CRITICO"

### Faixa de Distância

* Até 50 cm

---

# 🖥️ Interface do LCD

### Inicialização (Primeiros 2 segundos)

```text
SpaceClean
Inicializando
```

### Segurança OK

```text
Dist: XXX cm
SEGURANCA OK
```

### Estado de Alerta

```text
Dist: XXX cm
ALERTA
```

### Estado Crítico

```text
Dist: XXX cm
ALERTA CRITICO
```

---

# ▶️ Como Executar o Projeto

### 1. Acesse o projeto

Abra o link do Tinkercad disponibilizado neste README.

### 2. Inicie a simulação

Clique no botão "Start Simulation".

### 3. Interaja com o sensor

Utilize o controle de distância do objeto virtual presente no Sensor Ultrassônico.

Ao aproximar ou afastar o objeto, o sensor enviará novos valores ao Arduino.

### 4. Observe os indicadores

Dependendo da distância detectada, o sistema responderá automaticamente:

| Distância       | Situação       |
| --------------- | -------------- |
| Acima de 100 cm | Segurança OK   |
| 51 cm a 100 cm  | Alerta         |
| Até 50 cm       | Alerta Crítico |

### 5. Verifique os alertas

Durante a simulação você poderá observar:

* Mudança de LEDs conforme o nível de risco.
* Atualização das mensagens no LCD.
* Acionamento do buzzer em situações críticas.
* Atualização contínua da distância medida.

---

# 📊 Exemplo de Uso

Imagine que um fragmento de lixo espacial esteja se aproximando de um satélite.

À medida que a distância diminui:

1. O sistema detecta a aproximação.
2. O estado muda de Segurança OK para Alerta.
3. Caso a distância continue reduzindo, o sistema entra em Alerta Crítico.
4. O LED vermelho é acionado e o buzzer emite um alerta sonoro.
5. O operador recebe informações instantâneas sobre a situação.

Essa lógica simula, de forma simplificada, como sistemas de monitoramento podem auxiliar na prevenção de colisões em ambientes espaciais.

---

# 🚀 Conclusão

O SAFE ORBIT demonstra como sensores, sistemas embarcados e mecanismos de alerta podem trabalhar em conjunto para monitorar riscos de proximidade em tempo real.

Mesmo sendo uma simulação acadêmica, o projeto representa conceitos importantes utilizados na indústria espacial moderna, como monitoramento contínuo, análise de risco e resposta rápida a possíveis ameaças, contribuindo para a segurança operacional de equipamentos e missões espaciais.
