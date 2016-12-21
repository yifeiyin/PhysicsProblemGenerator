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
    
    std::cout.precision(6);
    
    for (int i = 0; i < 30; i++)
    {
        Problem problem;
        // problem.ExportAsCsvFile(i + 1, "exporting2.csv");
        problem.PrintAll();
    }
    
    return 0;
}

