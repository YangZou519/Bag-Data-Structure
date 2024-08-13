//Yang Zou
#ifndef SET_H
#define SET_H

#include <cassert>
#include <stddef.h>

class set
{
public:
    set();

    typedef int value_type;
    typedef size_t size_type;
    static const size_type CAPACITY = 30;
    size_type size() const{ return used;}
    void insert(const value_type& entry);
    size_type count(const value_type& target) const;
    bool erase_one(const value_type& target);

    set operator+(const set&);
    void operator+=(const set& addend);

    set operator-(const set&);
    void operator-=(const set&);

    bool contains(const value_type& target) const;

    bool operator!=(const set&) const;
    bool operator==(const set&) const;
    bool operator<(const set&) const;
    bool operator>(const set&) const;
    bool operator<=(const set&) const;
    bool operator>=(const set&) const;
    bool subset(const set&) const;
    bool proper_subset(const set&) const;

    //return the data
    const value_type* getData(){return data;}
    //return the used
    const value_type getUsed(){return used;}

    void erase_all();


private:
    value_type data[CAPACITY];
    size_type used;
};

#endif