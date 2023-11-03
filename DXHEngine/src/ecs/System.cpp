#include "System.h"

// Include all systems here
#include "systems/ScriptingSystem.h"
#include "systems/PhysicsSystem.h"
#include "systems/CameraSystem.h"
#include "systems/RenderSystem.h"

namespace DXH
{
void System::UpdateAll(const Timer& gt)
{
    // Systems creation
    static ScriptingSystem scriptingSystem;
    static PhysicsSystem physicsSystem;
    static CameraSystem cameraSystem;
    static RenderSystem renderSystem;

    // Systems update
    scriptingSystem.Update(gt);
    physicsSystem.Update(gt);
    cameraSystem.Update(gt);
    renderSystem.Update(gt);
}
}
