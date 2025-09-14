#include <bits/stdc++.h>
using namespace std;

struct SanPham {
    string MaSP;
    string TenSanPham;
    int SoLuongTon;
    double DonGia;
};

vector<SanPham> docFile(string tenFile) {
    vector<SanPham> ds;
    ifstream in(tenFile);
    if (!in.is_open()) {
        cout << " Loi mo file!" << endl;
        return ds;
    }

    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        SanPham sp;
        string SoLuongTonStr, DonGiaStr;
        getline(ss, sp.MaSP, ',');
        getline(ss, sp.TenSanPham, ',');
        getline(ss, SoLuongTonStr, ',');
        getline(ss, DonGiaStr, ',');
        sp.SoLuongTon = stoi(SoLuongTonStr);
        sp.DonGia = stod(DonGiaStr);
        ds.push_back(sp);

    }
    in.close();
    return ds;
}

void inDanhSach(vector<SanPham> ds) {
    cout << left << setw(10) << "MaSP"
         << setw(20) << "TenSP"
         << setw(15) << "SoLuongTon"
         << setw(10) << "DonGia" << endl;

    for (SanPham sp : ds) {
        cout << left << setw(10) << sp.MaSP
             << setw(20) << sp.TenSanPham
             << setw(15) << sp.SoLuongTon
             << setw(10) << sp.DonGia << endl;
    }
}

void timSanPham(vector<SanPham> ds, string maSP) {
    bool found = false;
    for (SanPham sp : ds) {
        if (sp.MaSP == maSP) {
            cout << " Tim thay san pham: " << sp.TenSanPham
                 << " So luong ton: " << sp.SoLuongTon
                 << " Don gia: " << sp.DonGia << endl;
                 found = true;
                 break;

        }
    }
    if ( !found ) {
        cout << " Khong tim thay san pham voi ma " ;

    }

}

void lietKeSanPhamTonNhoHon10(vector<SanPham> ds) {
    cout << " Danh sach san pham co so luong < 10:\n";
    for (SanPham sp: ds) {
        if (sp.SoLuongTon < 10)
        cout << sp.SoLuongTon << " - " << sp.TenSanPham
             << " - SL " << sp.SoLuongTon << endl; 
    }
}

void ghiFile(string tenFile, vector<SanPham> ds) {
    ofstream fout(tenFile);
    if (!fout.is_open()) {
        cout << " Khong mo duoc file de ghi!" << endl;
        return;
    }
    
    for (SanPham sp : ds) {
        fout << sp.MaSP << ","
             << sp.TenSanPham << ","
             << sp.SoLuongTon << ","
             << sp.DonGia << " \n";
    }

    fout.close();
}

int main() {
    vector<SanPham> ds = docFile("sanpham.csv");
    cout << " Danh sach san pham:\n";
    inDanhSach(ds);

    cout << " Nhap ma san pham can tim: ";
    string maSP;
    cin >> maSP;
    timSanPham(ds, maSP);
    lietKeSanPhamTonNhoHon10(ds);
    ghiFile("sanpham_update.txt", ds);

    cout << " Da luu danh sach vao san pham_update.txt\n";
    return 0;
}