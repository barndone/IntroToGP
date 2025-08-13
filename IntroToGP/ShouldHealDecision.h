#pragma once
#include "BaseDecision.h"


class ShouldHealDecision : public BaseDecision
{
public:
	ShouldHealDecision();
	ShouldHealDecision(Entity* decidingEntity);
	~ShouldHealDecision();

	BaseDecision* EvaluateDecision(Entity* decidingEntity, int& errorCode) override;
};