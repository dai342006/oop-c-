#include <iostream>
using namespace std;
class thanhtoan {
	protected:
		double sotien;
		public:
			virtual void nhap(){
				cout << " nhap so tien: ";
				cin >> sotien;
			}
			virtual void xuat (){
				cout << "so tien la: " << sotien << " VND " << endl;
			}
			virtual double tinhtien()=0;
			virtual ~thanhtoan(){};
};
class tienmat : public thanhtoan{
public:
	double tinhtien () override {
		return sotien;
	}
};
class vidientu : public thanhtoan{
	public:
		double tinhtien ()override {
			return sotien * 1.015;
		}
};
class tindung : public thanhtoan{
	public:
		double tinhtien ()override{
		return sotien *  1.02;
		}
};
int main (){
	thanhtoan* tt;
	int n;

    cout << "Nhap so giao dich: ";
    cin >> n;
 
 cout << "chon phuong thuc thanh toan: ";
 for(int i = 0; i < n; i++){
 	int loai;
 	cout << "1.thanh toan tien mat\n";
 	cout << "2.thanh toan vi dien tu\n";
 	cout << "3.thanh toan tin dung\n";
 	cin >> loai;
 	if(loai==1){
 	cout << "--- Tien Mat ---\n";
    tt = new tienmat();
   
	}
   else if  (loai==2){
    	cout <<"--- vi dien tu ---\n";
    	tt = new vidientu();
    	
	}
	else if  (loai==3){
		cout <<"---tin dung---\n";
		tt = new tindung();
	}
	else  {
		cout << " ko hop le!" << endl;
		continue;
	}
		tt -> nhap();
		tt -> xuat();
		cout << " so tien phai tra la: " << tt->tinhtien() << "VND"<<endl;
		delete tt;
 }
 return 0;
}
