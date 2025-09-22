# Levantamento e Justificativa da Escolha de Banco de Dados

### **Tarefas Cumpridas:**

* Identificação dos principais estilos de banco de dados.
* Análise dos trade-offs de cada abordagem.
* Relacionamento com as características do projeto.
* Verificação de escalabilidade, custo e complexidade.

---

### **1. Estilos de Banco de Dados**

Para o nosso projeto, os estilos de banco de dados mais relevantes são:

* **Relacional (SQL):** Bancos de dados tradicionais que armazenam dados em tabelas com um esquema fixo. Exemplo: PostgreSQL.
* **Não-Relacional (NoSQL):** Bancos de dados flexíveis que não exigem um esquema fixo. Subdividem-se em:
    * **Documento:** Armazena dados em documentos no formato JSON. Exemplo: MongoDB.
    * **Chave-Valor:** Armazena dados em pares de chaves e valores.
    * **Grafos:** Armazena dados em estruturas de nós e arestas.

---

### **2. Análise e Trade-offs: SQL vs. NoSQL (Documento)**

| Característica | Banco de Dados Relacional (SQL) | Banco de Dados Não-Relacional (NoSQL) |
| :--- | :--- | :--- |
| **Estrutura de Dados** | **Rígida e Estruturada.** | **Flexível e Dinâmica.** |
| **Vantagens** | Ideal para dados com estrutura fixa, garante integridade. | **Perfeito para dados que variam.** Mais rápido e fácil de começar. |
| **Desvantagens** | Dificuldade em lidar com dados não estruturados ou com esquema variável. | Menos adequado para dados com relações complexas. |
| **Aplicação no Projeto** | **Menos adequado**, pois os dados de notícias de diferentes fontes podem variar. | **Ideal**, pois o formato JSON dos dados de notícias pode ser facilmente armazenado. |

---

### **3. Escalabilidade, Custo e Complexidade**

| Característica | Escala Vertical (Relacional) | Escala Horizontal (NoSQL) |
| :--- | :--- | :--- |
| **Escalabilidade** | Aumenta o poder do servidor (CPU, RAM). **Custo elevado.** | Adiciona mais servidores simples para distribuir a carga. **Custo mais baixo.** |
| **Complexidade** | Exige um planejamento inicial detalhado da estrutura. | **Curva de aprendizado mais suave**, especialmente para quem já trabalha com JSON. |

A escalabilidade horizontal de bancos de dados NoSQL é a mais adequada para o nosso projeto, pois nos permite lidar com o crescimento do volume de notícias sem grandes custos.

---

### **4. Conclusão: Escolha e Justificativa**

**O estilo de banco de dados mais adequado para o nosso projeto é o:**

**Não-Relacional (Documento)**

**Justificativa:**

* **Flexibilidade:** A flexibilidade do esquema nos permite lidar com a variedade de dados de notícias de forma eficiente.
* **Facilidade de Uso:** O formato JSON é intuitivo para o desenvolvimento, o que acelera o progresso da equipe.
* **Escalabilidade e Custo:** A arquitetura do MongoDB nos permite lidar com o crescimento futuro do volume de dados de forma mais econômica e simples.

A escolha de um banco de dados NoSQL atende a todos os requisitos do projeto e fornece uma base sólida para o desenvolvimento da nossa aplicação.
