#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

const int SIZE = 20;
const int HEIGHT = 9;

int main () {

    int peaks[SIZE];
    int level[SIZE];

    srand(time(NULL));

    for (int i = 0; i < SIZE; ++i) {
        peaks[i] = rand() % (HEIGHT + 1);
        level[i] = 5;
    }

    cout << "   ";
    for (int i = 0; i < SIZE; ++i) {
        cout << peaks[i] << " ";
    }
    cout << endl;

    for (int h = HEIGHT + 1; h > 0; --h) {
        cout << setfill(' ') << setw(2) << h << "|";
        for (int i = 0; i < SIZE; ++i) {
            if ((peaks[i] + 1) == h) {
                cout << '_';
            } else if (peaks[i] == h) {
                cout << peaks[i];
            } else if (level[i] >= h && level[i] > peaks[i]) {
                cout << '*';
            } else {
                cout << ' ';
            }

            if (peaks[i] >= h || ((i + 1 < SIZE) && peaks[i + 1] >= h)) {
                cout << "|";
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}
