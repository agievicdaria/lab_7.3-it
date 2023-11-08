#include <iostream>
#include <iomanip>
using namespace std;

int countNonZeroRows(int** a, int k, int n) {
    int count = 0;

    for (int i = 0; i < k; ++i) {
        bool hasZero = false;
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (!hasZero) {
            count++;
        }
    }

    return count;
}

void Input(int** a, const int rowCount, const int colCount) {
 for (int i=0; i<rowCount; i++) {
    for (int j=0; j<colCount; j++) {
        cout << "a[" << i << "][" << j << "] = ";
        cin >> a[i][j];
    }
    cout << endl;
 }
}

void Print(int **a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void findMaxRepeated(int** a, int k, int n) {
    int maxRepeated = -1;
    int count = 0;

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            int current = a[i][j];
            int currentCount = 0;
            for (int x = 0; x < k; ++x) {
                for (int y = 0; y < n; ++y) {
                    if (a[x][y] == current) {
                        currentCount++;
                    }
                }
            }
            if (currentCount > 1 && current > maxRepeated) {
                maxRepeated = current;
                count = currentCount;
            }
        }
    }

    if (maxRepeated != -1) {
        cout << "Максимальне число, яке зустрічається більше одного разу: " << maxRepeated << endl;
        cout << "Кількість його зустрічей: " << count << endl; 
    } else {
        cout << "У матриці немає чисел, які зустрічаються більше одного разу." << endl; cout << endl;
    }
}

int main() {
    int rowCount, colCount;

    cout << "Введіть кількість рядків: "; cin >> rowCount;
    cout << "Введіть кількість стовпців (n): "; cin >> colCount;

    int** a = new int*[rowCount];
    for (int i = 0; i < rowCount; ++i) {
        a[i] = new int[colCount];
    }

    Input(a, rowCount, colCount);
    Print(a, rowCount, colCount);


    cout << "Кількість рядків, що не містять жодного нульового елементу: " << countNonZeroRows(a, rowCount, colCount) << endl;
    findMaxRepeated(a, rowCount, colCount);

    for (int i = 0; i < rowCount; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}