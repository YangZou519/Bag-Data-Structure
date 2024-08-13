#include "keyed_bag.h"
#include <algorithm>

keyed_bag::keyed_bag():used(0){}

//count how many given element are in the keyed_bag
keyed_bag::size_type keyed_bag::count(const value_type& target, int key) const
{
    size_type answer;
    size_type i;
    answer = 0;
    //check every index
    for (i = 0; i < used; ++i)
        if(target == data[i].first && key == data[i].second)
            ++answer;
    return answer;
}

//serche the keyed_bag to check if the key is already exist
bool keyed_bag::search_key(const value_type& key) const{
    for (value_type i = 0; i < used; ++i)
        if(key == data[i].second)
            return true;
    return false;
}

//insert element to the keyed_bag
void keyed_bag::insert(const value_type& entry, int key){
    //the key should be unique
    assert(size() < CAPACITY && !search_key(key));
    data[used].first = entry;
    data[used].second = key;
    ++used;
}

//use '+' operator to form the '+=' operator
void keyed_bag::operator+=(const keyed_bag& addend)
{
    assert(size() + addend.size() <= CAPACITY);
    *this = *this + addend;

}

//add all elements from kb to this->keyed_bag
keyed_bag keyed_bag::operator+(const keyed_bag& kb)
{
    assert(this->size() + kb.size() <= keyed_bag::CAPACITY);
    //insert all element from kb to *this
    for(value_type i = 0; i < kb.used; i++){
        insert(kb.data[i].first, kb.data[i].second);
    }
    return *this;
}

//remove all elements that set kb have from this->keyed_bag
keyed_bag keyed_bag::operator-(const keyed_bag& kb)
{
    keyed_bag result;
    for(size_type i = 0; i < used; i++){
        size_type diff = count(data[i].first, data[i].second) - kb.count(data[i].first, data[i].second);//check the difference
        //if the element is not in the result, and the diff is one. insert the element to the result
        if(result.count(data[i].first, data[i].second) == 0 && diff == 1){
            result.insert(data[i].first, data[i].second);
        }
    }
    return result;

}

//use the '-' operator to form '-=' operator
void keyed_bag::operator-=(const keyed_bag& kb)
{
    *this = *this - kb;
}

//afeter this function call it will erase all element in the keyed_bag
void keyed_bag::erase_all(){
    //erase every element
    for(value_type i = 0; i < used; i++){
        data[i].first = data[used].first;
        data[i].second = data[used].second;
    }
    used = 0;
}