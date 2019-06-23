//
//  Graph.h
//  GraphTp
//
//  Created by Luis Araújo on 10/06/2019.
//  Copyright © 2019 UFMG. All rights reserved.
//
#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <limits.h>
#include <math.h>
#include "Codernates.h"
#ifndef Graph_h
#define Graph_h
const int INF = INT_MAX/2;
using namespace std;
class Graph
{
private:
    int n_Vertices;
    int n_Arestas;
    
    void SetNumberOfArchs()
    {
        for(int a = 0; a<this->n_Vertices; a++)
        {
            for(int b = 0; b<this->n_Vertices; b++)
            {
                if(this->Matriz[a][b])
                    this->n_Arestas++;
            }
        }
    }
    
    
    void DFS(int pos, bool *visitedVertex)
    {
        visitedVertex[pos] = true;
        for(int i = 0; i< this->n_Vertices; i++)
        {
            if(this->Matriz[pos][i] && !visitedVertex[i])
            {
                cout << i;
                if(i<n_Vertices-1)
                {
                    cout << " - ";
                }
                DFS(i, visitedVertex);
            }
        }
    }
public:
    int **Matriz;
    Graph(){}
    Graph(int n_vertices)
    {
        this->n_Vertices = n_vertices;
        
        this->Matriz = (int **)calloc(n_Vertices, sizeof(int*));
        for(int a = 0; a<this->n_Vertices; a++)
        {
            this->Matriz[a] = new int[n_Vertices];
        }
        
        for(int a = 0; a<this->n_Vertices; a++){
            for(int b =0; b<this->n_Vertices; b++){
                Matriz[a][b] = 0;
            }
            this->Matriz[a][a] = 0;
        }
        this->SetNumberOfArchs();
    }
    
    Graph(int *matrice[5])
    {
        this->n_Vertices = 5;
        this->Matriz = (int **)calloc(n_Vertices, sizeof(int*));
        for(int a = 0; a<this->n_Vertices; a++)
        {
            this->Matriz[a] = new int[n_Vertices];
        }
        this->Matriz = matrice;
        this->SetNumberOfArchs();
    }
    
    ~Graph(){
        for(int i = 0; i < n_Vertices; i++){
            delete[] Matriz[i];
        }
        delete[] Matriz;
    }
    //insert a arc by coordenates
    bool Insert(int x_coordenates, int y_coordenates, int weight)
    {
        try{
            if(this->Matriz[x_coordenates][y_coordenates]){
                cout<< "As arestas em "<<x_coordenates<< "-"<<y_coordenates<<" não foram inseridas"<< endl;
                return false;
            }
            else if(!this->Matriz[x_coordenates][y_coordenates]){
                this->Matriz[x_coordenates][y_coordenates] = weight;
                this->Matriz[y_coordenates][x_coordenates] = weight;
                this->n_Arestas++;
                cout << "Arestas inseridas com sucesso" <<endl;
            }
            return true;
        }
        catch(exception e){
            throw e;
        }
    }    
    
    //remove a arc by coordenates
    bool Remove(int x_coordenates, int y_coordenates)
    {
        try{
            if(!this->Matriz[x_coordenates][y_coordenates]){
                return false;
            }
            else if(this->Matriz[x_coordenates][y_coordenates]){
                this->Matriz[x_coordenates][y_coordenates] = 0;
                this->Matriz[y_coordenates][x_coordenates] = 0;
                this->n_Arestas--;
            }
            return true;
        }
        catch(exception e){
            throw e;
        }
    }
    
    //return numbers of arch and vertices in graph
    list<int> ReturnNumberOfArchAndVertices()
    {
        list<int> *archsAndVertices = new list<int>;
        archsAndVertices->push_back(this->n_Vertices);
        archsAndVertices->push_back(this->n_Arestas);
        
        return *archsAndVertices;
    }
    
    //verify if there's a arc betwen the two vertices
    bool Edge(int x_coordenates, int y_coordenates)
    {
        try
        {
            if(!this->Matriz[x_coordenates][y_coordenates]){
                return false;
            }
            else{
                return true;
            }
        }
        catch(exception e){
            throw e;
        }
    }
    
    //verify if the graph is complete
    bool VerifyIfTheGraphIsComplete()
    {
        int numberOfPositions = n_Vertices*n_Vertices;
        if(this->n_Arestas == numberOfPositions)
            return true;
        return false;
    }
    
    //Completes the graph
    void CompletesTheGraph()
    {
        for(int a = 0; a<this->n_Vertices; a++){
            for(int b = 0; b<this->n_Vertices; b++){
                if(!this->Matriz[a][b])
                    this->Matriz[a][b] = 1;
            }
        }
    }
    
    //Bradth First Search - BFS
    list<int> BreadthFirstSearch(int x)
    {
        bool *visitedVertex = new bool[x];
        list<int> order;
        for(int a = 0; a<x; a++)
        {
            visitedVertex[a] = false;
        }
        queue<int> *visited = new queue<int>;
        visitedVertex[x] = true;
        
        visited->push(x);
        while(1)
        {
            for(int i = 0; i<n_Vertices; i++)
            {
                if(this->Matriz[x][i] && !visitedVertex[i])
                {
                    visitedVertex[i] = true;
                    visited->push(i);
                }
            }
            if(!visited->empty()){
                order.push_back(visited->front());
                x = visited->front();
                visited->pop();
            }
            else{
                break;
            }
        }
        
        return order;
    }
    
    //Deep First Search - DFS
    void DeepFirstSearch(int x)
    {
        bool *visitedVertex = new bool[this->n_Vertices];
        cout << x << " - ";
        this->DFS(x, visitedVertex);
    }

    void Dijkstra(int x, int y)
    {
        int distance[n_Vertices];
        list<int> path;
        bool visited[n_Vertices];
        for (int i = 0; i < n_Vertices; i++){
            distance[i] = INF;
            visited[i] = false;
        }
        distance[x] = 0;
        
        for (int count = 0; count < n_Vertices-1; count++)
        {
            int min = INF;
            int minValue;
            
            for (int v = 0; v < n_Vertices; v++)
                if (visited[v] == false && distance[v] <= min){
                    min = distance[v];
                    minValue = v;
                }
            
            int u = minValue;

            visited[u] = true;

            for (int v = 0; v < n_Vertices; v++)
                
                if (!visited[v] && Matriz[u][v] && distance[u] != INF && distance[u]+Matriz[u][v] < distance[v])
                {
                    distance[v] = distance[u] + Matriz[u][v];
                    if(v == y){
                        path.push_back(u);
                    }
                }
        }

        cout << "Distância do vértice " << x << " para o vértice " << y << ": " << distance[y]<<endl;
        cout << "Caminho para chegar ao vértice "<< y<<": ";
        for(auto p : path){
            cout << p;
            if(p != path.back())
                cout << " - ";
            else{
                cout<< " - " << y <<endl;
            }
        }
        
    }
    
    //Problema do caixeiro viajante
    int* NearestNaybor(int x)
    {
        bool *inserted = new bool[this->n_Vertices];
        int  *path = new int[this->n_Vertices+1];
        for(int a = 0; a<this->n_Vertices; a++)
        {
            inserted[a] = false;
        }
        
        path[0] = x;
        inserted[x] = true;
        
        for(int i = 0; i<n_Vertices; i++)
        {
            int referenceValue = INF;
            int nextValue = 0;
            
            for(int a = 0; a<n_Vertices; a++)
            {
                for(int j = 0; j<n_Vertices; j++)
                {
                    if(!inserted[j] && referenceValue > Matriz[a][j])
                    {
                        if(!Matriz[a][j])
                        {
                            this->Insert(a, j, 1);
                        }
                        nextValue = j;
                        referenceValue = Matriz[a][j];
                    }
                    
                }
            }
            
            path[i+1] = nextValue;
            inserted[nextValue] = true;
        }
        int pathCount = 0;
        path[n_Vertices] = x;
        for(int i = 0; i <n_Vertices; i++)
        {
            pathCount += this->Matriz[path[i]][path[i+1]];
        }
        cout << "Custo do caminho encontrado: " << pathCount << endl;
        
        
        return path;
    }
    
    
    int* PrimAlgorithm(int x)
    {
        int* father = new int[this->n_Vertices];
        int *level = new int[this->n_Vertices];
        int actualVertex = x;
        int lowestWeight;
        int son = 0;
        for(int a = 0; a<n_Vertices; a++)
        {
            father[a] = -1;
            level[a] = 0;
        }
        father[x] = x;
        
        while(true)
        {
            bool first = true;
            for(int i = 0; i < n_Vertices; i++){
                if(father[i] != -1){
                    for(int j = 0; j < n_Vertices; j++){
                        if(father[j] == -1 && Matriz[i][j]){
                            if(first){
                                lowestWeight = Matriz[i][j];
                                actualVertex = i;
                                son = j;
                                first = false;
                                
                            }
                            else{
                                if(lowestWeight > Matriz[i][j]){
                                    lowestWeight = Matriz[i][j];
                                    actualVertex = i;
                                    son = j;
                                }
                            }
                        }
                    }
                }
            }
            
            
            father[son] = actualVertex;
            if(first)
                break;
            
        }
        
        return father;
    }
    
    
    
    
    
    
    
    
    
    
    
};

#endif /* Graph_h */

