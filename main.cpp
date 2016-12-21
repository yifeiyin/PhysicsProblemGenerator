//
//  main.cpp
//  PhysicsProblemGenerator
//
//  Created by YinYifei on 2016-12-19.
//
//

#include <iostream>
#include "Problem.h"
#include "ExportAsMD.h"

int main() {
    
    Problem problems[10];
    ExportAsMD(10, problems, "MD.md");
    
//    for (int i = 0; i < 10; i++)
//    {
//        Problem problem;
//        problem.PrintProblem(i + 1, "exporting7.csv");
//    }
    
    std::cout << "Done.\n";
    
    return 0;
}

