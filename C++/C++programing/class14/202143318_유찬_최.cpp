#include<iostream>
using namespace std;

class B
{
    public:
        virtual void show() {}
};

class D: public B
{
    public:
        void show() {
            cout << "In D" << '\n';
        }
};

int main(void)

{
    B *b = new D;
    b->show();
    B &r = *b;
    r.show();
    return 0;
}