#pragma once
#include "BaseDecision.h"


class CheckHealCDDecision : public BaseDecision 
{
public:
	CheckHealCDDecision();
	~CheckHealCDDecision();

	BaseDecision* EvaluateDecision(Entity* decidingEntity, vector<Entity*> targetEntities, int& errorCode) override;
};