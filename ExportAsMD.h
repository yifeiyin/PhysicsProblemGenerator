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
    fileOut << "An object is placed on a plank $\\Delta{s}$ metres long, the static coefficient of friction is $\\mu_s$ and kinetic coefficient of friction is $\\mu_k$. The angle of the plank is carefully increased, A the angle $\\theta$ the object starts sliding down the plank. The acceleration of the object is $\\vec{a}$, the time it takes the object to get to the bottom of the plank is $\\Delta{t}$, and the final velocity of the object is $\\vec{v}$.\n";
    
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
            fileOut << "| " << i + 1 << " | ";
            if(p->flags[0]) fileOut << p->miu_k; fileOut << " | ";
            if(p->flags[1]) fileOut << p->miu_s; fileOut << " | ";
            if(p->flags[2]) fileOut << p->lhype; fileOut << " | ";
            if(p->flags[3]) fileOut << p->theta; fileOut << " | ";
            if(p->flags[4]) fileOut << p->time; fileOut << " | ";
            if(p->flags[5]) fileOut << p->velocity; fileOut << " | ";
            if(p->flags[6]) fileOut << p->acceleration; fileOut << " |";
            fileOut << endl;
        }
    }
    else if (mode == 2)
    {
        for(int i = 0; i < numOfProblem; i++)
        {
            Problem * p = &pproblem[i];
            fileOut << "| " << i + 1 << " | ";
            if(!p->flags[0]) fileOut << "**" << p->miu_k << "**"; else fileOut << p->miu_k; fileOut << " | ";
            if(!p->flags[1]) fileOut << "**" << p->miu_s << "**"; else fileOut << p->miu_s; fileOut << " | ";
            if(!p->flags[2]) fileOut << "**" << p->lhype << "**"; else fileOut << p->lhype; fileOut << " | ";
            if(!p->flags[3]) fileOut << "**" << p->theta << "**"; else fileOut << p->theta; fileOut << " | ";
            if(!p->flags[4]) fileOut << "**" << p->time << "**"; else fileOut << p->time; fileOut << " | ";
            if(!p->flags[5]) fileOut << "**" << p->velocity << "**"; else fileOut << p->velocity; fileOut << " | ";
            if(!p->flags[6]) fileOut << "**" << p->acceleration << "**"; else fileOut << p->acceleration; fileOut << " |";
            fileOut << endl;
        }
    }
    else
    {
        std::cout << "Invalid parameter.\n";
    }
    
    
    
    
    fileOut.close();
}

#endif /* ExportAsMD_h */
