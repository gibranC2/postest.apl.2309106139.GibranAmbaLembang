#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Struktur data
struct Barang {
    string kode;
    string nama;
    int stok;
    double harga;
};

struct Pengguna {
    string nama;
    string nim;
    string password;
};

// Fungsi rekursif: menghitung total stok barang
int hitungTotalStok(const vector<Barang>& daftarBarang, int index) {
    if (index < 0) return 0;
    return daftarBarang[index].stok + hitungTotalStok(daftarBarang, index - 1);
}

// Fungsi overloading: tampilkan semua barang
void tampilkanBarang(const vector<Barang>& daftarBarang) {
    cout << "\n==================== DAFTAR BARANG ANTIK ====================\n";
    cout << left << setw(10) << "Kode" << setw(20) << "Nama" << setw(10) << "Stok" << setw(15) << "Harga" << endl;
    cout << "-------------------------------------------------------------\n";
    for (const auto& barang : daftarBarang) {
        cout << left << setw(10) << barang.kode << setw(20) << barang.nama
             << setw(10) << barang.stok << setw(15) << barang.harga << endl;
    }
    cout << "=============================================================\n";
}

// Fungsi overloading: tampilkan satu barang berdasarkan kode
void tampilkanBarang(const vector<Barang>& daftarBarang, const string& kode) {
    for (const auto& barang : daftarBarang) {
        if (barang.kode == kode) {
            cout << "\nBarang Ditemukan:\n";
            cout << left << setw(10) << "Kode" << setw(20) << "Nama"
                 << setw(10) << "Stok" << setw(15) << "Harga" << endl;
            cout << left << setw(10) << barang.kode << setw(20) << barang.nama
                 << setw(10) << barang.stok << setw(15) << barang.harga << endl;
            return;
        }
    }
    cout << "Barang tidak ditemukan.\n";
}

// Prosedur: registrasi pengguna
void registrasi(vector<Pengguna>& daftarPengguna) {
    Pengguna user;
    cout << "\nREGISTRASI\n";
    cout << "Masukkan Nama: "; cin.ignore(); getline(cin, user.nama);
    cout << "Masukkan NIM: "; cin >> user.nim;
    cout << "Masukkan Password: "; cin >> user.password;
    daftarPengguna.push_back(user);
    cout << "Registrasi berhasil! Silakan login.\n";
}

// Fungsi: login
bool login(const vector<Pengguna>& daftarPengguna, Pengguna& penggunaAktif) {
    string nama, nim, password;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "\nLOGIN\n";
        cout << "Masukkan Nama: "; cin.ignore(); getline(cin, nama);
        cout << "Masukkan NIM: "; cin >> nim;
        cout << "Masukkan Password: "; cin >> password;

        for (const auto& user : daftarPengguna) {
            if (user.nama == nama && user.nim == nim && user.password == password) {
                penggunaAktif = user;
                cout << "Login berhasil!\n";
                return true;
            }
        }

        cout << "Login gagal! Coba lagi.\n";
        percobaan++;
    }

    cout << "Anda telah mencoba 3 kali. Silakan tunggu beberapa saat.\n";
    return false;
}

// Prosedur: tambah barang
void tambahBarang(vector<Barang>& daftarBarang) {
    Barang barang;
    cout << "Masukkan kode barang: "; cin >> barang.kode;
    cout << "Masukkan nama barang: "; cin.ignore(); getline(cin, barang.nama);
    cout << "Masukkan stok barang: "; cin >> barang.stok;
    cout << "Masukkan harga barang: "; cin >> barang.harga;
    daftarBarang.push_back(barang);
    cout << "Barang berhasil ditambahkan!\n";
}

// Prosedur: edit barang
void editBarang(vector<Barang>& daftarBarang) {
    string kode;
    cout << "Masukkan kode barang yang ingin diedit: "; cin >> kode;

    for (auto& barang : daftarBarang) {
        if (barang.kode == kode) {
            cout << "Masukkan nama baru: "; cin.ignore(); getline(cin, barang.nama);
            cout << "Masukkan stok baru: "; cin >> barang.stok;
            cout << "Masukkan harga baru: "; cin >> barang.harga;
            cout << "Barang berhasil diperbarui!\n";
            return;
        }
    }
    cout << "Barang tidak ditemukan!\n";
}

// Prosedur: hapus barang
void hapusBarang(vector<Barang>& daftarBarang) {
    string kode;
    cout << "Masukkan kode barang yang ingin dihapus: "; cin >> kode;

    for (size_t i = 0; i < daftarBarang.size(); i++) {
        if (daftarBarang[i].kode == kode) {
            daftarBarang.erase(daftarBarang.begin() + i);
            cout << "Barang berhasil dihapus!\n";
            return;
        }
    }
    cout << "Barang tidak ditemukan!\n";
}

int main() {
    vector<Pengguna> daftarPengguna;
    vector<Barang> daftarBarang;
    Pengguna penggunaAktif;

    int pilihan;

    while (true) {
        cout << "\n========== MENU ==========\n";
        cout << "1. Registrasi\n2. Login\n3. Keluar\n";
        cout << "Pilih menu: "; cin >> pilihan;

        switch (pilihan) {
            case 1:
                registrasi(daftarPengguna);
                break;
            case 2:
                if (login(daftarPengguna, penggunaAktif)) {
                    int subPilihan;
                    do {
                        cout << "\n===== MENU UTAMA =====\n";
                        cout << "1. Tambah Barang\n2. Edit Barang\n3. Hapus Barang\n4. Tampilkan Semua Barang\n";
                        cout << "5. Tampilkan Barang (by kode)\n6. Hitung Total Stok (rekursif)\n7. Logout\n";
                        cout << "Pilih menu: "; cin >> subPilihan;

                        switch (subPilihan) {
                            case 1: tambahBarang(daftarBarang); break;
                            case 2: editBarang(daftarBarang); break;
                            case 3: hapusBarang(daftarBarang); break;
                            case 4: tampilkanBarang(daftarBarang); break;
                            case 5: {
                                string kode;
                                cout << "Masukkan kode barang: "; cin >> kode;
                                tampilkanBarang(daftarBarang, kode);
                                break;
                            }
                            case 6:
                                cout << "Total stok seluruh barang: " << hitungTotalStok(daftarBarang, daftarBarang.size() - 1) << endl;
                                break;
                            case 7:
                                cout << "Logout berhasil.\n";
                                break;
                            default:
                                cout << "Pilihan tidak valid!\n";
                        }
                    } while (subPilihan != 7);
                }
                break;
            case 3:
                cout << "Keluar dari program.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }
}
