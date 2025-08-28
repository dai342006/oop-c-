#include <iostream>
#include <string>
using namespace std;

class DonHang {
protected:
    string maDH;
    string tenHang;
    double donGia;
    int soLuong;

public:
    void nhap() {
        cout << "Nhap ma don hang: ";
        cin >> maDH;
        cout << "Nhap ten hang: ";
        cin.ignore();
        getline(cin, tenHang);
        cout << "Nhap don gia: ";
        cin >> donGia;
        cout << "Nhap so luong: ";
        cin >> soLuong;
    }

    virtual void xuat() {
        cout << "Ma DH: " << maDH << ", Ten hang: " << tenHang
             << ", Don gia: " << donGia << ", So luong: " << soLuong;
    }

    virtual double tinhTongTien() = 0; // hàm thuần ảo

    virtual ~DonHang() {}
};
class DonHangTrongNuoc : public DonHang {
private:
    double thue; // % thuế

public:
    void nhap() {
        DonHang::nhap();
        cout << "Nhap % thue: ";
        cin >> thue;
    }

    void xuat() override {
        DonHang::xuat();
        cout << ", Thue: " << thue << "%" << endl;
    }

    double tinhTongTien() override {
        return donGia * soLuong * (1 + thue / 100);
    }
};
class DonHangXuatKhau : public DonHang {
private:
    double phiVanChuyen;

public:
    void nhap() {
        DonHang::nhap();
        cout << "Nhap phi van chuyen: ";
        cin >> phiVanChuyen;
    }

    void xuat() override {
        DonHang::xuat();
        cout << ", Phi van chuyen: " << phiVanChuyen << endl;
    }

    double tinhTongTien() override {
        return donGia * soLuong + phiVanChuyen;
    }
};
int main() {
    DonHang* ds[100];
    int n;

    cout << "Nhap so don hang: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\n1. Don hang trong nuoc\n2. Don hang xuat khau\nChon loai don hang: ";
        cin >> loai;

        if (loai == 1)
            ds[i] = new DonHangTrongNuoc();
        else
            ds[i] = new DonHangXuatKhau();

        ds[i]->nhap();
    }

    double tongGiaTri = 0;
    cout << "\n=== Danh sach don hang ===\n";
    for (int i = 0; i < n; i++) {
        ds[i]->xuat();
        double tong = ds[i]->tinhTongTien();
        cout << " => Tong tien: " << tong << endl;
        tongGiaTri += tong;
    }

    cout << "\nTong gia tri tat ca don hang: " << tongGiaTri << endl;

    for (int i = 0; i < n; i++)
        delete ds[i];

    return 0;
}