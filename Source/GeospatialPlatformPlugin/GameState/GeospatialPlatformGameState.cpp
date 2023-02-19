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

  // 2014
  m_AssetPaths[2][0] = "{ a3e3ceeb-7e38-4d02-88e5-f1d595a880e2 }";
  m_AssetPaths[2][1] = "{ 880c5b67-8a05-4a71-9198-bec681b47e93 }";
  m_AssetPaths[2][2] = "{ 2b369fe1-1b95-46e0-8d1f-ceaa34d34430 }";
  m_AssetPaths[2][3] = "{ 9db3dc2e-dfbd-44cb-8e30-62c911f6aaa1 }";
  m_AssetPaths[2][4] = "{ a59918e2-1211-41ca-a3d2-c7e4c370807c }";
  m_AssetPaths[2][5] = "{ 5272f35a-55be-4e07-8a7d-b17977453391 }";
  m_AssetPaths[2][6] = "{ c6fb73d3-b644-4a2e-8fe9-2bad0a50beba }";
  m_AssetPaths[2][7] = "{ 3a736842-7cfa-4032-a26b-1c345e8f9113 }";
  m_AssetPaths[2][8] = "{ 2f900a78-06bd-4cb2-aa09-8959aa6b735d }";
  m_AssetPaths[2][9] = "{ 7a79a57e-7ad5-47c6-bdc6-0309308b94b3 }";
  m_AssetPaths[2][10] = "{ 407e8216-0bbf-4f53-afbc-daf5317cfe73 }";
  m_AssetPaths[2][11] = "{ 039d0848-9f6c-4e59-b1dd-dc78837089ca }";

  // 2015
  m_AssetPaths[3][0] = "{ 1b70ef13-b386-4b17-8cdb-132ace1a39a0 }";
  m_AssetPaths[3][1] = "{ 63bc366a-9fe7-4ebe-b35b-5dddaf6e93dc }";
  m_AssetPaths[3][2] = "{ 0a9a3dc6-cdd4-42fb-a42d-9c1748b3ec57 }";
  m_AssetPaths[3][3] = "{ b64aaa67-9fd1-43b8-98bc-59275082140b }";
  m_AssetPaths[3][4] = "{ d0dfdde3-3aac-4d55-aab6-00844b1595d2 }";
  m_AssetPaths[3][5] = "{ c077e950-4426-4246-89ef-307bcfbae1ef }";
  m_AssetPaths[3][6] = "{ 80f76ca1-d8e4-489c-a6b7-86257bd18620 }";
  m_AssetPaths[3][7] = "{ 4318c57b-355c-4f46-b71b-d24d0c795321 }";
  m_AssetPaths[3][8] = "{ 496ce3d2-5636-4595-8660-b59c8c960902 }";
  m_AssetPaths[3][9] = "{ a302338b-5d8a-4594-af97-d54f4895cdc1 }";
  m_AssetPaths[3][10] = "{ fc310208-2286-4537-bed1-780c8518810b }";
  m_AssetPaths[3][11] = "{ 6ac0ed50-06f8-48ee-8b3a-69f236ef3ab6 }";

  // 2016
  m_AssetPaths[4][0] = "{ 65a28a2c-ff0b-4e2b-ad36-3021f6405fbc }";
  m_AssetPaths[4][1] = "{ a1a6c9d6-e0cb-41e5-bfdb-ee573d6db02c }";
  m_AssetPaths[4][2] = "{ e3694528-365b-4134-a929-a0edd64a5291 }";
  m_AssetPaths[4][3] = "{ 7bad768b-9469-42a2-a434-45226679eae9 }";
  m_AssetPaths[4][4] = "{ 77975501-5cea-4395-ad6d-950b54a33e03 }";
  m_AssetPaths[4][5] = "{ ac619dab-8b2a-49fb-affc-658bf84a98f0 }";
  m_AssetPaths[4][6] = "{ 7f48dba7-4980-4290-9caf-bba87f757eb8 }";
  m_AssetPaths[4][7] = "{ f4760774-482b-49eb-9682-0b0dc78b451f }";
  m_AssetPaths[4][8] = "{ a6ada947-ba84-4754-b83c-20526112754b }";
  m_AssetPaths[4][9] = "{ 6846594e-8dd3-48cf-986c-c8b091f0e1a7 }";
  m_AssetPaths[4][10] = "{ 36279052-9cac-4eb5-b6d0-cf2c86836090 }";
  m_AssetPaths[4][11] = "{ d1e82379-2d14-463f-89f0-9bfc234ac7b8 }";

  // 2017
  m_AssetPaths[5][0] = "{ 9eeafd76-5f4c-4ce1-b7b4-19194d294b07 }";
  m_AssetPaths[5][1] = "{ f4c50d68-7e0f-438a-a7e3-258e02c1291c }";
  m_AssetPaths[5][2] = "{ 1542772b-826b-4c23-919c-dca0cf8e4cde }";
  m_AssetPaths[5][3] = "{ 4177a29a-c5f3-4800-bd48-431f57876515 }";
  m_AssetPaths[5][4] = "{ 25acd697-18d0-4faf-9580-15167b6d2294 }";
  m_AssetPaths[5][5] = "{ 86643195-b7a7-4b9e-b0f7-a343c4e70a21 }";
  m_AssetPaths[5][6] = "{ 90db4561-1647-49c5-9355-7cb75ede6227 }";
  m_AssetPaths[5][7] = "{ 3dbe9c61-df5b-406d-88ec-c21f6bfd9da0 }";
  m_AssetPaths[5][8] = "{ 6af0eb45-a29a-4c43-bc00-ad82827cb3fb }";
  m_AssetPaths[5][9] = "{ b0b07624-e6ba-40c5-a54f-ade0bd2db7cb }";
  m_AssetPaths[5][10] = "{ 70ad2df8-0506-4495-9849-2f68649592d6 }";
  m_AssetPaths[5][11] = "{ c4afa6e0-2c1c-4d3d-9804-dfee6b86b075 }";

  // 2018
  m_AssetPaths[6][0] = "{ f3e6aca8-e597-4268-b183-6f54eed04c7f }";
  m_AssetPaths[6][1] = "{ 82fcf06f-bcb5-490b-a8cf-d06c1fd23ec4 }";
  m_AssetPaths[6][2] = "{ 86172972-efb0-4772-9d30-bc385b630abd }";
  m_AssetPaths[6][3] = "{ df9ce00d-a525-4967-a176-8d4b2b2d3f5d }";
  m_AssetPaths[6][4] = "{ b735c6eb-c54f-4dab-ba2d-a996cf160b1d }";
  m_AssetPaths[6][5] = "{ 203a36b8-4442-4301-b4f6-ee90f5b0979f }";
  m_AssetPaths[6][6] = "{ 9768b956-cfae-4df4-a1ff-3cc194bb695d }";
  m_AssetPaths[6][7] = "{ b305465b-d270-48c9-8a47-f089c380439c }";
  m_AssetPaths[6][8] = "{ a9dd005b-b65f-4469-8284-ae97f95d9caf }";
  m_AssetPaths[6][9] = "{ 5fdca287-e4d0-41c1-b6e4-866ecb665c84 }";
  m_AssetPaths[6][10] = "{ c78b7ac2-e78a-4c1a-8e79-440a7a57ff62 }";
  m_AssetPaths[6][11] = "{ c1a3a78e-eaf0-4a67-b711-f884c837e092 }";

  // 2019
  m_AssetPaths[7][0] = "{ f38e1912-5757-4e97-b0b3-b1351a27863c }";
  m_AssetPaths[7][1] = "{ 89c8e626-369f-46b7-a9ef-a049151ae991 }";
  m_AssetPaths[7][2] = "{ 7c1fba03-8f8c-44a5-88eb-e179eaaa289e }";
  m_AssetPaths[7][3] = "{ 6f3679d9-3dbd-40ad-8383-de79f1f0d4d2 }";
  m_AssetPaths[7][4] = "{ 01e5072f-dff2-4ff4-b85a-9f9f3d37d3b7 }";
  m_AssetPaths[7][5] = "{ 37677e47-80c1-43da-af93-6a4bba3d9066 }";
  m_AssetPaths[7][6] = "{ 8871bab9-337a-47d3-9e8b-cd912b6e98fe }";
  m_AssetPaths[7][7] = "{ a91ad9b0-d0a6-4cc1-a3c9-a4b0aca4dec8 }";
  m_AssetPaths[7][8] = "{ 62d5ff47-e301-4608-91bc-b6fc7709b0ef }";
  m_AssetPaths[7][9] = "{ 6bc83127-f896-412c-a6d6-43c51123f7a4 }";
  m_AssetPaths[7][10] = "{ 8d4011eb-5389-4609-b348-9962854763f3 }";
  m_AssetPaths[7][11] = "{ 0ceb9ef9-8b79-4340-8627-3d357f7ac9fd }";

  // 2020
  m_AssetPaths[8][0] = "{ 3830ada6-9cd6-4b89-b129-c70dcc996ed0 }";
  m_AssetPaths[8][1] = "{ e383118b-0ac9-4e35-84d4-01ab0468b2df }";
  m_AssetPaths[8][2] = "{ bceae58d-f942-4468-8965-d3435a3ccc86 }";
  m_AssetPaths[8][3] = "{ b9525444-e074-463f-af36-e21557bac668 }";
  m_AssetPaths[8][4] = "{ c9fe380c-7d5f-4ad0-833a-de057c5e7f6c }";
  m_AssetPaths[8][5] = "{ e030f29f-2150-41ba-84bb-60624559c1b8 }";
  m_AssetPaths[8][6] = "{ a1a57ec0-1481-4d65-8d7e-6ab98316daae }";
  m_AssetPaths[8][7] = "{ 2a23bb85-85e9-4565-9296-0acae00aa220 }";
  m_AssetPaths[8][8] = "{ 5463fd22-1343-483b-8b46-acd35ad98671 }";
  m_AssetPaths[8][9] = "{ d9d54e6b-9c1d-45dc-83fa-e2026e1bb6b1 }";
  m_AssetPaths[8][10] = "{ ec45d08c-2677-4c36-8392-e15fe3c7ac4d }";
  m_AssetPaths[8][11] = "{ 44cf41dd-f061-4a1d-9f2f-1bac007cf047 }";

  // 2021
  m_AssetPaths[9][0] = "{ 1cb1d130-553e-4549-beff-943c3a78fe5f }";
  m_AssetPaths[9][1] = "{ 5f1165e3-b3fb-402c-8632-612f182afb7e }";
  m_AssetPaths[9][2] = "{ 53db86c3-ee33-4e7b-9ac7-1d536db792c5 }";
  m_AssetPaths[9][3] = "{ e61b2dd6-82d1-4ccc-a581-a8736a13a0cb }";
  m_AssetPaths[9][4] = "{ d5864649-3306-4771-be3b-85eb3de2472a }";
  m_AssetPaths[9][5] = "{ 3f610e6b-5b73-480c-b0f7-ec40de97f7be }";
  m_AssetPaths[9][6] = "{ d97d8fc1-1ed7-49a3-b15a-1e5995d1702a }";
  m_AssetPaths[9][7] = "{ a217b901-6111-4007-b048-04aeb7d83641 }";
  m_AssetPaths[9][8] = "{ 4ae0de49-5087-4726-97cd-eaa6721adb6f }";
  m_AssetPaths[9][9] = "{ 6be5ec14-f8ef-4fed-9d45-2823183b013e }";
  m_AssetPaths[9][10] = "{ 56d65d0a-a000-41c1-8856-cfb0ac62dd4c }";
  m_AssetPaths[9][11] = "{ 411ea845-b4b7-47c3-9008-60ccbe039c4e }";

  // 2022 (Dataset is limited to 2022-08
  m_AssetPaths[10][0] = "{ c823d8c6-0526-46bb-81ce-5cfae48365af }";
  m_AssetPaths[10][1] = "{ 963a3ad2-9566-4fc8-9811-67c91136a25b }";
  m_AssetPaths[10][2] = "{ a7bd1779-2b14-4145-8d4a-4cb34de02adf }";
  m_AssetPaths[10][3] = "{ 99f15943-f211-4ad0-92e4-e602cb13d95a }";
  m_AssetPaths[10][4] = "{ 7077fed3-197d-48c6-a8c7-219d558fd403 }";
  m_AssetPaths[10][5] = "{ 97335809-2932-4859-9602-277c531256b6 }";
  m_AssetPaths[10][6] = "{ 61a47e91-8101-4aa9-9795-bc3adb3db198 }";
  m_AssetPaths[10][7] = "{ 8a09ace7-db71-425a-a90a-a5178fff8e47 }";
  m_AssetPaths[10][8] = "";
  m_AssetPaths[10][9] = "";
  m_AssetPaths[10][10] = "";
  m_AssetPaths[10][11] = "";

  // Reload new texture resources for the year
  xiiStringBuilder sData;

  for (xiiUInt32 i = 0; i < 11; ++i)
  {
    for (xiiUInt32 j = 0; j < 12; ++j)
    {
      if (i < 10)
        sData.Format("Content/Textures/ImageData/bm_vnp46A3_{0}_{1}{2}.png", m_Years[m_iCurrentYear], 0, m_iCurrentMonth);
      else
        sData.Format("Content/Textures/ImageData/bm_vnp46A3_{0}_{2}.png", m_Years[m_iCurrentYear], m_iCurrentMonth);

      m_hMonthlyTextures[i][j] = xiiResourceManager::LoadResource<xiiTexture2DResource>(m_AssetPaths[i][j]);

      if (i == 10 && j == 7)
        break;
    }
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

              if (m_iCurrentYear == 10 && m_iCurrentMonth > 7)
                // Reset the month to January
                m_iCurrentMonth = 0;

              ImGui::Combo("Current Month", &m_iCurrentMonth, m_Months.GetData(), static_cast<xiiInt32>(m_iCurrentYear == 10 ? 8 : m_Months.GetCount()));
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
