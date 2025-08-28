#include <iostream>
using namespace std;

class A {
private:
    int privateA;

public:
    A() { 
        this->privateA = -1; 
    }

    A(int v) { 
        this->privateA = v; 
    }

    void showValue() {
        cout << privateA << endl;
    }

    ~A() {
        cout << "Ham huy A()" << endl;
    }
};

class B : public A {
private:
    int privateB;

public:
    B() { 
        privateB = 0; 
    }

    B(int va, int vb) : A(va) {
        this->privateB = vb;
    }

    void show() {
        cout << "show() B" << endl;
        cout << "call showValue class A" << endl;
        showValue();
        cout << "value privateB: " << privateB << endl;
    }

    ~B() {
        cout << "Ham huy B()" << endl;
    }
};

int main() {
    B obj(10, 20);
    obj.show();
    return 0;
}
