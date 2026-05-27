# Sistema de Monitoramento de Distância Inteligente – SAFE ORBIT 🚀

## Link para os vídeos no Youtube:
- A ser produzido

---

## Link para acesso do Projeto no Tinkercad:
- https://www.tinkercad.com/things/eSzPrlO7Uxw-global-solution-espi1/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=p4yf_emXBDXeO0k2OVraEKoNhDgM6P90aRoYAVM6mvk

---

# 📝 Descrição do Projeto

Este projeto foi desenvolvido para o sistema **SpaceClean**, criando um dispositivo inteligente responsável pelo monitoramento contínuo de distância e detecção de proximidade em tempo real.

A solução foi construída utilizando um **Arduino Uno** e realiza o monitoramento simultâneo através de um **Sensor Ultrassônico (3 pinos - SIG)**. Os dados de distância são medidos em centímetros e exibidos dinamicamente em um **Display LCD 16x2 I2C**. O sistema também conta com indicadores visuais e sonoros para alertar o usuário conforme a aproximação de obstáculos.

O ambiente/distância é classificado em três estados de segurança:

🟢 Segurança OK (Distância Segura)  
🟡 Alerta (Aproximação Moderada)  
🔴 Alerta Crítico (Proximidade Perigosa)  

---

# ⚙️ Funcionalidades

## 🟢 Estado Segurança OK
Condições em que o obstáculo está distante e o ambiente está seguro.

### Comportamento:
- LED Verde ligado
- LED Amarelo desligado
- LED Vermelho desligado
- LCD indicando "SEGURANCA OK"
- Buzzer desligado

### Valores:
- Distância → acima de **100 cm**

---

## 🟡 Estado de Alerta
Condição que exige atenção devido à aproximação de um objeto.

### Comportamento:
- LED Verde desligado
- LED Amarelo ligado
- LED Vermelho desligado
- LCD exibindo "ALERTA"
- Sem acionamento do buzzer

### Valores:
- Distância → entre **51 cm** e **100 cm**

---

## 🔴 Estado Crítico
Condição considerada de perigo iminente ou colisão.

### Comportamento:
- LED Verde desligado
- LED Amarelo desligado
- LED Vermelho ligado
- Buzzer ativado continuamente com frequência de **1500Hz**
- LCD exibindo "ALERTA CRITICO"

### Valores:
- Distância → até **50 cm**

---

# 🖥️ Interface do LCD

### Inicialização (Primeiros 2 segundos)

```text
SpaceClean      
Inicializando