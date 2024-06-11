#include <iostream>

using namespace std;

template <typename T>
class smart_pointer {
    private:
        T* m_pRawPointer;

    public:
        smart_pointer(T* pData): m_pRawPointer(pData) {} // Constructor
        ~smart_pointer() {delete m_pRawPointer;} // Destructor

        // operator overloading for smart_pointer -> To implerment "*" operator, we need to use generic operator
        T& operator *() const {
            return *(m_pRawPointer);
        }

        T* operator -> () const {
            return m_pRawPointer;
        }
};

int main() {

    smart_pointer<int> pDynamicint(new int(42));
    return 0;
}

/*
    Key Idea of smart pointer
    1. A variale in the stack -> at the end of a function body or return ???; -> automatically its destructor is called
*/