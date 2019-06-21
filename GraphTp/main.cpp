//
//  main.cpp
//  GraphTp
//
//  Created by Luis Araújo on 10/06/2019.
//  Copyright © 2019 UFMG. All rights reserved.
//

#include "Graph.h"
#include <iostream>
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
    static Graph *graph = new Graph(5);
    static int **matrix;
    matrix = InitializeMatricePointer(matrix, 5);
    Graph *matrice = new Graph(matrix);
    //InitializeMatrice(matrix, 1);
    
    for(auto g : matrice->ReturnNumberOfArchAndVertices()){
        cout<< g << endl;
    }
    
    int *vector = graph->Dijkstra(1, 4);
    for(int j = 0; j<5; j++)
    {
        cout << vector[j];
        cout << " - ";
    }
    
    cout << vector << endl;
 
    PrintMatrice(graph->Matriz);
   /* PrintMatrice(graph->Matriz);
    PrintMatrice(matrice->Matriz);
    graph->DeepFirstSearch(0);
    cout << "" << endl;
    graph->Remove(0, 1);
    graph->Remove(2, 1);
    for(auto g : graph->BreadthFirstSearch(0, 2)){
        cout<< g << endl;
    }*/
    
    return 0;
}
