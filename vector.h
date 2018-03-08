//
// Created by chris on 04-Mar-18.
//

#ifndef POO_TEMA1_16_VECTOR_H
#define POO_TEMA1_16_VECTOR_H

template <typename T>
inline T min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template <typename T>
inline T max(const T& a, const T& b) {
    return (a < b) ? b : a;
}

template <typename T>
class vector {
    T *vect;
    int _size;
    int _capacity;

    void realloc(int newCap) {
        newCap = max(newCap, 1);
        if (_capacity == newCap) {
            return;
        }

        T *newVect = new T[newCap]();
        for (int i = 0; i < _size; ++i) {
            newVect[i] = vect[i];
        }

        _capacity = newCap;

        delete[] vect;
        vect = newVect;
    }

    void alloc(int newCap) {
        vect = new T[newCap]();
        _capacity = newCap;
    }

    void mergeArrays(T *A, int sizeA, T *B, int sizeB, bool (*lessThan)(T, T)) {
        int aPos = 0;
        int bPos = 0;

        T *newVect = new T[sizeA + sizeB]();
        int newPos = 0;

        while (aPos < sizeA and bPos < sizeB) {
//            if (A[aPos] < B[bPos]) {
            if (lessThan(A[aPos], B[bPos])) {
                newVect[newPos] = A[aPos];
                ++aPos;
            }
            else {
                newVect[newPos] = B[bPos];
                ++bPos;
            }

            ++newPos;
        }

        for (; aPos < sizeA; ++aPos, ++newPos) {
            newVect[newPos] = A[aPos];
        }

        for (; bPos < sizeB; ++bPos, ++newPos) {
            newVect[newPos] = B[bPos];
        }

        //A extends over B
        for (int i = 0; i < newPos; ++i) {
            A[i] = newVect[i];
        }

        delete[] newVect;
    }

    inline int getCapForSize(int newSize) {
        int pow2 = 1;
        while (pow2 < newSize) {
            pow2 *= 2;
        }

        return pow2;
    }

public:

    vector() {
        vect = new T[1]();
        _size = 0;
        _capacity = 1;
    }

    explicit vector(int newSize) {
        _size = newSize;
        alloc(getCapForSize(newSize));
    }

    vector(const vector &other) {
        *this = other;
//        _size = other._size;
//        _capacity = other._capacity;
//        vect = new T[_capacity];
//
//        for (int i = 0; i < _size; ++i) {
//            vect[i] = other[i];
//        }
    }

    ~vector() {
        delete[] vect;
    }

    inline T *begin() const {
        return vect;
    }

    inline T *end() const {
        return vect + _size;
    }

    inline void clear() {
//        resize(0);
        while (size()) {
            pop_back();
        }
    }

    inline void resize(int newSize) {
        realloc(getCapForSize(newSize));
        _size = newSize;
    }

    inline void push_back(const T &info) {
        if (_size + 1 > _capacity) {
            realloc(_capacity * 2);
        }

        ++_size;
        vect[_size - 1] = info;
    }

    inline void pop_back() {
        --_size;
        if (_size <= _capacity / 2) {
            realloc(_capacity / 2);
        }
    }

    inline T back() const {
        return vect[_size - 1];
    }

    inline int size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }

    void mergeSort(int lf, int rg, bool (*lessThan)(T a, T b)) {
        if (lf == rg) {
            return;
        }

        int med = (lf + rg) / 2;
        mergeSort(lf, med, lessThan);
        mergeSort(med + 1, rg, lessThan);

        int sizeLf = med - lf + 1;
        int sizeRg = rg - med;
        mergeArrays(vect + lf, sizeLf, vect + lf + sizeLf, sizeRg, lessThan);
    }

    T &operator [](const int &index) const {
        return vect[index];
    }

    vector &operator = (const vector &other) {
        _size = other._size;
        _capacity = other._capacity;
        vect = new T[_capacity]();

        for (int i = 0; i < _size; ++i) {
            vect[i] = other[i];
        }

        return *this;
    }

    bool operator == (const vector &other) const {
        if (_size == other._size) {
            bool areEqual = true;
            for (int i = 0; i < _size; ++i) {
                areEqual = min(areEqual, vect[i] == other[i]);
            }

            return areEqual;
        }

        return false;
    }

    bool operator != (const vector &other) const {
        return !(*this == other);
    }

    bool operator < (const vector &other) const {
        return _size < other._size;
    }
};

#endif //POO_TEMA1_16_VECTOR_H
