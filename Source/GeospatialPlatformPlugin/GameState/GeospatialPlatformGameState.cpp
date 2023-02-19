#include <GeospatialPlatformPlugin/GeospatialPlatformPluginPCH.h>

#include <Core/Input/InputManager.h>
#include <Core/System/Window.h>
#include <Core/World/World.h>
#include <Foundation/Configuration/CVar.h>
#include <Foundation/Logging/Log.h>
#include <RendererCore/Debug/DebugRenderer.h>
#include <RendererCore/Meshes/MeshComponent.h>

#include <GeospatialPlatformPlugin/GameState/GeospatialPlatformGameState.h>

XII_BEGIN_DYNAMIC_REFLECTED_TYPE(GeospatialPlatformGameState, 1, xiiRTTIDefaultAllocator<GeospatialPlatformGameState>)
XII_END_DYNAMIC_REFLECTED_TYPE;

GeospatialPlatformGameState::GeospatialPlatformGameState() = default;
GeospatialPlatformGameState::~GeospatialPlatformGameState() = default;

void GeospatialPlatformGameState::OnActivation(xiiWorld* pWorld, const xiiTransform* pStartPosition)
{
  XII_LOG_BLOCK("GameState::Activate");

  SUPER::OnActivation(pWorld, pStartPosition);

#ifdef BUILDSYSTEM_ENABLE_IMGUI_SUPPORT
  if (xiiImgui::GetSingleton() == nullptr)
  {
    XII_DEFAULT_NEW(xiiImgui);
  }
#endif
}

void GeospatialPlatformGameState::OnDeactivation()
{
  XII_LOG_BLOCK("GameState::Deactivate");

  SUPER::OnDeactivation();

#ifdef BUILDSYSTEM_ENABLE_IMGUI_SUPPORT
  if (xiiImgui::GetSingleton() != nullptr)
  {
    xiiImgui* pImgui = xiiImgui::GetSingleton();
    XII_DEFAULT_DELETE(pImgui);
  }
#endif
}

void GeospatialPlatformGameState::AfterWorldUpdate()
{
  SUPER::AfterWorldUpdate();
}

void GeospatialPlatformGameState::BeforeWorldUpdate()
{
  XII_LOCK(m_pMainWorld->GetWriteMarker());

#ifdef BUILDSYSTEM_ENABLE_IMGUI_SUPPORT
  if (xiiImgui::GetSingleton() != nullptr)
  {
    static bool stats = false;
    static bool window = true;

    xiiImgui::GetSingleton()->SetCurrentContextForView(m_hMainView);

    xiiImgui::GetSingleton()->SetPassInputToImgui(false); // Reset this state, to deactivate input processing as long as GeospatialPlatformGameState::ProcessInput() isn't called again

    ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiCond_FirstUseEver);
    ImGui::Begin("Settings Panel", &window);

    if (ImGui::Button("Toggle Stats"))
    {
      stats = !stats;
    }

    if (stats)
    {
      ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    }

    ImGui::End();
  }
#endif
}

xiiGameStatePriority GeospatialPlatformGameState::DeterminePriority(xiiWorld* pWorld) const
{
  return xiiGameStatePriority::Default;
}

void GeospatialPlatformGameState::ConfigureMainWindowInputDevices(xiiWindow* pWindow)
{
  SUPER::ConfigureMainWindowInputDevices(pWindow);

  // Setup devices here
}

void GeospatialPlatformGameState::ConfigureInputActions()
{
  SUPER::ConfigureInputActions();
}

void GeospatialPlatformGameState::ProcessInput()
{
#ifdef BUILDSYSTEM_ENABLE_IMGUI_SUPPORT
  if (xiiImgui::GetSingleton())
  {
    xiiImgui::GetSingleton()->SetPassInputToImgui(true);

    // If the UI wants input, do not process other game state input
    if (xiiImgui::GetSingleton()->WantsInput())
      return;
  }
#endif

  SUPER::ProcessInput();

  xiiWorld* pWorld = m_pMainWorld;
}

void GeospatialPlatformGameState::ConfigureMainCamera()
{
  SUPER::ConfigureMainCamera();

  // Custom camera setup here
}