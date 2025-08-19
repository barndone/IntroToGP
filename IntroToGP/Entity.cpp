
#include "BaseAbility.h"
#include "StatusAbility.h"
#include "Entity.h"
//  this is where we will define our entities

Entity::Entity()
{
	//	this is where defaults are set!
	EntityName = "Default Entity";
	MaxHealth = 10;
	CurHealth = 10;
	Attack = 1;
	Defence = 0;
	Speed = 1;
	CurEXP = 0;
	EXPYield = 1;
	Level = 1;
}

Entity::~Entity()
{

}

void Entity::Action(BaseAbility& abilityToUse, Entity& targetEntity)
{
	//	calculate damage
	//	attack - defence -> update current health with result

	//	our attack - entity defence
	int deltaHealth = 0;
	deltaHealth = (this->Attack - targetEntity.GetDefence()) * -1;

	abilityToUse.ActivateCD();
	if (!abilityToUse.CausesStun)
	{
		targetEntity.UpdateCurHP(deltaHealth);
	}
	//	update the CurCDValue by StunLength
	//	Set the entity to stunned
	//	Cause the entity to take damage by the stunDamage at the end of each turn

	//	if it affects the ability to use an ability- change the CurCDValue instead (or in addition) to health!

}

void Entity::Tick()
{
	//	step one, update cooldowns 
	for (auto& abilities : AbilityList)
	{
		if (abilities->CheckCD())
		{
			abilities->UpdateCD();
		}
	}
	for (auto& effect : StatusList)
	{
		//	step two, apply ticks for damage
		auto it = effect.statsToEffect.find(HEALTH);
		if (it != effect.statsToEffect.end())
		{
			CurHealth-= it->second;
		}	
		
		//	step three, update status durations
		effect.curDuration--;
	}


}
