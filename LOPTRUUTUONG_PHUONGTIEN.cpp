#include <iostream>
#include <string>
using namespace std;
class phuongtien {
	private:
		string hangsanxuat;
		double vttoida;
		public:
			virtual void nhap () {
				cout << " nhap hang san xuat: "; 
				cin >> hangsanxuat;
				cout << " nhap van toc toi da: ";
				cin >> vttoida;
			}
			virtual void xuat () {
				cout << "hang san xuat: " << hangsanxuat << endl;
				cout << " van toc toi da: " << vttoida << endl;
			}
			virtual double tinhchiphi(int km)=0;
			virtual ~phuongtien(){};
};
class xedap : public phuongtien{
	public:
		double tinhchiphi(int km) override{
			return 0;
		}
};
class oto : public phuongtien {
	public:
		double tinhchiphi(int km) override{
			return km * 3000;
		}
};
int main (){
	phuongtien* ds[100];
	int n;
	cout << " nhap so xe di chuyen: ";
	cin >> n;
	for(int i = 0 ; i < n; i ++){
		int loai;
		cout << "1.phuong tien xe dap: " << endl;
		cout << "2.phuong tien oto: " <<endl;
		cin >> loai;
		 if(loai == 1)
		 ds[i] = new xedap();
		 else
	     ds[i] = new oto();
	     
	     
	     ds[i] -> nhap();
	}
	int km;
	cout << "nhap km di chuyen: "  << endl;
	cin >> km;
	cout <<  "thong tin phuong tien: " << endl;
	for ( int i = 0; i < n; i ++){
		ds[i] -> xuat();
//		cout << " so tien la: " << ds[i] -> tinhchiphi(km) << endl;
 cout << "Chi phi di chuyen " << km << " km: " << ds[i]->tinhchiphi(km) << " VND\n\n";
	}
	for ( int i = 0; i < n; i++)
	delete ds[i];
	return 0;
	
}