#include "ShouldHealDecision.h"

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
		if (decidingEntity->GetCurHP() < 5)
		{
			return TruePath->EvaluateDecision(decidingEntity, targetEntities, errorCode);
		}
		else
		{
			return FalsePath->EvaluateDecision(decidingEntity, targetEntities, errorCode);
		}
	}

	else
	{
		errorCode = -1;
		return nullptr;
	}
}
