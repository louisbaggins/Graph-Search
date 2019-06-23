//
//  Codernates.h
//  GraphTp
//
//  Created by Luis Araújo on 22/06/2019.
//  Copyright © 2019 UFMG. All rights reserved.
//

#ifndef Codernates_h
#define Codernates_h

class Codernates
{
public:
    int x;
    int y;
    int weight;
    Codernates(int coodernates_x, int coodernates_y, int weight)
    {
        x = coodernates_x;
        y = coodernates_y;
        this->weight = weight;
    }
};
#endif /* Codernates_h */
