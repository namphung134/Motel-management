#include <iostream>
#include <fstream> // dùng để đọc file
#include <conio.h> // thu vien nay dung de dùng getch()
#include <stdio.h>

using namespace std;

class nhaTro
{

private:
    int soPhong;
    char hoTen[100];
    int namSinh;
    char sdt[10];
    char diaChi[100];
    char cccd[20];
    char gioiTinh[10];
    int thanhVien;
    float soDien = 0;
    int tienDien = 0;
    float soNuoc = 0;
    int tienNuoc = 0;
    int Sum = 0;
    int giaPhong = 500000;
    int tongDoanhThu = 0;

public:
    void menuChinh();
    void dangKyPhong();
    void capNhapPhong();
    void khachHang();
    int kiemTra(int);
    void thongTinKhachHang(int);
    void thayDoiThongTinKH(int);
    void xoaThongTinKH(int);
    int tinhTienDien(float, int);
    int tinhTienNuoc(float, int);
    int thanhToanVaDoanhThu(int, int, int);
};

//ham hien thi menu chinh

void nhaTro::menuChinh()
{
    int choice;
    while (choice > 4 || choice < 1)
    {
        system("cls"); // xoa man hinh ban dau cho de nhin

        cout << "============HE THONG QUAN LY NHA TRO============\n\n";
        cout << "\t\t\t 1. Dang ky phong tro\n";
        cout << "\t\t\t 2. Tinh trang cac phong\n";
        cout << "\t\t\t 3. Khach hang va doanh thu\n";
        cout << "\n\n\n\t\t\t\t\tHay nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            dangKyPhong();
            break;

        case 2:
            capNhapPhong();
            break;

        case 3:
            khachHang();
            break;

        default:
        {
            cout << "ban da nhap sai thong tin, hay nhap lai!!!\n";
            getch();
            menuChinh();
        }
        }
    }
}

// hàm này dùng để đặt phòng

void nhaTro::dangKyPhong()
{
    system("cls");
    int a, b;
    ofstream fout("Recorddata.txt", ios::app); //Output File Stream và được sử dụng để tạo các file và để ghi thông tin tới các file đó

    cout << "\nDanh sach cac phong: ";
    cout << "\n Tong co 10 phong o lau 2 va 3";
    cout << "\n Lau 2 gom cac phong tu 1 - 5";
    cout << "\n Lau 3 gom cac phong tu 6 - 10";
    cout << "\n Hay nhap so phong ban muon thue:- " << endl;
    cin >> a;

    b = kiemTra(a);

    if (b)
    {
        cout << "\nPhong nay da co nguoi su dung . . . ! !";
    }
    else
    {
        soPhong = a;
        cout << "\nNhap ho ten: ";
        cin >> hoTen;
        cout << "nam sinh: ";
        cin >> namSinh;
        cout << "so dien thoai: ";
        cin >> sdt;
        cout << "can cuoc cong dan: ";
        cin >> cccd;
        cout << "Dia chi: ";
        cin >> diaChi;
        cout << "Gioi tinh: ";
        cin >> gioiTinh;
        cout << "So thanh vien se o lai cung phong: ";
        cin >> thanhVien;

        fout.write((char *)this, sizeof(nhaTro));
        cout << "\n Phong da duoc dang ky...!!!";
    }
    cout << "\n Hay nhan phim bat ki de tiep tuc . . . ! !";

    getch();
    fout.close();
    menuChinh();
}

//hàm này dùng để hiển thị tất cả các phòng đã được đặt

void nhaTro::capNhapPhong()
{
    system("cls");
    ifstream fin("recorddata.txt", ios::in);
    cout << "Danh sach cac phong da su dung:";

    while (!fin.eof())
    {
        fin.read((char *)this, sizeof(nhaTro));

        if (fin.eof())
        {
            break;
        }

        cout << soPhong << ", ";
    }

    cout << "\n\nHay nhan phim bat ki de tiep tuc . . . ! !";
    getch();
    fin.close();
    menuChinh();
}

// hàm này dùng để kiểm tra phòng

int nhaTro::kiemTra(int a)
{
    int b = 0;

    ifstream fin("Recorddata.txt", ios::in); // ifstream,(ios::in) cái này dùng để mở một tệp tin để đọc

    while (!fin.eof())
    {

        fin.read((char *)this, sizeof(nhaTro));
        if (soPhong == a)
        {

            b = 1;
            break;
        }
    }

    fin.close();
    return (b);
}

// hàm này dùng để chỉnh sửa và hiên thị các thông tin của khách hàng

void nhaTro::khachHang()
{

    system("cls");

    int a, choice;

    cout << "Khach Hang: \n";
    cout << "\n1. Hien thi thong tin khach hang ban muon xem";
    cout << "\n2. Chinh sua thong tin cua khach hang";
    cout << "\n3. Xoa thong tin cua khach hang";
    cout << "\n4. Thanh toan chi phi va suat tong doanh thu";
    cout << "\nNhap: ";
    cin >> choice;

    system("cls");

    switch (choice)
    {
    case 1:
        thongTinKhachHang(a);
        break;

    case 2:
        thayDoiThongTinKH(a);
        break;

    case 3:
        xoaThongTinKH(a);
        break;

    case 4:
        thanhToanVaDoanhThu(Sum, giaPhong, tongDoanhThu);
        break;

    default:
        cout << "\nban da sai . . .";
    }
    cout << "\nHay nhan phim bat ki de tiep tuc . . . ! !";

    getch();
    menuChinh();
}

// hàm này dùng để hiển thị hồ sơ của từng khách hàng

void nhaTro::thongTinKhachHang(int a)
{

    system("cls");
    ifstream fin("recorddata.txt", ios::in); //Input File Stream và được sử dụng để đọc thông tin từ các file
    int b = 0;

    cout << "\n nhap so phong ban muon xem: ";
    cin >> a;

    while (!fin.eof()) // while (!eof(f)) theo mình hiểu nghĩa là khi nào chưa gặp kí tự kết thúc eof trong file thì sẽ còn
                       //  thực hiện đọc kí tự có trong file.
    {
        fin.read((char *)this, sizeof(nhaTro));
        if (soPhong == a)
        {
            system("cls");
            cout << "\n\nThong tin cua khach hang: \n";
            cout << "So phong: " << soPhong << endl;
            cout << "Ten: " << hoTen << endl;
            cout << "nam Sinh: " << namSinh << endl;
            cout << "Sdt: " << sdt << endl;
            cout << "Dia chi: " << diaChi << endl;
            cout << "can cuoc cong dan: " << cccd << endl;
            cout << "Gioi tinh: " << gioiTinh << endl;
            cout << "so thanh vien o cung: " << thanhVien << endl;
            b = 1;
            break;
        }
    }
    if (b == 0)

        cout << "khong co thong tin khach hang cua phong nay. . .";
    cout << "\n\t\t\t Hay nhan phim bat ki de tiep tuc . . . ! !";

    getch();
    fin.close();
    menuChinh();
}

// hàm này dùng để chỉnh sửa hồ sơ thông tin của khách hàng

void nhaTro::thayDoiThongTinKH(int a)
{
    int p, b = 0;
    cout << "Nhap so phong: \n";
    cin >> a;

    fstream file("Recorddata.txt", ios::in | ios::out | ios::binary);

    while (!file.eof())
    {

        p = file.tellg();
        file.read((char *)this, sizeof(nhaTro));

        if (soPhong == a)
        {

            cout << "\n Hay nhap thong tin moi vao duoi day: ";
            cout << "\n -----------------";
            cout << "\nNhap ho ten: ";
            cin >> hoTen;
            cout << "nam sinh: ";
            cin >> namSinh;
            cout << "so dien thoai: ";
            cin >> sdt;
            cout << "can cuoc cong dan: ";
            cin >> cccd;
            cout << "Dia chi: ";
            cin >> diaChi;
            cout << "Gioi tinh: ";
            cin >> gioiTinh;
            cout << "So thanh vien se o lai cung phong: ";
            cin >> thanhVien;
            file.seekg(p);
            file.write((char *)this, sizeof(nhaTro));
            cout << "\n Da thay doi xong....!!";
            b = 1;
            break;
        }
    }

    if (b == 0)
        cout << "\n khong tim duoc phong nay. . . ! !";
    file.close();
    cout << "\nHay nhan phim bat ki de tiep tuc . . . ! !";

    getch();
    menuChinh();
}

void nhaTro::xoaThongTinKH(int a)
{
    cout << "nhap so phong: \n";
    cin >> a;

    int b = 0;
    char c;
    ifstream fin("Recorddata.txt", ios::in);
    ofstream fout("tempdata.txt", ios::out);

    while (!fin.eof())
    {

        fin.read((char *)this, sizeof(nhaTro));
        if (soPhong == a)

        {

            cout << "So phong: " << soPhong << endl;
            cout << "Ten: " << hoTen << endl;
            cout << "nam Sinh: " << namSinh << endl;
            cout << "Sdt: " << sdt << endl;
            cout << "Dia chi: " << diaChi << endl;
            cout << "can cuoc cong dan: " << cccd << endl;
            cout << "Gioi tinh: " << gioiTinh << endl;
            cout << "so thanh vien o cung: " << thanhVien << endl;
            cout << "Do you want to delete this record(y/n): ";
            cin >> c;

            if (c == 'n')
                fout.write((char *)this, sizeof(nhaTro));
            b = 1;
        }

        else
            fout.write((char *)this, sizeof(nhaTro));
    }

    fin.close();
    fout.close();

    if (b == 0)
        cout << "\n khong tim thay phong nay...!!";

    else
    {

        remove("Recorddata.txt");
        rename("tempdata.txt", "Recorddata.txt");
    }
}

int nhaTro::tinhTienDien(float soDien, int tienDien)
{
    int bacdien1 = 1678, bacdien2 = 1734, bacdien3 = 2014, bacdien4 = 2536, bacdien5 = 2834, bacdien6 = 2927;
    cout << "\nNhap vao so dien cua ban (kWh): ";
    cin >> soDien;
    if (soDien < 0)
    {
        cout << "\nVui long nhap lai So Dien\nSo dien khong duoc nho hon 0\n";
    }
    else if (soDien <= 50)
    {
        tienDien = soDien * bacdien1;
        cout << "\nban da dung dien trong khoang 0 - 50 kWh so tien ban phai tra la: " << tienDien;
    }
    else if (soDien <= 100)
    {
        tienDien = 50 * bacdien1 + ((soDien - 50) * bacdien2);
        cout << "\nban da dung dien trong khoang 51 - 100 kWh so tien ban phai tra la: " << tienDien;
    }
    else if (soDien <= 200)
    {
        tienDien = 50 * bacdien1 + (50 * bacdien2) + ((soDien - 100) * bacdien3);
        cout << "\nban da dung dien trong khoang 101 - 200 kWh so tien ban phai tra la: " << tienDien;
    }
    else if (soDien <= 300)
    {
        tienDien = 50 * bacdien1 + (50 * bacdien2) + (100 * bacdien3) + ((soDien - 200) * bacdien4);
        cout << "\nban da dung dien trong khoang 201 - 300 kWh so tien ban phai tra la: " << tienDien;
    }
    else if (soDien <= 400)
    {
        tienDien = 50 * bacdien1 + (50 * bacdien2) + (100 * bacdien3) + (100 * bacdien4) + ((soDien - 300) * bacdien5);
        cout << "\nban da dung dien trong khoang 301 - 400 kWh so tien ban phai tra la: " << tienDien;
    }
    else if (soDien > 400)
    {
        tienDien = 50 * bacdien1 + (50 * bacdien2) + (100 * bacdien3) + (100 * bacdien4) + (100 * bacdien5) + ((soDien - 400) * bacdien6);
        cout << "\nban da dung dien tren 400 kWh so tien ban phai tra la: " << tienDien;
    }
    return tienDien;
}


int nhaTro::tinhTienNuoc(float soNuoc, int tienNuoc)
{
    int bacnuoc1 = 5973, bacnuoc2 = 7052, bacnuoc3 = 8669, bacnuoc4 = 15929;
    cout << "\nNhap vao so nuoc cua ban da su dung (m3): ";
    cin >> soNuoc;
    if (soNuoc < 0)
    {
        cout << "\nVui long nhap lai So nuoc\nSo nuoc khong duoc nho hon 0\n";
    }
    else if (soNuoc <= 10)
    {
        
        tienNuoc = soNuoc * bacnuoc1;
        cout << "\nban da dung nuoc trong khoang muc 10m3 so tien ban phai tra la: " << tienNuoc;
    }
    else if (soNuoc > 10 && soNuoc <= 20)
    {
        tienNuoc = soNuoc * bacnuoc2;
        cout << "\nban da dung nuoc trong khoang 10m3 - 20m3 so tien ban phai tra la: " << tienNuoc;
    }
    else if (soNuoc > 20 && soNuoc <= 30)
    {
        tienNuoc = soNuoc * bacnuoc3;
        cout << "\nban da dung nuoc trong khoang 20m3 - 30m3 so tien ban phai tra la: " << tienNuoc;
    }
    else if (soNuoc > 30)
    {
        tienNuoc = soNuoc * bacnuoc4;
        cout << "\nban da dung nuoc trong khoang Trên 30m3 so tien ban phai tra la: " << tienNuoc;

        
    }
return tienNuoc;
}

int nhaTro::thanhToanVaDoanhThu(int Sum, int giaPhong, int tongDoanhThu)
{
    system("cls");

        int tienDien = tinhTienDien(soDien, tienDien);
        int tienNuoc = tinhTienNuoc(soNuoc, tienNuoc);

        int chiPhiPhatSinh = 0;

        cout << "nhap chi phi phat sinh cua khach hang: ";
        cin >> chiPhiPhatSinh;

        Sum = tienDien + tienNuoc + giaPhong + chiPhiPhatSinh;

        cout << "\ntong tien ban se phai thanh toan la (gom tiennuoc + tiendien + tiennha): " << Sum << endl;

        tongDoanhThu += Sum;

        cout << "tong doanh thu la: " << tongDoanhThu << "vnd" << endl;

        return tongDoanhThu;

        getch();
    }

    int main()
    {
        nhaTro m;
        system("cls");

        cout << "                      *DU AN QUAN LY NHA TRO*\n\n\n\n\n\n";

        getch();

        m.menuChinh();
        return 0;
    }
