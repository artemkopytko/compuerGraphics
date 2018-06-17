//
//  main.cpp
//  cppProject
//
//  Created by Артем Копытько on 3/19/18.
//  Copyright © 2018 Artem Kopytko. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <fstream>

//Максимальное значение веса = 100
#define INF 3000

using namespace std;

void printMatrix(int** matrix, int numberOfVert) {
    for(int i = 0; i < numberOfVert; i++) {
        for(int j = 0; j < numberOfVert; j++) {
            if(matrix[i][j] == INF) {
                cout << "INF" << " ";
            }
            else {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}

//matrix - матрица смежности
void originalFloydWarshall(int **matrix, int numberOfVert) {
    //Пробегаемся по всем вершинам и ищем более короткий путь
    //через вершину k
    for(int k = 0; k < numberOfVert; k++) {
        for(int i = 0; i < numberOfVert; i++) {
            for(int j = 0; j < numberOfVert; j++) {
                //Новое значение ребра равно минимальному между старым
                //и суммой ребер i <-> k + k <-> j (если через k пройти быстрее)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    
    return;
}

int main(int argc, char** argv) {
    
    int N = 5;
    int M = 5;
    
    // dynamic allocation
    int** matrix = new int*[N];
    for(int i = 0; i < N; ++i)
        matrix[i] = new int[M];
//    int** matrix= new int*[5];
    
    matrix[0][0] = 0;
    matrix[0][1] = 850;
    matrix[0][2] = 1300;
    matrix[0][3] = 1400;
    matrix[0][4] = 2100;
    
    matrix[1][0] = 850;
    matrix[1][1] = 0;
    matrix[1][2] = 1100;
    matrix[1][3] = 2000;
    matrix[1][4] = 2300;
    
    matrix[2][0] = 1300;
    matrix[2][1] = 2100;
    matrix[2][2] = 0;
    matrix[2][3] = 800;
    matrix[2][4] = 1200;
    
    matrix[3][0] = 1400;
    matrix[3][1] = 1900;
    matrix[3][2] = 800;
    matrix[3][3] = 0;
    matrix[3][4] = 350;
    
    matrix[4][0] = 2100;
    matrix[4][1] = 2900;
    matrix[4][2] = 2400;
    matrix[4][3] = 650;
    matrix[4][4] = 0;
    
//        [9999,850,1300,1400,2100],
//        [850,9999,1100,2000,2300],
//        [1300,2100,9999,800,1200],
//        [1400,1900,800,9999,350],
//        [2100,2900,2400,650,9999]
//     ];
    int numberOfVert = 5;
//    file >> numberOfVert;
    cout << numberOfVert << endl;
    
    //Матрица смежности с весами ребер графа(101 - ребра нет, 0 ребро в себя)
//    int **matrix = (int**)malloc(sizeof(int)*numberOfVert);
//    for(int i = 0; i < numberOfVert; i++) {
//        matrix[i] = (int *) malloc(sizeof(int) * numberOfVert);
//    }
    
    //Считываем матрицу весов ребер
    
    
    cout << "Old matrix" << endl;
    printMatrix(matrix, numberOfVert);
    
    originalFloydWarshall(matrix, numberOfVert);
    
    cout << "New matrix" << endl;
    
    printMatrix(matrix, numberOfVert);
    
    return 0;
}

//5350
//4450
//6700

