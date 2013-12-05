#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

const int SIZE = 40;
const int HEIGHT = 9;

enum { MODE_SEARCH, MODE_FILL };

int peaks[SIZE];
int level[SIZE];
int volume = 0;

void fill() {

    srand(time(NULL));

    for (int i = 0; i < SIZE; ++i) {
        peaks[i] = rand() % (HEIGHT + 1);
        level[i] = 0;
    }
}

void calculate() {

    for (int h = 0; h <= HEIGHT; ++h) {
        int mode = MODE_SEARCH;
        int bound = -1;

        for (int i = 0; i < SIZE; ++i) {
            if (mode == MODE_SEARCH) {
                if (peaks[i] >= h) {
                    bound = i;
                    break;
                }
           }
        }

        if (-1 != bound) {
            for (int i = SIZE - 1; i > bound; --i) {
                if (mode == MODE_SEARCH) {
                    if (peaks[i] >= h) {
                        mode = MODE_FILL;
                    }
                } else if (mode == MODE_FILL) {
                    if (h > peaks[i]) {
                        level[i] = h;
                        volume++;
                    }
                }
            }
        }
    }
}

void print() {

    cout << "  |";
    for (int i = 0; i < SIZE; ++i) {
        cout << peaks[i] << " ";
    }
    cout << endl;

    for (int h = HEIGHT + 1; h > 0; --h) {
        cout << setfill(' ') << setw(2) << h << "|";
        for (int i = 0; i < SIZE; ++i) {

            if (peaks[i] == h) {
                cout << peaks[i];
            } else if (level[i] >= h && level[i] > peaks[i] && h > peaks[i]) {
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
    cout << endl;
    cout << "volume = " << volume << endl;
}

int main () {

    fill();

    calculate();

    print();

    return 0;
}
