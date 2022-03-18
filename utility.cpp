//
//  utilities.cpp
//  utilities
//
//  Created by Nick Johnson on 3/15/22.
//

#include "utility.h"

bool operator<(const AttValPair& at1, const AttValPair& at2){
    return (at1.attribute<at2.attribute);
}
bool operator>(const EmailCount& e1, const EmailCount& e2) {
        if(e1.count == e2.count)
        {
            return e1.email > e2.email;
        }
    return e1.count > e2.count;
    }

