#include <iostream>
using namespace std;

// Lop cha Employee
class Employee {
protected:
    string name;
    string salary;
public:
    Employee(string n, string s) : name(n), salary(s) {}
    
    string getName() {
        return name;
    }
    
    void pay() {
        cout << name << " da duoc tra luong " << salary << endl;
    }
    
    virtual void doWork() {
        cout << name << " dang lam viec..." << endl;
    }
};

// Lop Worker ke thua tu Employee
class Worker : public Employee {
public:
    Worker(string n, string s) : Employee(n, s) {}
    
    void doWork() override {
        cout << name << " dang lam cong viec cua cong nhan." << endl;
    }
};

// Lop Manager ke thua tu Employee
class Manager : public Employee {
private:
    int dept;
public:
    Manager(string n, string s, int d) : Employee(n, s), dept(d) {}
    
    void doWork() override {
        cout << name << " dang quan ly phong ban " << dept << "." << endl;
    }
};

// Lop Director ke thua tu Employee
class Director : public Employee {
public:
    Director(string n, string s) : Employee(n, s) {}

    void doWork() override {
        cout << name << " dang dieu hanh cong ty." << endl;
    }
};
   
// Ham main de kiem tra
int main() {
	cout << "==========NHAN LUONG========     \n";
    Worker w("- A", "1000$");
    Manager m("- B", "2000$", 101);
    Director d("- C", "5000$");

    w.doWork();
    w.pay();
    
    m.doWork();
    m.pay();
    
    d.doWork();
    d.pay();
   cout << "        *          *\n";
   cout << "       *            *\n";
   cout << "------****************-------  \n";
   cout << "      *              *\n";
   cout << "      *              *\n";
   cout << "      *              *\n";
   cout << "      *              *\n";
   cout << "------****************-------  \n";
    return 0;
}
