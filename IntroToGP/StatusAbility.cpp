#include "StatusAbility.h"
#include "Entity.h"

StatusAbility::StatusAbility()
{
	
}

StatusAbility::~StatusAbility()
{
}

void StatusAbility::ApplyStatusEffect(Entity* target)
{
	// assign our current (working) duration to our max duration
	Effect.curDuration = Effect.Duration;
	//	get every stat that we are affecting
	target->StatusList.push_back(Effect);

}

void StatusAbility::TickStatuses(Entity* target)
{
	//	iterate through all of the statusses applied to a target
	for (auto& effect : target->StatusList)
	{
		//	iterate through all of the stats a given effect hits
		for (auto& pair : Effect.statsToEffect)
		{
			//	update the given value on the target
			switch (pair.first)
			{
			//	case StatToEffect::HEALTH:
			//		//	"if statement" body
			//		int delta = pair.second;
			//		target->UpdateCurHP(delta);
			//		break;
			//	case StatToEffect::ATTACK:
			//	
			//		break;
			//	case StatToEffect::DEFENCE:
			//	
			//		break;
			//	case StatToEffect::SPEED:
			//	
			//		break;
			//	case StatToEffect::ACTION:
			//	
			//		break;
			}
		}
		effect.curDuration--;
		if (effect.curDuration <=0)
		{
			//	todo handle removing the status effect
		}
	}
}
