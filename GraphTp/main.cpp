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
int main(int argc, const char * argv[]) {
    // insert code here...
    static Graph *graph = new Graph(5);
    PrintMatrice(graph->Matriz);
    
    
    cout<<graph->Edge(0, 3)<<endl;
    cout<< graph->Insert(1,0)<<endl;
    PrintMatrice(graph->Matriz);
    cout<< graph->Remove(1,0)<<endl;
    PrintMatrice(graph->Matriz);
    cout<< graph->Remove(2,0)<<endl;
    cout << "Hello, World!\n";
    return 0;
}
