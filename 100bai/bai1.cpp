#include <bits/stdc++.h>
#include <cmath>
using namespace std;
const double PI = acos(-1.0);

int main() {
    double S, R, V;
    cout << "Nhap dien tich S: ";
    cin >> S;
    R = sqrt(S / (4.0 * PI)); 
    V = (4.0 / 3.0) * PI * pow(R, 3); // v = (4/3) * Pi * R^3
    // dùng 4.0/3.0 để đảm bảo phép chia là số thực

    cout << fixed << setprecision(6); // fixed và setprecision để hiển thị số chữ số thập phân cố định
    cout << "The tich V = " << V << endl;

    return 0;
}
