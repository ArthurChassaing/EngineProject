#include "CameraSystem.h"
#include "../ComponentManager.h"
#include "../components/Camera.h"
#include "../components/Transform.h"
#include "../../maths/Quaternion.h"
#include "../../maths/Matrix.h"
#include "../../core/Window.h"
void DXH::CameraSystem::Update(const Timer& gt)
{
	using namespace DirectX;

	auto& cameraMap = ComponentManager<Camera>::GetInstance().GetUsedComponentsMap();
	auto& transformMap = ComponentManager<Transform>::GetInstance().GetUsedComponentsMap();

	for (auto& pair : cameraMap)
	{
		if (!pair.second->IsPrimary)
			continue;

		auto go = pair.first;
		auto cam = pair.second;
		auto transform = transformMap.at(go);
		Matrix rotationMatrix = transform->Rotation.GetRotationMatrix();
		Vector3 forward = Vector3::Forward;
		cam->Target = XMVector3Normalize(XMVector3Transform(forward.Load(), rotationMatrix.Load()));
		cam->View = XMMatrixLookAtLH(transform->Position.Load(), cam->Target.Load(), Vector3::Up.Load());
		cam->Proj = XMMatrixPerspectiveFovLH(
			cam->fieldOfView,
			(float)Window::GetInstance().GetWidth() / Window::GetInstance().GetHeight(),
			cam->NearPlan,
			cam->FarPlan
		);

	}
}
