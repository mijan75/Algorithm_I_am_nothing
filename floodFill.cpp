#include <iostream>
using namespace std;
#define M 8
#define N 8

void floodFill(int screen[M][N], int x, int y, int prevColor, int currentColor){
    if(x<0 || x >=M || y <0 || y >=N) return;
    if(screen[x][y] != prevColor) return;

    screen[x][y] = currentColor;

    floodFill(screen, x+1, y, prevColor, currentColor);
    floodFill(screen, x-1, y, prevColor, currentColor);
    floodFill(screen, x, y+1, prevColor, currentColor);
    floodFill(screen, x, y-1, prevColor, currentColor);
}


int main() {
    int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 0, 0, 1, 1, 0, 1, 1},
                        {1, 2, 2, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 2, 2, 0},
                        {1, 1, 1, 1, 1, 2, 1, 1},
                        {1, 1, 1, 1, 1, 2, 2, 1},
    };
    floodFill(screen, 4,4,2,3);
    cout << "updated screen after flood fill" << endl;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cout << screen[i][j] <<" ";
        }
        cout << endl;
    }
    return 0;
}