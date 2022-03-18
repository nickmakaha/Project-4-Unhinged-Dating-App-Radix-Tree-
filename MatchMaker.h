//
//  MatchMaker.hpp
//  MatchMaker
//
//  Created by Nick Johnson on 3/15/22.
//

#ifndef MatchMaker_hpp
#define MatchMaker_hpp

#include <stdio.h>
#include "AttributeTranslator.h"
#include "MemberDatabase.h"
#include "utility.h"
#include <algorithm>
class MatchMaker
{
public:
    MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at);
    
    ~MatchMaker();
    
    std::vector<EmailCount> IdentifyRankedMatches(std::string email,
                                                  int threshold) const;
    
private:
    const MemberDatabase& m_mb;
    const AttributeTranslator& m_at;
};


#endif /* MatchMaker_hpp */
