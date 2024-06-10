#include<iostream>
#include<vector>
using namespace std;

class perusahaan;
class karyawan {
public:
	string nama;

	vector<perusahaan*> daftar_perusahaan;
	karyawan(string pNama) :nama(pNama) {
		cout << "Karyawan \"" << nama << "\" \n";
	}
	~karyawan() {
		cout << "Karyawan \"" << nama << "\"  \n";
	}
	void tambahPerusahaan(perusahaan*);
	void cetakPerusahaan();
};

class perusahaan {
public:
	string nama;
	vector<karyawan*> daftar_karyawan;

	perusahaan(string pNama) :nama(pNama) {
		cout << "perusahaan \"" << nama << "\"  \n";
	}
	~perusahaan() {
		cout << "Perusahaan \"" << nama << "\"  \n";
	}

	void tambahKaryawan(karyawan*);
	void cetakKaryawan();
};
class proyek {
public:
	string nama;
	vector<karyawan*> daftar_karyawan;

	proyek(string pNama) :nama(pNama) {
		cout << "proyek \"" << nama << "\"  \n";
	}
	~proyek() {
		cout << "proyek \"" << nama << "\"  \n";
	}

	void tambahKaryawan(karyawan*);
	void cetakKaryawan();
};
void karyawan::tambahPerusahaan(perusahaan* pPerusahaan) {
	daftar_perusahaan.push_back(pPerusahaan);
}
void karyawan::cetakPerusahaan() {
	cout << " \"" << this->nama << "\":\n";
	for (auto& a : daftar_perusahaan) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void perusahaan::tambahKaryawan(karyawan* pKaryawan) {
	daftar_karyawan.push_back(pKaryawan);
	pKaryawan->tambahPerusahaan(this);
}
void perusahaan::cetakKaryawan() {
	cout << "Daftar Karyawan Perusahaan PT. Maju Mundur \"" << this->nama << "\":\n";
	for (auto& a : daftar_karyawan) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

void proyek::cetakKaryawan() {
	cout << "Daftar Proyek Karyawan Budi \"" << this->nama << "\":\n";
	for (auto& a : daftar_karyawan) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
int main() {
	perusahaan* varPerusahaan1 = new perusahaan("Daftar Karyawan Proyek Sistem Informasi");
	karyawan* varKaryawan1 = new karyawan("Budi");
	karyawan* varKaryawan2 = new karyawan("Andi");

	proyek* varProyek1 = new proyek("Sistem Informasi");
	proyek* varProyek2 = new proyek("Sistem Keamanan");

	varPerusahaan1->tambahKaryawan(varKaryawan1);
	varPerusahaan1->tambahKaryawan(varKaryawan2);

	varPerusahaan1->cetakKaryawan();


	delete varKaryawan1;
	delete varKaryawan2;
	
	
	return 0;
}