#include <iostream>
#include <random>

using namespace std;

class ThoiGian {
private:
    int gio, phut, giay;

public:

    ThoiGian() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist_gio(0, 23);
        uniform_int_distribution<int> dist_phut_giay(0, 59);

        gio = dist_gio(gen);
        phut = dist_phut_giay(gen);
        giay = dist_phut_giay(gen);
    }


    ThoiGian(int h, int m, int s) : gio(h), phut(m), giay(s) {}


   void hienThi() const {
    if (gio < 10) cout << "0";
    cout << gio << ":";

    if (phut < 10) cout << "0";
    cout << phut << ":";

    if (giay < 10) cout << "0";
    cout << giay << endl;


    }

    ThoiGian operator+(const ThoiGian& t) const {
        int newGiay = giay + t.giay;
        int newPhut = phut + t.phut + newGiay / 60;
        int newGio = gio + t.gio + newPhut / 60;
        return ThoiGian(newGio % 24, newPhut % 60, newGiay % 60);
    }

    ThoiGian operator-(const ThoiGian& t) const {
        int total1 = gio * 3600 + phut * 60 + giay;
        int total2 = t.gio * 3600 + t.phut * 60 + t.giay;
        int diff = abs(total1 - total2);

        return ThoiGian(diff / 3600, (diff % 3600) / 60, diff % 60);
    }

    bool operator==(const ThoiGian& t) const {
        return gio == t.gio && phut == t.phut && giay == t.giay;
    }
    
};

int main() {
    ThoiGian t1, t2; 	

    cout << "Thoi gian 1: ";
    t1.hienThi();

    cout << "Thoi gian 2: ";
    t2.hienThi();


    ThoiGian tong = t1 + t2;
    cout << "Tong hai thoi gian: ";
    tong.hienThi();


    ThoiGian hieu = t1 - t2;
    cout << "Hieu hai thoi gian: ";
    hieu.hienThi();

    if (t1 == t2) {
        cout << "Hai thoi gian bang nhau!\n";
    } else {
        cout << "Hai thoi gian khac nhau!\n";
    }

    return 0;
}