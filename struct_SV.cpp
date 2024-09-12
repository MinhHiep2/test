#include<iostream>
#include<cmath>
#include<string>
using namespace std;
struct SINHVIEN {
	string HoTen, SBD;
	float TDiem;
};
struct node {
	SINHVIEN info;
	node* next;
};

struct LIST {
	node* head;
	node* tail;
};
void them(LIST& l, SINHVIEN &a)
{
	
	node* p = new node;
	if (p == NULL)
	{
		cout << "Khong du bo nho";
		exit(1);
	}
	p->info = a;
	p->next = NULL;
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void nhap(LIST& x)
{
		SINHVIEN a;
		do
		{
			cout << "Nhap ten sinh vien: ";
			getline(cin, a.HoTen);
			if (a.HoTen == "0")break;
			cout << "Nhap so bao danh: ";
			getline(cin, a.SBD);
			cout << "Nhap diem: ";
			cin >> a.TDiem; cout << endl;
			them(x, a);

			cin.ignore();
		} while (true);
	
}
void xuat(SINHVIEN a) {
	cout << "\nTen Sinh Vien: " << a.HoTen;
	cout << "\nSo Bao Danh: " << a.SBD;
	cout << "\nTong Diem: " << a.TDiem << endl;
}

void Out(LIST& l) {
	node* p = l.head;
	if (p == NULL) {
		cout << "Danh sach rong!\n";
		exit(1);
	}
	while (p != NULL) {
		xuat(p->info);
c   fv		p = p->next;
	}
}
void xoa(LIST& l)
{
	node* p;
	while (l.head!=NULL)
	{
		p = l.head;
		l.head = l.head->next;
		delete p;
		
	}
	l.tail = NULL;
}
void SX(LIST& l)
{
	SINHVIEN a;
	node* p = l.head, * q;
	while (p != NULL)
	{
		q = p->next;
		while (q!=NULL)
		{
			if (p->info.TDiem < q->info.TDiem)
				swap(p->info, q->info);
			q = q->next;
		}
		p = p->next;
	}
}

void main()
{
	
	LIST l;
	l.head = l.tail = NULL;
	nhap(l);
	
	Out(l);
	SX(l);
	cout << "\033[32m";//mau xanh la
	Out(l);
	xoa(l);
	cout << "\033[0m";//mau mac dinh
	Out(l);
}
