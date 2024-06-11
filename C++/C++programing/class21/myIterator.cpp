#include <iostream>
#include <stdio.h>

typedef int Type;

struct IType {
    Type* p;
    IType(Type *p) : p(p) {}
    bool operator != (IType rhs) {return p != rhs.p;}
    Type& operator* () {return *p;}
    void operator++ () {++p;}

};

const int SIZE = 10;
struct Iterable {
    Type data[SIZE];
    IType begin() {return IType(data);}
    IType end() {return IType(data + SIZE);}
};

Iterable iterable;
int main() {
    int i=0;
    for(Type& x : iterable) {
        x = i++;
    }

    for(Type x : iterable) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}