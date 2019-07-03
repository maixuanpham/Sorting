//
//  Comparator.h
//  Project_2
//
//  Created by Mai Pham on 4/14/18.
//  Copyright © 2018 Mai Pham. All rights reserved.
//

#ifndef Comparator_h
#define Comparator_h

#include <iostream>
using namespace std;

template <typename E>
class LeftRight {                // a left-right comparator
public:
    bool operator()(const E& p, const E& q) const
    { return p.key() < q.key(); }
    
};

#endif /* Comparator_h */
