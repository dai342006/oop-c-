#include <iostream>
#include <string>
using namespace std;
class nhanvien {
	private:
		string maNV, tenNV;
		public:
			virtual void nhap(){
				cout <<" nhap ma nha vien: " <<endl;
				 cin >> maNV;
				 cout <<" nhap ten nhan vien: " << endl;
				 cin.ignore();
				 getline(cin, tenNV);
			
			}
			virtual void xuat(){
				cout << " ma nhan vien: " << maNV <<endl;
				cout << " ten nhan vien: " << tenNV <<endl;
			}
			virtual  double tinhluong()=0;
			virtual ~nhanvien(){}
};
class vanphong :public nhanvien{
	private: 
	int ngaylam;
	public:
		void nhap(){
			nhanvien::nhap();
			cout << " so ngay lam la: " <<endl;
			cin >> ngaylam;
		}
	 void xuat()override {
	 	nhanvien :: xuat();
	 	cout << " so ngay lam: " << ngaylam << endl;
	 	
	 }
	 double tinhluong() override{
	 	return ngaylam * 100000;
	 }
};
class sanxuat : public nhanvien{
	private :
		int sosanpham;
		public:
			void nhap (){
			nhanvien :: nhap();
			cout << "nhap so san pham: " << endl ;
				cin >> sosanpham;
			}
			void xuat () override{
				nhanvien :: xuat();
				cout << " so san pham: " << sosanpham << endl;
				
			}
			double tinhluong()override{
				return sosanpham * 70000;
			}
			
};
int main(){

 nhanvien* ds[100];
    int n;

    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\n1. Nhan vien van phong\n2. Nhan vien san xuat\nChon loai nhan vien (1/2): ";
        cin >> loai;

        if (loai == 1) {
            ds[i] = new vanphong();
        } else {
            ds[i] = new sanxuat();
        }

       // cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---\n";
        ds[i]->nhap();
    }

    cout << "\n=== DANH SACH NHAN VIEN ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhan vien thu " << i + 1 << " ---\n";
        ds[i]->xuat();
        cout << "Luong: " << ds[i]->tinhluong() << " VND" << endl;
    }

    for (int i = 0; i < n; i++) {
        delete ds[i];
    }

    return 0;
}