#pragma once
#include "Customer.h"
class Forger :
    public Customer
{
    //attribute

public:

    //constructor
    Forger();
    Forger(string in_name, string in_tool);

    //method
    string show_name();


    virtual float buy(string tool);

    //detsurctor
    ~Forger();

};

