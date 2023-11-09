#pragma once
#include <DXHScripting.h>

class Blaster;

class SpaceShip : public DXH::Script
{
public:
    void Start() override;
    void Update(const DXH::Timer& gt) override;
    void OnDestroy() override;

private:
    DXH::RigidBody* m_SpaceshipRigibody;
    DXH::Camera* m_Camera;
    float m_DefaultSpeed = 1.f;
    float m_SqMaxVelocity = 5.f;

    float m_CameraDefaultPOV = 65.f;
    float m_ZoomScale = 0.5f;

    Blaster* m_LeftCannon;
    Blaster* m_RightCannon;
};
