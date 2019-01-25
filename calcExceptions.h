#ifndef CALCEXCEPTIONS_H
#define CALCEXCEPTIONS_H

#include <exception>

struct DivisionByZeroException : std::exception
{
    const char * what () const throw ()
    {
        return "Division by zero!";
    }
};

#endif
