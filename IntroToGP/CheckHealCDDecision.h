#pragma once
#include "BaseDecision.h"


class CheckHealCDDecision : public BaseDecision 
{
public:
	CheckHealCDDecision();
	~CheckHealCDDecision();

	BaseDecision* EvaluateDecision(class Entity* decidingEntity, std::vector<class Entity*> targetEntities, int& errorCode) override;
};