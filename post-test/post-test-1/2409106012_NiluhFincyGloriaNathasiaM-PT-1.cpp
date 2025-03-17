#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

int main(){
    string satuan[] = {"mi", "m", "cm", "ft"};
    string awal, akhir, nama, nim;
    int posisi_awal = -1, posisi_akhir = -1;
    double angka, hasil;
    double faktor_konversi[4][4] = {
        {1, 1609, 160900, 5280},             // mi ke mi, m, cm, ft
        {1.0/1609, 1, 100, 3.281},           // m ke mi, m, cm, ft
        {1.0/160900, 1.0/100, 1, 1.0/30.48}, // cm ke mi, m, cm, ft
        {1.0/5280, 1.0/3.281, 30.48, 1}      // ft ke mi, m, cm, ft
    };

    int percobaan = 0;
    while (percobaan < 3) {
        cout << "========================================\n";
        cout << "            LOGIN SISTEM\n";
        cout << "========================================\n";
        cout << "Masukkan Nama : "; getline(cin, nama);
        cout << "Masukkan NIM  : "; getline(cin, nim);
        
        if (nama == "Niluh Fincy Gloria Nathasia M" && nim == "2409106012") {
            system("cls");
            break;
        }
        
        cout << "Nama atau NIM salah! Coba lagi.\n";
        percobaan++;
        
        if (percobaan == 3) {
            cout << "Percobaan lebih dari 3 kali. Program berhenti.\n";
            return 1;
        }
    }

    char lanjut;
    do {
        cout << "========================================\n";
        cout << "         KONVERSI SATUAN PANJANG\n";
        cout << "========================================\n";
        cout << "Masukkan satuan awal  (mi/m/cm/ft): "; cin >> awal;
        cout << "Masukkan angka   : "; cin >> angka;
        cout << "Masukkan satuan akhir (mi/m/cm/ft): "; cin >> akhir;
        cout << "----------------------------------------\n";

        posisi_awal = -1;
        posisi_akhir = -1;

        for(int i = 0; i < 4; i++){
            if(awal == satuan[i]) posisi_awal = i;
            if(akhir == satuan[i]) posisi_akhir = i;
        }

        if(posisi_awal == -1 || posisi_akhir == -1){
            cout << "gak ada satuan itu, pastikan cuma pakai: (mi/m/cm/ft)\n";
        } else {
            hasil = angka * faktor_konversi[posisi_awal][posisi_akhir];
            cout << angka << " " << awal << " = " << hasil << " " << akhir << endl;
        }

        cout << "\n lanjut konversi gak? (y/n): "; cin >> lanjut;
        cin.ignore();
        system("cls");
    } while (lanjut == 'y' || lanjut == 'Y');

    cout << "program selesai\n";
    return 0;
}