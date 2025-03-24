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

int main() {
    int pilihan;
    string nama, nim;
    int userIndex = -1;

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
            int attempts = 0;
            int maxAttempts = 3;

            while (attempts < maxAttempts) {
                cout << "Masukkan Nama: ";
                getline(cin, nama);
                cout << "Masukkan NIM: ";
                getline(cin, nim);

                if (nama == "nilu" && nim == "012") {
                    cout << "Login Admin Berhasil!\n";
                    while (true) {
                        cout << "\n===== MENU ADMIN =====\n";
                        cout << "1. Tampilkan Bunga\n2. Tambah Bunga\n3. Hapus Bunga\n4. Ubah Bunga\n5. Logout\nPilihan: ";
                        cin >> pilihan;
                        cin.ignore();

                        if (pilihan == 1) {
                            cout << "\n===== DAFTAR BUNGA =====\n";
                            cout << left << setw(5) << "No" << setw(20) << "Nama Bunga" << setw(15) << "Harga" << setw(10) << "Stok" << endl;
                            cout << string(50, '-') << endl;
                            for (int i = 0; i < jumlahBunga; i++) {
                                cout << left << setw(5) << i + 1 << setw(20) << daftarBunga[i].nama << setw(15) << daftarBunga[i].harga << setw(10) << daftarBunga[i].stok << endl;
                            }
                        } else if (pilihan == 2) {
                            if (jumlahBunga < 10) {
                                cout << "Masukkan Nama Bunga: ";
                                getline(cin, daftarBunga[jumlahBunga].nama);
                                cout << "Masukkan Harga: ";
                                cin >> daftarBunga[jumlahBunga].harga;
                                cout << "Masukkan Stok: ";
                                cin >> daftarBunga[jumlahBunga].stok;
                                cin.ignore();
                                jumlahBunga++;
                                cout << "Bunga Berhasil Ditambahkan!\n";
                            } else {
                                cout << "Daftar bunga penuh!\n";
                            }
                        } else if (pilihan == 3) {
                            int hapus;
                            cout << "Masukkan nomor bunga yang akan dihapus: ";
                            cin >> hapus;
                            if (hapus >= 1 && hapus <= jumlahBunga) {
                                for (int i = hapus - 1; i < jumlahBunga - 1; i++) {
                                    daftarBunga[i] = daftarBunga[i + 1];
                                }
                                jumlahBunga--;
                                cout << "Bunga berhasil dihapus!\n";
                            } else {
                                cout << "Nomor tidak valid!\n";
                            }
                        } else if (pilihan == 4) {
                            int ubah;
                            cout << "Masukkan nomor bunga yang akan diubah: ";
                            cin >> ubah;
                            cin.ignore();
                            if (ubah >= 1 && ubah <= jumlahBunga) {
                                cout << "Masukkan Nama Baru: ";
                                getline(cin, daftarBunga[ubah - 1].nama);
                                cout << "Masukkan Harga Baru: ";
                                cin >> daftarBunga[ubah - 1].harga;
                                cout << "Masukkan Stok Baru: ";
                                cin >> daftarBunga[ubah - 1].stok;
                                cin.ignore();
                                cout << "Bunga Berhasil Diubah!\n";
                            } else {
                                cout << "Nomor tidak valid!\n";
                            }
                        } else if (pilihan == 5) {
                            cout << "Logout berhasil! Kembali ke menu utama.\n";
                            break;
                        }
                    }
                    break;
                }

                for (int i = 0; i < jumlahUser; i++) {
                    if (users[i].nama == nama && users[i].nim == nim) {
                        userIndex = i;
                        cout << "Login Berhasil!\n";
                        char kembaliKeMenuUtama = 'N';
                        while (kembaliKeMenuUtama == 'N') {
                            cout << "\n===== MENU USER =====\n";
                            cout << "1. Tampilkan Bunga\n2. Beli Bunga\n3. Logout\nPilihan: ";
                            cin >> pilihan;
                            cin.ignore();
                            if (pilihan == 1) {
                                cout << "\n===== DAFTAR BUNGA =====\n";
                                cout << left << setw(5) << "No" << setw(20) << "Nama Bunga" << setw(15) << "Harga" << setw(10) << "Stok" << endl;
                                cout << string(50, '-') << endl;
                                for (int i = 0; i < jumlahBunga; i++) {
                                    cout << left << setw(5) << i + 1 << setw(20) << daftarBunga[i].nama << setw(15) << daftarBunga[i].harga << setw(10) << daftarBunga[i].stok << endl;
                                }
                            } else if (pilihan == 2) {
                                cout << "\n===== DAFTAR BUNGA =====\n";
                                cout << left << setw(5) << "No" << setw(20) << "Nama Bunga" << setw(15) << "Harga" << setw(10) << "Stok" << endl;
                                cout << string(50, '-') << endl;
                                for (int i = 0; i < jumlahBunga; i++) {
                                    cout << left << setw(5) << i + 1 << setw(20) << daftarBunga[i].nama << setw(15) << daftarBunga[i].harga << setw(10) << daftarBunga[i].stok << endl;
                                }
                                int bungaIndex, jumlahBeli;
                                cout << "\nMasukkan nomor bunga yang ingin dibeli: ";
                                cin >> bungaIndex;
                                if (bungaIndex < 1 || bungaIndex > jumlahBunga) {
                                    cout << "Nomor bunga tidak valid!\n";
                                    continue;
                                }
                                cout << "Masukkan jumlah yang ingin dibeli: ";
                                cin >> jumlahBeli;
                                if (jumlahBeli < 1 || jumlahBeli > daftarBunga[bungaIndex - 1].stok) {
                                    cout << "Jumlah tidak valid atau stok tidak mencukupi!\n";
                                    continue;
                                }
                                daftarBunga[bungaIndex - 1].stok -= jumlahBeli;
                                transaksi[jumlahTransaksi].user = users[userIndex];
                                transaksi[jumlahTransaksi].bunga = daftarBunga[bungaIndex - 1];
                                transaksi[jumlahTransaksi].jumlah = jumlahBeli;
                                jumlahTransaksi++;
                                cout << "Pembelian berhasil!\n";
                            }   else if (pilihan == 3) {
                                cout << "Logout berhasil!\n";
                                userIndex = -1;
                                break;
                            } else {
                                cout << "Pilihan tidak valid!\n";
                            }
                        }
                        return 1;
                    }
                }
                attempts++;
                cout << "Login Gagal! Sisa percobaan: " << (maxAttempts - attempts) << "\n";
            }
        } else if (pilihan == 3) {
            return 0;
        }
    }
}