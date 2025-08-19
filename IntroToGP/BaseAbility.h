#pragma once
#include <iostream>


class BaseAbility
{
private:
	//	Variable for Hit Chance
	int HitChance;
	//	Our target used in cooldown calculations
	int CD;				//	this is what the CD is full stop- i.e., 3 turns
	//	our working Cooldown Value
	int CurCDValue;		//	this represents where we are along our CD journey
	//	when we attack, CurCDValue = cd
	//		THEN every turn, we subtract from CurCDValue until it equals 0
	//	Variable for Ability Level
	int Level;
	//	Does this Target Enemies?
	bool TargetsEnemies = true;

	int DamageMod = 100;



public:
	bool CausesStun = false;
	int StunLength;
	int StunDamage;
	std::string AbilityName;

	int GetHitChance() { return HitChance; }
	int GetCD() { return CD; }
	int GetLevel() { return Level; }
	bool GetTargetsEnemies() { return TargetsEnemies; }
	int GetDamageMod () { return DamageMod; }

	void SetHitChance(int input) { HitChance = input; }
	void SetCD(int input) { CD = input; }
	void SetLevel(int input) { Level = input; }
	void SetTargetsEnemies(bool input) { TargetsEnemies = input; }

	BaseAbility();
	~BaseAbility();

	//	we need to check if we hit
	bool CheckHit();
	//	we need to check if we are on CD
	bool CheckCD();
	//	activate the ability-set in on cooldown, whatever
	void ActivateCD();
	//	tick down the abilities cooldown each turn
	void UpdateCD();
	
	//	TODO: implement critical hits!
};