#ifndef GAME_MAP_H
#define GAME_MAP_H
#include "property.h"
#include "role.h"

// represent game maps
static string strs[] = 
{
"_________________________________________________________________________________________",
"|Goose  |       |NEEDLES|       |       |V1     |       |       |CIF    |       |GOTO   |",
"|Nesting|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |",
"|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |",
"|       |       |       |       |       |       |       |       |       |       |       |",
"|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|",
"|       |                                                                       |       |",
"|       |                                                                       |       |",
"|-------|                                                                       |-------|",
"|OPT    |                                                                       |EIT    |",
"|       |                                                                       |       |",
"|_______|                                                                       |_______|",
"|       |                                                                       |       |",
"|-------|                                                                       |-------|",
"|BMH    |                                                                       |ESC    |",
"|       |                                                                       |       |",
"|_______|                                                                       |_______|",
"|SLC    |                                                                       |SLC    |",
"|       |                                                                       |       |",
"|       |                                                                       |       |",
"|       |                                                                       |       |",
"|_______|                                                                       |_______|",
"|       |                                                                       |       |",
"|-------|                                                                       |-------|",
"|LHI    |                                                                       |C2     |",
"|       |               ________________________________________                |       |",
"|_______|              |                                        |               |_______|",
"|UWP    |              |   ###   ###   #####  ###   ###   ###   |               |REV    |",
"|       |              |   #  #  #  #     #  #   # #   # #   #  |               |       |",
"|       |              |   ####  ####    #   #   # #   # #   #  |               |       |",
"|       |              |   #   # #   #  #    #   # #   # #   #  |               |       |",
"|_______|              |   ####  ####  #      ###   ###   ###   |               |_______|",
"|       |              |________________________________________|               |NEEDLES|",
"|-------|                                                                       |HALL   |",
"|CPH    |                                                                       |       |",
"|       |                                                                       |       |",
"|_______|                                                                       |_______|",
"|       |                                                                       |       |",
"|-------|                                                                       |-------|",
"|DWE    |                                                                       |MC     |",
"|       |                                                                       |       |",
"|_______|                                                                       |_______|",
"|PAC    |                                                                       |COOP   |",
"|       |                                                                       |FEE    |",
"|       |                                                                       |       |",
"|       |                                                                       |       |",
"|_______|                                                                       |_______|",
"|       |                                                                       |       |",
"|-------|                                                                       |-------|",
"|RCH    |                                                                       |DC     |",
"|       |                                                                       |       |",
"|_______|_______________________________________________________________________|_______|",
"|DC Tims|       |       |NEEDLES|       |MKV    |TUITION|       |SLC    |       |COLLECT|",
"|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |",
"|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |",
"|       |       |       |       |       |       |       |       |       |       |       |",
"|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|"
};

// INDEX (playerposition - map)
static int MapOne[40][2] = 
{ 
	{ 4, 1  },{  4, 9  },{ 4, 17 },{ 4, 25 },{ 4, 33 },{ 4, 41 },{ 4, 49 },{ 4, 57 },{ 4, 65 },{ 4, 73 },
	{ 4, 81 },{ 10, 81 },{ 15, 81 },{ 20, 81 },{ 25, 81 },{ 30, 81 },{ 35, 81 },{ 40, 81 },{ 45, 81 },{ 50, 81 },
	{ 55,81 },{ 55, 73 },{ 55, 65 },{ 55, 57 },{ 55, 49 },{ 55, 41 },{ 55, 33 },{ 55, 25 },{ 55, 17 },{ 55, 9 },
	{ 55, 1 },{ 50, 1  },{ 45, 1 },{ 40, 1 },{ 35, 1 },{ 30, 1 },{ 25, 1 },{ 19, 1 },{ 15, 1 },{ 10, 1 } 
};
// INDEX (Propertyposition - map)
static int MapTwo[40][2] =
{ 
	{ 1, 1 },{ 1, 9 },{ 1, 17 },{ 1, 25 },{ 1, 33 },{ 1, 41 },{ 1, 49 },{ 1, 57 },{ 1, 65 },{ 1, 73 },
	{ 1, 81 },{ 7, 81 },{ 12, 81 },{ 17, 81 },{ 22, 81 },{ 27, 81 },{ 32, 81 },{ 37, 81 },{ 42, 81 },{ 47, 81 },
	{ 52, 81 },{ 52, 73 },{ 52, 65 },{ 52 ,57 },{ 52, 49 },{ 52, 41 },{ 52, 33 },{ 52, 25 },{ 52, 17 },{ 52, 9 },
	{ 52, 1 },{ 47, 1 },{ 42, 1 },{ 37, 1 },{ 32, 1 },{ 27, 1 },{ 22, 1 },{ 17, 1 },{ 12, 1 },{ 7, 1 } 
};

class gameMap
{
public:
	
	// push every string to maps
	gameMap()
	{
		for (int i= 0; i< 57; i++)
		{
			maps.push_back(strs[i]);
		}
	}
	// print gameMap
	void printMap(map<string, AcademicProperty*> Propertys, vector<Role*>);
	// gamemaps
	vector<string> maps;
};

#endif