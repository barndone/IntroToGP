#pragma once
#include "BaseDecision.h"

class PickTargetDecision : public BaseDecision
{
	PickTargetDecision();
	~PickTargetDecision();

	BaseDecision* EvaluateDecision(Entity* decidingEntity, vector<Entity*> targetEntities, int& errorCode) override;


};
