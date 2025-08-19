#pragma once
#include "BaseDecision.h"

class PickTargetDecision : public BaseDecision
{
	PickTargetDecision();
	~PickTargetDecision();

	BaseDecision* EvaluateDecision(class Entity* decidingEntity, std::vector<class Entity*> targetEntities, int& errorCode) override;


};
