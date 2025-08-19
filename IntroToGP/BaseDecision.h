#pragma once
#include <vector>

class BaseDecision
{
public:
	class Entity* DecidingEntity;

	BaseDecision* TruePath = nullptr;
	BaseDecision* FalsePath = nullptr;

	BaseDecision();
	~BaseDecision();

	virtual BaseDecision* EvaluateDecision(class Entity* decidingEntity, class std::vector<class Entity*> targetEntities, int& errorCode);
};