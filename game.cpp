#include "Game.h"

Game::Game(int size) : papan(size) {
    nyawa = 3;
    tx = papan.getSize() - 1;
    ty = papan.getSize() - 1;
}

void Game::mainkan() {
    bool menang = false;

    cout << "\n===== GAME BOM-BOMAN =====\n";
    cout << "Target berada di koordinat (size-1, size-1)\n\n";

    while (nyawa > 0 && !menang) {
        papan.tampilkan();
        cout << "\nNyawa: " << nyawa << endl;

        int x, y;
        cout << "Masukkan titik bom (x y): ";
        cin >> x >> y;

        papan.ledakkan(x, y);

        if (x == tx && y == ty)
            menang = true;
        else {
            nyawa--;
            cout << "Bom meleset!\n\n";
        }
    }

    papan.setCell(tx, ty, 'T');

    cout << "\n=== HASIL AKHIR ===\n";
    papan.tampilkan();

    if (menang)
        cout << "\nSelamat! Target berhasil dihancurkan!\n";
    else
        cout << "\nGame Over! Kamu kehabisan nyawa.\n";

    cout << "Target berada di: (" << tx << ", " << ty << ")\n";
}

