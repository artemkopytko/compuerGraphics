//
//  main.cpp
//  cppProject
//
//  Created by Артем Копытько on 3/19/18.
//  Copyright © 2018 Artem Kopytko. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int a, perimeter, square;
    
    while(cin >> a)
    {
        perimeter = 4 * a;
        square = pow(a,2);
    
        cout << noshowpoint << perimeter << ' ' << square << endl;
    }
    
    return 0;
}


