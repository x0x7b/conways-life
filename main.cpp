#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;


const int mapsize = 25;
int map[mapsize][mapsize] = {0};
int newmap[mapsize][mapsize] = {0};


void printMap(int (*ptr)[mapsize]);
void randomMap(int (*ptr)[mapsize]);
int countNeighbors(int (*ptr)[mapsize], int x, int y);
void nextGen(int (*ptr)[mapsize], int (*pptr)[mapsize]);
void updateMap(int (*ptr)[mapsize], int (*pptr)[mapsize]);
int countAlives(int (*ptr)[mapsize]);

int main() {
    int gens = 10;
    cout << "enter num of generations(default 10):";
    cin >> gens;
    randomMap(map);
    printMap(map);
    cout << endl;
    system("pause");
    for(int i = 0; i <= gens; i++) {
        system("cls");
        printMap(map);
        cout << "Cells alive: "<< countAlives(map) << endl;
        cout << "Gen " << i << endl; 
        if (countAlives(map) == 0) {cout << endl << "Genocide successful!" << endl; break;};
        nextGen(map, newmap);
        updateMap(map, newmap);
        Sleep(190);

        
        
    }
    system("pause");
}

void printMap(int (*ptr)[mapsize] ){

    for(int i = 0; i < mapsize; i++) {
        for(int j = 0; j < mapsize; j++) {
            if(ptr[j][i] == 1) {
                cout << "#";
            } else {
                cout << ".";
            }
    };
        cout << endl;
    }

}

void randomMap(int (*ptr)[mapsize]) {
    srand(time(NULL));
    for(int i = 0; i < mapsize; i++) {
        for(int j = 0; j < mapsize; j++) {

            if(rand() % 2 == 0) {
                ptr[j][i] = 1;
            } else {
                ptr[j][i] = 0;
            }
    };
        
    }
}

int countNeighbors(int (*ptr)[mapsize], int x, int y) {
    int count = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(j == 0 && i == 0) continue;
            int newx = x + i;
            int newy = y + j;
            if((newx >= 0 && newx < mapsize) && (newy >= 0 && newy < mapsize) ) {
                if(ptr[newx][newy] == 1) count++;
            };

        }
    }
    return count;
}

void nextGen(int (*ptr)[mapsize], int (*pptr)[mapsize]) {
    for(int i = 0; i < mapsize; i++) {
        for(int j = 0; j < mapsize; j++) {
            int nei = countNeighbors(ptr, i, j);
            if(ptr[i][j] == 0 && nei == 3){
                
                pptr[i][j] = 1;
            } else if(ptr[i][j] == 1 && (nei == 2 || nei == 3)) {
                
                pptr[i][j] = ptr[i][j];
            } else {
                
                pptr[i][j] = 0;
            }
            }
        }
}

void updateMap(int (*ptr)[mapsize], int (*pptr)[mapsize]) {
    for(int i = 0; i < mapsize; i++) {
        for(int j = 0; j < mapsize; j++) {
            ptr[i][j] = pptr[i][j];
        }
    }
}

int countAlives(int (*ptr)[mapsize]) {
    int count = 0;
    for(int i = 0; i < mapsize; i++) {
        for(int j = 0; j < mapsize; j++) {
            if(map[i][j] == 1) count++;;
            
        }
    }
    return count;
}
