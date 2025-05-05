#ifndef NALOGA7_1_POINTPRIMER_LINEARQUEUE_H
#define NALOGA7_1_POINTPRIMER_LINEARQUEUE_H

#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <random>
#include "Point.h"

using namespace std;

template<typename T>
class LinearQueue {
private:
    vector<T> values;

public:
    int size() const {
        return values.size();
    }

    const T& element() const {
        if (values.empty()) {
            throw out_of_range("Queue is empty");
        }
        return values.front();
    }

    void add(const T& v) {
        values.push_back(v);
    }

    bool remove() {
        if (values.empty()) {
            return false;
        }
        values.erase(values.begin());
        return true;
    }

    string toString() const {
        ostringstream ss;
        for (size_t i = 0; i < values.size(); ++i) {
            ss << values[i];
            if (i + 1 < values.size()) {
                ss << ", ";
            }
        }
        return ss.str();
    }

    T getMax() const {
        if (values.empty()) {
            throw out_of_range("Queue is empty");
        }
        return *max_element(values.begin(), values.end());
    }
};

template<>
Point LinearQueue<Point>::getMax() const {
    if (values.empty()) {
        throw out_of_range("Queue is empty");
    }
    return *max_element(values.begin(), values.end(), [](const Point& a, const Point& b) {
        int aDist = a.getX() * a.getX() + a.getY() * a.getY();
        int bDist = b.getX() * b.getX() + b.getY() * b.getY();
        return aDist < bDist;
    });
}

template<typename T>
void fillDefault(LinearQueue<T>& queue, int n) {
    for (int i = 0; i < n; ++i) {
        queue.add(T());
    }
}

template<>
void fillDefault<int>(LinearQueue<int>& queue, int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 100);
    for (int i = 0; i < n; ++i) {
        queue.add(distrib(gen));
    }
}

#endif //NALOGA7_1_POINTPRIMER_LINEARQUEUE_H