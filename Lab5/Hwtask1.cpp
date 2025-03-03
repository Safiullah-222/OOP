#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <memory>

using namespace std;

class Blend {
public:
    void blendJuice() {
        for (int i = 0; i < 4; i++) {
            cout << "Blending..." << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding..." << endl;
        this_thread::sleep_for(chrono::seconds(5));
    }
};

class JuiceMaker {
    Blend blend;
    Grind grind;
public:
    void makeJuice() {
        blend.blendJuice();
        grind.grindJuice();
    }
};


int main() {

    JuiceMaker maker;
    maker.makeJuice();
    
    
    return 0;
}