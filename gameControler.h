#ifndef GAME_CONTROLER_H
#define GAME_CONTROLER_H
#include <vector>
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "role.h"
#include "property.h"
#include "gameMap.h"

class gameControler {
public:
    // MIL: players, building/properties, game map
    gameControler(int nums, bool isDebug)
    {
        this->nums = nums;
        this->liveplayers = nums;
        this->playerIndex = 0;
        this->isDebug = isDebug;
        this->rollAgain = false;
        this->needPrint = true;
        initlize();
        
        for (int i = 0; i < nums; i++)
        {
            Roles.push_back(new Role());
        }
        gamemap = new gameMap();
        
        start();
    }
    
    gameControler(string fileName);
    // dctor
    ~gameControler()
    {
        for (vector<Property*>::iterator it = allPropertys.begin(); it != allPropertys.end(); it++)
        {
            delete *it;
        }
        for (vector<Role*>::iterator it = Roles.begin(); it != Roles.end(); it++)
        {
            delete *it;
        }
        delete gamemap;
    }
    
    //Next: next player’s turn
    void Next();
    // save: save current game
    void save();
    //start: to start a new game
    void start();
    
    void initlize();
    
    void AfterMove();
    
    void staticInit();
    //hasPlayer:check wether if the game end or not by checking if there is any player left
    bool hasPlayer();
    
    void Move(int steps);
    
    void splitStr(string, vector<int>&);
    //Trade: trade between two players with 3 different trade methods
    void Trade(string, string, string);
    
public:
    
    map<string, AcademicProperty*> Propertys;
    static map<string, vector<AcademicProperty*> > AcPropertys;
    vector<Property*> allPropertys;
    
    vector<Role*> Roles;
    // hasMoved: check if player has moved or not
    bool hasMoved;
    // isEnd: check if the game ends or not
    bool isEnd;
    // isDebug: in testing mode or not
    bool isDebug;
    //nums: total number of players
    int nums;
    //liveplayers: total number of players that still in game
    int liveplayers;
    //playerIndex: the position of player before player before
    int playerIndex;
    
    gameMap* gamemap;
    
    //rollAgian: whether player is eligible to roll dices for second times
    bool rollAgain;
    
    bool needPrint;
    
    int rollA;
    
    int rollB;
};

#endif
