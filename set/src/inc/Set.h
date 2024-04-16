//
// Created by Jingfeng Sun on 2024/4/16.
//

#ifndef ARRAYSET_SET_H
#define ARRAYSET_SET_H
#include <memory>
template <class T>
class Set {
public:
    /**
     * Adds an element to the set. If the element already exists, the set is not changed.
     * @param x The element to be added to the set.
     */
    virtual void add(T x) = 0;

    /**
     * Removes an element from the set. If the element does not exist, an error or exception is raised
     * or the operation is silently ignored, depending on the implementation.
     * @param x The element to be removed from the set.
     * @return element to be removed from the set.
     */
    virtual T remove(T x) = 0;

    /**
     * Checks if an element is in the set.
     * @param x The element to check for in the set.
     * @return A boolean value indicating whether the element is in the set.
     */
    virtual bool contains(T x) const = 0;

    /**
     * Returns the number of elements in the set.
     * @return An integer representing the number of elements in the set.
     */
    virtual int size() const = 0;

    /**
     * Checks if the set is empty.
     * @return A boolean value indicating whether the set is empty.
     */
    virtual bool isEmpty() const = 0;

    /**
     * Removes all elements from the set.
     */
    virtual void clear() = 0;

    /**
     * Returns a list containing all of the elements in the set, in no particular order.
     */
    virtual void printSet() const = 0;
};

#endif //ARRAYSET_SET_H
