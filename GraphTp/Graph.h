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
                cout << i << endl;
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
                Matriz[a][b] = (rand() % 2 - 0);
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
    //insert a arc by coordenates
    bool Insert(int x_coordenates, int y_coordenates)
    {
        try{
            if(this->Matriz[x_coordenates][y_coordenates]){
                return false;
            }
            else if(!this->Matriz[x_coordenates][y_coordenates]){
                this->Matriz[x_coordenates][y_coordenates] = 1;
                this->n_Arestas++;
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
    list<int> BreadthFirstSearch(int x, int y)
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
        cout << x << endl;
        this->DFS(x, visitedVertex);
    }
    
    
    //Busca pelo Algoritmo de Dijkstra
    int* Dijkstra(int x, int y)
    {
        bool visited[n_Vertices];
        int *distance = new int[this->n_Vertices];
        
        for(int i=0; i<n_Vertices; i++) {
            visited[i] = false;
            distance[i] = INF;
        }
        distance[x] = 0;
        int no = -1;
        
        while(!visited[y]) {
            for(int i=0; i<this->n_Vertices; i++){
                if(!visited[i] && (no == -1 || distance[i] < distance[no]))
                    no = i;
            }
            visited[no] = 1;
            
            if(distance[no] == INF)
                break;
            
            for(int i=0; i<n_Vertices; i++){
                if(distance[i] > distance[no]+this->Matriz[no][i])
                    distance[i] = distance[no]+this->Matriz[no][i];
            }
        }
        
        return distance;
    }
    
    //Problema do caixeiro viajante
    
    
    
};

#endif /* Graph_h */

