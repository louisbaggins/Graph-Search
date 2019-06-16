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
}

int** InitializeMatrice(int **matrice, int i)
{
    for(int a = 0; a< 5; a++){
        for(int b = 0; b<5; b++){
           matrice[a][b] = i;
        }
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

    
    PrintMatrice(graph->Matriz);
    
    
    cout<<graph->Edge(0, 3)<<endl;
    cout<< graph->Insert(1,0)<<endl;
    PrintMatrice(graph->Matriz);
    cout<< graph->Remove(1,0)<<endl;
    PrintMatrice(graph->Matriz);
    cout<< graph->Remove(2,0)<<endl;
    for(auto g : graph->ReturnNumberOfArchAndVertices()){
        cout<< g << endl;
    }
    cout<<graph->VerifyIfTheGraphIsComplete()<<endl;
    cout<<matrice->VerifyIfTheGraphIsComplete()<<endl;
    PrintMatrice(matrice->Matriz);
    
    for(auto g : matrice->ReturnNumberOfArchAndVertices()){
        cout<< g << endl;
    }
    
    
    cout << "Hello, World!\n";
    return 0;
}
