#pragma once
#include "BaseDecision.h"


class CheckHealCDDecision : public BaseDecision 
{
public:
	CheckHealCDDecision();
	~CheckHealCDDecision();

	BaseDecision* EvaluateDecision(Entity* decidingEntity, int& errorCode) override;
};