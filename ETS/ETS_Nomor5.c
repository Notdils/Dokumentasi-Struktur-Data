#include <bits/stdc++.h>


using namespace std;

void tampilkanAntrian(queue<string> q) {
    if (q.empty()) {
        cout << "Antrian saat ini: Kosong\n";
        return;
    }
    cout << "Antrian saat ini: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

int main() {
    queue<string> layananAkademik;

    cout << "--- Mulai Simulasi ---\n";
    
    // Mahasiswa A, B, C masuk antrian
    layananAkademik.push("A");
    layananAkademik.push("B");
    layananAkademik.push("C");
    cout << "Mahasiswa A, B, C masuk antrian.\n";

    // Mahasiswa pertama dilayani
    cout << "Melayani mahasiswa: " << layananAkademik.front() << "\n";
    layananAkademik.pop(); 

    // Tambah mahasiswa D
    layananAkademik.push("D");
    cout << "Mahasiswa D masuk antrian.\n";

    // Tampilkan kondisi antrian
    tampilkanAntrian(layananAkademik);

    return 0;
}
