//
// Created by chris on 03-Mar-18.
//

#ifndef POO_TEMA1_16_GRAPH_H
#define POO_TEMA1_16_GRAPH_H

template <typename T>
class vector {
    T *vect;
    int _size;
    int _capacity;

    void realloc(int newCap) {
        newCap = std::max(newCap, 0);
        T *newVect = new T[newCap];
        for (int i = 0; i < _size; ++i) {
            newVect[i] = vect[i];
        }

        _capacity = newCap;

        delete[] vect;
        vect = newVect;
    }

public:
    vector() {
        vect = new T;
        _size = 0;
        _capacity = 1;
    }

    void push_back(T info) {
        ++_size;
        if (_size > _capacity) {
            realloc(_capacity * 2);
        }

        vect[_size - 1] = info;
    }

    void pop_back() {
        --_size;
        if (_size <= _capacity / 2) {
            realloc(_capacity / 2);
        }
    }

    T back() {
        return vect[_size - 1];
    }


    int size() {
        return _size;
    }


    bool empty() {
        return _size == 0;
    }


    T & operator [](int index) const {
        return vect[index];
    }
};

class Graph {

};

#endif //POO_TEMA1_16_GRAPH_H
