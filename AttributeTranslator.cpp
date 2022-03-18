//
//  AttributeTranslator.cpp
//  AttributeTranslator
//
//  Created by Nick Johnson on 3/15/22.
//

#include "AttributeTranslator.h"
#include <sstream>
#include <vector>
#include "utility.h"

AttributeTranslator::AttributeTranslator()
{
    
}

AttributeTranslator::~AttributeTranslator()
{
    
}

bool AttributeTranslator::Load(std::string filename)
{
    std::ifstream infile(filename);
    if(!infile)
        return false;
    
    std::string line;

    std::string sourceatt;
    std::string sourceval;
    std::string sourcepair;
    std::string compatt;
    std::string compval;
    while(getline(infile, line))
    {
        std::istringstream iss(line);
        if(!getline(iss, sourceatt, ','))
            return false;
        if(!getline(iss, sourceval, ','))
            return false;
        if(!getline(iss, compatt, ','))
            return false;
        if(!getline(iss, compval, ','))
            return false;
        
        sourcepair = sourceatt + sourceval;
        
        AttValPair attval(compatt, compval);
       
        if(r.search(sourcepair) == nullptr)
        {
            std::vector<AttValPair> s1;
            r.insert(sourcepair, s1);
            (*r.search(sourcepair)).push_back(attval);
            
        }
        else
        {
            (*r.search(sourcepair)).push_back(attval);
        }
   

        
    }
    
    return true;
}

std::vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(const AttValPair& source) const
{
    std::string pair = source.attribute + source.value;
    
    std::vector<AttValPair> v1;
    
    if(r.search(pair) == nullptr)
    {
        return v1;
    }
    else
        return(*r.search(pair));
}
