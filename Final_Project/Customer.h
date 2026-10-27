#pragma once
#include "Human.h"

class Customer :
    public Human
{
    //attribute
protected:
    string special_tool;

public:

    //constructor
    Customer();

    Customer(string in_name);


    //method
    virtual string show_name();
    virtual float buy(string tool);

    string show_tool();




    //destructor
    ~Customer();
};

