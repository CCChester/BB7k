#ifndef Property_H
#define Property_H
#include <vector>
#include <map>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>

class gameControler;
class Role;
using namespace std;

class Property
{
public:
    
    Property(string name)
    {
        this->name = name;
        this->type = 0;
        this->Mortgagesed = false;
    }
    // process: how player process during game
	virtual void process(Role* role, gameControler* game);
    // print: print all information of Property
	virtual void print(ofstream&);
public:
    // the type of property
    int type;
    string name;
    bool Mortgagesed;
};

class AcademicProperty : public Property
{
public:
    // initial values
    AcademicProperty(string name, string block_type, int purchase_cost, int improve_cost, int index) : Property(name)
    {
        this->type = 1;
        this->level = 0;
        this->block_type = block_type;
        this->purchase_cost = purchase_cost;
        this->improve_cost = improve_cost;
        this->ownable = true;
        this->owner = NULL;
        this->index = index;
    }
    // IsOwned: whether player owned this Property
    bool	IsOwned(Role* role);
    
    virtual void process(Role* role, gameControler* game);
    virtual void print(ofstream&);
public:
    //level: indicate the level of improvement
    int level;
    // block_type: the type of block
    string block_type;
    //purchase_cost: the price of buying a property
    int purchase_cost;
    //improve_cost:the price of improving a property
    int improve_cost;
    //ownable: indicate if this property is able to own by players
    bool ownable;
    //owner: the owner of a property
    Role* owner;
    //index: the index/location of a property
    int index;
    // tuitions price list
    static map<string, vector<int> > Tuitions;
};

class OwnableProperty : public Property
{
public:
	// default values
	OwnableProperty(string name) : Property(name) {
		this->type = 2;
		this->ownable = true;
		this->owner = NULL;
	}
	//IsOwned: whether player owned this Property
	bool	IsOwned(Role* role);
	virtual void process(Role* role, gameControler* game);
	virtual void print(ofstream&);
public:
	//owner: the owner of a property
	bool ownable;
	//owner: the owner of a property
	Role* owner;
};

#endif
