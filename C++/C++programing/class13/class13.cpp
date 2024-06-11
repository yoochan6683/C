#include <iostream>

using namespace std;

class Motor {
    public:
        void SwitchIgnition() {
            cout << "ignition on" << '\n';
        }

        void PumpFuel() {
            cout << "Fuel is Cylinders" << '\n';
        }

        void FireCylinders() {
            cout << "Vroom" << '\n';
        }
};

// class Car : private Motor {
//     public:
//         void Move() {
//             SwitchIgnition();
//             PumpFuel();
//             FireCylinders();
//         }
// };

class Car : protected Motor {
    public:
        void Move() {
            SwitchIgnition();
            PumpFuel();
            FireCylinders();
        }
};

int main() {

    Car myDreamCar;
    myDreamCar.Move();
    // myDreamCar.PumpFuel(); -> 에러: private

    return 0;
}