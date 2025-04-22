#include "iostream"

using namespace std;

class SparseMatrix {
    private:
        int row, col, val;

    public:
        SparseMatrix() : row(0), col(0), val(0) {}

        SparseMatrix(int r, int c, int v) {
            row = r;
            col = c;
            val = v;
        };

        void print() {
            cout << row << col << val;
        }
};

int main() {
    int m, n;
    cin >> m >> n;
    SparseMatrix sm[2];
    sm[0].print();
    for (int i = 0;i<m;i++) {
        int r;
        cin >> r;
        int indexes[r];
        for (int j = 0;j<r;j++) {
            cin >> indexes[j];
        }
        for (int j = 0;j<r;j++) {
            cin >> indexes[j];
        }
    }

    return 0;
}