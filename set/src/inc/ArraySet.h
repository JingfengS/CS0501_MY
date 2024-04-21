//
// Created by Jingfeng Sun on 2024/4/16.
//

#ifndef SET_SET_H
#define SET_SET_H

#include "Set.h"
#include "deque.h"

template<class T>
class ArraySet : public Set<T> {
private:
    deque<T> *arraySet;
public:
    ArraySet() {
        arraySet = new deque<T>();
    }

    ~ArraySet() {
        delete arraySet;
    }

    ArraySet(const ArraySet<T> &other) {
        arraySet = new deque<T>(*(other.arraySet));
    }

    ArraySet<T> &operator=(const ArraySet<T> &other) {
        if (this != &other) {
            delete arraySet;
            arraySet = new deque<T>(*(other.arraySet));
        }
        return *this;
    }

    void add(T x) override {
        if (contains(x)) {
            return;
        }
        arraySet->addLast(x);
        return;
    }

    T remove(T x) override {
        if (!contains(x)) {
            throw std::runtime_error("Cannot remove item not in the set");
        }
        arraySet->remove(x);
    }

    bool contains(T x) const override {
        return arraySet->contains(x);
    }

    int size() const override {
        return arraySet->getSize();
    }

    bool isEmpty() const override {
        return arraySet->isEmpty();
    }

    void clear() override {
        while (!isEmpty()) {
            arraySet->removeLast();
        }
    }

    void printSet() const override {
        arraySet->printList();
    }

    class Iterator {
    private:
        typename deque<T>::Iterator it;
    public:
        Iterator(typename deque<T>::Iterator it) : it(it) {}

        Iterator &operator++() {
            ++it;
            return *this;
        }

        bool operator!=(const ArraySet<T>::Iterator &other) const {
            return it != static_cast<const Iterator &>(other).it;
        }

        T &operator*() const {
            return *it;
        }
    };

    Iterator begin() const {
        return Iterator(arraySet->begin());
    }

    Iterator end() const {
        return Iterator(arraySet->end());
    }

    /**
     * Returns a new set that is the union of this set and another set.
     * @param other Another set to perform the union with.
     * @return A new set containing all elements that are in either set.
     */
    ArraySet<T> operator+(const ArraySet<T> &other) const {
        ArraySet<T> unionSet(*this);
        for (auto item: other) {
            unionSet.add(item);
        }
        return unionSet;
    }

    /**
     * Returns a new set that is the intersection of this set and another set.
     * @param other Another set to perform the intersection with.
     * @return A new set containing all elements that are in both sets.
     */
    ArraySet<T> operator*(const ArraySet<T> &other) const {
        ArraySet<T> intersection;
        for (auto item: other) {
            if (contains(item)) {
                intersection.add(item);
            }
        }
        return intersection;
    }

    /**
     * Returns a new set that is the difference of this set and another set.
     * @param other Another set to perform the difference with.
     * @return A new set containing all elements that are in this set but not in the other set.
     */
    ArraySet<T> operator-(const ArraySet<T> &other) const {
        ArraySet<T> difference(*this);
        for (auto item: other) {
            if (difference.contains(item)) {
                difference.remove(item);
            }
        }
        return difference;
    }
};

#endif //SET_SET_H
