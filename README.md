# Smart-Sleep
Sensor de temperatura + luz + Spotify → IA monta rotina de sono + playlist

## Integrantes:
| Nome | GitHub |
|------|--------|
| [Olavo Belfante Dias] | [@OlavoBD] |
| [Lorenzo Dias Lanzoni] | [@LorenzoDL] |
| [Simão Kiaku Pedro Quanguluka] | [@Simao2026] |


## Arquitetura

```mermaid
flowchart TD

    A[Usuario] --> B[Frontend]

    B --> C[Entrada]
    C --> D[Webhook N8N]

    D --> E[Processamento]
    E --> F[API Gemini]

    F --> G[Resposta]
    G --> H[Tratamento]

    H --> I[Saida]
    I --> J[Resultado]

    J --> A
```
