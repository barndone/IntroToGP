#pragma once
#include "BaseDecision.h"


class ShouldHealDecision : public BaseDecision
{
public:
	ShouldHealDecision();
	//	ShouldHealDecision(Entity* decidingEntity);
	~ShouldHealDecision();

	BaseDecision* EvaluateDecision(Entity* decidingEntity, vector<Entity*> targetEntities, int& errorCode) override;
};