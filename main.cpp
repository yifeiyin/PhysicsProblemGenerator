//
//  main.cpp
//  PhysicsProblemGenerator
//
//  Created by YinYifei on 2016-12-19.
//
//

#include <iostream>
#include "Problem.h"

int main() {
    
    for (int i = 0; i < 10; i++)
    {
        Problem problem;
        problem.ExportAsCsvFile(i + 1, "exporting4.csv");
    }
    
    std::cout << "Done.\n";
    
    return 0;
}

