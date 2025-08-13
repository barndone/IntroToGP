#include "BaseAbility.h"
#include <cstdlib>
#include <ctime>

BaseAbility::BaseAbility()
{
	// this is where we will assign 
	// good defaults for all of our BaseAbility variables!
	HitChance = 0;
	CD = 1;
	CurCDValue = 0;
	Level = 1;
	TargetsEnemies = true;

}

BaseAbility::~BaseAbility()
{

}

bool BaseAbility::CheckHit()
{
	int RandValue = std::rand() % 50 + 1;

	//	if our RandValue is LESS or EQUAL to our hit chance, we hit!
	//	otherwise, we don't!

	if (RandValue <= HitChance)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BaseAbility::CheckCD()
{
	//	if CDValue is NOT 0, we are on cooldown
	if (CurCDValue > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BaseAbility::ActivateCD()
{
	CurCDValue = CD;
}

void BaseAbility::UpdateCD()
{
	//	&& - AND
	//	|| - OR
	if (CheckCD())
	{
		CurCDValue--;
	}
	//	CurCDValue -= 1;
	//	CurCDValue = CurCDValue - 1;
	//	--CurCDValue;
}
