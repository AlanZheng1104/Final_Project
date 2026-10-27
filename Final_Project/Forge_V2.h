#pragma once
#include "Forge.h"
class Forge_V2 :
    public Forge
{
    friend class Forge;
    friend class Forge_V3;

protected:
    //attribute
    int num_mace;
    int num_anvil;
    int num_titanium;
    int num_carbon;

public:

    //constructor
    Forge_V2();
    Forge_V2(Forge& inv, int in_mace = 0, int in_anvil = 0, int in_titanium = 0, int in_carbon = 0);

    //method

    virtual void show_inv(Human& human);

    virtual void show_inv_2();

    virtual void ordering(Store& store, Human& human);

    virtual void create();
  
    virtual void sell(Customer& perosn, Human& player);


    //destructor

};

