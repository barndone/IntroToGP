#pragma once
#include "Entity.h"
#include <iostream>
#include <stdlib.h>


class BaseDecision
{
public:
	Entity* DecidingEntity;

	BaseDecision* TruePath = nullptr;
	BaseDecision* FalsePath = nullptr;

	BaseDecision();
	~BaseDecision();

	virtual BaseDecision* EvaluateDecision(Entity* decidingEntity, vector<Entity*> targetEntities, int& errorCode);
};