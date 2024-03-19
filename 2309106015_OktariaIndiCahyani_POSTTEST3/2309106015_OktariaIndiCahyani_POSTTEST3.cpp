#include <iostream>
#include <cstdlib>
using namespace std;

const int max_produk = 10;
string produk[max_produk], ulang;
double oneyearreturns[max_produk] = {0};
int posisi = 0;

void tampilkan() {
    system("cls");
    if (posisi > 0) {
        cout << "Data investasi tersimpan" << endl;
        for (int a = 0; a < posisi; a++) {
            cout << a + 1 << ". " << produk[a] << " 1 year return: "<< oneyearreturns[a]<< "%"<< endl;
        }
    } else {
        cout << "====== ANDA BELUM INVESTASI ======" << endl;
    }
}

void tambahdata() {
    do {
        tampilkan();

        if (posisi < max_produk) {
            cout << "Masukkan data produk investasi baru:\n";

            cout << "Nama: ";
            cin.ignore();
            getline(cin, produk[posisi]);

            cout << "1 Year Return (%): ";
            cin >> oneyearreturns[posisi];

            cout << "Produk berhasil ditambahkan.\n";
            posisi++;
        } else {
            cout << "Maaf, sudah mencapai batas maksimum produk.\n";
        }

        cout << "Tambah data lagi? (y/n): ";
        cin >> ulang;

    } while (ulang == "y" || ulang == "Y");
}

void perbarui() {
    int i;
    do {
        tampilkan();
        cout << "Ubah data ke : ";
        cin >> i;
        cin.ignore();
        i--;
        cout << "Ubah menjadi: ";
        getline(cin, produk[i]);
        cout << "1 year return (%): ";
        cin >> oneyearreturns[i];
        cout << "Data berhasil diperbarui.";
        tampilkan();
        cout << "Apakah mau ubah lagi? (y/n): ";
        cin >> ulang;
        i = -1;
        }while (ulang == "y");
    } 
    
void hapusdata() {
    int j;
    do {
        tampilkan();
        if (posisi > 0) {
            cout << "Hapus data ke: ";
            cin >> j;
            cin.ignore();
        
            if ( j >= 1 && j <= posisi){
                for (int i = j-1; i < posisi - 1; ++i) {
                        produk[i] = produk[i+1];
                        oneyearreturns[i] = oneyearreturns[i+1];
                    }
                    posisi--;
                    produk[posisi] = "";
                    oneyearreturns[posisi] = 0;
                   
                    tampilkan();
            } else{
                cout << "Pilihan yang anda masukan salah";
            }
                    cout << "Hapus lagi (y/n): ";
                    cin >> ulang;
        } else {
            cout << "Tidak ada yang bisa anda hapus";
            cout << "Isi n : ";
            cin >> ulang;
        }
    } while (ulang == "y");
}


void menu(){
    int pilih;
    do {
        system("cls");
        cout << "\nAyo pilih\n";
        cout << "1. Tampilkan data produk investasi\n";
        cout << "2. Tambahkan data produk investasi\n";
        cout << "3. Perbarui informasi produk investasi\n";
        cout << "4. Hapus data produk investasi\n";
        cout << "5. Selesai\n";
        cout << "Tentukan Pilihan anda: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                do {
                    tampilkan();
                    cout << "Kembali? (y): ";
                    cin >> ulang;
                } while (ulang != "y" && ulang != "Y");
                break;
            case 2:
                tambahdata();
                break;
            case 3:
                perbarui();
                break;
            case 4:
                hapusdata();
                break;
            case 5:
                cout << "Anda telah keluar dari program\n";
                break;
            default:
                cout << "Pilih angka 1-5" << endl;
                break;
        }
        if (pilih == 5){
            break;
        }
    } while (true);
}

int main() {
    int i;
    string pass_input, user_input;
    cout << "=====================================================\n";
    cout << "                   AYO INVESTASI!!!\n";
    cout << "=====================================================\n";
    cout << "Investasikan hari ini, raih impian masa depanmu.\n";
    cout << "=====================================================\n\n";
    string username = "oktaria";
    string password = "2309106015";
    string login = "block";
    i = 1;

    do {
        cout << "Username = ";
        cin >> user_input;
        cout << "Password = ";
        cin >> pass_input;
        if (user_input == username && pass_input == password) {
            cout << " =====================================\n";
            cout << "| Login Berhasil Selamat berinvestasi |" << endl;
            i = 4;
            login = "berhasil";
        } else {
            cout << "\n=============================\n";
            cout << "Username / Password Salah!!! (" << i << "x)\n";
            cout << "=============================\n\n";
            i = i + 1;
        }
    } while (i <= 3 && login != "berhasil");

    if (login != "berhasil") {
        cout << "Anda telah 3x salah login.\n";
        cout << "Silahkan coba setelah 24 jam dari sekarang. Terima Kasih..\n\n";
        return 0;
    }

    menu();
    cout << "Buatlah langkah kecil menuju kebebasan finansial dengan investasi.. Sampai jumpa lagi ";
    return 0;

}