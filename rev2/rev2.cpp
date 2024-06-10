#include <iostream>
#define max 10
using namespace std;

// Queue = kasir
// Linked list = admin

int pil;
double totalHarga;
string akun;

void enqueue();
void dequeue();
void tampilData();
void halamanAdmin();
void halamanKasir();


int main()
{
	
	do
	{
		cout << "Login Akun : ";
		cin >> akun;
		if (akun == "admin")
		{
			halamanAdmin();
		}
		else if (akun == "kasir")
		{
			halamanKasir();
		}
		else
		{
			cout << "Akun tidak ditemukan!";
		}
	} while (akun != "admin" && akun != "kasir");
	
}

struct dataPesanan
{
	string nama;
	int jmlSoto, jmlSotoKulit, jmlEsTeh, jmlEsJeruk;
	dataPesanan* next;
};

struct queue
{
	dataPesanan data[max];
	int head;
	int tail;
}antrian;

bool kosong()
{
	if (antrian.tail == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool penuh()
{
	if (antrian.tail == max)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void tampilData()
{
	if (!kosong())
	{
		for (int i = antrian.head; i < antrian.tail; i++)
		{
			cout << "Antrian ke-" << i + 1 << "\n";
			cout << "Nama Pemesan : " << antrian.data[i].nama << endl;
			cout << "Jumlah Soto Biasa : " << antrian.data[i].jmlSoto << endl;
			cout << "Jumlah Soto Kulit : " << antrian.data[i].jmlSotoKulit << endl;
			cout << "Jumlah Es Teh : " << antrian.data[i].jmlEsTeh << endl;
			cout << "Jumlah Es Jeruk : " << antrian.data[i].jmlEsJeruk << endl;
		}
	}
	else
	{
		cout << "Data masih kosong!\n";
	}

}

void enqueue()
{
	if (!penuh())
	{
		cout << "Masukkan nama pemesan : ";
		cin >> antrian.data[antrian.tail].nama;
		cout << "Masukkan jumlah soto biasa: ";
		cin >> antrian.data[antrian.tail].jmlSoto;
		cout << "Masukkan jumlah soto kulit : ";
		cin >> antrian.data[antrian.tail].jmlSotoKulit;
		cout << "Masukkan jumlah es teh : ";
		cin >> antrian.data[antrian.tail].jmlEsTeh;
		cout << "Masukkan jumlah es jeruk : ";
		cin >> antrian.data[antrian.tail].jmlEsJeruk;
	
		cout << "Pesanan berhasil dimasukkan!" << endl;

		
		double totalSoto = antrian.data[antrian.tail].jmlSoto * 15000;
		double totalKulit = antrian.data[antrian.tail].jmlSotoKulit * 18000;
		double totalJeruk = antrian.data[antrian.tail].jmlEsJeruk * 5000;
		double totalEsTeh = antrian.data[antrian.tail].jmlEsTeh * 4000;

		totalHarga = totalSoto + totalKulit + totalJeruk + totalEsTeh;
		cout << "==== NOTA PEMBAYARAN ====\n";
		cout << "Total harga soto : " << totalSoto << endl;
		cout << "Total harga soto kulit : " << totalKulit << endl;
		cout << "Total harga es teh : " << totalEsTeh << endl;
		cout << "Total harga es jeruk : " << totalJeruk << endl;
		cout << "Total harga : " << totalHarga << endl;
		antrian.tail++;
	}
	else
	{
		cout << "Antrian sudah penuh!";
	}
}

void dequeue()
{
	dataPesanan dataPesanan[max];
	if (!kosong())
	{
			cout << "Pesanan atas nama " << antrian.data[antrian.head].nama << " telah selesai!"  << endl;
			antrian.head++;
	}
	else
	{
		cout << "Antrian masih kosong!";
	}
}

// Halaman Kasir
void halamanKasir()
{
	do
	{
		cout << "==== HALAMAN KASIR ====" << endl;
		cout << "1. Masukkan pesanan" << endl;
		cout << "2. Tampilkan pesanan" << endl;
		cout << "3. Pesanan selesai" << endl;
		cout << "4. Keluar" << endl;
		cout << "Masukkan pilihan : ";
		cin >> pil;
		switch (pil)
		{
		case 1:
			enqueue();
			break;
		case 2:
			tampilData();
			break;
		case 3:
			dequeue();
			break;
		case 4:
			do
			{
				cout << "Login Akun : ";
				cin >> akun;
				if (akun == "admin")
				{
					halamanAdmin();
				}
				else if (akun == "kasir")
				{
					halamanKasir();
				}
				else
				{
					cout << "Akun tidak ditemukan!";
				}
			} while (akun != "admin" && akun != "kasir");
			break;
		}
	} while (pil != 4);
}


struct LinkedList 
{
	dataPesanan* head;
	dataPesanan* tail;
	int size;
} list;

void initLinkedList() {
	list.head = NULL;
	list.tail = NULL;
	list.size = 0;
}

bool kosongLinkedList() {
	return list.size == 0;
}

void tampilDataLinkedList() {
	if (!kosongLinkedList()) {

		cout << "==== RIWAYAT PESANAN ====\n";
		dataPesanan* current = list.head;
		while (current != NULL) 
		{
			cout << "Nama pemesan : " << current->nama << endl;
			cout << "Jumlah soto : " << current->jmlSoto << endl;
			cout << "Jumlah soto kulit : " << current->jmlSotoKulit << endl;
			cout << "Jumlah es teh : " << current->jmlEsTeh << endl;
			cout << "Jumlah es jeruk : " << current->jmlEsJeruk << endl;
			cout << "Total harga : " << totalHarga << endl;
			cout << endl;
			current = current->next;
		}
	}
	else {

		cout << "Data Kosong" << endl;
	}
}
// Halaman Admin
void halamanAdmin()
{
	do
	{
		cout << "==== HALAMAN ADMIN ====" << endl;
		cout << "1. Tampilkan semua data" << endl;
		cout << "2. Cari berdasarkan nama pemesan" << endl;
		cout << "3. Urutkan berdasarkan total harga" << endl;
		cout << "Masukkan pilihan : ";
		cin >> pil;
		switch (pil)
		{
		case 1:
			tampilDataLinkedList();
			break;
		case 2:
			break;
		case 3:
			break;

		}
	} while (pil != 4);

}
