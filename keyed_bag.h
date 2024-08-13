//Yang Zou
#ifndef KEYED_BAG_H
#define KEYED_BAG_H

#include "set.h"
#include <utility>    
#include <string>   
#include <array>  
//#include <cassert>
//#include <stddef.h> 
//#include <iostream> 

class keyed_bag{
public:
    keyed_bag();

    typedef int value_type;
    typedef size_t size_type;
    static const size_type CAPACITY = 30;
    size_type size() const{ return used;}
    size_type count(const value_type&, int) const;
    bool search_key(const value_type& ) const;

    void insert(const value_type&, int);

    keyed_bag operator+(const keyed_bag&);
    void operator+=(const keyed_bag& addend);

    keyed_bag operator-(const keyed_bag&);
    void operator-=(const keyed_bag&);

    //return the data
    const std::array<std::pair<value_type, int>, CAPACITY>& getData() const{return data;}
    //return the used
    const value_type getUsed(){return used;}

    void erase_all();

private:
    std::array<std::pair<value_type, int>, CAPACITY>data;
    size_type used;
};


#endif