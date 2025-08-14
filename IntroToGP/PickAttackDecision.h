#pragma once
#include "BaseDecision.h"

class PickAttackDecision : public BaseDecision
{
	PickAttackDecision();
	~PickAttackDecision();

	BaseDecision* EvaluateDecision(Entity* decidingEntity, vector<Entity*> targetEntities, int& errorCode) override;

};