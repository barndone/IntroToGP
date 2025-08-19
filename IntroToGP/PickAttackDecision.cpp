#include "PickAttackDecision.h"
#include "Entity.h"
#include "BaseAbility.h"
#include "StatusAbility.h"

PickAttackDecision::PickAttackDecision()
{

}

PickAttackDecision::~PickAttackDecision()
{
}

BaseDecision* PickAttackDecision::EvaluateDecision(Entity* decidingEntity, vector<Entity*> targetEntities, int& errorCode)
{
    BaseAbility* curAbility = nullptr;

    //  case 0: empty list
    if (decidingEntity->AbilityList.size() == 0)
    {
        errorCode = -2;
        return nullptr;
    }
    
    //  case 1: one entry
    else if (decidingEntity->AbilityList.size() == 1)
    {
        decidingEntity->CurrentAbility = decidingEntity->AbilityList[0];
        return nullptr;
    }
    
    //  case 2: two+ entries
    else
    {
        curAbility = decidingEntity->AbilityList[0];
        for (int idx = 1; decidingEntity->AbilityList.size(); idx++)
        {
            //  if the damage mod of the next ability is greater
            if (curAbility->GetDamageMod() < decidingEntity->AbilityList[idx]->GetDamageMod())
            {
                //  swap
                curAbility = decidingEntity->AbilityList[idx];
            }
        }
        decidingEntity->CurrentAbility = curAbility;
        return nullptr;
    }
}
