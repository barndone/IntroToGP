#include "CheckHealCDDecision.h"

CheckHealCDDecision::CheckHealCDDecision()
{
}

CheckHealCDDecision::~CheckHealCDDecision()
{
}

BaseDecision* CheckHealCDDecision::EvaluateDecision(Entity* decidingEntity, int& errorCode)
{
	//	true- we can heal? assign our active ability/target to the entity and return a nullptr
	//	false- call the function of the falsepath
	decidingEntity->Action(*decidingEntity->CurrentAbility, *decidingEntity->Target);
	return nullptr;
}
