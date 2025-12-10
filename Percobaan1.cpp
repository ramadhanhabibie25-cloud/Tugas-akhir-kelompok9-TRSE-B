#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

void tampilkanPenjelasanZBB() {
    const vector<string> hari = {
        "Senin", "Selasa", "Rabu", "Kamis",
        "Jumat", "Sabtu", "Minggu"
    };

    cout << "=======================================================================\n";
    cout << "              PROGRAM ANALISIS & OPTIMASI PENGELUARAN MINGGUAN\n";
    cout << "                   (Metode: Zero-Based Budgeting / ZBB)\n";
    cout << "=======================================================================\n\n";

    cout << "SELAMAT DATANG DI PROGRAM KEUANGAN\n";
    cout << "ZERO BASED BUDGETING - KELOMPOK 9" <<endl;
    cout << "\nTekan ENTER untuk melanjutkan...";
    cin.get();
    cout << "" << endl;
    cout << "===PENJELASAN PRORGAM===" <<endl;
    cout << "" << endl;
    cout << "Program ini menggunakan metode *Zero-Based Budgeting* (ZBB), yaitu:\n";
    cout << "- Setiap rupiah dalam seminggu harus dialokasikan dengan jelas.\n";
    cout << "- Tidak ada uang yang dibiarkan menganggur.\n";
    cout << "- Semua hari memiliki persentase pengeluaran yang sama.\n\n";

    cout << "Tabel berikut menjelaskan cara kerja program:\n\n";

    double persen = 100.0 / 7.0;

    cout << left << setw(15) << "Hari"
         << setw(20) << "Persentase Alokasi (%)" << endl;
    cout << "----------------------------------------\n";

    for (int i = 0; i < 7; i++) {
        cout << left << setw(15) << hari[i]
             << setw(20) << fixed << setprecision(2) << persen << endl;
    }

    cout << "\nTotal persentase: 100%\n";
    cout << "=======================================================================\n\n";
}

int main() {
    char mulai;

    do {
        tampilkanPenjelasanZBB();

        cout << "Jika sudah paham maka tekan huruf 'Y' untuk melanjutkan: ";
        cin >> mulai;

        if (toupper(mulai) != 'Y') {
            cout << "Program dihentikan.\n";
            return 0;
        }

        system("clear || cls");

        const vector<string> hari = {
            "Senin", "Selasa", "Rabu", "Kamis",
            "Jumat", "Sabtu", "Minggu"
        };

        vector<double> pengeluaran(7);
        double totalUang;

        cout << "=======================================================================\n";
        cout << "              INPUT PENGELUARAN MINGGUAN ANDA\n";
        cout << "=======================================================================\n\n";

        cout << "Silahkan masukkan total uang yang anda siapkan untuk seminggu: ";
        cin >> totalUang;

        cout << "\nMasukkan pengeluaran Anda per hari:\n\n";

        for (int i = 0; i < 7; i++) {
            cout << "Pengeluaran hari " << hari[i] << ": ";
            cin >> pengeluaran[i];
        }


        double idealPerHari = totalUang / 7.0;

        system("clear || cls");

        cout << "=======================================================================\n";
        cout << "                   HASIL ANALISIS PENGELUARAN ANDA\n";
        cout << "=======================================================================\n\n";

        cout << left << setw(12) << "Hari"
             << setw(20) << "Pengeluaran Anda"
             << setw(25) << "Alokasi Ideal (ZBB)"
             << setw(20) << "Status" << endl;
        cout << "-----------------------------------------------------------------------\n";

        for (int i = 0; i < 7; i++) {
            string status;

            if (pengeluaran[i] > idealPerHari)
                status = "Melebihi ideal";
            else if (pengeluaran[i] < idealPerHari)
                status = "Di bawah ideal";
            else
                status = "Pas";

            cout << left
                 << setw(12) << hari[i]
                 << setw(20) << pengeluaran[i]
                 << setw(25) << fixed << setprecision(2) << idealPerHari
                 << setw(20) << status
                 << endl;
        }

        cout << "\n=======================================================================\n";
        cout << "                      YANG PERLU DIPERHATIKAN\n";
        cout << "=======================================================================\n";
        cout << "- Metode Zero-Based Budgeting menekankan bahwa setiap rupiah harus\n";
        cout << "  memiliki tujuan yang jelas.\n";
        cout << "- Jika pengeluaran suatu hari melebihi alokasi ideal, kurangi\n";
        cout << "  pengeluaran di hari lain agar total mingguan tetap seimbang.\n";
        cout << "- Tujuan utama: membantu Anda mengendalikan pengeluaran harian.\n";
        cout << "=======================================================================\n\n";

        cout << "Apakah anda ingin memulai lagi dari awal? (y/n): ";
        cin >> mulai;

        system("clear || cls");

    } while (toupper(mulai) == 'Y');

    cout << "Terima kasih telah menggunakan program ini!\n";
}
