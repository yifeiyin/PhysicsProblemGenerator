//
//  Mathematic.h
//  PhysicsProblemGenerator
//
//  Created by YinYifei on 2016-12-20.
//
//

#ifndef Mathematic_h
#define Mathematic_h

double NumG(double min, double max, int precision = 0)
{
    min *= pow(10, precision);
    max *= pow(10, precision);
    
    std::srand((int)std::time(NULL)+rand());
    
    double output = rand() % (int)(max - min) + min;
    output /= pow(10, precision);
    return output;
}

double Round(double number, int precision = 0)
{
    double output = number * pow(10, precision);
    
    if (output - (int)output >= 0.5)
        output = (int)output + 1;
    else
        output = (int)output;
    
    output /= pow(10,precision);
    
    return output;
}

#endif /* Mathematic_h */
