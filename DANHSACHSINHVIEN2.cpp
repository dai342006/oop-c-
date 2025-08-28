#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    string name;
    int age;
    double score;
    static int studentCount; 
public:
    Student() {
        name = "";
        age = 0;
        score = 0.0;
    }
    void input() {
        cin.ignore(); // Xóa bộ đệm để tránh lỗi khi nhập chuỗi
        cout << "Nhap ten: ";
        getline(cin, name);
        cout << "Nhap tuoi: ";
        cin >> age;
        cout << "Nhap diem: ";
        cin >> score;
        studentCount++; 
    }
    void printInfo() const {
        cout << "Ten: " << name << endl;
        cout << "Tuoi: " << age << endl;
        cout << "Diem: " << score << endl;
    }
    static int getStudentCount() {
        return studentCount;
    }
};
int Student::studentCount = 0;
int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    Student* students = new Student[n]; 
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien " << i + 1 << ":\n";
        students[i].input();
    }
    cout << "\nDanh sach sinh vien:\n";
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien " << i + 1 << ":\n";
        students[i].printInfo();
        cout << endl;
    }
    cout << "Tong so sinh vien da tao: " << Student::getStudentCount() << endl;
    delete[] students; // Giải phóng bộ nhớ động

    return 0;
}
