#pragma once
#include <DXHScripting.h>

class SpaceShip : public DXH::Script
{
public:
    void Start() override;
    void Update(const DXH::Timer& gt) override;

private:
    DXH::RigidBody* m_SpaceshipRigibody;
    float m_DefaultSpeed = 1.f;
    float m_SqMaxVelocity = 10.f;

    float m_FireRate = 0.5f;
    float m_FireCooldown = 0.f;
};
