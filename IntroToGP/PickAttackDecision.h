#pragma once
#include "BaseDecision.h"

class PickAttackDecision : public BaseDecision
{
	PickAttackDecision();
	~PickAttackDecision();

	BaseDecision* EvaluateDecision(class Entity* decidingEntity, std::vector<class Entity*> targetEntities, int& errorCode) override;
};