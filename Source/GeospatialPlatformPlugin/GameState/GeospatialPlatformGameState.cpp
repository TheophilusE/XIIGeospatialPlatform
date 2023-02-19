#include <GeospatialPlatformPlugin/GeospatialPlatformPluginPCH.h>

#include <Core/Input/InputManager.h>
#include <Core/System/Window.h>
#include <Core/World/World.h>
#include <Foundation/Configuration/CVar.h>
#include <Foundation/Logging/Log.h>
#include <Foundation/Utilities/ConversionUtils.h>
#include <RendererCore/Debug/DebugRenderer.h>
#include <RendererCore/Meshes/MeshComponent.h>
#include <RendererCore/Textures/Texture2DResource.h>

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

  m_Years.PushBack("2012");
  m_Years.PushBack("2013");
  m_Years.PushBack("2014");
  m_Years.PushBack("2015");
  m_Years.PushBack("2016");
  m_Years.PushBack("2017");
  m_Years.PushBack("2018");
  m_Years.PushBack("2019");
  m_Years.PushBack("2020");
  m_Years.PushBack("2021");
  m_Years.PushBack("2022");
  m_Years.PushBack("2023");

  m_Months.PushBack("January");
  m_Months.PushBack("February");
  m_Months.PushBack("March");
  m_Months.PushBack("April");
  m_Months.PushBack("May");
  m_Months.PushBack("June");
  m_Months.PushBack("July");
  m_Months.PushBack("August");
  m_Months.PushBack("September");
  m_Months.PushBack("October");
  m_Months.PushBack("November");
  m_Months.PushBack("December");

  // 2012
  m_AssetPaths[0][0] = "{ ae24f2d9-2d7f-465f-b226-6fa407afde04 }";
  m_AssetPaths[0][1] = "{ 60b7b90d-6424-4ff3-be2b-7c99d196e378 }";
  m_AssetPaths[0][2] = "{ 11abc487-85de-43d3-b14c-29f87942523f }";
  m_AssetPaths[0][3] = "{ e8fced3b-3931-4c87-8014-f7f733c443b5 }";
  m_AssetPaths[0][4] = "{ f7a00287-6a12-4dc4-a326-b8b2afc42b14 }";
  m_AssetPaths[0][5] = "{ 8e36309f-aa2e-44a5-960c-247c37a849d2 }";
  m_AssetPaths[0][6] = "{ 85d1241d-40d1-46bb-9149-f72fbded5969 }";
  m_AssetPaths[0][7] = "{ 9706cd98-20ce-4bcd-a427-9b85c65b67e7 }";
  m_AssetPaths[0][8] = "{ 71c5ab22-584a-41af-92f8-cba15b644d03 }";
  m_AssetPaths[0][9] = "{ 0a45df2c-79c7-4d5f-b41e-cf065655cfd2 }";
  m_AssetPaths[0][10] = "{ 4c0a6eb3-b5b0-4cb7-a14b-8f9520a6763f }";
  m_AssetPaths[0][11] = "{ 4ca67a24-3185-44c4-b323-c74678befbc2 }";

  // 2013
  m_AssetPaths[1][0] = "{ 586d47c2-8fd1-46d9-ae01-d9850624f711 }";
  m_AssetPaths[1][1] = "{ e25ef403-54fb-47a7-b3a3-c44f42d215d7 }";
  m_AssetPaths[1][2] = "{ c8fc0635-5265-4360-9587-47e2232b26da }";
  m_AssetPaths[1][3] = "{ 505b70b4-9399-47e2-b84b-737dd652fcc8 }";
  m_AssetPaths[1][4] = "{ f624c2a4-8892-4195-b667-f58c36b16345 }";
  m_AssetPaths[1][5] = "{ 3c5604e5-fcc8-4f64-aaa6-55b67c4189e9 }";
  m_AssetPaths[1][6] = "{ 3396e1f4-4a28-4e64-b27b-5cd843a76911 }";
  m_AssetPaths[1][7] = "{ fe4da2a4-7825-4594-a2e8-09acff5efbac }";
  m_AssetPaths[1][8] = "{ a7a29e9f-ffe2-4c9b-b31e-cd5b0523baf3 }";
  m_AssetPaths[1][9] = "{ e7a4f481-434a-41de-a1b3-e5baa44c9d6a }";
  m_AssetPaths[1][10] = "{ e7ab6990-a118-4113-ac48-a0a8392b0267 }";
  m_AssetPaths[1][11] = "{ 5344faaa-2b8a-40d3-a0e8-75cdfe4254ca }";

  // Reload new texture resources for the year
  xiiStringBuilder sData;

  for (xiiUInt32 i = 0; i < 12; ++i)
  {
    for (xiiUInt32 j = 0; j < 12; ++j)
    {
      if (i < 10)
        sData.Format("Content/Textures/ImageData/bm_vnp46A3_{0}_{1}{2}.png", m_Years[m_iCurrentYear], 0, m_iCurrentMonth);
      else
        sData.Format("Content/Textures/ImageData/bm_vnp46A3_{0}_{2}.png", m_Years[m_iCurrentYear], m_iCurrentMonth);

      m_hMonthlyTextures[i][j] = xiiResourceManager::LoadResource<xiiTexture2DResource>(m_AssetPaths[i][j]);
    }
    if (i > 1)
      break;
  }
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
    ImGui::Begin("Settings Panel", &window, ImGuiWindowFlags_AlwaysAutoResize);

    // Update material parameters
    {
      xiiGameObject* pScreenObject = nullptr;
      if (m_pMainWorld->TryGetObjectWithGlobalKey("ScreenObject", pScreenObject))
      {
        xiiMeshComponent* pMeshComponent = nullptr;
        if (pScreenObject->TryGetComponentOfBaseType(pMeshComponent))
        {
          xiiMaterialResourceHandle hMaterial0 = pMeshComponent->GetMaterial(0);
          if (hMaterial0.IsValid())
          {
            xiiResourceLock<xiiMaterialResource> pMaterial0(hMaterial0, xiiResourceAcquireMode::AllowLoadingFallback);
            if (pMaterial0.GetAcquireResult() == xiiResourceAcquireResult::LoadingFallback)
              xiiLog::Error("Failed to retrieve texture resource from ScreenObject.");
            else
            {
              auto year = m_iCurrentYear;
              auto month = m_iCurrentMonth;

              ImGui::Combo("Current Year", &m_iCurrentYear, m_Years.GetData(), static_cast<xiiInt32>(m_Years.GetCount()));
              ImGui::Combo("Current Month", &m_iCurrentMonth, m_Months.GetData(), static_cast<xiiInt32>(m_Months.GetCount()));
              ImGui::SliderFloat("Adjust Weighting", &m_fLerpFactor, 0.0f, 2.0f);

              if (year != m_iCurrentYear || month != m_iCurrentMonth)
              {
                // Reset the blend. Having the setting remaining on the blend when switching textures is inconvenient.
                m_fLerpFactor = 1.0f;
              }

              pMaterial0->SetTexture2DBinding("CurrentTexture", m_hMonthlyTextures[m_iCurrentYear][m_iCurrentMonth]);

              if ((m_iCurrentMonth - 1) >= 0)
              {
                pMaterial0->SetParameter("LerpFactorOneTwo", m_fLerpFactor < 1.0f ? m_fLerpFactor : 1.0f);
                pMaterial0->SetTexture2DBinding("PreviousTexture", m_hMonthlyTextures[m_iCurrentYear][m_iCurrentMonth - 1]);
              }
              else
              {
                pMaterial0->SetTexture2DBinding("PreviousTexture", m_hMonthlyTextures[m_iCurrentYear][m_iCurrentMonth]);
                pMaterial0->SetParameter("LerpFactorOneTwo", 1.0f);
              }

              if (m_iCurrentMonth + 1 < 12)
              {
                pMaterial0->SetParameter("LerpFactorTwoThree", m_fLerpFactor > 1.0f ? m_fLerpFactor - 1.0f : 0.0f);
                pMaterial0->SetTexture2DBinding("NextTexture", m_hMonthlyTextures[m_iCurrentYear][m_iCurrentMonth + 1]);
              }
              else
              {
                pMaterial0->SetTexture2DBinding("NextTexture", m_hMonthlyTextures[m_iCurrentYear][m_iCurrentMonth]);
                pMaterial0->SetParameter("LerpFactorTwoThree", 0.0f);
              }
            }
          }
          else
          {
            xiiLog::Error("Screen object material at index 0 is invalid.");
          }
        }
        else
        {
          xiiLog::Error("Failed to retrieve mesh component from screen object.");
        }
      }
      else
      {
        xiiLog::Error("Failed to retrieve main screen object with global key '{}'.", "ScreenObject");
      }
    }

    bool bDebug = false;
    if (bDebug)
    {
      ImGui::Text("Current Year: %u", m_iCurrentYear);
      ImGui::Text("Current Month: %u", m_iCurrentMonth);
    }

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
