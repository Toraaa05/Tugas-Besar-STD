#include "MLL.h"

// Inisialisasi list Guru
void createListGuru(ListGuru &G) {
    G.First = Nil;
}

// Inisialisasi list Murid
void createListMurid(ListMurid &M) {
    M.First = Nil;
}

// Membuat node Guru baru
adrPr createGuru(string namaGuru) {
    adrPr P = new elmPr;
    P->namaGuru = namaGuru;
    P->FirstCh = Nil; // Belum ada murid yang dihubungkan
    P->nextPr = Nil;  // Node berikutnya kosong
    return P;
}

// Membuat node Murid baru
adrCh createMurid(string namaMurid) {
    adrCh P = new elmCh;
    P->namaMurid = namaMurid;
    P->nextCh = Nil; // Node berikutnya kosong
    return P;
}

// Menambahkan Guru ke dalam list Guru
void insertGuru(ListGuru &G, adrPr P) {
    P->nextPr = G.First; // Hubungkan node baru ke awal list
    G.First = P;         // Perbarui pointer head
}

// Menambahkan Murid ke dalam list Murid
void insertMurid(ListMurid &M, adrCh P) {
    P->nextCh = M.First; // Hubungkan node baru ke awal list
    M.First = P;         // Perbarui pointer head
}

// Mencari Guru berdasarkan nama
adrPr cariGuru(const ListGuru &G, string namaGuru) {
    adrPr P = G.First;
    while (P != Nil && P->namaGuru != namaGuru) {
        P = P->nextPr;
    }
    return P; // Kembalikan node Guru atau Nil jika tidak ditemukan
}

// Mencari Murid berdasarkan nama
adrCh cariMurid(const ListMurid &M, string namaMurid) {
    adrCh P = M.First;
    while (P != Nil && P->namaMurid != namaMurid) {
        P = P->nextCh;
    }
    return P; // Kembalikan node Murid atau Nil jika tidak ditemukan
}

// Menampilkan semua Guru dalam list
void showGuru(const ListGuru &G) {
    adrPr P = G.First;
    while (P != Nil) {
        cout << "Guru: " << P->namaGuru << endl;

        // Menampilkan murid-murid yang terhubung
        adrCh murid = P->FirstCh;
        if (murid != Nil) {
            cout << "  Murid: ";
            while (murid != Nil) {
                cout << murid->namaMurid << (murid->nextCh != Nil ? ", " : "");
                murid = murid->nextCh;
            }
            cout << endl;
        } else {
            cout << "  Tidak ada murid yang terhubung." << endl;
        }

        P = P->nextPr;
    }
}

// Menghubungkan Guru dengan Murid
void menghubungkanGuruMurid(ListGuru &G, ListMurid &M, string namaGuru, string namaMurid) {
    adrPr guru = cariGuru(G, namaGuru); // Cari Guru
    adrCh murid = cariMurid(M, namaMurid); // Cari Murid

    if (guru != Nil && murid != Nil) {
        // Buat salinan murid untuk dimasukkan ke dalam list Guru
        adrCh relasi = new elmCh;
        relasi->namaMurid = murid->namaMurid;
        relasi->nextCh = guru->FirstCh; // Hubungkan ke murid pertama dari Guru
        guru->FirstCh = relasi;         // Perbarui murid pertama dari Guru
        cout << "Berhasil menghubungkan Guru " << namaGuru << " dengan Murid " << namaMurid << "." << endl;
    } else {
        cout << "Gagal menghubungkan. Pastikan nama Guru dan Murid benar." << endl;
    }
}
