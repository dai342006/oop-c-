#include <iostream>
#include <string>
using namespace std;

class SanPham {
protected:
    string maSP;
    string tenSP;
    float gia;

public:
    void nhap() {
        cout << "Nhap ma SP: ";
        cin >> maSP;
        cout << "Nhap ten SP: ";
        cin.ignore();
        getline(cin, tenSP);
        cout << "Nhap gia: ";
        cin >> gia;
    }

    virtual void xuat() {
        cout << "Ma SP: " << maSP << ", Ten SP: " << tenSP << ", Gia: " << gia << endl;
    }

    virtual float tinhGiaSauThue() {
        return gia * 1.1; // giả sử thuế 10%
    }

    virtual ~SanPham() {} // Hàm hủy ảo
};
class SanPhamDienTu : public SanPham {
private:
    int baoHanh; // tháng
    float congSuat; // watt

public:
    void nhap() {
        SanPham::nhap();
        cout << "Nhap thoi gian bao hanh (thang): ";
        cin >> baoHanh;
        cout << "Nhap cong suat (W): ";
        cin >> congSuat;
    }

    void xuat() override {
        SanPham::xuat();
        cout << "Bao hanh: " << baoHanh << " thang, Cong suat: " << congSuat << "W" << endl;
    }

    float tinhGiaSauThue() override {
        return gia * 1.15; // thuế cao hơn: 15%
    }
};
class SanPhamThoiTrang : public SanPham {
private:
    string kichCo;
    string chatLieu;

public:
    void nhap() {
        SanPham::nhap();
        cout << "Nhap kich co: ";
        cin >> kichCo;
        cout << "Nhap chat lieu: ";
        cin.ignore();
        getline(cin, chatLieu);
    }

    void xuat() override {
        SanPham::xuat();
        cout << "Kich co: " << kichCo << ", Chat lieu: " << chatLieu << endl;
    }

    float tinhGiaSauThue() override {
        return gia * 1.08; // thuế thấp hơn: 8%
    }
};
int main() {
    SanPham* danhSach[100];
    int n;

    cout << "Nhap so san pham: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\n1. San pham dien tu\n2. San pham thoi trang\nChon loai san pham: ";
        cin >> loai;

        if (loai == 1) {
            danhSach[i] = new SanPhamDienTu();
        } else {
            danhSach[i] = new SanPhamThoiTrang();
        }

        danhSach[i]->nhap();
    }

    cout << "\n=== Thong tin san pham ===\n";
    for (int i = 0; i < n; i++) {
        danhSach[i]->xuat();
        cout << "Gia sau thue: " << danhSach[i]->tinhGiaSauThue() << endl << endl;
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < n; i++) {
        delete danhSach[i];
    }

    return 0;
}