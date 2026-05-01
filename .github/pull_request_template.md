## O que foi feito
<!-- Descreva brevemente as mudanças deste PR -->

## Issue relacionada
<!-- Ex: Closes #12 -->

## Arquitetura do Projeto

```mermaid
flowchart LR

A[Entrada do Usuário] --> B{Dados Necessários}
B --> C[API ViaCEP]
B --> D[API OpenWeather]
C --> E[Gemini AI]
D --> E
E --> F[Resposta Final]
```

## Como funciona

O Smart-Sleep recebe informações do usuário, consulta APIs externas e usa IA para gerar recomendações personalizadas de sono.
