#include <sys/termios.h>
#include <unistd.h>
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define w 13
#define h 13

enum dir {
    UP, 
    LEFT, 
    DOWN, 
    RIGHT, 
    NUM
};

typedef struct {
    int xCords;
    int yCords;
} playerA;

typedef struct {
    int xCords;
    int yCords;
} playerB;

int visited[w/2][h/2] = {0};

int getch() {
    struct termios old_t, new_t;
    int ch;
    tcgetattr(STDIN_FILENO, &old_t);
    new_t = old_t;
    new_t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_t);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_t);
    return ch;
}

void generateBorders(char maze[w][h]) {
    int i, j;
    for (i = 0;i<w;i++) maze[i][0] = '#';
    for (i = 0;i<w;i++) maze[i][h-1] = '#';
    for (i = 0;i<h;i++) maze[0][i] = '#';
    for (i = 0;i<h;i++) maze[w-1][i] = '#';

    // for (i = 1;i<h-1;i++) {
    //     for (j = 1;j<w-1;j++) {
    //         if (!(i%2)) maze[j][i] = '#';
    //     }
    // }
    // for (i = 1;i<w-1;i++) {
    //     for (j = 1;j<h-1;j++) {
    //         if (!(i%2)) maze[i][j] = '#';
    //     }
    // }
}

int paths(int dir[], int x, int y) {
    int nDir = 0;

    if (y > 0 && !visited[x][y - 1]) dir[nDir++] = UP;
    if (x > 0 && !visited[x - 1][y]) dir[nDir++] = LEFT;
    if (y < h/2 && !visited[x][y + 1]) dir[nDir++] = DOWN;
    if (x < w/2 && !visited[x + 1][y]) dir[nDir++] = RIGHT;

    return nDir;
}

void generateMaze(char maze[w][h], int x, int y) {
    srand(time(NULL));
    int dir[NUM];
    int ndir, j, i;

    visited[x][y] = 1;

    ndir = paths(dir, x, y);

    while (ndir) {
        int seed = rand() % ndir;

        switch (dir[seed]) {
            case UP: 
                maze[x][y-1] = ' ';
                generateMaze(maze, x, y-1);
                break;

            case LEFT:
                maze[x-1][y] = ' ';
                generateMaze(maze, x - 1, y);
                break;

            case DOWN: 
                maze[x][y+1] = ' ';
                generateMaze(maze, x, y + 1);
                break;

            case RIGHT:  
                maze[x+1][y] = ' ';
                generateMaze(maze, x + 1, y);
                break;
        }

        ndir = paths(dir, x, y);
    }
}

void printMaze(char maze[w][h], playerA a, playerB b) {
    system("clear");
    int i, j;

    for (i = 0;i<h;i++) {
        for (j = 0;j<w;j++) {
            if (a.xCords == j && a.yCords == i) {
                if (a.xCords == b.xCords && a.yCords == b.yCords) putc('S', stdout);
                else putc('A', stdout);
                continue;
            }
            if (b.xCords == j && b.yCords == i) {
                putc('B', stdout);
                continue;
            }
            putc(maze[j][i], stdout);
        }
        printf("\n");
    }
}

int main() {
    char maze[w][h] = {0}, cmd;
    int i, j;
    for (i = 0;i<h;i++) {
        for (j = 0;j<w;j++) {
            maze[j][i] = ' ';
        }
    }
    playerA a = {.xCords = 1, .yCords = 1};
    playerB b = {.xCords = w-2, .yCords = h-2};
    generateBorders(maze);
    generateMaze(maze, 0, 0);
    
    while (1) {
        printMaze(maze, a, b);
        cmd = getch();
        switch (cmd) {
            case 'w':
                if (a.yCords-1) a.yCords--;
                break;

            case 'a':
                if (a.xCords-1) a.xCords--;
                break;

            case 's':
                if (a.yCords+1<h-1) a.yCords++;
                break;

            case 'd':
                if (a.xCords+1<w-1) a.xCords++;
                break;

            case '5':
                if (b.yCords-1) b.yCords--;
                break;

            case '1':
                if (b.xCords-1) b.xCords--;
                break;

            case '2':
                if (b.yCords+1<h-1) b.yCords++;
                break;

            case '3':
                if (b.xCords+1<w-1) b.xCords++;
                break;
        }
    }

    return 0;
}