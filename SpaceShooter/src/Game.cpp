#include "Game.h"

void Game::StartEngine()
{
	using namespace DXH;
	DXHEngine::GetInstance().Init(AppProperties{
			.WindowTitle = L"Space Shooter",
		},
		[](const Timer& gt) { GetInstance().Init(gt); },
		[](const Timer& gt) { GetInstance().Update(gt); },
		[](const Timer& gt) { GetInstance().Destroy(gt); });
	DXHEngine::GetInstance().Run();
}

void Game::Init(const DXH::Timer& gt)
{
	using namespace DXH;
	GameObject* pObject = new GameObject();
	GameObject* pObject2 = new GameObject();
	pObject->Add<Transform>();
	Transform* transform = pObject2->Add<Transform>();
	transform->Position = { 0.0f, 2.0f, 0.0f };
	Mesh* mesh = pObject->Add<Mesh>();
	Mesh* mesh2 = pObject2->Add<Mesh>();
	mesh->Geo = RendererResource::GetGeometry("Cube");
	mesh->Mat = RendererResource::GetMaterial("SimpleMaterial");
	mesh2->Geo = RendererResource::GetGeometry("Sphere");
	mesh2->Mat = RendererResource::GetMaterial("SimpleMaterial");
	m_GameObjects.emplace_back(pObject);
	m_GameObjects.emplace_back(pObject2);

	// Create Camera
	GameObject* pCamera = new GameObject();
	Transform& camTransform = *(pCamera->Add<Transform>());
	camTransform.Position = { 0.0f, 0.0f, -5.0f };
	camTransform.Rotation.SetRotationFromAngles(300.0f, 0.0f, 0.0f);
	Camera& cam = *(pCamera->Add<Camera>());
	cam.IsPrimary = true;
}

void Game::Update(const DXH::Timer& gt)
{
	gt.DeltaTime();
}

void Game::Destroy(const DXH::Timer& gt)
{
	for (auto go : m_GameObjects)
	{
		delete go;
	}
}
