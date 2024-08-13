#include "set.h"
#include <algorithm>

set::set():used(0){}

//check if the set contains the given target
bool set::contains(const value_type& target) const{
    for(size_type i = 0; i < used; i++){
        if(data[i] == target)//if target in the data return true
            return true;
    }
    return false;
}

//insert one integer into the set
void set::insert(const value_type& entry)
{
    //the set can only contains one copy of each element
    assert(size() < CAPACITY && count(entry) < 1);
    data[used] = entry;
    ++used;
}

//count how many target are in the data
set::size_type set::count(const value_type& target) const
{
    size_type answer;
    size_type i;
    answer = 0;
    for (i = 0; i < used; ++i)
        if(target == data[i])
            ++answer;
    return answer;
}

//erase one of the target from the data
bool set::erase_one(const value_type& target)
{
    size_type index;
    
    index = 0;
    while((index < used) && (data[index] != target))
        ++index;
        
    if(index == used)
        return false;
        
    --used;
    data[index] = data[used];
    return true;
}

void set::operator+=(const set& addend)
{
    assert(size() + addend.size() <= CAPACITY);
    
    std::copy(addend.data, addend.data + addend.used, data + used);
    used += addend.used;
}

set set::operator+(const set& s)
{
    set answer;
    
    assert(this->size() + s.size() <= set::CAPACITY);
    
    answer += *this;
    answer += s;
    return answer;
}

//remove all elements that set s have from this->set
set set::operator-(const set& s)
{
    set result;
    for(size_type i = 0; i < used; i++){
        size_type diff = count(data[i]) - s.count(data[i]);//check the difference
        //if the diff is greater than 0 and the element is not in the result too. insert the element to the result
        if(diff > 0 && result.count(data[i]) == 0){
            result.insert(data[i]);
        }
    }
    return result;
}

//use the '-' operator to form -=
void set::operator-=(const set& s)
{
    *this = *this - s;
}

//check if the set s is different as this->set
bool set::operator!= (const set& s) const{
    //check if this->set contains all the elements in the set s
    for(size_type i = 0; i < used; i++){
        if (!contains(s.data[i]))
            return true;
    }
    return false;
}

//check if the set s is same as this->set
bool set::operator==(const set& s) const{
    //check if this->set contains all the elements in the set s
    for(size_type i = 0; i < used; i++){
        if(!contains(s.data[i]))
            return false;

    }
    return true;
}

//check if *this is a proper subset of set s
bool set::operator<(const set& s) const{
    return proper_subset(s);
}
//check if *this is a subset of set s
bool set::operator<=(const set& s) const{
    return subset(s);
}
//check if set s is a proper subset of *this
bool set::operator>(const set& s) const{
    return s.proper_subset(*this);
}
//check if set s is a subset of *this
bool set::operator>=(const set& s) const{
    return s.subset(*this);
}

//check if set s is a subset of *this
bool set::subset(const set& s) const{
    //check if set s contains all elements in *this
    for (size_type i = 0; i < used; i++){
        if(!s.contains(data[i])){
            return false;
        }
    }
    return true;
}

//check if set s is a proper subset of *this
bool set::proper_subset(const set& s)const{
    //the size of *this should greater or equal than size of set s otherwise it is not a proper subset
    if(used >= s.used){
        return false;
    }
    //check if set s contains all elements in *this
    for(size_type i = 0; i < used; i++){
        if(!s.contains(data[i])){
            return false;
        }
    }
    return true;
}

void set::erase_all(){
    for(value_type i = 0; i < used; i++){
        data[i] = data[used];
    }
    used = 0;
}
