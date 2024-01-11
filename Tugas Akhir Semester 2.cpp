#include <iostream>
#include <iomanip>	 // untuk fungsi setw dalam membaut tabel
#include <windows.h> // untuk memanggil perintah yang ada pada command prompt

using namespace std;

int maxTugas = 10; // pendeklarasian batas maksimum array

// struct : data yang terbentuk dari beberapa data
struct Tugas
{
	string nama;
	int deadline, Tgl, Bulan, Tahun;
};

void judul()
{
	system("cls");
	cout << "\t\t=====================================================" << endl;
	cout << "\t\t|         Tugas Akhir Algoritma Struktur Data       |" << endl;
	cout << "\t\t|              Program Task Management              |" << endl;
	cout << "\t\t|            Dibuat Oleh : Sohibul Males            |" << endl;
	cout << "\t\t=====================================================" << endl;
	cout << endl;
}

// fungsi tanpa nilai pengembalian (void)
void tambahTugas(Tugas daftarTugas[], int &jumlahTugas)
{
	system("cls");
	judul();

	if (jumlahTugas == maxTugas)
	{
		cout << "Daftar tugas sudah penuh ! " << endl;
		return;
	}

	Tugas newTugas; // Penamaan variabel struct
	cout << "Masukan Tugas Anda : ";
	cin.ignore();
	getline(cin, newTugas.nama);

	cout << "Masukan deadline hari (DD) : ";
	cin >> newTugas.Tgl;
	cout << "Masukan deadline bulan (MM) : ";
	cin >> newTugas.Bulan;
	cout << "Masukan deadline tahun (YYYY) : ";
	cin >> newTugas.Tahun;

	system("cls");
	judul();

	daftarTugas[jumlahTugas] = newTugas;
	jumlahTugas++;
	cout << "Tugas ditambahkan ! " << endl;
}

void tampilanTugas(Tugas daftarTugas[], int &jumlahTugas)
{
	system("cls");
	judul();

	if (jumlahTugas == 0)
	{
		cout << "Tidak ada tugas dalam daftar.\n " << endl;
		return;
	}

	cout << "Daftar Tugas : " << endl;

	// Membuat tabel
	cout << "+----+-------------------------------+-----------------------+" << endl;
	cout << "| No |             Nama              |        Deadline       |" << endl;
	cout << "+----+-------------------------------+-----------------------+" << endl;

	for (int i = 0; i < jumlahTugas; i++)
	{
		cout << "| " << setw(2) << i + 1 << " | ";
		cout << setw(30) << left << daftarTugas[i].nama << "|   ";
		cout << daftarTugas[i].Tgl << "-" << daftarTugas[i].Bulan << "-" << daftarTugas[i].Tahun << " 	     |" << endl;
	}
	cout << "+----+-------------------------------+-----------------------+" << endl;
}

void sortNama(Tugas daftarTugas[], int &jumlahTugas)
{
	system("cls");
	judul();
	for (int i = 0; i < jumlahTugas - 1; i++)
	{
		for (int j = i + 1; j < jumlahTugas; j++)
		{
			if (daftarTugas[i].nama > daftarTugas[j].nama)
			{
				Tugas temp = daftarTugas[i];
				daftarTugas[i] = daftarTugas[j];
				daftarTugas[j] = temp;
			}
		}
	}
	cout << endl;
	cout << "Daftar tugas diurutkan berdasarkan NAMA." << endl;
}

void sortDeadline(Tugas daftarTugas[], int &jumlahTugas)
{
	system("cls");
	judul();
	for (int i = 0; i < jumlahTugas - 1; i++)
	{
		for (int j = i + 1; j < jumlahTugas; j++)
		{
			if (daftarTugas[i].Tgl > daftarTugas[j].Tgl)
			{
				Tugas temp = daftarTugas[i];
				daftarTugas[i] = daftarTugas[j];
				daftarTugas[j] = temp;
			}
			else if (daftarTugas[i].Bulan > daftarTugas[j].Bulan)
			{
				Tugas temp = daftarTugas[i];
				daftarTugas[i] = daftarTugas[j];
				daftarTugas[j] = temp;
			}
			else if (daftarTugas[i].Tahun > daftarTugas[j].Tahun)
			{
				Tugas temp = daftarTugas[i];
				daftarTugas[i] = daftarTugas[j];
				daftarTugas[j] = temp;
			}
		}
	}
	cout << endl;
	cout << "Daftar Tugas diurutkan berdasarkan Deadline." << endl;
}

void hapusTugas(Tugas daftarTugas[], int &jumlahTugas)
{
	system("cls");
	judul();
	tampilanTugas(daftarTugas, jumlahTugas);
	if (jumlahTugas == 0)
	{
		cout << "Tidak ada tugas kakaaa " << endl;
		return;
	}

	int hapus;
	cout << "Masukan nomor tugas yang ingin anda hapus : ";
	cin >> hapus;
	if (hapus < 1 || hapus > jumlahTugas)
	{
		cout << "YANG BENER DONG KAKAA" << endl;
		return;
	}
	else
	{
		for (int i = hapus - 1; i < jumlahTugas - 1; i++)
		{
			daftarTugas[i] = daftarTugas[i + 1];
		}
	}

	jumlahTugas--;
	cout << endl;
	cout << "Tugas dihapus !!! " << endl
		 << endl;
}

void menu()
{
	Tugas daftarTugas[maxTugas];
	int jumlahTugas = 0;
	int pilih;

	system("cls");
	judul();
	while (true)
	{

		cout << "\n\n========================================" << endl;
		cout << "|              Menu utama              |" << endl;
		cout << "========================================" << endl;
		cout << "| 1.   Tambahkan Tugas                 |" << endl;
		cout << "| 2.   Daftar Tugas                    |" << endl;
		cout << "| 3.   Urutkan berdasarkan nama        |" << endl;
		cout << "| 4.   Urutkan berdasarkan deadline    |" << endl;
		cout << "| 5.   Hapus Tugas                     |" << endl;
		cout << "| 6.   Keluar dari program             |" << endl;
		cout << "========================================" << endl
			 << endl;
		cout << " Pilih : ";
		cin >> pilih;

		switch (pilih)
		{
		case 1:
			tambahTugas(daftarTugas, jumlahTugas);
			break;
		case 2:
			tampilanTugas(daftarTugas, jumlahTugas);
			break;
		case 3:
			sortNama(daftarTugas, jumlahTugas);
			break;
		case 4:
			sortDeadline(daftarTugas, jumlahTugas);
			break;
		case 5:
			hapusTugas(daftarTugas, jumlahTugas);
			break;
		case 6:
			system("cls");
			cout << "\n\t\t====================================" << endl;
			cout << "\t\t|    Terima kasih. Sampai jumpa !  |" << endl;
			cout << "\t\t====================================" << endl;
			cout << endl;
			return;
		default:
			system("cls");
			cout << "=================================================" << endl;
			cout << "|  Pilihan tidak valid kaka. coba lagi donggg ! |" << endl;
			cout << "=================================================" << endl
				 << endl;
			break;
		}
	}
}

int main()
{
	menu();

	return 0;
}