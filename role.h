#ifndef ROLE_H
#define ROLE_H
#include "property.h"
#include <vector>
#include <map>
#include <iostream>

class Role
{
public:
    //initial values
    Role()
    {
        appreance = selectApperance();
        cash = 1500;
        quit = false;
        IsMoneyEnough = true;
        haveToPay = 0;
        gyms = 0;
        ress = 0;
        indec = false;
        dctimes = 0;
        cups = 0;
        position = 20;
        propertys.clear();
    }
    // available symbol represented for players
    Role(string str);
    // pick a symbol for each player
    static char selectApperance();
    //movement
    void move(int);
    // pay money
    void pay(int);// player receive money
    void receive(int);
    // improve up
    void buyImprove(string build_name);
    // decrease improvement
    void sellImprove(string build_name);
    // Dropout the game/bankrupt
    void bankrupt();
    // mortgage building
    void mortgage(string);
    // unmortgage building
    void unmortgage(string);
    
    // OwnallBlock: to check wether a player have all buildings in the same block
    bool OwnallBlock(string name);
    // foundBuild: to check whether a building is owned by looking up their name
    bool foundBuild(string&, AcademicProperty*&);
    // removeBuild: remove Building from the owned list(assets)
    void removeBuild(string);
    // player’s assets
    int worth();
    // printAll: print all assets of a player
    void printAll();
    
public:
    // initlize: whether initialized before
    static bool initlize;
    
    static map<char, bool> roles;
    
    string appreance;
    //player’s cash
    int	cash;
    //player’s location
    int position;
    
    //quit: ends game
    bool quit;
    // total # of gyms
    int gyms;
    //  total # of residences
    int ress;
    // indec: whether in DC Tims line
    bool indec;
    // # of time rolling in dc times’ line
    int dctimes;
    // number of tim cups
    int cups;
    
    bool IsMoneyEnough;
    // haveToPay: the amount of money that have to pay
    int haveToPay;
    // the list of owned buildings
    vector<AcademicProperty*> propertys;
    vector<OwnableProperty*> opropertys;
};
#endif
