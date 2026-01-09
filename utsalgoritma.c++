#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// 1. Menggunakan struct untuk menyimpan data Pegawai
struct Pegawai {
    string nama;
    int jamKerja;
    int honorHarian = 25000;
    int honorLembur;
    int totalGaji;
};

// 2. Menggunakan class untuk menghitung gaji
class KalkulatorGaji {
public:
    void hitung(Pegawai &p) {
        int jamNormal = 8;
        if (p.jamKerja > jamNormal) {
            int kelebihanJam = p.jamKerja - jamNormal;
            p.honorLembur = kelebihanJam * 1500;
        } else {
            p.honorLembur = 0;
        }
        p.totalGaji = p.honorHarian + p.honorLembur;
    }
};

int main() {
    int jumlah;
    KalkulatorGaji kalkulator;

    cout << "PT. Meriang Gembira" << endl;
    cout << "Masukkan jumlah pegawai: ";
    cin >> jumlah;

    // 3. Menggunakan pointer untuk menyimpan data array dinamis
    Pegawai *daftarPegawai = new Pegawai[jumlah];

    // Input Data
    for (int i = 0; i < jumlah; i++) {
        cout << "\nPegawai ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin.ignore();
        getline(cin, daftarPegawai[i].nama);
        cout << "Jam Kerja: ";
        cin >> daftarPegawai[i].jamKerja;

        // Hitung gaji menggunakan class
        kalkulator.hitung(daftarPegawai[i]);
    }

    // Output Laporan (Tabel)
    cout << "\nPT. Meriang Gembira" << endl;
    cout << "Tanggal : 12 Januari 2026" << endl;
    cout << "======================================================================" << endl;
    cout << left << setw(4) << "No." 
         << setw(15) << "Nama" 
         << setw(12) << "Honor" 
         << setw(12) << "Jam Kerja" 
         << setw(15) << "Honor Lembur" 
         << "Total" << endl;
    cout << "======================================================================" << endl;

    long totalSeluruhHonor = 0;
    for (int i = 0; i < jumlah; i++) {
        cout << left << setw(4) << i + 1
             << setw(15) << daftarPegawai[i].nama
             << setw(12) << daftarPegawai[i].honorHarian
             << setw(12) << daftarPegawai[i].jamKerja
             << setw(15) << daftarPegawai[i].honorLembur
             << daftarPegawai[i].totalGaji << endl;
        totalSeluruhHonor += daftarPegawai[i].totalGaji;
    }

    cout << "======================================================================" << endl;
    cout << "Total Honor Pegawai Sebesar : Rp " << totalSeluruhHonor << endl;

    // Menghapus alokasi memori pointer
    delete[] daftarPegawai;

    return 0;
}