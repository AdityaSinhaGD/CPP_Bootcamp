//
//  List.h
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 09/06/21.
//

#ifndef List_h
#define List_h

template <class tData>
class List {
    
public:
    virtual void insert(const tData& data) = 0;
    virtual void push(const tData& data) = 0;
    virtual void remove(const tData& data) = 0;
    virtual void traverseList() const = 0;
    virtual int size() const = 0;
};

#endif /* List_h */
