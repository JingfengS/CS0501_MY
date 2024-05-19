//
// Created by Jingfeng Sun on 2024/5/19.
//

#ifndef HW9_DYNAMICSEARCHTABLE_H
#define HW9_DYNAMICSEARCHTABLE_H

template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

template <class KEY, class OTHER>
class dynamicSearchTable {
public:
    virtual SET<KEY, OTHER> *find(const KEY &x) const = 0;
    virtual ~dynamicSearchTable() {}
    virtual void insert(const KEY &x, const OTHER &y) = 0;
    virtual void remove(const KEY &x) = 0;
};

#endif //HW9_DYNAMICSEARCHTABLE_H
