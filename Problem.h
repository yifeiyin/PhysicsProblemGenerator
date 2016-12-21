//
//  Problem.h
//  PhysicsProblemGenerator
//
//  Created by YinYifei on 2016-12-19.
//
//

#ifndef Problem_h
#define Problem_h

#include <ctime>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>

class Problem
{
private:
    const int decimalSetting = 2;
    const double g = 9.8;
    int type = -1;
    double miu_k = 0.0;
    double miu_s = 0.0;
    double theta = 0.0;
    double lhype = 0.0;
    double time = 0.0;
    double velocity = 0.0;
    
    double NumG (double min, double max, int deci = -1)
    {
        if (deci == -1)
            deci = decimalSetting;
        
        min *= pow(10, deci);
        max *= pow(10, deci);
        
        std::srand((int)std::time(NULL)+rand());
        
        double output = rand() % (int)(max - min) + min;
        output /= pow(10, deci);
        return output;
    }
    
    double Round (double number, int deci = -1)
    {
        if (deci == -1)
            deci = decimalSetting;
        
        double output = number * pow(10, deci);
        
        if (output - (int)output >= 0.5)
            output = (int)output + 1;
        else
            output = (int)output;
        
        output /= pow(10,deci);
        
        return output;
    }
    
public:
    Problem()
    {
        miu_k = NumG(0, 0.99);
        miu_s = NumG(miu_k + 0.01, 1);
        lhype = NumG(20, 100);
        
        theta = atan(miu_s);
        time = sqrt(
                    (lhype)/
                    (0.5 * g * (sin(theta) - miu_k * cos(theta)))
                    );
        velocity = g * (sin(theta) - miu_k * cos(theta)) * time;
        theta = theta / 3.14159265 * 180;
        SetProblemType();
    }
    
    void SetProblemType(int typ = -1)
    {
        if (typ == -1)
        {
            type = NumG(1,5,0);
        }
        else
        {
            type = typ;
        }
    }
    
    void PrintProblem()
    {
        if (type == 1)
        {
            
        }
        else if (type == 2)
        {
            
        }
        else if (type == 3)
        {
            
        }
        else if (type == 4)
        {
            
        }
        else
        {
            std::cout << "Unexpected error.\n";
        }
    }
    
    void PrintAll()
    {
        
        
        std::cout << "Unrounded numbers: " << std::endl
                  << "miu_k = " << miu_k << std::endl
                  << "miu_s = " << miu_s << std::endl
                  << "lhype = " << lhype << std::endl
                  << "theta = " << theta << " deg" << std::endl
                  << "time  = " << time << std::endl
                  << "veloc = " << velocity << std::endl
                  << "----------------" << std::endl;
        
        std::ios_base::fmtflags originalFlags = std::cout.flags();
        std::cout.precision(3);
        std::cout << std::fixed;
        
        std::cout << "Problem: " << std::endl
                  << "\t| miu_k\t| miu_s\t| lhype\t| theta\t| time\t| velocity\t|"
                  << std::endl
                  << " \t+----------\t+----------\t+----------\t+----------\t+----------\t+----------\t+"
                  << std::endl
                  << "\t| "
                  << miu_k << "\t| "
                  << miu_s << "\t| "
                  << lhype << "\t| "
                  << theta << "\t| "
                  << time << "\t| "
                  << velocity << "\t|"
                  << std::endl
                  << "\n================\n" << std::endl;
        
        std::cout.flags(originalFlags);
    }
    
    void ExportAsCsvFile(int counter = 0, std::string fileName = "untitled.csv")
    {
        bool isFileExist = false;
        
        std::ifstream fileIn;
        fileIn.open(fileName);
        
        if(fileIn.is_open())
            isFileExist = true;
        // else
        //     isFileExist = false;
        
        fileIn.close();
        
        std::ofstream fileOut;
        fileOut.open(fileName, std::ios::out | std::ios::app);
        
        if (!isFileExist) // Add a heading
        {
            fileOut << "#,miu_k,miu_s,lhype,theta(°),time,velocity\n";
        }
        
        std::ios_base::fmtflags originalFlags = std::cout.flags();
        fileOut.precision(decimalSetting); // Format the decimal setting
        fileOut << std::fixed;
        
        fileOut << counter << ","
                << miu_k << ","
                << miu_s << ","
                << lhype << ","
                << theta << ","
                << time << ","
                << velocity << "\n";
        
        std::cout.flags(originalFlags); // Reset the decimal setting
        
        fileOut.close();
    }
    
    void PrintContinuously()
    {
        std::ios_base::fmtflags originalFlags = std::cout.flags();
        std::cout.precision(3);
        std::cout << std::fixed;
        
        std::cout << " \t+----------\t+----------\t+----------\t+----------\t+----------\t+----------\t+"
                  << std::endl
                  << "\t| "
                  << miu_k << "\t| "
                  << miu_s << "\t| "
                  << lhype << "\t| "
                  << theta << "\t| "
                  << time << "\t| "
                  << velocity << "\t|"
                  << std::endl;
        
        std::cout.flags(originalFlags);
    }
};

#endif /* Problem_h */
