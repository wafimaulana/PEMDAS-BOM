#include <iostream>
using namespace std;

// ===============================
// CLASS INDUK : BOARD
// ===============================
class Board {
private:
    int size;
    char grid[20][20];

public:
    Board(int s) {
        size = s;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                grid[i][j] = '-';
    }

    int getSize() { return size; }

    void setCell(int x, int y, char simbol) {
        if (x >= 0 && x < size && y >= 0 && y < size)
            grid[x][y] = simbol;
    }

    void tampilkan() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
    }
};

// ===============================
// CLASS TURUNAN : BOM
// ===============================
class Bom : public Board {
public:
    Bom(int s) : Board(s) {}

    // ===== FITUR LANJUTAN: DEFAULT PARAMETER =====
    void ledakkan(int x = 0, int y = 0) {
        setCell(x, y, '*');
    }
};

// ===============================
// CLASS GAME
// ===============================
class Game {
private:
    Bom papan;
    int tx, ty;
    int nyawa;

public:
    Game(int size) : papan(size) {
        nyawa = 3;
        tx = papan.getSize() - 1;
        ty = papan.getSize() - 1;
    }

    void mainkan() {
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
};

// ===============================
// MAIN PROGRAM
// ===============================
int main() {
    int ukuran;
    cout << "Masukkan ukuran papan (maksimal 20): ";
    cin >> ukuran;

    while (ukuran > 20 || ukuran < 1) {
        cout << "? Ukuran harus 1 - 20!\nMasukkan lagi: ";
        cin >> ukuran;
    }

    Game g(ukuran);
    g.mainkan();

    return 0;
}

