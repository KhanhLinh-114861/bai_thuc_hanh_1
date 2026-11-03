
#include <iostream>
#include <string>
using namespace std;
class Xe {
private:
    int maXe, gioVao, thoiGianDo;
    string loaiXe;
    double phiDoXe;
    bool dangChiemCho;
public:
    Xe() {
        maXe = gioVao = thoiGianDo = 0;
        loaiXe = "";
        phiDoXe = 0;
        dangChiemCho = false;
    }
    Xe(int ma, const string& loai, int gio, int tg) {
        maXe = ma;
        loaiXe = loai;
        gioVao = gio;
        thoiGianDo = tg;
        phiDoXe = 0;
        dangChiemCho = true;
        tinhPhiDoXe();
    }
    int layMaXe() const { return maXe; }
    string layLoaiXe() const { return loaiXe; }
    double layPhiDoXe() const { return phiDoXe; }
    void ganMaXe(int ma) { maXe = ma; }
    void ganLoaiXe(const string& loai) { loaiXe = loai; }
    void ganGioVao(int gio) { gioVao = gio; }
    void ganThoiLuongDo(int tg) { thoiGianDo = tg; }
    void ganDangChiemCho(bool tt) { dangChiemCho = tt; }
    void tinhPhiDoXe() {
        double gia = 0;
        if (loaiXe == "Car") gia = 6;
        else if (loaiXe == "Motorcycle") gia = 4;
        else if (loaiXe == "Bicycle") gia = 2;
        phiDoXe = gia * thoiGianDo;
    }
    void hienThi() const {
        cout << "\nMa xe: " << maXe;
        cout << "\nLoai xe: " << loaiXe;
        cout << "\nGio vao: " << gioVao;
        cout << "\nThoi gian do: " << thoiGianDo;
        cout << "\nPhi: " << phiDoXe << endl;
    }
};
class baixe {
private:
    int mabai;
    char kichthuoc;
    Xe pt1, pt2, pt3;
    bool co1, co2, co3;
public:
    baixe() {
        mabai = 0;
        kichthuoc = 'S';
        co1 = co2 = co3 = false;
    }
    baixe(int ma, char kt) {
        mabai = ma;
        kichthuoc = kt;
        co1 = co2 = co3 = false;
    }
    int layma() const { return mabai; }
    bool them(Xe v) {
        if (!co1) { pt1 = v; co1 = true; return true; }
        if (kichthuoc != 'S' && !co2) {
            pt2 = v; co2 = true; return true;
        }
        if (kichthuoc == 'L' && !co3) {
            pt3 = v; co3 = true; return true;
        }
        return false;
    }
    bool xoa(int ma) {
        if (co1 && pt1.layMaXe() == ma) { co1 = false; return true; }
        if (co2 && pt2.layMaXe() == ma) { co2 = false; return true; }
        if (co3 && pt3.layMaXe() == ma) { co3 = false; return true; }
        return false;
    }
    void hienthi() const {
        cout << "\nMa bai: " << mabai;
        cout << "\nKich thuoc: " << kichthuoc;
        if (co1) pt1.hienThi();
        if (co2) pt2.hienThi();
        if (co3) pt3.hienThi();
    }

    bool coloai(string loai, int& dem, double& tong) const {
        bool tim = false;
        if (co1 && pt1.layLoaiXe() == loai) {
            dem++; tong += pt1.layPhiDoXe(); tim = true;
        }
        if (co2 && pt2.layLoaiXe() == loai) {
            dem++; tong += pt2.layPhiDoXe(); tim = true;
        }
        if (co3 && pt3.layLoaiXe() == loai) {
            dem++; tong += pt3.layPhiDoXe(); tim = true;
        }
        return tim;
    }
};
class SystemInterface {
private:
    baixe bai1, bai2, bai3;
    bool co1, co2, co3;
public:
    SystemInterface() {
        co1 = co2 = co3 = false;
    }
    void runMenu() {
        int chon;
        do {
            cout << "\n1.Tao bai  2.Them xe  3.Xoa bai";
            cout << "\n4.Lay xe   5.Hien thi 6.Thong ke 0.Thoat";
            cout << "\nChon: ";
            cin >> chon;
            if (chon == 1) {
                int ma; char kt;
                cin >> ma >> kt;
                if (!co1) { bai1 = baixe(ma, kt); co1 = true; }
                else if (!co2) { bai2 = baixe(ma, kt); co2 = true; }
                else if (!co3) { bai3 = baixe(ma, kt); co3 = true; }
                else cout << "Da du bai!";
            }
            else if (chon == 2) {
                int ma, gio, tg; string loai;
                cin >> ma >> loai >> gio >> tg;
                Xe v(ma, loai, gio, tg);
                bool kq = false;
                if (co1) kq = bai1.them(v);
                if (!kq && co2) kq = bai2.them(v);
                if (!kq && co3) kq = bai3.them(v);
                cout << (kq ? "Thanh cong" : "That bai");
            }
            else if (chon == 3) {
                int ma; cin >> ma;
                if (co1 && bai1.layma() == ma) co1 = false;
                else if (co2 && bai2.layma() == ma) co2 = false;
                else if (co3 && bai3.layma() == ma) co3 = false;
            }
            else if (chon == 4) {
                int ma; cin >> ma;
                bool kq = false;
                if (co1) kq = bai1.xoa(ma);
                if (!kq && co2) kq = bai2.xoa(ma);
                if (!kq && co3) kq = bai3.xoa(ma);
            }
            else if (chon == 5) {
                if (co1) bai1.hienthi();
                if (co2) bai2.hienthi();
                if (co3) bai3.hienthi();
            }
            else if (chon == 6) {
                string loai; int dem = 0; double tong = 0;
                cin >> loai;
                if (co1) bai1.coloai(loai, dem, tong);
                if (co2) bai2.coloai(loai, dem, tong);
                if (co3) bai3.coloai(loai, dem, tong);
                cout << "So xe: " << dem << "\nTong phi: " << tong;
            }
        } while (chon != 0);
    }
};
int main() {
    SystemInterface ql;
    ql.runMenu();
    return 0;
}
