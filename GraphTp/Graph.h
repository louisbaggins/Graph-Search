//
//  Graph.h
//  GraphTp
//
//  Created by Luis Araújo on 10/06/2019.
//  Copyright © 2019 UFMG. All rights reserved.
//
#include <iostream>
#include <stdlib.h>
#ifndef Graph_h
#define Graph_h
using namespace std;
class Graph
{
private:
    int n_Vertices;
    int n_Arestas;
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
        }
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
};

#endif /* Graph_h */

