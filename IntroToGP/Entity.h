
#pragma once
#include <iostream>
#include <vector>
//  corresponds to a map data type- key : value association
#include <unordered_map>

#include "BaseAbility.h"

using namespace std;

//  this is where we will declare things for our entities
// 
//  a class is just a variable that can 
//    be made up of other variables and have functions 
//    associated with it'
class Entity
{
	//  private variable / function / etc., only accessable by itself
private:

	//  functionally it's private, but things 
	//  that derive from this class have access to these fields
protected:
	string EntityName;

	int MaxHealth;
	int CurHealth;
	int Attack;
	int Defence;
	int Speed;

	int CurEXP;
	int EXPYield;
	int Level;



public:
	//  getters and setters
	//  returntype FunctionName(input parameters);

	//	used for AI entities
	BaseAbility* CurrentAbility;
	Entity* Target;

	std::vector<BaseAbility*> AbilityList;
	std::unordered_map<std::string, BaseAbility*> AbilityMap;

	string GetName() { return EntityName; }
	int GetMaxHP() { return MaxHealth; }
	int GetCurHP() { return CurHealth; }
	int GetAttack() { return Attack; }
	int GetDefence() { return Defence; }
	int GetSpeed() { return Speed; }

	void SetName(string newName) { EntityName = newName; }
	void SetCurHP(int input) { CurHealth = input; }
	void SetAttack(int input) { Attack = input; }
	void SetDefence(int input) { Defence = input; }
	void SetSpeed(int input) { Speed = input; }
	void UpdateCurHP(int delta) { CurHealth += delta; }

	Entity();
	~Entity();

	void Action(BaseAbility& abilityToUse, Entity& targetEntity);
	//void Skip();
};