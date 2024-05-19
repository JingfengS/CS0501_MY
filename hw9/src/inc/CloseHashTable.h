//
// Created by Jingfeng Sun on 2024/5/19.
//

#ifndef HW9_CLOSEHASHTABLE_H
#define HW9_CLOSEHASHTABLE_H
#include <DynamicSearchTable.h>
#include <vector>

template <class KEY, class OTHER>
class closeHashTable : public dynamicSearchTable<KEY, OTHER> {
private:
    static constexpr double ENLARGE_FACTOR = 2.;
    // Note that for test, I set the factor as 0.9, but in real, this is encouraged to be 1.
    static constexpr double DELETE_RESIZE_FACTOR = 0.9;
    struct node {
        SET<KEY, OTHER> data;
        int state; //0 - empty, 1 - active, 2 - deleted
        node() {
            state = 0;
        }
    };
    node* array;
    int size;
    int currentSize;
    int deletedCount;
    int maxDeletedCount;
    int (*key) (const KEY &x);
    static int defaultKey(const int & x) {
        return x;
    }

    void rehash(double factor);

public:
    explicit closeHashTable(int length = 101, int maxDeleted = 10, int (*f) (const KEY & x) = defaultKey);
    ~closeHashTable() {
        delete [] array;
    }
    SET<KEY, OTHER> *find(const KEY& x) const override;
    void insert(const KEY &k, const OTHER &v) override;
    void remove(const KEY &x) override;
    int getSize() {
        return size;
    }
};

template<class KEY, class OTHER>
closeHashTable<KEY, OTHER>::closeHashTable(int length, int maxDeleted, int (*f)(const KEY &)) {
    size = length;
    array = new node[size];
    key = f;
    currentSize = 0;
    deletedCount = 0;
    maxDeletedCount = maxDeleted;
}

template<class KEY, class OTHER>
void closeHashTable<KEY, OTHER>::remove(const KEY &x) {
    int initPos, pos;

    initPos = pos = key(x) % size;
    do {
        if (array[pos].state == 0) {
            return;
        }
        if (array[pos].state == 1 && array[pos].data.key == x) {
            array[pos].state = 2;
            deletedCount++;
            currentSize--;
            if (deletedCount >= maxDeletedCount) {
                rehash(DELETE_RESIZE_FACTOR);
            }
            return;
        }
        pos = (pos + 1) % size;
    } while (pos != initPos);
}

template<class KEY, class OTHER>
void closeHashTable<KEY, OTHER>::insert(const KEY &k, const OTHER &v) {
    SET<KEY, OTHER> x = {k, v};
    if (currentSize >= size / 2) {
        rehash(ENLARGE_FACTOR);
    }

    int initPos, pos;

    initPos = pos = key(x.key) % size;
    do {
        if (array[pos].state != 1) {
            array[pos].data = x;
            array[pos].state = 1;
            currentSize++;
            return;
        }
        pos = (pos + 1) % size;
    } while (pos != initPos);
}

template<class KEY, class OTHER>
SET<KEY, OTHER> *closeHashTable<KEY, OTHER>::find(const KEY &x) const {
    int initPos, pos;

    initPos = pos = key(x) % size;
    do {
        if (array[pos].state == 0) {
            return nullptr;
        }
        if (array[pos].state == 1 && array[pos].data.key == x) {
            return (SET<KEY, OTHER>*) &array[pos].data;
        }
        pos = (pos + 1) % size;
    } while (pos != initPos);
    return nullptr;
}

template<class KEY, class OTHER>
void closeHashTable<KEY, OTHER>::rehash(double factor) {
    int oldSize = size;
    node* oldArray = array;

    size = int (factor * oldSize);
    array = new node[size];
    currentSize = 0;
    deletedCount = 0;

    for (int i = 0; i < oldSize; ++i) {
        if (oldArray[i].state == 1) {
            insert(oldArray[i].data.key, oldArray[i].data.other);
        }
    }

    delete[] oldArray;
}


#endif //HW9_CLOSEHASHTABLE_H
