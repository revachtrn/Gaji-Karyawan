#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

int main() {
    string nama, divisi, periodeGaji;
    int jamKerja;
    double tarifPerJam, uangLembur, potonganBPJS;

    cout << "====================================" << endl;
    cout << "        Program Gaji Karyawan       " << endl;
    cout << "====================================" << endl;
    cout << "Masukkan nama karyawan: ";
    cin >> nama; 
    cout << "Masukkan divisi karyawan: ";
    cin >> divisi; 
    cout << "Masukkan periode gaji : ";
    cin.ignore();
    getline(cin, periodeGaji);

    cout << "Masukkan jumlah jam kerja: ";
    cin >> jamKerja;

    if (jamKerja < 0) {
        cout << "Error: Jam kerja tidak boleh negatif." << endl;
        return 1; 
    }

    cout << "Masukkan tarif per jam: ";
    cin >> tarifPerJam;

    if (tarifPerJam < 0) {
        cout << "Error: Tarif per jam tidak boleh negatif." << endl;
        return 1; 
    }

    cout << "Masukkan uang lembur per jam: ";
    cin >> uangLembur;

    if (uangLembur < 0) {
        cout << "Error: Uang lembur tidak boleh negatif." << endl;
        return 1; 
    }

    cout << "Masukkan potongan BPJS: ";
    cin >> potonganBPJS;

    if (potonganBPJS < 0) {
        cout << "Error: Potongan BPJS tidak boleh negatif." << endl;
        return 1; 
    }

    double gajiPokok = 0.0;
    double gajiLembur = 0.0;
    double totalGaji = 0.0;
    double pajak = 0.0;

    if (jamKerja > 40) {
        int jamLembur = jamKerja - 40;
        gajiPokok = 40 * tarifPerJam;
        gajiLembur = jamLembur * uangLembur;
        totalGaji = gajiPokok + gajiLembur;
        cout << "\nKaryawan bekerja lembur." << endl;
        cout << "Jam kerja lembur: " << jamLembur << " jam." << endl;
    } else if (jamKerja == 40) {
        gajiPokok = jamKerja * tarifPerJam;
        totalGaji = gajiPokok;
        cout << "\nKaryawan bekerja tepat 40 jam, tidak ada lembur." << endl;
    } else {
        gajiPokok = jamKerja * tarifPerJam;
        totalGaji = gajiPokok;
        cout << "\nKaryawan bekerja kurang dari 40 jam." << endl;
    }

    pajak = 0.05 * totalGaji;
    totalGaji -= pajak;
    totalGaji -= potonganBPJS;

    const double UMR = 3000000.0;
    if (totalGaji > UMR) {
        cout << "\nGaji karyawan lebih tinggi dari UMR." << endl;
    } else if (totalGaji == UMR) {
        cout << "\nGaji karyawan sama dengan UMR." << endl;
    } else {
        cout << "\nGaji karyawan di bawah UMR." << endl;
    }

    cout << fixed << setprecision(0);
    cout << "\n====================================" << endl;
    cout << "      Informasi Gaji Karyawan        " << endl;
    cout << "====================================" << endl;
    cout << "Nama: " << nama << endl;
    cout << "Divisi: " << divisi << endl;
    cout << "Periode Gaji: " << periodeGaji << endl;
    cout << "Gaji Pokok: Rp" << gajiPokok << endl;
    cout << "Gaji Lembur: Rp" << gajiLembur << endl;
    cout << "Pajak (5%): Rp" << pajak << endl;
    cout << "Potongan BPJS: Rp" << potonganBPJS << endl;
    cout << "Total Gaji (setelah pajak dan BPJS): Rp" << totalGaji << endl;
    cout << "\nTerima kasih telah menggunakan program ini!" << endl;

    return 0;
}


