#include <bits/stdc++.h>
using namespace std;

struct SinhVien{
    string MSSV;
    string HoTen;
    float DiemTB;
};

vector <SinhVien> docFile(string tenFile) {
    vector <SinhVien> ds;
    ifstream in(tenFile);
    if (!in.is_open()) {
        cout << "Loi mo file!" << endl;
        return ds;
    }
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        SinhVien sv;
        string diem;
        
        getline(ss, sv.MSSV, ',');
        getline(ss, sv.HoTen, ','); 
        getline(ss, diem, ',');
        sv.DiemTB = stof(diem);

        ds.push_back(sv);
    }

        in.close();
    return ds;

}

void xuatManHinh(vector<SinhVien> ds) {
    cout << left << setw(10) << "MSSV"
         << setw(20) << "Ho Ten"
         << setw(10) << "DiemTB" << endl;

    for (SinhVien sv : ds) {
        cout << left << setw(10) << sv.MSSV
             << setw(20) << sv.HoTen
             << setw(10) << sv.DiemTB << endl;
    }
}

void ghiFile(string tenFile, vector<SinhVien> ds) {
    ofstream out(tenFile);
    if (!out.is_open()) {
        cout << "Loi mo file!" << endl;
        return;
    }

    for (SinhVien sv : ds) {
        out << sv.MSSV << "," << sv.HoTen << "," << sv.DiemTB << endl;
    }

    out.close();
}

int main() {
    string tenFile = "sinhvien.txt";
    vector<SinhVien> ds = docFile(tenFile);
    
    cout << "Danh sach sinh vien:" << endl;
    xuatManHinh(ds);

    string tenFileOut = "output.txt";
    ghiFile(tenFileOut, ds);
    cout << "Da ghi du lieu vao file " << tenFileOut << endl;

    return 0;
} 





