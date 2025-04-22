#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct User {
    string nama;
    string nim;
};

struct Bunga {
    string nama;
    float harga;
    int stok;
};

struct Transaksi {
    User user;
    Bunga bunga;
    int jumlah;
};

User users[10];
Bunga daftarBunga[10] = {
    {"Mawar", 15000, 10},
    {"Melati", 12000, 8},
    {"Tulip", 25000, 5},
    {"Anggrek", 20000, 7}
};
Transaksi transaksi[100];

int jumlahUser = 0, jumlahBunga = 4, jumlahTransaksi = 0;

void tampilkanBunga(Bunga bunga) {
    cout << left << setw(20) << bunga.nama
         << setw(15) << bunga.harga
         << setw(10) << bunga.stok << endl;
}

void tampilkanBunga(Bunga daftar[], int jumlah) {
    cout << left << setw(5) << "No"
         << setw(20) << "Nama Bunga"
         << setw(15) << "Harga"
         << setw(10) << "Stok" << endl;
    cout << string(50, '-') << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << left << setw(5) << i + 1;
        tampilkanBunga(daftar[i]);
    }
}

void tambahBunga(Bunga daftar[], int &jumlah) {
    if (jumlah < 10) {
        cout << "Masukkan Nama Bunga: ";
        getline(cin, daftar[jumlah].nama);
        cout << "Masukkan Harga: ";
        cin >> daftar[jumlah].harga;
        cout << "Masukkan Stok: ";
        cin >> daftar[jumlah].stok;
        cin.ignore();
        jumlah++;
        cout << "Bunga Berhasil Ditambahkan!\n";
    } else {
        cout << "Daftar bunga penuh!\n";
    }
}

void hapusBunga(Bunga daftar[], int &jumlah) {
    int hapus;
    cout << "Masukkan nomor bunga yang akan dihapus: ";
    cin >> hapus;
    if (hapus >= 1 && hapus <= jumlah) {
        for (int i = hapus - 1; i < jumlah - 1; i++) {
            daftar[i] = daftar[i + 1];
        }
        jumlah--;
        cout << "Bunga berhasil dihapus!\n";
    } else {
        cout << "Nomor tidak valid!\n";
    }
}

void ubahBunga(Bunga daftar[], int jumlah) {
    int ubah;
    cout << "Masukkan nomor bunga yang akan diubah: ";
    cin >> ubah;
    cin.ignore();
    if (ubah >= 1 && ubah <= jumlah) {
        cout << "Masukkan Nama Baru: ";
        getline(cin, daftar[ubah - 1].nama);
        cout << "Masukkan Harga Baru: ";
        cin >> daftar[ubah - 1].harga;
        cout << "Masukkan Stok Baru: ";
        cin >> daftar[ubah - 1].stok;
        cin.ignore();
        cout << "Bunga Berhasil Diubah!\n";
    } else {
        cout << "Nomor tidak valid!\n";
    }
}

// Fungsi menggunakan parameter dengan address-of
void tambahStokBunga(Bunga* bunga) {
    int tambah;
    cout << "Masukkan jumlah stok yang ingin ditambahkan: ";
    cin >> tambah;
    bunga->stok += tambah;
    cout << "Stok bunga berhasil ditambahkan. Stok sekarang: " << bunga->stok << endl;
}

// Fungsi menggunakan parameter dengan dereference
void cetakTransaksi(Transaksi* t, int jumlah) {
    cout << "\n===== DAFTAR TRANSAKSI =====\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". "
             << "Nama: " << (t + i)->user.nama << ", "
             << "Bunga: " << (t + i)->bunga.nama << ", "
             << "Jumlah: " << (t + i)->jumlah << endl;
    }
}

// Fungsi login rekursif
bool login(User &userLogin, int attempts = 0) {
    if (attempts >= 3) {
        cout << "Gagal login 3 kali. Program berhenti.\n";
        return false;
    }

    string nama, nim;
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);

    if (nama == "nilu" && nim == "012") {
        userLogin.nama = nama;
        userLogin.nim = nim;
        cout << "Login Admin Berhasil!\n";
        return true;
    }

    for (int i = 0; i < jumlahUser; i++) {
        if (users[i].nama == nama && users[i].nim == nim) {
            userLogin = users[i];
            cout << "Login Berhasil!\n";
            return true;
        }
    }

    cout << "Login Gagal! Sisa percobaan: " << (2 - attempts) << "\n";
    return login(userLogin, attempts + 1);
}

void menuAdmin(Bunga daftar[], int &jumlah) {
    int pilihan;
    while (true) {
        cout << "\n===== MENU ADMIN =====\n";
        cout << "1. Tampilkan Bunga\n2. Tambah Bunga\n3. Hapus Bunga\n4. Ubah Bunga\n";
        cout << "5. Logout\n6. Tambah Stok Bunga (pointer)\n7. Lihat Transaksi (pointer)\nPilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) tampilkanBunga(daftar, jumlah);
        else if (pilihan == 2) tambahBunga(daftar, jumlah);
        else if (pilihan == 3) hapusBunga(daftar, jumlah);
        else if (pilihan == 4) ubahBunga(daftar, jumlah);
        else if (pilihan == 5) {
            cout << "Logout berhasil!\n";
            break;
        } else if (pilihan == 6) {
            tampilkanBunga(daftar, jumlah);
            int index;
            cout << "Pilih nomor bunga untuk tambah stok: ";
            cin >> index;
            cin.ignore();
            if (index >= 1 && index <= jumlah) {
                tambahStokBunga(&daftar[index - 1]);
            } else {
                cout << "Nomor tidak valid!\n";
            }
        } else if (pilihan == 7) {
            cetakTransaksi(transaksi, jumlahTransaksi);
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }
}

void menuUser(User user, Bunga daftar[], int &jumlah, Transaksi transaksi[], int &jumlahTransaksi) {
    int pilihan;
    while (true) {
        cout << "\n===== MENU USER =====\n";
        cout << "1. Tampilkan Bunga\n2. Beli Bunga\n3. Logout\nPilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            tampilkanBunga(daftar, jumlah);
        } else if (pilihan == 2) {
            tampilkanBunga(daftar, jumlah);
            int bungaIndex, jumlahBeli;
            cout << "Masukkan nomor bunga yang ingin dibeli: ";
            cin >> bungaIndex;
            cout << "Masukkan jumlah: ";
            cin >> jumlahBeli;
            cin.ignore();

            if (bungaIndex < 1 || bungaIndex > jumlah || jumlahBeli > daftar[bungaIndex - 1].stok) {
                cout << "Data tidak valid atau stok tidak mencukupi!\n";
                continue;
            }

            daftar[bungaIndex - 1].stok -= jumlahBeli;
            transaksi[jumlahTransaksi++] = {user, daftar[bungaIndex - 1], jumlahBeli};
            cout << "Pembelian berhasil!\n";
        } else if (pilihan == 3) {
            cout << "Logout berhasil!\n";
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }
}

int main() {
    int pilihan;

    while (true) {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Register\n2. Login\n3. Keluar\nPilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            if (jumlahUser < 10) {
                cout << "Masukkan Nama: ";
                getline(cin, users[jumlahUser].nama);
                cout << "Masukkan NIM: ";
                getline(cin, users[jumlahUser].nim);
                jumlahUser++;
                cout << "Registrasi Berhasil!\n";
            } else {
                cout << "User penuh!\n";
            }
        } else if (pilihan == 2) {
            User currentUser;
            if (login(currentUser)) {
                if (currentUser.nama == "nilu") {
                    menuAdmin(daftarBunga, jumlahBunga);
                } else {
                    menuUser(currentUser, daftarBunga, jumlahBunga, transaksi, jumlahTransaksi);
                }
            } else {
                break;
            }
        } else if (pilihan == 3) {
            cout << "Terima kasih telah menggunakan program ini.\n";
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}