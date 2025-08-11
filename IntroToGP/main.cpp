// main area where our application updates and is ran
//  corresponds to cout/cin- printing to console
#include <iostream>
//  corresponds to system("cls")
#include <stdlib.h>
//  corresponds to to_string for integers and what have you
#include <string>

//  corresponds to a map data type- key : value association
#include <unordered_map>

//  we wrote these :)
#include "Entity.h"
#include "BaseAbility.h"
using namespace std;

int main()
{
    //  step 1: intialize all of our objects/data 
    //   for the runtime of our game (or the start of our game)
    BaseAbility* testAbilityOne = new BaseAbility(/*input could go here*/);
    testAbilityOne->SetHitChance(50);
    testAbilityOne->AbilityName = "Special Attack";
    BaseAbility* testAbilityTwo = new BaseAbility();
    testAbilityTwo->SetHitChance(75);
    testAbilityTwo->AbilityName = "Not so special Attack";
    //  set up an ablity to have a cooldown
    testAbilityTwo->SetCD(3);


    Entity* testPlayer = new Entity();
    testPlayer->SetName("Player");
    //  TODO: set up setters/getters for attack, defence, etc
    testPlayer->AbilityList.push_back(testAbilityOne);
    testPlayer->AbilityList.push_back(testAbilityTwo);

    Entity* targetDummyA = new Entity();
    targetDummyA->SetName("dummy A");
    Entity* targetDummyB = new Entity();
    targetDummyB->SetName("dummy B");

    vector<Entity*> enemies = { targetDummyA, targetDummyB };

    //  using the enemiesVector as a way to initialize the enemiesMap
    unordered_map<string, Entity*> enemiesMap = {};

    for (int i = 0; i < enemies.size(); i++)
    {
        //  adds a pair to the map with a key for the corresponding string input that is associated with the given enemy
        enemiesMap.emplace(to_string(i + 1), enemies[i]);
    }

    //  init the ability maps for each entity using their abilitylist
    //  TODO: init enemies
    for (int i = 0; i < testPlayer->AbilityList.size(); i++)
    {
        //  adds the players ability from the abilityList to the ablityMap
        testPlayer->AbilityMap.emplace(to_string(i+1), testPlayer->AbilityList[i]);
    }

    BaseAbility* currentAbility = nullptr;
    Entity* currentTarget = nullptr;

    int CurrentTurn = 1;
    bool ShouldExit = false;
    //  step 2: actually run the game
    while (ShouldExit == false)
    {
        //  run the game!
        //  convey info to the player
        cout << "Turn Number: " + std::to_string(CurrentTurn) << endl;
        cout << "Enemies: " << endl;
        for (int currentEnemy = 0; currentEnemy < enemies.size(); currentEnemy++)
        {
            cout << enemies[currentEnemy]->GetName() + " : Current HP : " + to_string(enemies[currentEnemy]->GetCurHP()) << endl;
        }
        cout << "Player HP: " + std::to_string(testPlayer->GetCurHP()) << endl;
        cout << "Inputs:" << endl;
        cout << "\t1: Action List" << endl;
        cout << "\t2: Skip the Turn" << endl;
        //  for collecting input from the player
        string input;
        cin >> input;
        if (input == "1")
        {
            //  show the action list
            std::system("cls");
            cout << "Available Actions:" << endl;
           //    for (int currentListEntry = 0; currentListEntry < testPlayer->AbilityList.size(); currentListEntry++)
           //    {
           //        cout << std::to_string(currentListEntry + 1) + 
           //                ": " + testPlayer->AbilityList[currentListEntry]->AbilityName << endl;
           //    }

            for (auto& pair : testPlayer->AbilityMap)
            {
                auto it = testPlayer->AbilityMap.find(pair.first);
                if (it != testPlayer->AbilityMap.end())
                {

                    if (!testPlayer->AbilityMap[pair.first]->CheckCD())
                    {
                        cout << pair.first + ": " + testPlayer->AbilityMap[pair.first]->AbilityName << endl;
                    }
                }
            }

            cin >> input;
            //  show the enemy list
            std::system("cls");
            if (input == "1")
            {
                currentAbility = testPlayer->AbilityList[0];

                for (int currentEnemy = 0; currentEnemy < enemies.size(); currentEnemy++)
                {
                    cout << to_string(currentEnemy + 1) + ": " + enemies[currentEnemy]->GetName() << endl;
                }

                cin >> input;

                if (input == "1")
                {
                    //  assign currentTarget to first enemy!
                    currentTarget = enemies[0];

                    testPlayer->Action(*currentAbility, *currentTarget);
                }
                else if (input == "2")
                {
                    //  assign currentTarget to second enemy!
                    currentTarget = enemies[1];

                    testPlayer->Action(*currentAbility, *currentTarget);
                }
            }
            else if (input == "2")
            {
                currentAbility = testPlayer->AbilityList[1];

                for (int currentEnemy = 0; currentEnemy < enemies.size(); currentEnemy++)
                {
                    cout << to_string(currentEnemy + 1) + ": " + enemies[currentEnemy]->GetName() << endl;
                }

                cin >> input;

                if (input == "1")
                {
                    //  assign currentTarget to first enemy!
                    currentTarget = enemies[0];

                    testPlayer->Action(*currentAbility, *currentTarget);
                }
                else if (input == "2")
                {
                    //  assign currentTarget to second enemy!
                    currentTarget = enemies[1];

                    testPlayer->Action(*currentAbility, *currentTarget);
                }
                else 
                {
                    //TODO: error checking for input
                }
            }
            else
            {
                //  TODO: warn player of bad input
            }

        }
        else if (input == "2")
        {
            //  skip the turn
        }
        else
        {
            //  TODO: otherwise, invalid input
        }
       

        testAbilityOne->UpdateCD();
        testAbilityTwo->UpdateCD();
        CurrentTurn++;
        //  clears the console window so that we only have relevant information displayed
        std::system("cls");
    }


    //  step 3: cleanup our data when the application should be closing
}

