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

int main()
{
    using namespace std;
    
    cout << "Number of questions?\n> ";
    
    int nProblem;
    cin >> nProblem;
    
    cout << "Do you want answer key?\n[Y/N]> ";
    char ch;
    cin >> ch;
    cin.ignore(99999, '\n');
    
    cout << "Name of the file?\n> ";
    string fileN;
    getline(cin,fileN);
    
    if ((fileN.find(".md") != fileN.length() - 3) && (fileN.find(".MD") != fileN.length() - 3))
    {
        fileN += ".md";
    }
    
    string fileAnswer;
    fileAnswer  = fileN.substr(0,fileN.length() - 3) + "-ANSWER.md";
    
    cout << endl << endl;
    cout << "Number of questions: " << nProblem << endl;
    cout << "File name: " << fileN << endl;
    cout << "Answer file name: " << fileAnswer << endl;
    cout << endl;
    
    Problem * problems = new Problem [nProblem];
    ExportAsMD(nProblem, problems, fileN, 1);
    
    if(ch == 'Y' || ch == 'y')
        ExportAsMD(nProblem, problems, fileAnswer, 2);
    
    std::cout << "Done.\n";
    
    return 0;
}

