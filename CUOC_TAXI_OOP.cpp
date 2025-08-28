#include <iostream>
#include <string>
using namespace std;

class Taxi{
	private:
		string tentaixe;
	    string id;
		float km;
		float tiencuoc;
			float phiDV;
		public:
			Taxi(string ten, string ma, float k,float t,float v){
		    tentaixe = ten;
		    id = ma;
			km = k;
			tiencuoc = t;
			phiDV = v;
		
}
 	float taxiphothong() {
 		return (tiencuoc * km) * 15000;
 		
	 }
	float taxivip (){
	
		return (tiencuoc * km) * 20000 + phiDV;
		
	}
	void xuat() {
        cout << "\nTen tai xe: " << tentaixe;
        cout << "\nID: " << id;
        cout << "\nTong tien taxi pho thong: " << taxiphothong();
        cout << "\nTong tien taxi vip: " << taxivip() << endl;
    }
};
int main (){
string tentaixe, id;
    float km, tiencuoc, phiDV;

    // Nhập dữ liệu từ người dùng
    cout << "Nhap ten tai xe: ";
    getline(cin, tentaixe); // Dùng getline để nhập chuỗi có dấu cách
    cout << "Nhap ID: ";
    getline(cin, id);
    cout << "Nhap so km: ";
    cin >> km;
    cout << "Nhap cuoc taxi: ";
    cin >> tiencuoc;
    cout << "Nhap phi dich vu: ";
    cin >> phiDV;
    
	  Taxi loai(tentaixe, id, km, tiencuoc, phiDV);
    loai.xuat();
    return 0;
}