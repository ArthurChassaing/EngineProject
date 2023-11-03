#pragma once
#include <DXHScripting.h>


class Player : public DXH::Script
{
public:
	void Start() override;
	void Update(const DXH::Timer& gt) override;
private:
	const float m_MouseSensitivity = 0.5f;
	//Rotation Axes in Quaternion 
	float m_pitch;
	float m_yaw;
	float m_roll = 0;

	void SetYaw();
	void SetPitch();

	DXH::Transform* m_camTransform;
};