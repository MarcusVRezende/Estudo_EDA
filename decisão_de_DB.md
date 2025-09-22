# Levantamento e Justificativa da Escolha de Banco de Dados 📊

### **Tarefas Cumpridas:** ✅

* Identificação dos principais estilos de banco de dados.
* Análise dos trade-offs de cada abordagem.
* Relacionamento com as características do projeto.
* Verificação de escalabilidade, custo e complexidade.

---

### **1. Estilos de Banco de Dados** 📚

Para o nosso projeto, os estilos de banco de dados mais relevantes são:

* **Relacional (SQL):** Bancos de dados tradicionais que armazenam dados em tabelas com um esquema fixo. Exemplo: PostgreSQL.
* **Não-Relacional (NoSQL):** Bancos de dados flexíveis que não exigem um esquema fixo. Subdividem-se em:
    * **Documento:** Armazena dados em documentos no formato JSON. Exemplo: MongoDB.
    * **Chave-Valor:** Armazena dados em pares de chaves e valores.
    * **Grafos:** Armazena dados em estruturas de nós e arestas.

---

### **2. Análise e Trade-offs: SQL vs. NoSQL (Documento)** ⚖️

| Característica | Banco de Dados Relacional (SQL) | Banco de Dados Não-Relacional (NoSQL) |
| :--- | :--- | :--- |
| **Estrutura de Dados** | **Rígida e Estruturada.** | **Flexível e Dinâmica.** |
| **Vantagens** | Ideal para dados com estrutura fixa, garante integridade. | **Perfeito para dados que variam.** Mais rápido e fácil de começar. |
| **Desvantagens** | Dificuldade em lidar com dados não estruturados ou com esquema variável. | Menos adequado para dados com relações complexas. |
| **Aplicação no Projeto** | **Menos adequado**, pois os dados de notícias de diferentes fontes podem variar. | **Ideal**, pois o formato JSON dos dados de notícias pode ser facilmente armazenado. |

---

### **3. Escalabilidade, Custo e Complexidade** 📈

| Característica | Escala Vertical (Relacional) | Escala Horizontal (NoSQL) |
| :--- | :--- | :--- |
| **Escalabilidade** | Aumenta o poder do servidor (CPU, RAM). **Custo elevado.** | Adiciona mais servidores simples para distribuir a carga. **Custo mais baixo.** |
| **Complexidade** | Exige um planejamento inicial detalhado da estrutura. | **Curva de aprendizado mais suave**, especialmente para quem já trabalha com JSON. |

A escalabilidade horizontal de bancos de dados NoSQL é a mais adequada para o nosso projeto, pois nos permite lidar com o crescimento do volume de notícias sem grandes custos.

---

### **4. Conclusão: Escolha e Justificativa** ✅

**O estilo de banco de dados mais adequado para o nosso projeto é o:**

**Não-Relacional (Documento)**

**Justificativa:**

* **Flexibilidade:** A flexibilidade do esquema nos permite lidar com a variedade de dados de notícias de forma eficiente.
* **Facilidade de Uso:** O formato JSON é intuitivo para o desenvolvimento, o que acelera o progresso da equipe.
* **Escalabilidade e Custo:** A arquitetura do MongoDB nos permite lidar com o crescimento futuro do volume de dados de forma mais econômica e simples.

A escolha de um banco de dados NoSQL atende a todos os requisitos do projeto e fornece uma base sólida para o desenvolvimento da nossa aplicação.
# Decisão de Tecnologia: Por que usar MongoDB?

![Texto alternativo para a imagem]<img width="438" height="115" alt="image" src="https://github.com/user-attachments/assets/547ab99a-ae9c-4629-bd96-e0d46096baf0" />


### 1. Flexibilidade de Esquema (Schema-less)

O MongoDB é um banco de dados NoSQL, o que significa que ele não exige que os dados tenham uma estrutura rígida. Cada documento (que é como um JSON) pode ter campos diferentes.

* **Vantagem:** Em um projeto de mineração de notícias, o formato dos dados pode variar muito entre as fontes. A flexibilidade do MongoDB permite que a equipe armazene notícias de diferentes jornais sem precisar de um esquema fixo, o que acelera o desenvolvimento.

### 2. Formato de Dados Intuitivo (JSON)

O MongoDB armazena os dados no formato **BSON** (uma versão binária do JSON). Isso o torna muito fácil de usar para desenvolvedores web, que já trabalham com JSON no dia a dia.

* **Vantagem:** A equipe de front-end, que lida com dados em JSON, terá uma curva de aprendizado mais suave e poderá integrar a aplicação com o banco de dados de forma mais rápida e natural.

### 3. Escalabilidade e Desempenho

O MongoDB é projetado para lidar com grandes volumes de dados de forma eficiente. Ele se expande facilmente (escalabilidade horizontal) e é otimizado para buscas complexas, como as buscas por palavras-chave que o nosso projeto exige.

* **Vantagem:** A arquitetura do banco de dados suporta o crescimento do projeto de mineração sem comprometer a performance, o que é crucial para a nossa aplicação.

### 4. Suporte e Comunidade

O MongoDB é um dos bancos de dados mais populares do mercado, com uma documentação excelente, tutoriais e uma comunidade ativa.

* **Vantagem:** A equipe terá acesso a um vasto material de apoio e poderá resolver dúvidas rapidamente, o que é ideal para um projeto com prazo de entrega definido.

### Conclusão

A escolha do MongoDB se justifica por sua **flexibilidade**, **facilidade de uso** e **poder de processamento de dados em escala**. Ele é a ferramenta ideal para garantir que o projeto seja entregue com sucesso, atendendo a todos os requisitos do projeto.


