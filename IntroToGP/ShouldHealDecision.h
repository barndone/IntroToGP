#pragma once
#include "BaseDecision.h"


class ShouldHealDecision : public BaseDecision
{
public:
	ShouldHealDecision();
	//	ShouldHealDecision(Entity* decidingEntity);
	~ShouldHealDecision();

	BaseDecision* EvaluateDecision(class Entity* decidingEntity, std::vector<class Entity*> targetEntities, int& errorCode) override;
};