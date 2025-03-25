#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Struktur untuk menyimpan data barang
struct Barang {
    string kode;
    string nama;
    int stok;
    double harga;
};

// Struktur untuk menyimpan data pengguna
struct Pengguna {
    string nama;
    string nim;
    string password;
};

vector<Pengguna> daftarPengguna;
vector<Barang> daftarBarang;
Pengguna penggunaAktif;

// Fungsi untuk registrasi
void registrasi() {
    Pengguna user;
    cout << "\nREGISTRASI" << endl;
    cout << "Masukkan Nama: "; cin.ignore(); getline(cin, user.nama);
    cout << "Masukkan NIM: "; cin >> user.nim;
    cout << "Masukkan Password: "; cin >> user.password;
    daftarPengguna.push_back(user);
    cout << "Registrasi berhasil! Silakan login." << endl;
}

// Fungsi untuk login
bool login() {
    string nama, nim, password;
    int attempts = 0;
    while (attempts < 3) {
        cout << "\nLOGIN" << endl;
        cout << "Masukkan Nama: "; cin.ignore(); getline(cin, nama);
        cout << "Masukkan NIM: "; cin >> nim;
        cout << "Masukkan Password: "; cin >> password;
        
        for (const auto& user : daftarPengguna) {
            if (user.nama == nama && user.nim == nim && user.password == password) {
                penggunaAktif = user;
                cout << "Login berhasil!" << endl;
                return true;
            }
        }
        cout << "Login gagal! Coba lagi." << endl;
        attempts++;
    }
    cout << "Anda telah mencoba beberapa kali . Silahkan tunggu beberapa saat." << endl;
    return false;
}

// Fungsi menampilkan daftar barang
void tampilkanBarang() {
    cout << "\n==================== DAFTAR BARANG ANTIK ====================\n";
    cout << left << setw(10) << "Kode" << setw(20) << "Nama" << setw(10) << "Stok" << setw(15) << "Harga" << endl;
    cout << "----------------------------------------------------------\n";
    for (const auto& barang : daftarBarang) {
        cout << left << setw(10) << barang.kode << setw(20) << barang.nama << setw(10) << barang.stok << setw(15) << barang.harga << endl;
    }
    cout << "==========================================================\n";
}

// Fungsi menambah barang
void tambahBarang() {
    Barang barang;
    cout << "Masukkan kode barang: "; cin >> barang.kode;
    cout << "Masukkan nama barang: "; cin.ignore(); getline(cin, barang.nama);
    cout << "Masukkan stok barang: "; cin >> barang.stok;
    cout << "Masukkan harga barang: "; cin >> barang.harga;
    daftarBarang.push_back(barang);
    cout << "Barang berhasil ditambahkan!" << endl;
}

// Fungsi mengedit barang
void editBarang() {
    string kode;
    cout << "Masukkan kode barang yang ingin diedit: "; cin >> kode;
    for (auto& barang : daftarBarang) {
        if (barang.kode == kode) {
            cout << "Masukkan nama baru: "; cin.ignore(); getline(cin, barang.nama);
            cout << "Masukkan stok baru: "; cin >> barang.stok;
            cout << "Masukkan harga baru: "; cin >> barang.harga;
            cout << "Barang berhasil diperbarui!" << endl;
            return;
        }
    }
    cout << "Barang tidak ditemukan!" << endl;
}

// Fungsi menghapus barang
void hapusBarang() {
    string kode;
    cout << "Masukkan kode barang yang ingin dihapus: "; cin >> kode;
    for (size_t i = 0; i < daftarBarang.size(); i++) {
        if (daftarBarang[i].kode == kode) {
            daftarBarang.erase(daftarBarang.begin() + i);
            cout << "Barang berhasil dihapus!" << endl;
            return;
        }
    }
    cout << "Barang tidak ditemukan!" << endl;
}

int main() {
    int pilihan;
    while (true) {
        cout << "\n========== MENU ==========";
        cout << "\n1. Registrasi\n2. Login\n3. Keluar\n";
        cout << "Pilih menu: "; cin >> pilihan;
        
        switch (pilihan) {
            case 1: registrasi(); break;
            case 2:
                if (login()) {
                    int subPilihan;
                    do {
                        cout << "\n========== MENU UTAMA ==========";
                        cout << "\n1. Tambah Barang\n2. Edit Barang\n3. Hapus Barang\n4. Tampilkan Barang\n5. Logout\n";
                        cout << "Pilih menu: "; cin >> subPilihan;
                        
                        switch (subPilihan) {
                            case 1: tambahBarang(); break;
                            case 2: editBarang(); break;
                            case 3: hapusBarang(); break;
                            case 4: tampilkanBarang(); break;
                            case 5: cout << "Logout berhasil." << endl; break;
                            default: cout << "Pilihan tidak valid!" << endl;
                        }
                    } while (subPilihan != 5);
                }
                break;
            case 3: cout << "Keluar dari program." << endl; return 0;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    }
}
