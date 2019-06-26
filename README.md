# Graph-Search

### Classes do Projeto:
  
## Codernates:
  ```cpp
  int x - Armazena a coordenada x de uma aresta.
  int y - Armazena a coordenada y de uma aresta.
  int weight - Armazena o peso da aresta.
```
## GraphSpecs:
```cpp
int edges - Armazena o número de vértices
```
```cpp
list<Codernates> coodernates - Armazena uma lista de coordenadas onde deverão ser inseridas arestas. Além disso o objeto 
```
Codernates também armazena o peso da aresta.
```cpp
void AddSpecs(string x, string y, string weight)
```
Adiciona uma coordenada x, uma coordenada y e um peso a ser inserido na lista de coordenadas.
```cpp
list<Codernates> GetCoodernates()
```
Retorna a lista de coordenadas.


## Graph
### Atributos:
int n_Vertices - Armazena o número de vértices do grafo.
int n_Arestas - Armazena o número de arestas do grafo.
int** Matriz - Armazena a matriz de adjacência que representa o grafo.

Métodos:

```cpp
bool Insert(int x, int y)
```
Função membro da classe Graph, que recebe uma coordenada e adiciona uma aresta no grafo, caso ela ainda não exista.
```cpp
bool Remove(int x, int y)
```
Função membro da classe Graph, que recebe uma coordenada e remove uma aresta do grafo.
```cpp
list<int> ReturnNumberOfArchAndVertices()
```
Função membro da classe Graph, que retorna o número de vértices e  arestas do grafo.
```cpp
bool Edge(int x_coordenates, int y_coordenates)
```
Função membro da classe Graph que retorna true caso possua alguma aresta na coordenada passada.
```cpp
bool VerifyIfTheGraphIsComplete()
```
Verifica se o grafo é completo(todos os vértices se conectam entre si). Caso o grafo esteja completo, a função retorna true, se tiver incompleto, a função retornará false.
```cpp
 void CompletesTheGraph()
 ```
 Função que completa o grafo caso o mesmo não seja completo.
```cpp
list<int> BreadthFirstSearch(int x)
```
Método que retorna o caminho percorrido na busca em largura, usando um vértice x como referência.

```cpp
void DeepFirstSearch(int x)
```
Método que imprime o caminho percorrido na busca em profundida, usando um vértice x como referência.
```cpp
void Dijkstra(int x, int y)
```
Calcula o menor caminho entre dois vértices, onde x é o vértice inicial e y o final, utilizando o algoritmo guloso de Dijkstra, a função irá imprimir o custo do trajeto, e o trajeto.
```cpp
int* NearestNaybor(int x)
```
Função que tenta resolver o problema do caixeiro viajante utilizando a heurística do vizinho mais próximo, esta função não necessariamente retornará o menor caminho.
	O retorno da função é um vetor contendo o trajeto por todo o grafo, buscando sempre o vértice mais próximo, e no final, retornando ao vértice inicial.
```cpp
int* PrimAlgorithm(int x)
```
Método que cria uma árvore geradora de menor caminho através do algoritmo de Prim.
A função retorna um vetor onde, cada posição do vetor corresponde a um vértice, e o vetor posição do vértice armazena o seu pai.
Ex: A posição três do vetor retornado, representará o vértice três, e na posição três do vetor, será armazenada o pai do vértice três.
