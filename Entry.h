//
//  Entry.h
//  Project_2
//
//  Created by Mai Pham on 4/14/18.
//  Copyright © 2018 Mai Pham. All rights reserved.
//

#ifndef Entry_h
#define Entry_h

template <typename K, typename V>
class Entry {                                       // a (key, value) pair
public:                                             // public functions
    Entry(const K& k = K(), const V& v = V())       // constructor
    : _key(k), _value(v) { }
    const K& key() const { return _key; }           // get key
    const V& value() const { return _value; }       // get value
    void setKey(const K& k) { _key = k; }           // set key
    void setValue(const V& v) { _value = v; }       // set value
private:                                            // private data
    K _key;                                         // key
    V _value;                                       // value
};

#endif /* Entry_h */
