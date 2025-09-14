#include <bits/stdc++.h>
using namespace std;

// Khai bao cau truc luu thong tin SinhVien 

struct SinhVien {
    string maSV;
    string hoTen;
    float diemToan;
    float diemLy;
    float diemHoa;
    float diemTB;
};

// Ham tinh diem trung binh

void tinhDiemTB(SinhVien &sv) {
    sv.diemTB = (sv.diemToan + sv.diemLy + sv.diemHoa) / 3.0;
}

// Ham doc du lieu tu file

vector<SinhVien> docDuLieu(const string &filename) {
    vector<SinhVien> danhSach;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << " Khong the mo file!" << filename << endl;
        return danhSach;
    }
    string line;

    // Bo qua dong tieu de dau tien 
    getline(file, line);
    
    while (getline(file, line)) {
        SinhVien sv;
        char delimiter = ',';
        size_t pos = 0;
        string token;

        // Lay ma sinh vien
        pos = line.find(delimiter);
        sv.maSV = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Lay ho ten sinh vien
        pos = line.find(delimiter);
        sv.hoTen = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Lay diem toan
        pos = line.find(delimiter);
        sv.diemToan = stof(line.substr(0, pos));
        line.erase(0, pos + 1);

        // Lay diem ly
        pos = line.find(delimiter);
        sv.diemLy = stof(line.substr(0, pos));
        line.erase(0, pos + 1);

        // lay diem hoa
        sv.diemHoa = stof(line);
        
    // tinh diem trung binh
    tinhDiemTB(sv);

    danhSach.push_back(sv);
    }
    file.close();
    return danhSach;

}

// Ham in danh sach sinh vien

void inDanhSach(const vector<SinhVien> &danhSach) {
    cout << setw(10) << "MaSV" 
         << setw(25) << "HoTen" 
         << setw(10) << "DiemToan" 
         << setw(10) << "DiemLy" 
         << setw(10) << "DiemHoa" 
         << setw(10) << "DiemTB" << endl;
    cout << string(75, '-') << endl;

    for (const auto &sv : danhSach) {
        cout << setw(10) << sv.maSV 
             << setw(25) << sv.hoTen 
             << setw(10) << fixed << setprecision(2) << sv.diemToan 
             << setw(10) << fixed << setprecision(2) << sv.diemLy 
             << setw(10) << fixed << setprecision(2) << sv.diemHoa 
             << setw(10) << fixed << setprecision(2) << sv.diemTB 
             << endl;
    }
    
}

int main() {
    vector<SinhVien> danhSach = docDuLieu("diemthi.txt");
    // Sap xep danh sach theo diem trung binh giam dan
    auto compareByDiemTB = [](const SinhVien &a, const SinhVien &b) {
        return a.diemTB > b.diemTB;
    };
    sort(danhSach.begin(), danhSach.end(), compareByDiemTB); 
    
    // In danh sach sinh vien
    inDanhSach(danhSach);
    return 0;

}

