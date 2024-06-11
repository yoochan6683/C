#include <iostream>

using namespace std;

class Parent {
    public:
        virtual void show() {
            cout << "Parent virtual show()" << '\n'; 
        }
        // void show(int a) {
        //     cout << "a: " << a <<  '\n'; 
        // }
        virtual void show2() {cout << "Parent virtual show2()" << '\n';}
        virtual void show3() {cout << "Parent virtual show3()" << '\n';}
        virtual void show4() {cout << "Parent virtual show4()" << '\n';}
};

class Child: public Parent {
    public:
        virtual void show() {
            cout << "Child virtual show()" << '\n';
        }
        virtual void show2() {
            cout << "Child virtual show2()" << '\n';
        }
};

class ChildChild: public Child {
    public:
        virtual void show() {
            cout << "ChildChild virtual show()" << '\n';
        }
};

int main() {
    Parent *p = new Parent;
    Child *c = new Child;
    ChildChild *cc = new ChildChild;

    p->show();
    c->show();
    c->show3();
    c->show4();
    cc->show();
    cc->show2();

    // p->show();c->show();cc->show(); //Step 1
    p = c;
    p->show();
    p = cc;
    p->show();

    // Child *c = new Child;
    // c->show();
    // c->show(10);
    return 0;
}

/*
    "Overriding"
    Function Binding will happen - at compile time
                                |   (static binding)
                                 - running time
                                    (dynamic binding)
*/