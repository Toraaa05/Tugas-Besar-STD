// Program utama untuk mengelola hubungan antara Guru dan Murid

#include "MLL.h"
#include <iostream>

using namespace std;

int main() {
    // Initial state
    // ListGuru G dan ListMurid M kosong.
    ListGuru G;
    ListMurid M;

    createListGuru(G); // Membuat list Guru kosong
    createListMurid(M); // Membuat list Murid kosong

    int pilihan;
    string namaGuru, namaMurid;

    do {
        // Menampilkan menu utama
        cout << "\n=== Menu ===" << endl;
        cout << "1. Tambah Guru" << endl;
        cout << "2. Tampilkan Guru" << endl;
        cout << "3. Tambah Murid" << endl;
        cout << "4. Hubungkan Guru dan Murid" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama Guru: ";
                cin >> namaGuru;
                insertGuru(G, createGuru(namaGuru)); // Menambahkan Guru ke dalam list
                break;

            case 2:
                showGuru(G); // Menampilkan semua Guru yang ada di list
                break;

            case 3:
                cout << "Masukkan nama Murid: ";
                cin >> namaMurid;
                insertMurid(M, createMurid(namaMurid)); // Menambahkan Murid ke dalam list
                break;

            case 4:
                cout << "Masukkan nama Guru: ";
                cin >> namaGuru;
                cout << "Masukkan nama Murid: ";
                cin >> namaMurid;
                menghubungkanGuruMurid(G, M, namaGuru, namaMurid); // Menghubungkan Guru dengan Murid
                break;

            case 5:
                cout << "Keluar program." << endl; // Keluar dari program
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    // Final state
    // Semua data Guru dan Murid disimpan dalam struktur multi-linked list.
    return 0;
}
