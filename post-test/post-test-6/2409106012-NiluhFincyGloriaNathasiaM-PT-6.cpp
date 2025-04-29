#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
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

// Fungsi overloading
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

// 1. Metode sorting huruf secara descending (berdasarkan nama bunga)
void sortBungaByNameDesc(Bunga daftar[], int jumlah) {
    for (int i = 0; i < jumlah-1; i++) {
        for (int j = 0; j < jumlah-i-1; j++) {
            if (daftar[j].nama < daftar[j+1].nama) {
                Bunga temp = daftar[j];
                daftar[j] = daftar[j+1];
                daftar[j+1] = temp;
            }
        }
    }
    cout << "Daftar bunga setelah diurutkan berdasarkan nama (descending):\n";
    tampilkanBunga(daftar, jumlah);
}

// 2. Metode sorting angka secara ascending (berdasarkan harga bunga)
void sortBungaByPriceAsc(Bunga daftar[], int jumlah) {
    for (int i = 0; i < jumlah-1; i++) {
        for (int j = 0; j < jumlah-i-1; j++) {
            if (daftar[j].harga > daftar[j+1].harga) {
                Bunga temp = daftar[j];
                daftar[j] = daftar[j+1];
                daftar[j+1] = temp;
            }
        }
    }
    cout << "Daftar bunga setelah diurutkan berdasarkan harga (ascending):\n";
    tampilkanBunga(daftar, jumlah);
}

// 3. Metode insertion sort berdasarkan stok (descending)
void sortBungaByStockDesc(Bunga daftar[], int jumlah) {
    for (int i = 1; i < jumlah; i++) {
        Bunga key = daftar[i];
        int j = i - 1;
        
        while (j >= 0 && daftar[j].stok < key.stok) {
            daftar[j + 1] = daftar[j];
            j = j - 1;
        }
        daftar[j + 1] = key;
    }
    cout << "Daftar bunga setelah diurutkan berdasarkan stok (descending):\n";
    tampilkanBunga(daftar, jumlah);
}

// 4. Metode pencarian bunga berdasarkan nama (case insensitive)
void cariBungaByName(Bunga daftar[], int jumlah) {
    string keyword;
    cout << "Masukkan nama bunga yang dicari: ";
    getline(cin, keyword);
    
    bool found = false;
    for (int i = 0; i < jumlah; i++) {
        string namaBunga = daftar[i].nama;
        transform(namaBunga.begin(), namaBunga.end(), namaBunga.begin(), ::tolower);
        transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
        
        if (namaBunga.find(keyword) != string::npos) {
            if (!found) {
                cout << "Hasil pencarian:\n";
                cout << left << setw(5) << "No" << setw(20) << "Nama Bunga" 
                     << setw(15) << "Harga" << setw(10) << "Stok" << endl;
                cout << string(50, '-') << endl;
                found = true;
            }
            cout << left << setw(5) << i + 1;
            tampilkanBunga(daftar[i]);
        }
    }
    
    if (!found) {
        cout << "Bunga dengan nama '" << keyword << "' tidak ditemukan.\n";
    }
}

// Fungsi dengan parameter dereference (int*)
void tampilkanJumlahBunga(int *jumlah) {
    cout << "Jumlah jenis bunga saat ini: " << *jumlah << " jenis.\n";
}

// Fungsi dengan parameter address-of (Bunga*)
void tambahStok(Bunga *bunga, int tambahan) {
    bunga->stok += tambahan;
    cout << "Stok bunga " << bunga->nama << " ditambah menjadi " << bunga->stok << endl;
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

// Fungsi rekursif login
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
        cout << "1. Tampilkan Bunga\n2. Tambah Bunga\n3. Hapus Bunga\n"
             << "4. Ubah Bunga\n5. Sorting Nama (Desc)\n6. Sorting Harga (Asc)\n"
             << "7. Sorting Stok (Desc)\n8. Cari Bunga\n9. Logout\nPilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            tampilkanBunga(daftar, jumlah);
            tampilkanJumlahBunga(&jumlah);
        } else if (pilihan == 2) {
            tambahBunga(daftar, jumlah);
        } else if (pilihan == 3) {
            hapusBunga(daftar, jumlah);
        } else if (pilihan == 4) {
            ubahBunga(daftar, jumlah);
        } else if (pilihan == 5) {
            sortBungaByNameDesc(daftar, jumlah);
        } else if (pilihan == 6) {
            sortBungaByPriceAsc(daftar, jumlah);
        } else if (pilihan == 7) {
            sortBungaByStockDesc(daftar, jumlah);
        } else if (pilihan == 8) {
            cariBungaByName(daftar, jumlah);
        } else if (pilihan == 9) {
            cout << "Logout berhasil!\n";
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }
}

void menuUser(User user, Bunga daftar[], int &jumlah, Transaksi transaksi[], int &jumlahTransaksi) {
    int pilihan;
    while (true) {
        cout << "\n===== MENU USER =====\n";
        cout << "1. Tampilkan Bunga\n2. Beli Bunga\n3. Sorting Nama (Desc)\n"
             << "4. Sorting Harga (Asc)\n5. Sorting Stok (Desc)\n6. Cari Bunga\n7. Logout\nPilihan: ";
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
            sortBungaByNameDesc(daftar, jumlah);
        } else if (pilihan == 4) {
            sortBungaByPriceAsc(daftar, jumlah);
        } else if (pilihan == 5) {
            sortBungaByStockDesc(daftar, jumlah);
        } else if (pilihan == 6) {
            cariBungaByName(daftar, jumlah);
        } else if (pilihan == 7) {
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