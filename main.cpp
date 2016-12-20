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
    for (int i = 0; i < 30; i++)
    {
        Problem problem;
        if (i == 0) problem.PrintAll();
        else problem.PrintContinuously();
    }
    
    return 0;
}

