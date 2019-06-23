//
//  main.cpp
//  GraphTp
//
//  Created by Luis Araújo on 10/06/2019.
//  Copyright © 2019 UFMG. All rights reserved.
//

#include "Graph.h"
#include "GraphSpecs.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
void PrintMatrice(int **matrice)
{
    for(int a = 0; a< 5; a++){
        for(int b = 0; b<5; b++){
            cout<< matrice[a][b];
        }
        cout<<endl;
    }
    
    cout<<endl;
}

int** InitializeMatrice(int **matrice, int i)
{
    for(int a = 0; a< 5; a++){
        for(int b = 0; b<5; b++){
            matrice[a][b] = i;
        }
        matrice[a][0] = 0;
        
    }
    
  
    return matrice;
}
int** InitializeMatricePointer(int **matrice, int n)
{
    matrice = (int **)calloc(n, sizeof(int*));
    for(int a = 0; a< 5; a++){
            matrice[a] = new int[n];
    }
    return InitializeMatrice(matrice, n);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    GraphSpecs *graphSpecs = new GraphSpecs();
    ifstream ip("/Users/luisaraujo/Desktop/POO/GraphTp/GraphTp/GraphValues.txt");
    
    if(!ip.is_open()){
        cout << "Error on reading file" << endl;
    }
    
    bool first = true;
    int count = 0;
    int size;
    string sizes;
    string x;
    string y;
    string weight;
    while(ip.good())
    {
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if(first){
            getline(ip, sizes, ',');
            first = false;
        }
        
        getline(ip,x,',');
        getline(ip,y,',') ;
        getline(ip,weight,'\n') ;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        graphSpecs->AddSpecs(x, y, weight);
    }
    
    ip.close();
    
    
    size = atoi(sizes.c_str());
    
    static Graph *graph = new Graph(size);
    static int **matrix;
    matrix = InitializeMatricePointer(matrix, 5);
    //setting archs
    for(auto c: graphSpecs->GetCoodernates())
    {
        graph->Insert(c.x, c.y, c.weight);
    }
    PrintMatrice(graph->Matriz); cout<<""<<endl;
    //number of arch and vertices
    list<int> vertex = graph->ReturnNumberOfArchAndVertices();
    cout << "Número de vértices: " << vertex.front() << endl;
    cout << "Número de arestas: " << vertex.back() << endl;
    
    
    if(graph->Remove(0,1))
    {
        cout << "Aresta removida em: "<<0<<"-"<<1<<endl;
    }
    else{
        cout << "Não há aresta em: "<<0<<"-"<<1<<endl;
    }

    graph->Insert(3, 0, 5);
    graph->Insert(4, 0, 3);
    graph->Insert(1,1,6);
    //graph->Insert(0,1,4);
    
    cout <<"Caminho Busca em profundidade: ";
    graph->DeepFirstSearch(0);
    cout << "" <<endl;
    cout <<"Caminho Busca em largura: ";
    list<int> bfs = graph->BreadthFirstSearch(0);
    for(auto b : bfs)
    {
        cout << b;
        if(b != bfs.back())
            cout<< " - ";
        else
            cout << "" << endl;
    }
    if(!graph->VerifyIfTheGraphIsComplete())
    {
        cout << "O grafo não está completo, completando o grafo..."<<endl;
        try{
            graph->CompletesTheGraph();
            cout <<"Grafo completado com sucesso!" <<endl;
        }
        catch(exception e){
            cout<< "Erro ao completar o grafo" << endl;
        }
        
    }
    else{
        cout <<"O grafo está completo!" <<endl;
    }
    
    cout <<"Resolvendo o problema do caixeiro viajante usando a heurística do vizinho mais próximo, iniciando em 0: " <<endl;
    int *vector = graph->NearestNaybor(0);
    cout <<"Caminho encontrado: ";
    for(int j = 0; j<6; j++)
    {
        cout << vector[j];
        if(j<5){
            cout << " - ";
        }
    }
    cout <<""<<endl;
    cout << "Árvore geradora mínima pelo algorítmo de Prim: "<<endl;
    int *tree = graph->PrimAlgorithm(2);
    cout << "" << endl;
    for(int j = 0; j<5; j++)
    {
        cout <<"Vértice pai do vértice "<< j << ": "<< tree[j]<<endl;
    }
    
    //cout << vector << endl;
    cout << "Matriz de adjacência final: " << endl;
    PrintMatrice(graph->Matriz);
    return 0;
}
