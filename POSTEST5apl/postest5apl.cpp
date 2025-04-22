 #include <iostream>
 #include <iomanip>
 #include <vector>
 using namespace std;
 
 /* ---------- Struktur data ---------- */
 struct Barang {
     string kodeBarang;
     string namaBarang;
     int jumlahStok;
     double hargaSatuan;
 };
 
 struct Pengguna {
     string namaPengguna;
     string nimPengguna;
     string kataSandi;
 };
 
 /* ---------- Prototipe ---------- */
 //–– Rekursif total stok (sudah ada di Posttest 4)
 int hitungTotalStok(const vector<Barang>& daftarBarang, int indeksTerakhir);
 
 //–– Overloading tampilkan
 void tampilkanBarang(const vector<Barang>& daftarBarang);
 void tampilkanBarang(const vector<Barang>& daftarBarang, const string& kodeBarangDicari);
 
 //–– Registrasi & login
 void registrasi(vector<Pengguna>& daftarPengguna);
 bool login(const vector<Pengguna>& daftarPengguna, Pengguna& penggunaAktif);
 
 //–– CRUD barang (tanpa pointer, versi lama)
 void tambahBarang(vector<Barang>& daftarBarang);
 void editBarang(vector<Barang>& daftarBarang);
 void hapusBarang(vector<Barang>& daftarBarang);
 
 //–– FUNGSI BARU: memakai POINTER
 void tambahBarangPointer(vector<Barang>* alamatDaftarBarang);           // parameter address‑of
 void totalAsetPointer(const vector<Barang>& daftarBarang, double* aset); // parameter dereference
 
 /* =================================== */
 /* =========== Implementasi ========== */
 /* =================================== */
 
 int hitungTotalStok(const vector<Barang>& daftarBarang, int indeksTerakhir) {
     if (indeksTerakhir < 0) return 0;
     return daftarBarang[indeksTerakhir].jumlahStok +
            hitungTotalStok(daftarBarang, indeksTerakhir - 1);
 }
 
 void tampilkanBarang(const vector<Barang>& daftarBarang) {
     cout << "\n==================== DAFTAR BARANG ANTIK ====================\n";
     cout << left << setw(10) << "Kode" << setw(20) << "Nama"
          << setw(10) << "Stok" << setw(15) << "Harga\n";
     cout << "-------------------------------------------------------------\n";
     for (const auto& barang : daftarBarang) {
         cout << left << setw(10) << barang.kodeBarang
              << setw(20) << barang.namaBarang
              << setw(10) << barang.jumlahStok
              << setw(15) << barang.hargaSatuan << '\n';
     }
 }
 
 void tampilkanBarang(const vector<Barang>& daftarBarang, const string& kodeBarangDicari) {
     for (const auto& barang : daftarBarang) {
         if (barang.kodeBarang == kodeBarangDicari) {
             cout << "\nBarang ditemukan:\n";
             cout << left << setw(10) << "Kode" << setw(20) << "Nama"
                  << setw(10) << "Stok" << setw(15) << "Harga\n";
             cout << left << setw(10) << barang.kodeBarang
                  << setw(20) << barang.namaBarang
                  << setw(10) << barang.jumlahStok
                  << setw(15) << barang.hargaSatuan << '\n';
             return;
         }
     }
     cout << "Barang tidak ditemukan.\n";
 }
 
 /* ----- Registrasi & Login ----- */
 void registrasi(vector<Pengguna>& daftarPengguna) {
     Pengguna penggunaBaru;
     cout << "\nREGISTRASI\n";
     cout << "Masukkan Nama        : "; cin.ignore(); getline(cin, penggunaBaru.namaPengguna);
     cout << "Masukkan NIM         : "; cin >> penggunaBaru.nimPengguna;
     cout << "Masukkan Kata Sandi  : "; cin >> penggunaBaru.kataSandi;
     daftarPengguna.push_back(penggunaBaru);
     cout << "Registrasi berhasil! Silakan login.\n";
 }
 
 bool login(const vector<Pengguna>& daftarPengguna, Pengguna& penggunaAktif) {
     string namaInput, nimInput, sandiInput;
     int percobaanLogin = 0;
 
     while (percobaanLogin < 3) {
         cout << "\nLOGIN\n";
         cout << "Masukkan Nama        : "; cin.ignore(); getline(cin, namaInput);
         cout << "Masukkan NIM         : "; cin >> nimInput;
         cout << "Masukkan Kata Sandi  : "; cin >> sandiInput;
 
         for (const auto& user : daftarPengguna) {
             if (user.namaPengguna == namaInput && user.nimPengguna == nimInput
                 && user.kataSandi == sandiInput) {
                 penggunaAktif = user;
                 cout << "Login berhasil!\n";
                 return true;
             }
         }
         cout << "Login gagal! Coba lagi.\n";
         ++percobaanLogin;
     }
     cout << "Anda telah mencoba 3 kali. Silakan tunggu beberapa saat.\n";
     return false;
 }
 
 /* ----- CRUD BARANG (versi referensi lama) ----- */
 void tambahBarang(vector<Barang>& daftarBarang) {
     Barang barangBaru;
     cout << "Masukkan Kode Barang : "; cin >> barangBaru.kodeBarang;
     cout << "Masukkan Nama Barang : "; cin.ignore(); getline(cin, barangBaru.namaBarang);
     cout << "Masukkan Jumlah Stok : "; cin >> barangBaru.jumlahStok;
     cout << "Masukkan Harga       : "; cin >> barangBaru.hargaSatuan;
     daftarBarang.push_back(barangBaru);
     cout << "Barang berhasil ditambahkan!\n";
 }
 
 void editBarang(vector<Barang>& daftarBarang) {
     string kodeBarangDipilih;
     cout << "Masukkan Kode Barang yang ingin diedit: "; cin >> kodeBarangDipilih;
 
     for (auto& barang : daftarBarang) {
         if (barang.kodeBarang == kodeBarangDipilih) {
             cout << "Masukkan Nama Baru   : "; cin.ignore(); getline(cin, barang.namaBarang);
             cout << "Masukkan Stok Baru   : "; cin >> barang.jumlahStok;
             cout << "Masukkan Harga Baru  : "; cin >> barang.hargaSatuan;
             cout << "Barang berhasil diperbarui!\n";
             return;
         }
     }
     cout << "Barang tidak ditemukan!\n";
 }
 
 void hapusBarang(vector<Barang>& daftarBarang) {
     string kodeBarangDipilih;
     cout << "Masukkan Kode Barang yang ingin dihapus: "; cin >> kodeBarangDipilih;
 
     for (size_t indeks = 0; indeks < daftarBarang.size(); ++indeks) {
         if (daftarBarang[indeks].kodeBarang == kodeBarangDipilih) {
             daftarBarang.erase(daftarBarang.begin() + static_cast<long>(indeks));
             cout << "Barang berhasil dihapus!\n";
             return;
         }
     }
     cout << "Barang tidak ditemukan!\n";
 }
 
 /* ---------- FUNGSI BARU BERBASIS POINTER ---------- */
 
 // parameter address‑of: menerima ALAMAT vector
 void tambahBarangPointer(vector<Barang>* alamatDaftarBarang) {
     Barang barangBaru;
     cout << "Masukkan Kode Barang : "; cin >> barangBaru.kodeBarang;
     cout << "Masukkan Nama Barang : "; cin.ignore(); getline(cin, barangBaru.namaBarang);
     cout << "Masukkan Jumlah Stok : "; cin >> barangBaru.jumlahStok;
     cout << "Masukkan Harga       : "; cin >> barangBaru.hargaSatuan;
     alamatDaftarBarang->push_back(barangBaru);   // akses via ->
     cout << "Barang berhasil ditambahkan (via pointer)!\n";
 }
 
 // parameter dereference: hasil disimpan lewat *aset
 void totalAsetPointer(const vector<Barang>& daftarBarang, double* aset) {
     double nilaiTotal = 0.0;
     for (const auto& barang : daftarBarang) {
         nilaiTotal += barang.hargaSatuan * barang.jumlahStok;
     }
     *aset = nilaiTotal;   // kembalikan melalui pointer
 }
 
 /* ================== MAIN ================== */
 int main() {
     vector<Pengguna> daftarPengguna;
     vector<Barang> daftarBarang;
     Pengguna penggunaAktif;
 
     int pilihanMenuAwal;
 
     while (true) {
         cout << "\n========== MENU AWAL ==========\n";
         cout << "1. Registrasi\n2. Login\n3. Keluar\n";
         cout << "Pilih menu: "; cin >> pilihanMenuAwal;
 
         switch (pilihanMenuAwal) {
             case 1:
                 registrasi(daftarPengguna);
                 break;
 
             case 2:
                 if (login(daftarPengguna, penggunaAktif)) {
                     int pilihanMenuUtama;
                     do {
                         cout << "\n===== TOKO BARANG ANTIK =====\n";
                         cout << "1. Tambah Barang (referensi)\n";
                         cout << "2. Edit Barang\n";
                         cout << "3. Hapus Barang\n";
                         cout << "4. Tampilkan Semua Barang\n";
                         cout << "5. Tampilkan Barang (berdasarkan kode)\n";
                         cout << "6. Hitung Total Stok (rekursif)\n";
                         cout << "7. Tambah Barang (via pointer)\n";
                         cout << "8. Hitung Total Nilai Aset (via pointer)\n";
                         cout << "9. Logout\n";
                         cout << "Pilih menu: "; cin >> pilihanMenuUtama;
 
                         switch (pilihanMenuUtama) {
                             case 1: tambahBarang(daftarBarang); break;
                             case 2: editBarang(daftarBarang); break;
                             case 3: hapusBarang(daftarBarang); break;
                             case 4: tampilkanBarang(daftarBarang); break;
                             case 5: {
                                 string kodeInput;
                                 cout << "Masukkan Kode Barang: "; cin >> kodeInput;
                                 tampilkanBarang(daftarBarang, kodeInput);
                                 break;
                             }
                             case 6:
                                 cout << "Total stok semua barang: "
                                      << hitungTotalStok(daftarBarang,
                                                          static_cast<int>(daftarBarang.size()) - 1)
                                      << '\n';
                                 break;
                             case 7:
                                 tambahBarangPointer(&daftarBarang);
                                 break;
                             case 8: {
                                 double totalNilaiAset = 0.0;
                                 totalAsetPointer(daftarBarang, &totalNilaiAset);
                                 cout << "Total nilai aset (stok × harga): " << totalNilaiAset << '\n';
                                 break;
                             }
                             case 9:
                                 cout << "Logout berhasil.\n";
                                 break;
                             default:
                                 cout << "Pilihan tidak valid!\n";
                         }
                     } while (pilihanMenuUtama != 9);
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
 