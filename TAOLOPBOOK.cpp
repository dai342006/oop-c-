#include <iostream>
#include <string>

using namespace std;

class Library {
private:
    string tenSach;
    string tacGia;
    int namXuatBan;
    static int soSach;

public:
    Library() {} // Hàm tạo mặc định để có thể khai báo mảng

    Library(string ten, string tacGia, int nam) {
        tenSach = ten;
        tacGia = tacGia;
        namXuatBan = nam;
        soSach++;
    }

    static int laySoSach() {
        return soSach;
    }

    void nhapThongTin() {
        cout << "Ten sach: ";
        getline(cin, tenSach);
        cout << "Tac gia: ";
        getline(cin, tacGia);
        cout << "Nam xuat ban: ";
        cin >> namXuatBan;
        cin.ignore();
        soSach++;
    }

    void hienThiThongTin() const {
        cout << "Sach: " << tenSach << " | Tac gia: " << tacGia
             << " | Nam xuat ban: " << namXuatBan << endl;
    }
};

int Library::soSach = 0;

int main() {
    int n;
    cout << "Nhap so luong sach: ";
    cin >> n;
    cin.ignore();

    Library danhSachSach[n]; // Mảng tĩnh lưu danh sách sách

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sach " << i + 1 << ":\n";
        danhSachSach[i].nhapThongTin();
    }

    cout << "\nDanh sach sach trong thu vien:\n";
    for (int i = 0; i < n; i++) {
        danhSachSach[i].hienThiThongTin();
    }

    cout << "So sach trong thu vien: " << Library::laySoSach() << endl;

    return 0;
}
