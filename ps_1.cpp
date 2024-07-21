#include <iostream>
#include <cstdlib>

using namespace std;

struct PHANSO {
    int tu, mau;
};

void nhap(PHANSO&);
void xuat(PHANSO);
PHANSO tongPS(PHANSO, PHANSO);
void rutgon(PHANSO&); 
void nhapDSPS(PHANSO[], int&);
void xuatDSPS(PHANSO[], int);
PHANSO tongDSPS(PHANSO[], int);
int sosanhPS(PHANSO, PHANSO);
PHANSO timMAX(PHANSO[], int);
PHANSO hieuPS(PHANSO a, PHANSO b);
PHANSO tichPS(PHANSO a, PHANSO b);
PHANSO thuongPS(PHANSO a, PHANSO b);
int main() {
    int chon;
    cout << "Nhap vao chuc nang muon chon: ";
    cin >> chon;

    switch (chon) {
    case 1: {
        PHANSO p, x;
        nhap(p);
        cout << "Phan so 1: \t";
        xuat(p);
        nhap(x);
        cout << "Phan so 2: \t";
        xuat(x);
        PHANSO tong = thuongPS(p, x);
        cout << "Phan so sau khi rut gon la: ";
        rutgon(tong); 
        xuat(tong);
        cout << "Phan so sau khi tinh tong la: ";
        xuat(tong);
    } break;
    case 2: {
        PHANSO p[100];
        int n;
        nhapDSPS(p, n);
        PHANSO tong = tongDSPS(p, n);
        xuat(tong);
        rutgon(tong); 
        xuat(tong);
    } break;
    case 3: {
        PHANSO p[100];
        int n;
        nhapDSPS(p, n);
        xuatDSPS(p, n);
        PHANSO max = timMAX(p, n);
        cout << "Phan so lon nhat la: ";
        xuat(max);
    } break;
    default: 
        break;
    }

    return 0; 
}

void nhap(PHANSO& p) {
    cout << "Nhap vao tu so: ";
    cin >> p.tu;
    cout << "Nhap vao mau so: ";
    cin >> p.mau;
    while (p.mau==0)
    {
        cout << "Nhap lai vao mau so: ";
        cin >> p.mau;
    }
    if (p.tu == p.mau)
        p.mau = p.tu = 1;
}

void xuat(PHANSO p) {
    if (p.mau == 1)
        cout << p.tu << endl;
    else
        cout << p.tu << "|" << p.mau << endl;
}

PHANSO tongPS(PHANSO a, PHANSO b) {
    PHANSO t;
    t.mau = a.mau * b.mau;
    t.tu = a.tu * b.mau + b.tu * a.mau;
    rutgon(t); 
    return t;
}

PHANSO hieuPS(PHANSO a, PHANSO b)
{
    PHANSO t;
    t.mau = a.mau * b.mau;
    t.tu = a.tu * b.mau - a.mau * b.tu;
    rutgon(t);
    return t;
}

PHANSO tichPS(PHANSO a, PHANSO b)
{
    PHANSO t;
    t.tu = a.tu * b.tu;
    t.mau = a.mau * b.mau;
    rutgon(t);
    return t;
}
PHANSO thuongPS(PHANSO a, PHANSO b) {
    PHANSO t;
    t.tu = a.tu * b.mau;
    t.mau = a.mau * b.tu;
    rutgon(t);
    return t;
}
void rutgon(PHANSO& p) {
    int ucln = 1;
    int min = p.tu < p.mau ? p.tu : p.mau;
    for (int i = min; i > 1; i--) {
        if (p.mau % i == 0 && p.tu % i == 0) {
            ucln = i;
            break;
        }
    }
    p.tu /= ucln;
    p.mau /= ucln;
}

void nhapDSPS(PHANSO p[], int& n) {
    cout << "Nhap vao so danh sach: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao tu so: ";
        cin >> p[i].tu;
        cout << "Nhap vao mau so: ";
        cin >> p[i].mau;
        while (p[i].mau == 0) {
            cout << "Mau so phai khac 0. Nhap lai: ";
            cin >> p[i].mau;
        }
    }
}

void xuatDSPS(PHANSO p[], int n) {
    for (int i = 0; i < n; i++) {
        cout << " -Phan so " << i << " la :" << p[i].tu << "/" << p[i].mau << endl;
    }
}

PHANSO tongDSPS(PHANSO p[], int n) {
    PHANSO tong = p[0];
    for (int i = 1; i < n; i++) {
        tong = tongPS(p[i], tong);
    }
    rutgon(tong);
    return tong;
}

int sosanhPS(PHANSO a, PHANSO b) {
    int t1 = a.tu * b.mau;
    int t2 = b.tu * a.mau;
    if (t1 == t2)
        return 0;
    else if (t1 > t2)
        return 1;
    else
        return -1;
}

PHANSO timMAX(PHANSO p[], int n) {
    PHANSO max = p[0];
    for (int i = 1; i < n; i++) {
        if (sosanhPS(p[i], max) == 1) {
            max = p[i];
        }
    }
    return max;
}