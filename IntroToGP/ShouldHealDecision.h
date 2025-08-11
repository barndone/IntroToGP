#pragma once
#include "BaseDecision.h"

class ShouldHealDecision : BaseDecision
{
	ShouldHealDecision();
	ShouldHealDecision(Entity* decidingEntity);
	~ShouldHealDecision();

	BaseDecision* EvaluateDecision(Entity* decidingEntity, int& errorCode) override;
};