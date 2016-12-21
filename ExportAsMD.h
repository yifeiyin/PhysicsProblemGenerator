//
//  ExportAsMD.h
//  PhysicsProblemGenerator
//
//  Created by YinYifei on 2016-12-21.
//
//

#ifndef ExportAsMD_h
#define ExportAsMD_h

#include "Problem.h"
#include <iostream>
#include <fstream>
#include <string>

void ExportAsMD(int numOfProblem, Problem * pproblem = nullptr, std::string fileName = "untitled.md", int mode = 0)
{
    if (pproblem == nullptr)
        return;
    
    /*
    bool isFileExist = false;
    std::ifstream fileIn;
    fileIn.open(fileName);
    if(fileIn.is_open())
        isFileExist = true;
    fileIn.close();
    */
    
    using std::endl;
    
    std::ofstream fileOut;
    fileOut.open(fileName);
    
    fileOut << "#Physics Problems\n";
    fileOut << "An object is placed on a plank L metres long, the static coefficient of friction is $\\mu_s$ and kinetic coefficient of friction is $\\mu_k$. The angle of the plank is carefully increased, A the angle $\\theta$ the object starts sliding down the plank. The acceleration of the object is $\\vec{a}$, the time it takes the object to get to the bottom of the plank is $\\Delta{t}$, and the final velocity of the object is $\\vec{v}$.\n";
    
    fileOut << "Diagram: \n[![diagram-friction.png](https://s30.postimg.org/6gfszcrht/diagram_friction.png)](https://postimg.org/image/ssdlsqqlp/)\n";
    
    fileOut << "| # | $\\mu_k$ | $\\mu_s$ | $\\Delta{s}$ | $\\theta$ | $\\Delta{t}$ | $\\vec{v}$ | $\\vec{a}$ |" << endl;
    fileOut << "| -: | -: | -: | -: | -: | -: | -: | -: |" << endl;
    
    fileOut.precision(2);
    fileOut << std::fixed;

    if (mode == 0)
    {
        for(int i = 0; i < numOfProblem; i++)
        {
            Problem * p = &pproblem[i];
            fileOut << "| " << i + 1 << " | " << p->miu_k << " | " << p->miu_s << " | " << p->lhype << " | "
            << p->theta << " | " << p->time << " | " << p->velocity << " | " << p->acceleration << " |"
            << endl;
        }
    }
    else if (mode == 1)
    {
        for(int i = 0; i < numOfProblem; i++)
        {
            Problem * p = &pproblem[i];
            fileOut << "| " << i + 1 << " | " << p->miu_k << " | " << p->miu_s << " | " << p->lhype << " | "
            << p->theta << " | " << p->time << " | " << p->velocity << " | " << p->acceleration << " |"
            << endl;
        }
    }
    else if (mode == 2)
    {
        
    }
    else
    {
        std::cout << "Invalid parameter.\n";
    }
    
    
    
    
    fileOut.close();
}

#endif /* ExportAsMD_h */
