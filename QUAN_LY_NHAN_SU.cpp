#include <iostream>
using namespace std;
class nhanvien {
	public:
		virtual  double tinhluong()=0;
		virtual void xuat () = 0;
		virtual ~nhanvien(){};
};
class nhanvienvanphong : public nhanvien{
	private:
		double luongcoban, phucap;
		public:
		 void nhap(){
		 	cout << " nhap luong co ban: ";
		 	cin >> luongcoban;
		 	cout <<"nhap luong phu cap: ";
		 	cin >> phucap;
		 	
		 }
			
			double tinhluong ()override {
				return luongcoban + phucap;
			}
			void xuat ()override{
		
	cout << "nhan vien van phong luong " << tinhluong() << endl; 		}	
};
class nhanviensanxuat : public nhanvien{
	private:
		double sanpham, dongia;
		public:
			void nhap (){
				cout <<" nhap so luong san pham: ";
				cin >> sanpham;
				cout << " nhap don gia: ";
				cin >> dongia;
			}
			double tinhluong() override{
				return sanpham * dongia;
			}
			void xuat () override {
				cout << " luong nhan vien san xuat nhan la: " << tinhluong() << endl;
				
			}
};
int main (){
	cout << " <<<luong nhan vien van phong>>>" << endl;
	nhanvienvanphong nv;
	nv.nhap();
	nv.xuat();
	cout <<" <<<luong nhan vien san xuat>>>" << endl;
	nhanviensanxuat sx;
	sx.nhap();
	sx.xuat();
	return 0; 
}