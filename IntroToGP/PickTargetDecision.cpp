#include "PickTargetDecision.h"
#include "Entity.h"
#include "BaseAbility.h"
#include "StatusAbility.h"

PickTargetDecision::PickTargetDecision()
{

}

PickTargetDecision::~PickTargetDecision()
{

}

BaseDecision* PickTargetDecision::EvaluateDecision(Entity* decidingEntity, vector<Entity*> targetEntities, int& errorCode)
{
    if (targetEntities.size() > 0)
    {
        Entity* curTarget = targetEntities[0];
        //  case 1: only one entry in list
        if (targetEntities.size() == 1)
        {
            decidingEntity->Target = curTarget;
        }
        //  case 2: more than one entry
        else
        {
            //  compare defence
            for (int idx = 1; idx < targetEntities.size(); idx++)
            {
                //  only overwrite our curTarget if the defence of the item we are looking at is lower
                if (curTarget->GetDefence() > targetEntities[idx]->GetDefence())
                {
                    curTarget = targetEntities[idx];
                }
            }

            decidingEntity->Target = curTarget;
        }

        return TruePath->EvaluateDecision(decidingEntity, targetEntities, errorCode);
    }
    //  why tf is the list empty
    else
    {
        errorCode = -3;
        return nullptr;
    }
}
