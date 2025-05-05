//
// Created by Martini on 3. 05. 2025.
//

#ifndef NALOGA7_1_POINTPRIMER_LINEARQUEUE_H
#define NALOGA7_1_POINTPRIMER_LINEARQUEUE_H

#include <vector>
#include <stdexcept>

using namespace std;

template<typename T>
class LinearQueue{
private:
    std::vector<T> values;

public:
    int size() const{
        return values.size();
    }

    const T& element() const{
        if(values.empty()){
            throw std::out_of_range("Ni elementov v queue.");
        }
        return values.front();
    }

    void add(const T& v){
        values.push_back(v);
    }

    bool remove(){
        if(values.empty()){
            return false;
        }
        values.erase(values.begin());
        return true;
    }
};

#endif //NALOGA7_1_POINTPRIMER_LINEARQUEUE_H
