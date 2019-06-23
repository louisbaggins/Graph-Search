//
//  GraphSpecs.h
//  GraphTp
//
//  Created by Luis Araújo on 22/06/2019.
//  Copyright © 2019 UFMG. All rights reserved.
//

#ifndef GraphSpecs_h
#define GraphSpecs_h
#include <list>
#include <stdlib.h>
#include "Codernates.h"
using namespace std;

class GraphSpecs
{
private:
    int edges;
    list<Codernates> coodernates;
public:
    GraphSpecs(){}
    
    GraphSpecs(int edges, list<Codernates> cod)
    {
        this->edges = edges;
        coodernates = cod;
    }
    
    void AddSpecs(string x, string y, string weight)
    {
        Codernates *params = new Codernates(atoi(x.c_str()), atoi(y.c_str()), atoi(weight.c_str()));
        coodernates.push_back(*params);
    }
    
    list<Codernates> GetCoodernates()
    {
        return coodernates;
    }
};



#endif /* GraphSpecs_h */
