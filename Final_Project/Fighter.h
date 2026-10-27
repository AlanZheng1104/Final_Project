#pragma once
#include "Customer.h"
class Fighter :
    public Customer
{


public:

    //constructor
    Fighter();
    Fighter(string in_name, string in_tool);

    //method

    string show_name();


    virtual float buy(string tool);


    //deststructor
    ~Fighter();

};

