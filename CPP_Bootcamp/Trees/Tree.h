//
//  Tree.h
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 30/06/21.
//

#ifndef Tree_h
#define Tree_h

template <class t_Data>
class Tree {
public:
    virtual void traversal() const = 0;
    virtual void insert(const t_Data& data) = 0;
    virtual void remove(const t_Data& data) = 0;
    virtual const t_Data& getMaxValue() const = 0;
    virtual const t_Data& getMinValue() const = 0;
};

#endif /* Tree_h */
