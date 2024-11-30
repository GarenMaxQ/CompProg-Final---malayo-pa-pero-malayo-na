﻿#include <iostream>
#include <string>
using namespace std;
int main()
{
	/*
	string monsterSelection[4] = {
	"Xxr4mc3Lm@51k1pxX", "[(@rG0$iN○m@LnW@g)]", "The Guevarras", "Art",
	"Programming", "Science", "Philosophy", "P.E.",
	"Music", "PPE"
	*/
	bool restartGame = false;
	int hp, mp, phy, energy;
	int heal = 100;
	int numberHeals = 10;
	string Class[3] = { "Knight", "Sorcerer", "Assassin" };
	int monsterHP, monsterPHY, monster2HP, monster2PHY;
	string user, monsterName, monster2Name, ChosenClass;
	char monsterChoice, actionChoice, buffChoice, fireAgain = false, classChoice, itemChoice, playAgain;
	bool invalidMonster, invalidAction, invalidClass, invalidItem{}, invalidBuff = false;
	do {

		do
		{
			cout << "Enter your name: ";
			getline(cin, user);
			cout << "Choose starting class.\n";
			cout << "1. Knight\n";
			cout << "   Health  - 500\n";
			cout << "   Atk Dmg - 50\n";
			cout << "   Energy  - 100\n";
			cout << "2. Viking\n";
			cout << "   Health  - 300\n";
			cout << "   Atk Dmg - 100\n";
			cout << "   Energy  - 50\n";
			cout << "3. Assassin\n";
			cout << "   Health  - 100\n";
			cout << "   Atk Dmg - 60\n";
			cout << "   Energy  - 200\n";
			cout << "Enter number of chosen class: ";
			cin >> classChoice;
			do {
				switch (classChoice)
				{
				case'1':
					hp = 500; phy = 50; energy = 100;
					ChosenClass = "Knight";
					cout << "Starting Class: " << ChosenClass << endl;
					invalidClass = false;
					break;
				case '2':
					hp = 300; phy = 100; energy = 50;
					ChosenClass = "Viking";
					cout << "Starting Class: Viking\n";
					invalidClass = false;
					break;
				case '3':
					hp = 150; phy = 60; energy = 150;
					ChosenClass = "Assassin";
					cout << "Starting Class: Assassin\n";
					invalidClass = false;
					break;
				default:
					cout << "Not a valid class\n";
					cout << "Choose starting class.\n";
					cout << "1. Knight\n";
					cout << "\tHealth: 300\n\tAtk Dmg: 20\n\tEnergy: 50\n ";
					cout << "2. Sorcerer\n";
					cout << "\tHealth: 150\n\tAtk Dmg: 50\n\tEnergy: 30\n";
					cout << "3. Assassin\n";
					cout << "\tHealth: 120\n\tAtk Dmg: 35\n\tEnergy 60\n";
					cout << "Enter number of chosen class: ";
					cin >> classChoice;
					invalidClass = true;
					break;
				}
			} while (invalidClass);

			system("pause");
			system("cls");

			cout << "Level 1\n";
			monsterHP = 250;
			monsterName = "Xxr4mc3Lm@51k1pxX";
			monsterPHY = 50;
			do
			{
				monsterPHY = 50;
				cout << "\nPlayer: " << "(" << ChosenClass << ")" << user << "\tHealth: " << hp << "\tEnergy: " << energy << endl;
				cout << "Monster: " << monsterName << "\tHealth: " << monsterHP << endl;
				cout << "It's your turn.\n";
				cout << "Select action.\n";
				cout << "1. Attack\n";
				cout << "2. Use item\n";
				cout << "3. Do nothing\n";
				cout << "4. Dodge roll & attack\n";
				cout << "Enter: ";
				cin >> actionChoice;

				while ('1' == actionChoice && 0 >= energy || '4' == actionChoice && 0 >= energy)
				{
					cout << "Not enough Energy to perform action! Please choose a different action." << endl;
					cout << "\nPlayer: " << "(" << ChosenClass << ")" << user << "\tHealth: " << hp << "\tEnergy: " << energy << endl;
					cout << "Monster: " << monsterName << "\tHealth: " << monsterHP << endl;
					cout << "It's your turn.\n";
					cout << "Select action.\n";
					cout << "1. Attack\n";
					cout << "2. Use item\n";
					cout << "3. Do nothing\n";
					cout << "4. Dodge roll & attack\n";
					cout << "Enter: ";
					cin >> actionChoice;
				}

				do {

					switch (actionChoice)
					{
					case'1':
						monsterHP -= phy;
						cout << "You attacked " << monsterName << "!" << endl;
						system("pause");
						cout << "You lost 20 energy" << endl;
						energy -= 20;
						cout << monsterName << " lost " << phy << " Health.\n";
						cout << "Ending turn\n";
						invalidAction = false;
						system("pause");
						break;
					case '2':
						cout << "Inventory\n";
						cout << "1. PotPots - " << "+" << heal << " hp" << "(" << numberHeals << ")\n";
						cout << "2. Return\n";
						cout << "Enter: ";
						cin >> itemChoice;
						while (0 == numberHeals && '1' == itemChoice)
						{
							cout << "Not enough Heals! Please choose a different action." << endl;
							cout << "Inventory\n";
							cout << "1. PotPots - " << "+" << heal << " hp" << "(" << numberHeals << ")\n";
							cout << "2. Return\n";
							cout << "Enter: ";
							cin >> itemChoice;
						}

						do {
							switch (itemChoice)
							{
							case'1':
								hp += heal;
								cout << "Used PotPots! Gained " << heal << " hp!\n";
								numberHeals -= 1;
								system("pause");
								cout << "Ending turn\n";
								invalidAction = false;
								system("pause");
								break;
							case'2':
								cout << "Select action.\n";
								cout << "1. Attack\n";
								cout << "2. Use item\n";
								cout << "3. Do nothing\n";
								cout << "4. Dodge roll\n";
								cout << "Enter: ";
								cin >> actionChoice;
								invalidAction = true;
								break;
							default:
								cout << "Invalid Item\n";
								cout << "Inventory\n";
								cout << "1. PotPots - +20HP\n";
								cout << "2. Return";
								cout << "Enter: ";
								cin >> itemChoice;
								invalidItem = true;
								break;
							}
						} while (invalidItem);
						break;
					case'3':
						cout << "Gained 40 Energy" << endl;
						energy += 40;
						cout << "Ending turn\n";
						invalidAction = false;
						system("pause");
						break;
					case '4':
						cout << "Performed a dodge roll and immediately attacked!\n";
						system("pause");
						cout << "You lost 20 Energy\n";
						monsterPHY = 0;
						invalidAction = false;
						energy -= 30;
						cout << monsterName << " lost " << phy << " Health.\n";
						monsterHP -= phy;
						cout << "Ending turn\n";
						invalidAction = false;
						system("pause");
						break;
					default:
						cout << "Invalid action.";
						cout << "Select action.\n";
						cout << "1. Attack\n";
						cout << "2. Use item\n";
						cout << "3. Do nothing\n";
						cout << "4. Dodge roll\n";
						cout << "Enter: ";
						cin >> actionChoice;
						invalidAction = true;
						break;
					}
				} while (invalidAction);
					if (0 < monsterHP)
					{
						cout << monsterName << " is attacking!\n";
						system("pause");
						hp -= monsterPHY;
						cout << user << " lost " << monsterPHY << "HP!\n";
						system("pause");
					}




			} while (0 < monsterHP && 0 < hp);

			if (0 >= monsterHP)
			{

				do
				{
					cout << "You have defeated " << monsterName << "!\n";
					cout << "[1] +40 damage\n[2] +50 Healing\n[3] +5 PotPots" << "\nPlease select a buff: \n";
					cin >> buffChoice;

					switch (buffChoice)
					{
					case '1':
						cout << "You have selected +40 damage!\n";
						phy += 40;
						break;

					case '2':
						cout << "You have selected +50 Healing!\n";
						heal += 50;
						break;
					case '3':
						cout << "You have selected +5 PotPots!\n";
						numberHeals += 5;
						break;
					default:
						cout << "Invalid choice\n";
						invalidBuff = true;
						break;
					}
				} while (invalidBuff);

				cout << "Proceed to the next level\n";
			}
			else if (0 >= hp)
			{
				cout << "You were defeated by " << monsterName << "!\n";
				cout << "Play again? (y/n)";
				cin >> playAgain;
				switch (playAgain)
				{
				case'y':
					restartGame = true;
					system("pause");
					system("cls");
					break;
				case'n':
					exit(0);
					break;
				default:
					cout << "Invalid answer. Exiting game";
					exit(0);
					break;
					system("pause");
					system("cls");

				}
			}
		} while (restartGame);
		system("pause");
		system("cls");
		cout << "\nLevel 2\n";
		monster2HP = 300;
		monster2Name = "The Guevarras: Kupal & imissu";
		monster2PHY = 80;

		do {
			cout << "\nPlayer: " << "(" << ChosenClass << ")" << user << "\tHealth: " << hp << "\tEnergy: " << energy << endl;
			cout << "Monster: " << monster2Name << "\tHealth: " << monster2HP << endl;
			cout << "It's your turn.\n";
			cout << "Select action.\n";
			cout << "1. Attack\n";
			cout << "2. Use item\n";
			cout << "3. Do nothing\n";
			cout << "4. Dodge roll & attack\n";
			cout << "Enter: ";
			cin >> actionChoice;

			while ('1' == actionChoice && 0 >= energy)
			{
				cout << "Not enough Energy to Attack! Please choose a different action." << endl;
				cout << "\nPlayer: " << "(" << ChosenClass << ")" << user << "\tHealth: " << hp << "\tEnergy: " << energy << endl;
				cout << "Monster: " << monsterName << "\tHealth: " << monsterHP << endl;
				cout << "It's your turn.\n";
				cout << "Select action.\n";
				cout << "1. Attack\n";
				cout << "2. Use item\n";
				cout << "3. Do nothing\n";
				cout << "4. Dodge roll & attack\n";
				cout << "Enter: ";
				cin >> actionChoice;
			}
			do {
				switch (actionChoice) {
				case '1':
					monster2HP -= phy;
					cout << "You attacked " << monster2Name << "!" << endl;
					system("pause");
					cout << "You lost 20 energy" << endl;
					energy -= 20;
					cout << monster2Name << " lost " << phy << " Health.\n";
					cout << "Ending turn\n";
					invalidAction = false;
					system("pause");
					break;
				case '2':
					cout << "Inventory\n";
					cout << "1. PotPots - " << "+" << heal << " hp" << "(" << numberHeals << ")\n";
					cout << "2. Return\n";
					cout << "Enter: ";
					cin >> itemChoice;

					while (0 == numberHeals && '1' == itemChoice)
					{
						cout << "Not enough Heals! Please choose a different action." << endl;
						cout << "Inventory\n";
						cout << "1. PotPots - " << "+" << heal << " hp" << "(" << numberHeals << ")\n";
						cout << "2. Return\n";
						cout << "Enter: ";
						cin >> itemChoice;
					}

					do {
						switch (itemChoice) {
						case '1':
							hp += heal;
							cout << "Used PotPots! Gained " << heal << " hp\n";
							numberHeals -= 1;
							system("pause");
							cout << "Ending turn\n";
							invalidAction = false;
							system("pause");
							break;
						case '2':
							cout << "Select action.\n";
							cout << "1. Attack\n";
							cout << "2. Use item\n";
							cout << "3. Do nothing\n";
							cout << "4. Dodge roll & attack\n";
							cout << "Enter: ";
							cin >> actionChoice;
							invalidAction = true;
							break;
						default:
							cout << "Invalid Item\n";
							cout << "Inventory\n";
							cout << "1. PotPots - +20HP\n";
							cout << "2. Return";
							cout << "Enter: ";
							cin >> itemChoice;
							invalidItem = true;
							break;
						}
					} while (invalidItem);
					break;
				case '3':
					cout << "Gained 30 Energy" << endl;
					energy += 40;
					cout << "Ending turn\n";
					invalidAction = false;
					system("pause");
					break;
				case '4':
					cout << "Performed a dodge roll and immediately attacked!\n";
					system("pause");
					cout << "You lost 30 Energy\n";
					monster2PHY = 0;
					invalidAction = false;
					energy -= 30;
					cout << monster2Name << " lost " << phy << " Health.\n";
					monster2HP -= phy;
					cout << "Ending turn\n";
					invalidAction = false;
					system("pause");
					break;
				default:
					cout << "Invalid action.";
					cout << "Select action.\n";
					cout << "1. Attack\n";
					cout << "2. Use item\n";
					cout << "3. Do nothing\n";
					cout << "4. Dodge roll\n";
					cout << "Enter: ";
					cin >> actionChoice;
					invalidAction = true;
					break;
				}
			} while (invalidAction);
				if (0 < monster2HP)
				{
					cout << monster2Name << " is attacking!\n";
					system("pause");
					hp -= monster2PHY;
					cout << user << " lost " << monster2PHY << "HP!\n";
					system("pause");
				}
		} while (0 < monster2HP && 0 < hp);

		if (0 >= monster2HP) {
			cout << "You have defeated " << monster2Name << "!\n";
		}
		else if (0 >= hp) {
			cout << "You were defeated by " << monster2Name << "!\n";
			cout << "Play again? (y/n)";
			cin >> playAgain;
			cin.ignore();
			switch (playAgain) {
			case 'y':
				restartGame = true;
				break;
			case 'n':
				exit(0);
				break;
			default:
				cout << "Invalid answer. Exiting game";
				exit(0);
				break;
			}
		}
		cout << "Move on to the next level\m";

		system("pause");
		system("cls");

		cout << "\nLevel 3\n";
		monster2HP = 500;
		monster2Name = "[(@rG0$iN○m@£ùwàğ)]";
		monster2PHY = 100;

		do {
			monster2PHY = 80;
			cout << "\nPlayer: " << "(" << ChosenClass << ")" << user << "\tHealth: " << hp << "\tEnergy: " << energy << endl;
			cout << "Monster: " << monster2Name << "\tHealth: " << monster2HP << endl;
			cout << "It's your turn.\n";
			cout << "Select action.\n";
			cout << "1. Attack\n";
			cout << "2. Use item\n";
			cout << "3. Do nothing\n";
			cout << "4. Dodge roll & attack\n";
			cout << "Enter: ";
			cin >> actionChoice;

			while ('1' == actionChoice && 0 >= energy)
			{
				cout << "Not enough Energy to Attack! Please choose a different action." << endl;
				cout << "\nPlayer: " << "(" << ChosenClass << ")" << user << "\tHealth: " << hp << "\tEnergy: " << energy << endl;
				cout << "Monster: " << monsterName << "\tHealth: " << monsterHP << endl;
				cout << "It's your turn.\n";
				cout << "Select action.\n";
				cout << "1. Attack\n";
				cout << "2. Use item\n";
				cout << "3. Do nothing\n";
				cout << "4. Dodge roll & attack\n";
				cout << "Enter: ";
				cin >> actionChoice;
			}
			do {
				switch (actionChoice) {
				case '1':
					monster2HP -= phy;
					cout << "You attacked " << monster2Name << "!" << endl;
					system("pause");
					cout << "You lost 20 energy" << endl;
					energy -= 20;
					cout << monster2Name << " lost " << phy << " Health.\n";
					cout << "Ending turn\n";
					invalidAction = false;
					system("pause");
					break;
				case '2':
					cout << "Inventory\n";
					cout << "1. PotPots - " << "+" << heal << " hp" << "(" << numberHeals << ")\n";
					cout << "2. Return\n";
					cout << "Enter: ";
					cin >> itemChoice;

					while (0 == numberHeals && '1' == itemChoice)
					{
						cout << "Not enough Heals! Please choose a different action." << endl;
						cout << "Inventory\n";
						cout << "1. PotPots - " << "+" << heal << " hp" << "(" << numberHeals << ")\n";
						cout << "2. Return\n";
						cout << "Enter: ";
						cin >> itemChoice;
					}

					do {
						switch (itemChoice) {
						case '1':
							hp += heal;
							cout << "Used PotPots! Gained " << heal << " hp\n";
							numberHeals -= 1;
							system("pause");
							cout << "Ending turn\n";
							invalidAction = false;
							system("pause");
							break;
						case '2':
							cout << "Select action.\n";
							cout << "1. Attack\n";
							cout << "2. Use item\n";
							cout << "3. Do nothing\n";
							cout << "4. Dodge roll & attack\n";
							cout << "Enter: ";
							cin >> actionChoice;
							invalidAction = true;
							break;
						default:
							cout << "Invalid Item\n";
							cout << "Inventory\n";
							cout << "1. PotPots - +20HP\n";
							cout << "2. Return";
							cout << "Enter: ";
							cin >> itemChoice;
							invalidItem = true;
							break;
						}
					} while (invalidItem);
					break;
				case '3':
					cout << "Gained 30 Energy" << endl;
					energy += 40;
					cout << "Ending turn\n";
					invalidAction = false;
					system("pause");
					break;
				case '4':
					cout << "Performed a dodge roll and immediately attacked!\n";
					system("pause");
					cout << "You lost 30 Energy\n";
					monster2PHY = 0;
					invalidAction = false;
					energy -= 30;
					cout << monster2Name << " lost " << phy << " Health.\n";
					monster2HP -= phy;
					cout << "Ending turn\n";
					invalidAction = false;
					system("pause");
					break;
				default:
					cout << "Invalid action.";
					cout << "Select action.\n";
					cout << "1. Attack\n";
					cout << "2. Use item\n";
					cout << "3. Do nothing\n";
					cout << "4. Dodge roll\n";
					cout << "Enter: ";
					cin >> actionChoice;
					invalidAction = true;
					break;
				}
			} while (invalidAction);
			if (0 < monster2HP)
			{
				cout << monster2Name << " is attacking!\n";
				system("pause");
				hp -= monster2PHY;
				cout << user << " lost " << monster2PHY << "HP!\n";
				system("pause");
			}
		} while (0 < monster2HP && 0 < hp);

		if (0 >= monster2HP) {
			cout << "You have defeated " << monster2Name << "!\n";
			cout << "Congratulations! You completed the game.\n";
		}
		else if (0 >= hp) {
			cout << "You were defeated by " << monster2Name << "!\n";
			cout << "Play again? (y/n)";
			cin >> playAgain;
			cin.ignore();
			switch (playAgain) {
			case 'y':
				restartGame = true;
				break;
			case 'n':
				exit(0);
				break;
			default:
				cout << "Invalid answer. Exiting game";
				exit(0);
				break;
			}
		}
		cout << "Thank you for playing the game!\n";
		cout << "Adios.\n";
	} while (restartGame);
	system("pause");
	system("cls");

	return 0;
}