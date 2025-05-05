//
// Created by Martini on 3. 05. 2025.
//

#ifndef NALOGA7_1_POINTPRIMER_LINEARQUEUE_H
#define NALOGA7_1_POINTPRIMER_LINEARQUEUE_H

#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Point.h"

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

    std::string toString() const {
        std::ostringstream ss;
        for (size_t i = 0; i < values.size(); ++i) {
            ss << values[i];
            if (i + 1 < values.size())
                ss << ", ";
        }
        return ss.str();
    }

    T getMax() const {
        if (values.empty())
            throw std::out_of_range("Queue is empty");
        return *std::max_element(values.begin(), values.end());
    }


};

template<>
Point LinearQueue<Point>::getMax() const {
    if (values.empty())
        throw std::out_of_range("Queue is empty");

    return *std::max_element(values.begin(), values.end(), [](const Point& a, const Point& b) {
        return (a.getX() + a.getY()) < (b.getX() + b.getY());
    });
}

#endif //NALOGA7_1_POINTPRIMER_LINEARQUEUE_H
