#include <XIIGeospatialPlatforPlugin/XIIGeospatialPlatforPluginPCH.h>

#include <Core/Input/InputManager.h>
#include <Core/System/Window.h>
#include <Core/World/World.h>
#include <Foundation/Configuration/CVar.h>
#include <Foundation/Logging/Log.h>
#include <RendererCore/Debug/DebugRenderer.h>
#include <RendererCore/Meshes/MeshComponent.h>

#include <XIIGeospatialPlatforPlugin/GameState/XIIGeospatialPlatforGameState.h>

XII_BEGIN_DYNAMIC_REFLECTED_TYPE(XIIGeospatialPlatforGameState, 1, xiiRTTIDefaultAllocator<XIIGeospatialPlatforGameState>)
XII_END_DYNAMIC_REFLECTED_TYPE;

XIIGeospatialPlatforGameState::XIIGeospatialPlatforGameState()  = default;
XIIGeospatialPlatforGameState::~XIIGeospatialPlatforGameState() = default;

void XIIGeospatialPlatforGameState::OnActivation(xiiWorld* pWorld, const xiiTransform* pStartPosition)
{
  XII_LOG_BLOCK("GameState::Activate");

  SUPER::OnActivation(pWorld, pStartPosition);
}

void XIIGeospatialPlatforGameState::OnDeactivation()
{
  XII_LOG_BLOCK("GameState::Deactivate");

  SUPER::OnDeactivation();
}

void XIIGeospatialPlatforGameState::AfterWorldUpdate()
{
  SUPER::AfterWorldUpdate();
}

void XIIGeospatialPlatforGameState::BeforeWorldUpdate()
{
  XII_LOCK(m_pMainWorld->GetWriteMarker());
}

xiiGameStatePriority XIIGeospatialPlatforGameState::DeterminePriority(xiiWorld* pWorld) const
{
  return xiiGameStatePriority::Default;
}

void XIIGeospatialPlatforGameState::ConfigureMainWindowInputDevices(xiiWindow* pWindow)
{
  SUPER::ConfigureMainWindowInputDevices(pWindow);

  // Setup devices here
}

void XIIGeospatialPlatforGameState::ConfigureInputActions()
{
  SUPER::ConfigureInputActions();
}

void XIIGeospatialPlatforGameState::ProcessInput()
{
  SUPER::ProcessInput();

  xiiWorld* pWorld = m_pMainWorld;
}

void XIIGeospatialPlatforGameState::ConfigureMainCamera()
{
  SUPER::ConfigureMainCamera();

  // Custom camera setup here
}
