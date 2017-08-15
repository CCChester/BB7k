#include "role.h"
#include <string>
#include <iostream>
#include "gameControler.h"
#include <sstream>

using namespace std;

char Role::selectApperance()
{
	while (true) 
	{
		char ch;
		for (map<char, bool>::iterator it = roles.begin(); it != roles.end(); it++)
		{
			if ( !it->second )
			{
				cout << " " << it->first;
			}		
		}

		cout << endl << "Please input a name :";
		cin >> ch;
		cin.get();
		for (map<char, bool>::iterator it = roles.begin(); it != roles.end(); it++)
		{
			if (it->first == ch && !it->second)
			{
				it->second = true;
				return ch;
			}
		}

		cout << "Name not found!" << endl;
	}
}

void Role::move(int steps)
{
	int oldpos = position;
	position = (steps + position) % 40;

	// osap
	if ((oldpos < 20 && position >= 20))
	{
		cout << "pass osap , collect 200!" << endl;
		this->receive(200);
	}
}

void Role::pay(int cost) 
{
	cout << this->appreance << " have to pay "<< cost << endl;
	
	if (cost > this->cash)
	{
		haveToPay = cost;
		this->IsMoneyEnough = false;
		cout << "Cash not enough!! "<< endl;
	}
	else
	{
		cash -= cost;
	}
}

void Role::receive(int cashs)
{
	cash += cashs;
}

void Role::printAll()
{
	cout << appreance << " has cash :" << cash << endl;

	if(propertys.size() > 0)
	{
		cout << "AcademicProperty lists :" << endl;
		for (vector<AcademicProperty*>::iterator it = propertys.begin(); it != propertys.end(); it++)
		{
			cout << (*it)->name << endl;;
		}
	}

	if (opropertys.size() > 0)
	{
		cout << "OwnableProperty lists:" << endl;
		for (vector<OwnableProperty*>::iterator it = opropertys.begin(); it != opropertys.end(); it++)
		{
			cout << (*it)->name << " " << endl;
		}
	}
}

bool Role::foundBuild(string& name, AcademicProperty*& p)
{
	for (vector<AcademicProperty*>::iterator it = propertys.begin(); it != propertys.end(); it++)
	{
		if ((*it)->name == name)
		{
			p = *it;
			return true;
		}
	}
	return false;
}

bool Role::OwnallBlock(string name)
{
	vector<AcademicProperty*>& vec= gameControler::AcPropertys[name];

	for (vector<AcademicProperty*>::iterator it = vec.begin(); it != vec.end(); it++) 
	{
		if (this != (*it)->owner ) 
		{
			return false;
		}
	}
	return true;
}

void Role::buyImprove(string build_name)
{
	AcademicProperty* p = NULL;
	
	if (foundBuild(build_name, p))
	{
		if (cash > p->improve_cost)
		{
			if (p->level == 4)
			{
				if(!OwnallBlock(p->block_type))
					return ;
			}
			p->level++;
			cash -= p->improve_cost;
		}
		else
		{
			cout << "cash not enough for improve" << endl;
		}
	}
	else
	{
		cout << "Property not belong to you or can't improve!" << endl;
	}
}

void Role::sellImprove(string build_name)
{
	AcademicProperty* p = NULL;
	
	if (foundBuild(build_name, p))
	{
		if (p->level>=1)
		{
			p->level--;
			cash += p->improve_cost/2;
		}
		else
		{
			cout << "no improvement can be selled" << endl;
		}
	}
	else
	{
		cout << "Property not belong to you!" << endl;
	}
}

void Role::bankrupt()
{
	for (vector<AcademicProperty*>::iterator it = propertys.begin(); it != propertys.end(); it++) 
	{
		(*it)->owner = NULL;
		(*it)->ownable = true;
		(*it)->level = 0;
		(*it)->Mortgagesed = false;
	}

	for (vector<OwnableProperty*>::iterator it = opropertys.begin(); it != opropertys.end(); it++) 
	{
		(*it)->owner = NULL;
		(*it)->ownable = true;
		(*it)->Mortgagesed = false;
	}

	this->quit = true;
}

int Role::worth()
{
	int sum = cash;
	for (vector<AcademicProperty*>::iterator it = propertys.begin(); it != propertys.end(); it++)
	{
		sum += ((*it)->purchase_cost + (*it)->improve_cost*(*it)->level);
	}

	for (vector<OwnableProperty*>::iterator it = opropertys.begin(); it != opropertys.end(); it++)
	{
		if((*it)->name == "MKV" || (*it)->name == "UWP" || (*it)->name == "V1" || (*it)->name == "REV")
			sum += 200;
		else
			sum += 100;
	}

	return sum;
}

void Role::mortgage(string property_name)
{	
	AcademicProperty* p = NULL;

	if (foundBuild(property_name, p))
	{	
		if (p->level > 0)
		{
			cout << "You must sell all improves!"<< endl;
		}
		else
		{
			if (!p->Mortgagesed)
			{
				int receive = p->purchase_cost / 2;
				p->Mortgagesed = true;
				cout << "You receive " << receive << endl;
				this->receive(receive);
			}
			else
			{
				cout << "This build had been Mortgagesed!" << endl;
			}

		}	
	}
	else
	{
		cout << "You don't own this property!" << endl;
	}
}	

void Role::unmortgage(string property_name)
{
	AcademicProperty* p = NULL;

	if (foundBuild(property_name, p))
	{	
		if (p->level > 0 && p->Mortgagesed)
		{
			cout << "You must sell all improves!" << endl;
		}
		else
		{
			if (p->Mortgagesed)
			{
				int pay = p->purchase_cost * 0.6;
				if (pay <= cash)
				{
					this->pay(pay);
					p->Mortgagesed = false;
				}
				else
				{
					cout << "Your money are not enough to unmortgage!" << endl;
				}
			}
			else
			{
				cout << "This build haven't been Mortgagesed!" << endl;
			}
		}	
	}
	else
	{
		cout << "You don't own this property!" << endl;
	}
}

void Role::removeBuild(string build_name)
{
	for (vector<AcademicProperty*>::iterator it = propertys.begin(); it != propertys.end(); it++)
	{
		if (build_name == (*it)->name)
		{
			propertys.erase(it);
			break;
		}
	}
}

Role::Role(string str)
{
	quit = false;
	IsMoneyEnough = true;
	haveToPay = 0;
	gyms = 0;
	ress = 0;
	indec = false;
	dctimes = 0;
	cups = 0;
	propertys.clear();

	stringstream ss(str);
	ss >> this->appreance;
	ss >> this->cups;
	ss >> this->cash;
	ss >> this->position;

	// in DC times
	if (this->position == 30) 
	{
		ss >> this->indec;
		if (this->indec)
		{
			ss >> this->dctimes;
		}		
	}
}
