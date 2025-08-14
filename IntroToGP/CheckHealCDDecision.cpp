#include "CheckHealCDDecision.h"

CheckHealCDDecision::CheckHealCDDecision()
{
}

CheckHealCDDecision::~CheckHealCDDecision()
{
}

BaseDecision* CheckHealCDDecision::EvaluateDecision(Entity* decidingEntity, vector<Entity*> targetEntities, int& errorCode)
{
	//	true- we can heal? assign our active ability/target to the entity and return a nullptr
	//	false- call the function of the falsepath
	decidingEntity->Action(*decidingEntity->CurrentAbility, *decidingEntity->Target);
	
	BaseAbility* tempAbility = nullptr;

	for (auto& ability : decidingEntity->AbilityList)
	{
		if (!ability->GetTargetsEnemies() && !ability->CheckCD())
		{
			tempAbility = ability;
		}
	}

	if (tempAbility)
	{
		return TruePath->EvaluateDecision(decidingEntity, targetEntities, errorCode);
	}
	else
	{
		return FalsePath->EvaluateDecision(decidingEntity, targetEntities, errorCode);
	}
}
