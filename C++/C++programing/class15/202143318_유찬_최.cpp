#include <iostream>
#include <string>
#include <vector>  // No #include<string>

using namespace std;

class E {
    private:
        string fn;
        string ln;
    public:
        E(string f, string l): fn(f), ln(l) {
        }

        string gfn() {
            return fn + " " + ln;
        }

        virtual void pw() {}

        virtual ~E() {

        }
};

class HE: public E {
    private:
        double hw;

    public:
        HE(string fn, string ln, double hw): E(fn, ln), hw(hw) {}

        void pw() {
            cout << "HaHa "<< gfn() << " is " << hw << '\n';
        }
};

class RE: public E {
    private:
        double mw;

    public:
        RE(string fn, string ln, double mw): E(fn, ln), mw(mw) {}

        void pw() {
            cout << "HoHo "<< gfn() << " is " << mw << '\n';
        }
};

int main() {

    vector<E*> Es = {new HE("Super", "Sonic", 11.5), new RE("One", "Piece", 1310.4)};        // No array

    for(E* E: Es) {
        E->pw();
    }

    return 0;
}