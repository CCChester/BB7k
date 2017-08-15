#include "gameMap.h"
#include <string>
#include <iostream>

using namespace std;

// print board
void gameMap::printMap(map<string, AcademicProperty*> Propertys, vector<Role *> roles) {
	
	for (vector<Role *>::iterator it = roles.begin(); it != roles.end(); it++)
	{	
		int index = 0;
		while (true)
		{
			char orign = maps[MapOne[(*it)->position][0]][MapOne[(*it)->position][1] + index ];
			if (orign == ' ')
			{
				maps[MapOne[(*it)->position][0]][MapOne[(*it)->position][1] + index] = (*it)->appreance[0];
				break;
			}
			else
			{
				index++;
			}
		}
	}

	for (map<string, AcademicProperty*>::iterator it = Propertys.begin(); it != Propertys.end(); it++) 
	{ 
		if ( !it->second->ownable && it->second->level > 0) 
		{
			for (int j = 1; j <= it->second->level; j++) 
			{
				maps[MapTwo[it->second->index][0]][MapTwo[it->second->index][1] + j - 1] = '^';
			}
		} 
	}

	for (vector<string>::iterator it = maps.begin(); it != maps.end(); it++)
	{
		cout << *it << endl;
	}


	for (vector<Role *>::iterator it = roles.begin(); it != roles.end(); it++)
	{
		int index = 0;
		maps[MapOne[(*it)->position][0]][MapOne[(*it)->position][1] + index ] = ' ';

		while (true)
		{
			index++;
			if (index >= 7)
				break;
			char orign = maps[MapOne[(*it)->position][0]][MapOne[(*it)->position][1] + index ];
			if (orign != ' ')
			{
				maps[MapOne[(*it)->position][0]][MapOne[(*it)->position][1] + index ] = ' ';
			}
			else
			{
				break;
			}
		}
		
	}

	for (map<string, AcademicProperty*>::iterator it = Propertys.begin(); it != Propertys.end(); it++)
	{
		if (!it->second->ownable && it->second->level > 0) 
		{
			for (int j = 1; j <= it->second->level; j++) 
			{
				maps[MapTwo[it->second->index][0]][MapTwo[it->second->index][1] + j - 1] = ' ';
			}
		}
	}
}
