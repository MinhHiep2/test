#include<iostream>
#include<cmath>
#include<string>
using namespace std;
struct DIEM {
	float x,y;
};
struct TAMGIAC {
	DIEM A, B, C;
};
void nhap(DIEM &a)
{
	cout << " Nhap toa do x: "; cin >> a.x;
	cout << " Nhap toa do y: "; cin >> a.y;
}
void nhapTAMGIAC(TAMGIAC& a)
{
	cout << "Nhap dinh A:\n"; nhap(a.A);
	cout << "Nhap dinh B:\n"; nhap(a.B);
	cout << "Nhap dinh C:\n"; nhap(a.C);
}
void xuatDiem(DIEM a)
{
	cout << "(" << a.x << ", " << a.y << ")";
}
void xuatTAMGIAC(TAMGIAC a)
{
	cout << "Dinh A: ";xuatDiem(a.A);
	cout << "Dinh B: "; xuatDiem(a.B);
	cout << "Dinh C: "; xuatDiem(a.C);
	cout <<endl;
}
//Cong thuc: A(x1,y1) ; B(x2,y2) -- (x2-x1)^2 +(y2-y1)^2
float TimKC(DIEM a, DIEM b)
{
	return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
bool kiemtraTAMGIAC(TAMGIAC a)
{
	float AB = TimKC(a.A, a.B);
	float BC = TimKC(a.B, a.C);
	float AC = TimKC(a.A, a.C);
	return (AB + BC > AC) && (AB + AC > BC) && (BC + AC > AB);
}
//Cong thuc: AB + BC + AC
float CHUVI(TAMGIAC a)
{
	return TimKC(a.A, a.B) + TimKC(a.B, a.C) + TimKC(a.A, a.C);
}
float DIENTICH(TAMGIAC a)
{
	float s = CHUVI(a) / 2;
	return sqrt(s * (s - TimKC(a.A, a.B)) * (s - TimKC(a.B, a.C)) * (s - TimKC(a.A, a.C)));
}
void loaiTAMGIAC(TAMGIAC a)
{
	float AB = TimKC(a.A, a.B);
	float BC = TimKC(a.B, a.C);
	float AC = TimKC(a.A, a.C);
	if (AB == BC && AB == AC && BC == AC)
		cout << "\nTam giac deu\n";
	else if (AB == BC && AB == AC || AB == AC && BC == AC || AB == BC && AC == BC)
		cout << "\nTam giac can\n";
	else if (abs(pow(AB,2) == BC * BC + AC * AC) || abs(pow(BC,2) == AC * AC + AB * AB) || abs(pow(AC,2) == AB * AB + BC * BC))
		cout << "\nTam giac vuong";
	else
		cout << "\nTam giac thuong";
	
}

void main()
{
	TAMGIAC tg;
	nhapTAMGIAC(tg);
	xuatTAMGIAC(tg);
	cout << "\033[34m";//mau xanh duong
	if (kiemtraTAMGIAC(tg))
	{
		cout << "\nBa diem co the tao thanh tam giac\n";
		cout << "Khoang cach giua cac dinh la: ";
		cout << "\nDinh AB: " << TimKC(tg.A, tg.B);
		cout << "\nDinh BC: " << TimKC(tg.B, tg.C);
		cout << "\nDinh AC: " << TimKC(tg.A, tg.C);
		cout << "\033[33m";//mau vang
		cout << "\nChu vi tam giac la: " << CHUVI(tg);
		cout << "\nDien tich tam giac la: " << DIENTICH(tg) << endl;
		cout << "\033[32m";//mau xanh la
		loaiTAMGIAC(tg);
		cout << endl;
	}
	else
	 cout << "\033[31m" << "\n3 diem khong the tao thanh tam giac\n";//mau do
	cout << "\033[0m";//mau mac dinh
	
}