#include <iostream>
#include <iomanip> 
#include <string>
using namespace std;

#define MAX_BUNGA 100  
#define INFO 3  

string bunga[MAX_BUNGA][INFO] = {
    {"Mawar", "15000", "20"},
    {"Tulip", "20000", "15"},
    {"Melati", "10000", "30"},
    {"Lily", "25000", "10"}
};
int jumlahBunga = 4;

bool login() {
    string nama, nim;
    int kesempatan = 3;

    cout << "========================================\n";
    cout << "   Selamat Datang di Fresh Flower  \n";
    cout << "========================================\n";

    while (kesempatan > 0) {
        cout << "Masukkan Nama: ";
        getline(cin,nama);
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (nama == "niluu" && nim == "012") {
            return true;
        } else {
            kesempatan--;
            cout << "Login gagal! Kesempatan tersisa: " << kesempatan << endl;
        }
    }
    return false;
}

int tampilkanBunga() {
    if (jumlahBunga == 0) {
        cout << "Tidak ada bunga dalam daftar.\n";
        return 0;
    }

    cout << "=====================================================\n";
    cout << "| No | Nama Bunga       |  Harga   |  Stok          |\n";
    cout << "=====================================================\n";

    for (int i = 0; i < jumlahBunga; i++) {
        cout << "| " << setw(2) << i + 1 
            << " | " << left << setw(16) << bunga[i][0] 
            << " | " << right << setw(8) << bunga[i][1] 
            << " | " << setw(6) << bunga[i][2] << " |\n";
    }

    cout << "=====================================================\n";
    return jumlahBunga; 
}

int tambahBunga() {
    if (jumlahBunga < MAX_BUNGA) {
        cin.ignore();  
        cout << "Masukkan Nama Bunga: ";
        getline(cin, bunga[jumlahBunga][0]);

        cout << "Masukkan Harga Bunga/tangkai: ";
        cin >> bunga[jumlahBunga][1];

        cout << "Masukkan Stok Bunga: ";
        cin >> bunga[jumlahBunga][2];

        jumlahBunga++;
        cout << "Bunga berhasil ditambahkan!\n";
        return jumlahBunga;
    } else {
        cout << "Kapasitas bunga penuh!\n";
        return -1;
    }
}

int ubahBunga() {
    if (jumlahBunga == 0) {
        cout << "Belum ada bunga untuk diubah.\n";
        return 0;
    }

    tampilkanBunga();
    int index;
    cout << "Masukkan nomor bunga yang ingin diubah: ";
    cin >> index;
    
    if (index > 0 && index <= jumlahBunga) {
        index--;  
        cin.ignore();
        cout << "Masukkan Nama Baru: ";
        getline(cin, bunga[index][0]);

        cout << "Masukkan Harga Baru: ";
        cin >> bunga[index][1];

        cout << "Masukkan Stok Baru: ";
        cin >> bunga[index][2];

        cout << "Bunga berhasil diperbarui!\n";
        return 1;
    } else {
        cout << "Nomor bunga tidak valid!\n";
        return -1;
    }
}

int hapusBunga() {
    if (jumlahBunga == 0) {
        cout << "Belum ada bunga untuk dihapus.\n";
        return 0;
    }

    tampilkanBunga();
    int index;
    cout << "Masukkan nomor bunga yang ingin dihapus: ";
    cin >> index;

    if (index > 0 && index <= jumlahBunga) {
        index--;  
        for (int i = index; i < jumlahBunga - 1; i++) {
            bunga[i][0] = bunga[i + 1][0];
            bunga[i][1] = bunga[i + 1][1];
            bunga[i][2] = bunga[i + 1][2];
        }
        jumlahBunga--;
        cout << "Bunga berhasil dihapus!\n";
        return 1;
    } else {
        cout << "Nomor bunga tidak valid!\n";
        return -1;
    }
}

int main() {
    if (!login()) {
        cout << "Login gagal 3 kali. Program berhenti.\n";
        return 0;
    }

    int pilihan;
    do {
        cout << "\n===== Menu Fresh Flower =====\n";
        cout << "1. Tampilkan Daftar Bunga\n";
        cout << "2. Tambah Bunga\n";
        cout << "3. Ubah Bunga\n";
        cout << "4. Hapus Bunga\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanBunga();
                break;
            case 2:
                tambahBunga();
                break;
            case 3:
                ubahBunga();
                break;
            case 4:
                hapusBunga();
                break;
            case 5:
                cout << "Terima kasih telah menggunakan sistem!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
