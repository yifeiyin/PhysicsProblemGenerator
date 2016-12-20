//
//  Problem.h
//  PhysicsProblemGenerator
//
//  Created by YinYifei on 2016-12-19.
//
//

#ifndef Problem_hpp
#define Problem_hpp

#include <ctime>
#include <cmath>
#include <iostream>

class Problem
{
private:
    const int decimal_setting = 2;
    const double g = 9.8;
    int type = -1;
    double miu_k = 0.0;
    double miu_s = 0.0;
    double theta = 0.0;
    double lhype = 0.0;
    double time = 0.0;
    double velocity = 0.0;
    
    double NumG ( double min, double max, int setting = -1)
    {
        if (setting == -1)
            setting = decimal_setting;
        
        int i_min = Round(min, setting) * pow(10, setting);
        int i_max = Round(max, setting) * pow(10, setting);
        
        std::srand((int)std::time(NULL)+rand());
        
        double output = rand() % (i_max - i_min) + i_min;
        output = Round(output / pow(10, setting), setting);
        return output;
    }
    
    double Round (double number, int setting = -1)
    {
        if (setting == -1)
            setting = decimal_setting;
        
        double output = number * pow(10, setting);
        
        if (output - (int)output >= 0.5)
            output = (int)output + 1;
        else
            output = (int)output;
        
        output /= pow(10,setting);
        
        return output;
    }
    
public:
    Problem()
    {
        miu_k = NumG(0,1);
        miu_s = NumG(miu_k+0.1,1);
        lhype = NumG(20,100);
        
        theta = atan(miu_s);
        time = sqrt(
                    (lhype)/
                    (0.5 * g * (sin(theta) - miu_k * cos(theta)))
                    );
        velocity = g * (sin(theta) - miu_k * cos(theta)) * time;
        theta = theta / 3.14159265 * 180;
        SetProblem();
    }
    
    void SetProblem(int type = -1)
    {
        if (type == -1)
        {
            
        }
    }
    
    void PrintAll()
    {
        std::cout << "Problem: " << std::endl
        << "miu_k = " << miu_k << std::endl
        << "miu_s = " << miu_s << std::endl
        << "lhype = " << lhype << std::endl
        << "theta = " << theta << " deg" << std::endl
        << "time  = " << time << std::endl
        << "veloc = " << velocity << std::endl
        << "----------------" << std::endl;
    }
    
};

#endif /* Problem_h */
