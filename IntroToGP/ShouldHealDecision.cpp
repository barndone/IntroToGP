#include "ShouldHealDecision.h"
#include "Entity.h"
#include "BaseAbility.h"
#include "StatusAbility.h"

ShouldHealDecision::ShouldHealDecision()
{
	DecidingEntity = nullptr;
}

//	ShouldHealDecision::ShouldHealDecision(Entity* decidingEntity)
//	{
//		DecidingEntity = decidingEntity;
//	}

ShouldHealDecision::~ShouldHealDecision()
{

}

BaseDecision* ShouldHealDecision::EvaluateDecision(Entity* decidingEntity, vector<Entity*> targetEntities, int& errorCode)
{
	if (decidingEntity)
	{
		//	layer one- can we heal
		bool HasHealingAbilities = false;
		//	i t e r a t i o n	
		for (auto& abilities : decidingEntity->AbilityList)
		{
			if (!abilities->GetTargetsEnemies())
			{
				HasHealingAbilities = true;
			}
			if (HasHealingAbilities) break;
			else
			{
				return FalsePath->EvaluateDecision(decidingEntity, targetEntities, errorCode);
			}
		}

		if (HasHealingAbilities)
		{
			//	layer two- do we need to heal
			if (decidingEntity->GetCurHP() < 5)
			{
				return TruePath->EvaluateDecision(decidingEntity, targetEntities, errorCode);
			}
			else
			{
				return FalsePath->EvaluateDecision(decidingEntity, targetEntities, errorCode);
			}
		}
	}

	else
	{
		errorCode = -1;
		return nullptr;
	}
}
