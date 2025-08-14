#pragma once
#include "BaseAbility.h"
#include <vector>
#include <unordered_map>


enum StatToEffect
{
	HEALTH = 1,
	ATTACK = 2,
	DEFENCE = 3,
	SPEED = 4,
	ACTION = 5
};

struct StatusEffect
{
	//	public by default :)
	//	culturally don't put functions in here >:(
	//	do whatever though, i'm not your boss
	std::unordered_map<StatToEffect, int> statsToEffect = {};
	int Duration;
	int curDuration;

	//	stretch goal, decay?

};

class StatusAbility : protected BaseAbility
{
public:
	StatusEffect Effect;

	StatusAbility();
	~StatusAbility();

	void ApplyStatusEffect(class Entity* target);
	void TickStatuses(class Entity* target);
};