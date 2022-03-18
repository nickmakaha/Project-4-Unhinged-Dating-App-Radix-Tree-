//
//  AttributeTranslator.hpp
//  AttributeTranslator
//
//  Created by Nick Johnson on 3/15/22.
//

#ifndef AttributeTranslator_hpp
#define AttributeTranslator_hpp

#include <stdio.h>
#include "provided.h"
#include <fstream>
#include <set>
#include "RadixTree.h"
#include <vector>

class AttributeTranslator
{
public:
    AttributeTranslator();
    
    ~AttributeTranslator();
    
    bool Load(std::string filename);
    
    std::vector<AttValPair> FindCompatibleAttValPairs(const AttValPair& source) const;
    
private:
    //std::set<AttValPair> s1;
    RadixTree<std::vector<AttValPair>> r;
    
};

#endif /* AttributeTranslator_hpp */
