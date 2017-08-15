#include "property.h"
#include "role.h"
#include <iostream>
#include <string>
#include "gameControler.h"

using namespace std;

void Property::process(Role* role, gameControler* game)
{

	if (name == "OSAP")
	{
		role->receive(200);
                role->receive(-200);
	}
	else if (name == "GotoTims")
	{
		role->position = 30;
		role->indec = true;
		role->dctimes = 0;
	}
	else if (name == "GooseNesting")
	{
		cout << "Catch GooseNesting!" << endl;
	}
	else if (name == "Tuition")
	{
		cout << "chose Y paying $300 , N paying 10% of your worth!" << endl;
		string s;

		cin >> s;
		cin.get();

		if ((s == "y" || s == "Y") && role->cash > 300)
		{
			role->pay(300);
		}
		else
		{
			role->pay(role->worth()*0.1);
		}
	}
	else if (name == "Coopfee")
	{
		role->pay(150);
	}
	else if (name == "SLC")
	{
		int poss[] = { 2, 6, 10, 13, 17, 21, 22, 23 };
		int value[] = { -3, -2, -1, 1, 2, 3 };

		if (abs(rand() % 100) == 0) 
		{
			role->cups++;
			cout << "You receives a winning Roll Up the Rim cup " << endl;
		}

		int random = abs(rand() % 24);

		for (int i = 0; i < 8; i++) 
		{
			if (i == 6) 
			{
				cout << "You move to DC TIMES " << endl;
				role->position = 30;
				break;
			}
			if (i == 7) 
			{
				cout << "You move to OSAP " << endl;
				role->position = 20;
				break;
			}
			if (poss[i] >= random) 
			{
				cout << "You move " << value[i] << endl;
				role->move(value[i]);
				break;
			}
		}
	}
	else if (name == "NeedlesHall")
	{
		int poss[] = { 1, 3, 6, 12, 15, 17, 18 };
		int value[] = { -200, -100, -50, 25, 50, 100, 200 };
		
		int random = abs(rand() % 18);
		for (int i = 0; i < 8; i++) 
		{

			if (value[i] >= random) 
			{
				if (value[i] < 0) 
				{
					cout << "You have to pay " << value[i] << endl;
					role->pay(value[i]);
				}
				else 
				{
					cout << "You receive " << value[i] << endl;
					role->receive(value[i]);
				}
				break;
			}
		}
	}
}

void AcademicProperty::process(Role* role, gameControler* game)
{
	if (!this->ownable)
	{
		if (!IsOwned(role))
		{
			// pay
			if (!this->Mortgagesed)
			{
				int Tuition = Tuitions[this->name][this->level];
				cout << role->appreance << " have to pay " << Tuition << " to " << this->owner->appreance << endl;
				role->pay(Tuition);
				this->owner->receive(Tuition);
			}
		}
	}
	else
	{
		if (role->cash > this->purchase_cost)
		{
			string s;
			cout << "Do you want to pay " << this->purchase_cost << " to buy this Property (Y/N)?";

			cin >> s;
			cin.get();
			if (s == "y" || s == "Y")
			{
				role->pay(this->purchase_cost);
				this->ownable = false;
				this->owner = role;
				role->propertys.push_back(this);
			}
		}
	}
}

bool AcademicProperty::IsOwned(Role* role)
{
	if (role != owner)
		return false;

	return true;
}

void OwnableProperty::process(Role* role, gameControler* game)
{
	if (name == "MKV" || name == "UWP" || name == "V1" || name == "REV")
	{
		if (!this->ownable)
		{
			if (!IsOwned(role))
			{
				// pay
				int Tuition = 25 * pow(2,(this->owner->ress-1));
				role->pay(Tuition);
				this->owner->receive(Tuition);
			}
		}
		else
		{
			if (role->cash > 200)
			{
				string s;
				cout << "Do you want to pay " << 200 << " to buy this Property(Y/N)?";

				cin >> s;
				cin.get();
				if (s == "y" || s == "Y")
				{
					role->pay(200);
					this->ownable = false;
					this->owner = role;
					role->ress++;
					role->opropertys.push_back(this);
				}
			}
		}
	}
	else if (name == "PAC" || name == "CIF")
	{
		if (!this->ownable)
		{
			if (!IsOwned(role))
			{
				// pay
				int Tuition = game->rollA + game->rollB;
				if (this->owner->gyms == 1)
				{
					Tuition = Tuition * 4;
				}
				else
				{
					Tuition = Tuition * 10;
				}
				role->pay(Tuition);
				this->owner->receive(Tuition);
			}
		}
		else
		{
			if (role->cash > 150)
			{
				string s;
				cout << "Do you want to pay " << 150 << " to buy this Property(Y/N)?";
				cin >> s;
				cin.get();

				if (s == "y" || s == "Y")
				{
					role->pay(150);
					this->ownable = false;
					this->owner = role;
					role->gyms++;
					role->opropertys.push_back(this);
				}
			}
		}
	}
}

bool OwnableProperty::IsOwned(Role* role)
{
	if (role != owner)
		return false;

	return true;
}

void Property::print(ofstream& fileout)
{

}

void AcademicProperty::print(ofstream& fileout)
{
	
	fileout << this->name;
	if (!this->ownable)
	{
		fileout << " " << this->owner->appreance << " ";
	}
	else
	{
		fileout << " none " ;
	}
	fileout << this->level << " " << endl;
}

void OwnableProperty::print(ofstream& fileout)
{
	fileout << this->name;
	if (!this->ownable)
	{
		fileout << " " << this->owner->appreance;
	}
	else
	{
		fileout << " none";
	}
	fileout << " -1" << endl;
}
