#pragma once
#include "Forge.h"
#include "Forge_V2.h"
class Forge_V3 :
    public Forge_V2
{

    //attribute
    int num_armor;
    int num_greatsword;
    int num_greathammer;
    int num_gold;
    int num_dsilver;

public:
    //constructor

    Forge_V3();

    Forge_V3(Forge_V2& inv, int in_armor = 0, int in_greatsword = 0, int in_greathammer = 0, int in_gold = 0, int in_dsilver = 0);


    //method
    void show_inv(Human& human);

    virtual void show_inv_2();

    virtual void ordering(Store& store, Human& human);

    virtual void create();

    virtual void sell(Customer& perosn, Human& player);



    //destructor

};

