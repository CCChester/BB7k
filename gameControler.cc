#include "gameControler.h"
#include <sstream>
#include <fstream>
#include <iostream>


bool Role::initlize = false;
map<char, bool> Role::roles;
map<string, vector<int> > AcademicProperty::Tuitions;
map<string, vector<AcademicProperty*> > gameControler::AcPropertys;

static bool isNum(string str)
{
	stringstream sin(str);
	double d;
	char c;

	if (!(sin >> d))
		return false;
	if (sin >> c)
		return false;

	return true;
}

void gameControler::splitStr(string str, vector<int>& vec)
{
	stringstream stream(str);
	int temp;
	int i = 0;

	while(i < 6)
	{ 
		i++;
		stream >> temp;
		vec.push_back(temp);
	}
}

void gameControler::staticInit()
{

	if (!Role::initlize)
	{
		Role::initlize = true;
		Role::roles['G'] = false;
		Role::roles['B'] = false;
		Role::roles['D'] = false;
		Role::roles['P'] = false;
		Role::roles['S'] = false;
		Role::roles['$'] = false;
		Role::roles['L'] = false;
		Role::roles['T'] = false;
	}
	
	splitStr("18 90 250  700 875 1050", AcademicProperty::Tuitions["EV1"]);
	splitStr("18 90 250  700 875 1050", AcademicProperty::Tuitions["EV2"]);
	splitStr("20 100 300 700 925 1100", AcademicProperty::Tuitions["EV3"]);
	splitStr("22 110 330 800 975 1150", AcademicProperty::Tuitions["PHYS"]);
	splitStr("22 110 330 800 975 1150", AcademicProperty::Tuitions["B1"]);
	splitStr("24 120 360 850 1025 1200", AcademicProperty::Tuitions["B2"]);
	splitStr("26 130 390 900 1100 1275", AcademicProperty::Tuitions["EIT"]);
	splitStr("26 130 390 900 1100 1275", AcademicProperty::Tuitions["ESC"]);
	splitStr("28 150 450 1000 1200 1400", AcademicProperty::Tuitions["C2"]);
	splitStr("35 175 500 1100 1300 1500", AcademicProperty::Tuitions["MC"]);
	splitStr("50 200 600 1400 1700 2000", AcademicProperty::Tuitions["DC"]);
	splitStr("2 10 30 90 160 250", AcademicProperty::Tuitions["AL"]);
	splitStr("4 20 60 180 320 450", AcademicProperty::Tuitions["ML"]);
	splitStr("6 30 90 270 400 550", AcademicProperty::Tuitions["ECH"]);
	splitStr("6 30 90 270 400 550", AcademicProperty::Tuitions["PAS"]);
	splitStr("8 40 100 350 450 600", AcademicProperty::Tuitions["HH"]);
	splitStr("10 50 150 450 625 750", AcademicProperty::Tuitions["RCH"]);
	splitStr("10 50 150 450 625 750", AcademicProperty::Tuitions["DWE"]);
	splitStr("12 60 180 500 700 900", AcademicProperty::Tuitions["CPH"]);
	splitStr("14 70 250 550 750 950", AcademicProperty::Tuitions["LHI"]);
	splitStr("14 70 250 550 750 950", AcademicProperty::Tuitions["BMH"]);
	splitStr("16 80 200 600 800 1000", AcademicProperty::Tuitions["OPT"]);
	
	srand(time(NULL));
}

void gameControler::initlize()
{
	staticInit();

	Propertys["EV1"] = new AcademicProperty("EV1", "ENV", 220, 150, 1);
	Propertys["EV2"] = new AcademicProperty("EV2", "ENV", 220, 150, 3);
	Propertys["EV3"] = new AcademicProperty("EV3", "ENV", 240, 150, 4);

	Propertys["PHYS"] = new AcademicProperty("PHYS", "Sci1", 260, 150, 6);
	Propertys["B1"] = new AcademicProperty("B1", "Sci1", 260, 150, 7);
	Propertys["B2"] = new AcademicProperty("B2", "Sci1", 280, 150, 9);

	Propertys["EIT"] = new AcademicProperty("EIT", "Sci2", 300, 200, 11);
	Propertys["ESC"] = new AcademicProperty("ESC", "Sci2", 300, 200, 12);
	Propertys["C2"] = new AcademicProperty("C2", "Sci2", 320, 200, 14);

	Propertys["MC"] = new AcademicProperty("MC", "Math", 350, 200, 17);
	Propertys["DC"] = new AcademicProperty("DC", "Math", 400, 200, 19);

	Propertys["AL"] = new AcademicProperty("AL", "Arts1", 40, 50, 21);
	Propertys["ML"] = new AcademicProperty("ML", "Arts1", 60, 50, 23);

	Propertys["ECH"] = new AcademicProperty("ECH", "Arts2", 100, 50, 26);
	Propertys["PAS"] = new AcademicProperty("PAS", "Arts2", 100, 50, 28);
	Propertys["HH"] = new AcademicProperty("HH", "Arts2", 120, 50, 29);

	Propertys["RCH"] = new AcademicProperty("RCH", "Eng", 140, 100, 31);
	Propertys["DWE"] = new AcademicProperty("DWE", "Eng", 140, 100, 33);
	Propertys["CPH"] = new AcademicProperty("CPH", "Eng", 160, 100, 34);

	Propertys["LHI"] = new AcademicProperty("LHI", "Health", 180, 100, 36);
	Propertys["BMH"] = new AcademicProperty("BMH", "Health", 180, 100, 38);
	Propertys["OPT"] = new AcademicProperty("OPT", "Health", 200, 100, 39);

	AcPropertys["ENV"].push_back((AcademicProperty*)Propertys["EV1"]);
	AcPropertys["ENV"].push_back((AcademicProperty*)Propertys["EV2"]);
	AcPropertys["ENV"].push_back((AcademicProperty*)Propertys["EV3"]);

	AcPropertys["Sci1"].push_back((AcademicProperty*)Propertys["PHYS"]);
	AcPropertys["Sci1"].push_back((AcademicProperty*)Propertys["B1"]);
	AcPropertys["Sci1"].push_back((AcademicProperty*)Propertys["B2"]);

	AcPropertys["Sci2"].push_back((AcademicProperty*)Propertys["EIT"]);
	AcPropertys["Sci2"].push_back((AcademicProperty*)Propertys["ESC"]);
	AcPropertys["Sci2"].push_back((AcademicProperty*)Propertys["C2"]);

	AcPropertys["Math"].push_back((AcademicProperty*)Propertys["MC"]);
	AcPropertys["Math"].push_back((AcademicProperty*)Propertys["DC"]);

	AcPropertys["Arts1"].push_back((AcademicProperty*)Propertys["AL"]);
	AcPropertys["Arts1"].push_back((AcademicProperty*)Propertys["ML"]);

	AcPropertys["Arts2"].push_back((AcademicProperty*)Propertys["ECH"]);
	AcPropertys["Arts2"].push_back((AcademicProperty*)Propertys["PAS"]);
	AcPropertys["Arts2"].push_back((AcademicProperty*)Propertys["HH"]);

	AcPropertys["Eng"].push_back((AcademicProperty*)Propertys["RCH"]);
	AcPropertys["Eng"].push_back((AcademicProperty*)Propertys["BMH"]);
	AcPropertys["Eng"].push_back((AcademicProperty*)Propertys["OPT"]);

	AcPropertys["Health"].push_back((AcademicProperty*)Propertys["LHI"]);
	AcPropertys["Health"].push_back((AcademicProperty*)Propertys["EV2"]);
	AcPropertys["Health"].push_back((AcademicProperty*)Propertys["EV3"]);
	
	allPropertys.push_back(new Property("GooseNesting"));
	allPropertys.push_back(Propertys["EV1"]);
	allPropertys.push_back(new Property("NeedlesHall"));
	allPropertys.push_back(Propertys["EV2"]);
	allPropertys.push_back(Propertys["EV3"]);
	allPropertys.push_back(new OwnableProperty("V1"));
	allPropertys.push_back(Propertys["PHYS"]);
	allPropertys.push_back(Propertys["B1"]);
	allPropertys.push_back(new OwnableProperty("CIF"));
	allPropertys.push_back(Propertys["B2"]);

	allPropertys.push_back(new Property("GotoTims"));
	allPropertys.push_back(Propertys["EIT"]);
	allPropertys.push_back(Propertys["ESC"]);
	allPropertys.push_back(new Property("SLC"));
	allPropertys.push_back(Propertys["C2"]);
	allPropertys.push_back(new OwnableProperty("REV"));
	allPropertys.push_back(new Property("NeedlesHall"));
	allPropertys.push_back(Propertys["MC"]);
	allPropertys.push_back(new Property("Coopfee"));
	allPropertys.push_back(Propertys["DC"]);
	
	allPropertys.push_back(new Property("OSAP"));
	allPropertys.push_back(Propertys["AL"]);
	allPropertys.push_back(new Property("SLC"));
	allPropertys.push_back(Propertys["ML"]);
	allPropertys.push_back(new Property("Tuition"));
	allPropertys.push_back(new OwnableProperty("MKV"));
	allPropertys.push_back(Propertys["ECH"]);
	allPropertys.push_back(new Property("NeedlesHall"));
	allPropertys.push_back(Propertys["PAS"]);
	allPropertys.push_back(Propertys["HH"]);
	
	allPropertys.push_back(new Property("DCTIMES"));
	allPropertys.push_back(Propertys["RCH"]);
	allPropertys.push_back(new OwnableProperty("PAC"));
	allPropertys.push_back(Propertys["DWE"]);
	allPropertys.push_back(Propertys["CPH"]);
	allPropertys.push_back(new OwnableProperty("UWP"));
	allPropertys.push_back(Propertys["LHI"]);
	allPropertys.push_back(new Property("SLC"));
	allPropertys.push_back(Propertys["BMH"]);
	allPropertys.push_back(Propertys["OPT"]);
}

void gameControler::start()
{
	char chose[30];
	hasMoved = false;
	
	while (hasPlayer()) 
	{	

		gamemap->printMap(Propertys, Roles);

		cout << "Player " << Roles[playerIndex]->appreance << " Please input your chose:";

		cin.getline(chose, 30);
		string command = chose;

		if (command.find("roll") != string::npos)
		{
			if (hasMoved)
			{
				cout << "You have rolled already!" << endl;
				continue;
			}

			if (this->isDebug)
			{
				if (command.size() > 5)
				{
					stringstream stream(command);
					int moves = 0;
					int moves2 = 0;
					string s;
					stream >> s;
					stream >> moves;
					stream >> moves2;
					if (moves == moves2)
					{
						rollAgain = true;
					}
					Move(moves2 + moves);
				}
				else
				{
					Move(0);
				}			
			}
			else
			{
				Move(0);				
			}
			needPrint = false;
			gamemap->printMap(Propertys, Roles);
			AfterMove();
			
			if (rollAgain == true)
			{
				cout << "Roll same,Roll again!" << endl;
				Move(0);
				gamemap->printMap(Propertys, Roles);
				AfterMove();
				rollAgain = false;
			}
			hasMoved = true;
		}
		else if (command.find("next") != string::npos)
		{
			if (!Roles[playerIndex]->IsMoneyEnough)
			{
				cout << "You must have to pay or bankrupt !"<< endl;
				continue;
			}
			if (!hasMoved)
			{
				cout << "You must roll once!" << endl;
				continue;
			}
			Next();
			hasMoved = false;
		}
		else if (command.find("trade") != string::npos)
		{
			stringstream stream(command);
			string name;
			string feedone;
			string feedtwo;
			stream >> name;
			stream >> name;
			stream >> feedone;
			stream >> feedtwo;

			Trade(name, feedone, feedtwo);
		}
		else if (command.find("improve") != string::npos)
		{
			stringstream stream(command);
			string pro;
			stream >> pro; 
			stream >> pro;
			
			if (command.find("buy") != string::npos)
			{
				Roles[playerIndex]->buyImprove(pro);
			}
			else if(command.find("sell") != string::npos)
			{
				Roles[playerIndex]->sellImprove(pro);
			}
			else
			{
				cout << "Command error!" << endl;
			}
		}
		else if (command.find("unmortgage") != string::npos)
		{
			stringstream stream(command);
			string pro;
			stream >> pro;
			stream >> pro;

			Roles[playerIndex]->unmortgage(pro);
		}
		else if (command.find("mortgage") != string::npos)
		{
			stringstream stream(command);
			string pro;
			stream >> pro;
			stream >> pro;

			Roles[playerIndex]->mortgage(pro);
		}
		else if (command.find("bankrupt") != string::npos)
		{
			Roles[playerIndex]->bankrupt();
			this->Roles.erase((this->Roles.begin() + playerIndex));
		}
		else if (command.find("assets") != string::npos)
		{
			//cout << Roles[playerIndex]->appreance << " has cash :" << Roles[playerIndex]->cash << endl;
			Roles[playerIndex]->printAll();
		}
		else if (command.find("save") != string::npos)
		{
			// save to file
			save();
		}
		else if (command.find("quit") != string::npos)
		{
			cout << "Game End!!" << endl;
			return;
		}
		else
		{
			cout << "UnKnowable command!" << endl;
		}
	}

	string winer ;
	for (vector<Role*>::iterator it = Roles.begin(); it != Roles.end(); it++)
	{
		if (!(**it).quit)
		{
			winer = (*it)->appreance;
		}
	}

	cout <<  winer << "win" << endl;
}

void gameControler::Move(int steps)
{
	int moves = 0;
	rollA = (abs(rand()) % 6 + 1);
	rollB = (abs(rand()) % 6 + 1);

	if (steps != 0)
	{
		moves = steps;
	}
	else
	{
		cout << "Roll " << rollA << " " << rollB << endl;
		moves = rollA + rollB;

		if (rollA == rollB)
		{
			rollAgain = true;
		}
	}

	if (Roles[playerIndex]->indec)
	{
		Roles[playerIndex]->dctimes++;

		if (Roles[playerIndex]->dctimes < 3)
		{
			
			if (rollA == rollB && Roles[playerIndex]->cash > 50)
			{
				cout << "You are in DCtimes and roll same, Do you want to pay 50 to get out(Y/N)!" << endl;
				string s;
				cin >> s;
				cin.get();

				if (s == "y" || s == "Y")
				{
					Roles[playerIndex]->pay(50);
					Roles[playerIndex]->indec = false;
				}
				else
				{	
					rollAgain = false;
					return;
				}
			}
			else
			{
				rollAgain = false;
				return;
			}
		}
		else
		{
			cout << "three times up, must pay 50 to leave!" << endl;
			Roles[playerIndex]->pay(50);
			Roles[playerIndex]->indec = false;
		}
	}

	Roles[playerIndex]->move(moves);
}

void gameControler::AfterMove()
{
	allPropertys[Roles[playerIndex]->position]->process(Roles[playerIndex], this);
	
	// Auctions
	if (allPropertys[Roles[playerIndex]->position]->type == 1)
	{
		if (Propertys[allPropertys[Roles[playerIndex]->position]->name]->ownable)
		{
			cout << "Auctions begin!" << endl;
			bool hasone = false;
			Role* role = NULL;
			int max_price = 0;

			while (true)
			{
				cout << "max-price now : " << max_price << endl;
				cout << "If you want to attend Auctions,Please input name(no more please input N):";
				string name;
				cin >> name;
				cin.get();
				Role* roleTemp = NULL;

				if (name == "n" || name == "N")
				{
					break;
				}

				for (vector<Role*>::iterator it = Roles.begin(); it != Roles.end(); it++)
				{
					if ((*it)->appreance == name)
					{
						roleTemp = (*it);
						break;
					}
				}

				if (roleTemp != NULL)
				{
					cout << roleTemp->appreance << " please input your price:";
					int money;
					cin >> money;
					cin.get();

					if (money <= roleTemp->cash )
					{
						if (max_price < money)
						{
							max_price = money;
							role = roleTemp;
						}
					}
					else
					{
						cout << "money not enough!" << endl;
					}
				}
				else
				{
					cout << "player not found!" << endl;
				}
			}

			if (role != NULL && max_price != 0)
			{
				cout << role->appreance << " win the Auctions!" << endl;
				Propertys[allPropertys[Roles[playerIndex]->position]->name]->ownable = false;
				Propertys[allPropertys[Roles[playerIndex]->position]->name]->owner = role;
				role->propertys.push_back(Propertys[allPropertys[Roles[playerIndex]->position]->name]);
				role->pay(max_price);
			}

		}
	}
}

void gameControler::Next()
{
	while(hasPlayer())
	{ 
		playerIndex = (playerIndex + 1) % this->Roles.size();
		if (!Roles[playerIndex]->quit)
		{
			break;
		}
	}
}

bool gameControler::hasPlayer()
{
	int count = 0;
	for (vector<Role*>::iterator it = Roles.begin(); it != Roles.end() ; it++) 
	{
		if (!(**it).quit)
		{
			count++;
			if(count >=2)
				return true;
		}
	}

	return false;
}

void gameControler::save()
{
	ofstream fileout("SavingMap.dat");

	fileout << this->Roles.size() << endl;

	for (int i = 0; i<Roles.size(); i++)
	{

		fileout << Roles[i]->appreance << " " << Roles[i]->cups << " " << Roles[i]->cash << " " << Roles[i]->position;

		if (Roles[i]->position == 30 && !Roles[i]->indec)
		{
			fileout << "0" << endl;
		}
		else if (Roles[i]->indec) 
		{
			fileout << "1 " << Roles[i]->dctimes;
		}
		fileout << endl;
	}

	for (vector<Property*>::iterator it = allPropertys.begin(); it != allPropertys.end(); it++)
	{
		(*it)->print(fileout);
	}

	fileout.close();
}

// load a game from a file
gameControler::gameControler(string fileName)
{
	this->playerIndex = 0;
	this->isDebug = false;
	this->rollAgain = false;
	initlize();

	// load file
	ifstream infile(fileName.c_str());
	if (infile.good())
	{
		char desc[100];
		infile >> this->nums;

		this->liveplayers = this->nums;
		gamemap = new gameMap();

		infile.get();

		for (int i = 0; i<nums; i++) 
		{
			infile.getline(desc, 100);
			string str = string(desc);
			Roles.push_back(new Role(str));
		}

		while (!infile.eof()) 
		{
			int level;
			infile.getline(desc, 100);
			string str = string(desc);

			// check User whether have owner
			if (str.find("none") != string::npos) 
			{
				continue;
			}
			stringstream stream(str);
			string build_name;
			string owner_name;
			stream >> build_name;
			stream >> owner_name;

			if ( Propertys.find(build_name) != Propertys.end() )
			{
				stream >> Propertys[build_name]->level;			
				for (int i = 0; i < nums; i++) 
				{
					if (Roles[i]->appreance == owner_name)
					{
						Propertys[build_name]->ownable = false;
						Propertys[build_name]->owner = Roles[i];
						Roles[i]->propertys.push_back(Propertys[build_name]);
					}
				}	
			}
			else
			{
				for (vector<Property*>::iterator it = allPropertys.begin(); it != allPropertys.end(); it++) 
				{
					if ( (*it)->name == build_name)
					{
						for (int i = 0; i < nums; i++)
						{
							if (Roles[i]->appreance == owner_name)
							{
								((OwnableProperty*)(*it))->ownable = false;
								((OwnableProperty*)(*it))->owner = Roles[i];
								Roles[i]->opropertys.push_back((OwnableProperty*)(*it));
								if (build_name == "MKV" || build_name == "UWP" || build_name == "V1" || build_name == "REV")
								{
									Roles[i]->ress++;
								}
								else
								{
									Roles[i]->gyms++;
								}						
							}
						}
					}
				}
			}
		}
	}
	start();
}

void gameControler::Trade(string name, string feedone, string feedtwo)
{
	bool found = false;
	Role* role = NULL;

	for (vector<Role*>::iterator it = Roles.begin(); it != Roles.end(); it++)
	{
		if ((*it)->appreance == name)
		{
			role = *it;
			found = true;
		}
	}

	if (found)
	{
		// trade
		if (isNum(feedone) && isNum(feedtwo))
		{
			cout << "Can't trade money with money!" << endl;
		}
		else
		{
			AcademicProperty* buildone = NULL;
			AcademicProperty* buildtwo = NULL;

			if (!isNum(feedone) && !isNum(feedtwo))
			{				
				if (Roles[playerIndex]->foundBuild(feedone, buildone) && role->foundBuild(feedtwo, buildtwo) )
				{

					if (buildone->level > 0 || buildtwo->level > 0)
					{ 
						cout << "must sell all improvements" << endl;
						return;
					}

					string s;
					cout << "Player " << role->appreance << ",Do you want to trade " << feedtwo << " for " << feedone << "(Y/N)?" << endl;
					cin >> s;
					cin.get();

					if (s == "y" || s == "Y")
					{
						buildone->owner = role;
						Roles[playerIndex]->removeBuild(feedone);
						role->propertys.push_back(buildone);
						buildtwo->owner = Roles[playerIndex];
						role->removeBuild(feedtwo);
						Roles[playerIndex]->propertys.push_back(buildtwo);
					}
					else
					{
						cout << "Trade reject!" << endl;
					}
				}
				else
				{
					cout << "Trade info error !!" << endl;
				}
			}
			else if (isNum(feedone) && !isNum(feedtwo))
			{
				int money;
				stringstream ss(feedone);
				ss >> money;

				if (Roles[playerIndex]->cash > money && role->foundBuild(feedtwo, buildtwo))
				{
					if (buildtwo->level > 0)
					{
						cout << "must sell all improvements" << endl;
						return;
					}

					string s;
					cout << "Player " << role->appreance << ",Do you want to trade " << feedtwo << " for cash " << feedone << "(Y/N)?" << endl;
					cin >> s;
					cin.get();
					if (s == "y" || s == "Y")
					{
						buildtwo->owner = Roles[playerIndex];
						role->removeBuild(feedtwo);
						role->receive(money);
						Roles[playerIndex]->pay(money);
						Roles[playerIndex]->propertys.push_back(buildtwo);
					}
					else
					{
						cout << "Trade reject!" << endl;
					}
				}
				else
				{
					cout << "Trade info error !!" << endl;
				}
			}
			else
			{
				int money;
				stringstream ss(feedtwo);
				ss >> money;

				if (Roles[playerIndex]->foundBuild(feedone, buildone) && role->cash > money)
				{
					if (buildone->level > 0)
					{
						cout << "must sell all improvements" << endl;
						return;
					}

					string s;
					cout << "Player " << role->appreance << ",Do you want to trade " << feedtwo << " for build "  << feedone << "(Y/N)?" << endl;
					cin >> s;
					cin.get();

					if (s == "y" || s == "Y")
					{
						buildone->owner = role;
						Roles[playerIndex]->removeBuild(feedone);
						Roles[playerIndex]->receive(money);
						role->pay(money);
						role->propertys.push_back(buildone);
					}
					else
					{
						cout << "Trade reject!" << endl;
					}
				}
				else
				{
					cout << "Trade info error !!" << endl;
				}
			}
		}
	}
	else
	{
		cout << "Player not found !" << endl;
	}
}

int main(int argc, char* argv[])
{
	bool isDebug = false;
	int nums = 0;
	gameControler *game  = NULL;

	if (argc == 3) 
	{
		game = new gameControler(argv[2]);
	}
	else if (argc == 2 || argc == 1)
	{
		cout << "Please input the number of players:";
		cin.clear();
		cin >> nums;
		cin.get();
		if (argc == 1)
		{
			game = new gameControler(nums, false);
		}
		else
		{
			game = new gameControler(nums, true);
		}
	}
	else
	{
		cout << "Command error!" << endl;
	}
	if (game != NULL) 
	{
		delete game;
	}

	return 0;
}
