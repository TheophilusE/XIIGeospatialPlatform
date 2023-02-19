#pragma once

#include <Core/Input/Declarations.h>
#include <Core/World/Declarations.h>
#include <GameEngine/GameApplication/GameApplication.h>
#include <GameEngine/GameState/FallbackGameState.h>
#include <GameEngine/GameState/GameState.h>
#include <GeospatialPlatformPlugin/GeospatialPlatformPluginDLL.h>

class GeospatialPlatformGameState : public xiiFallbackGameState
{
  XII_ADD_DYNAMIC_REFLECTION(GeospatialPlatformGameState, xiiFallbackGameState);

public:
  GeospatialPlatformGameState();
  ~GeospatialPlatformGameState();

  virtual xiiGameStatePriority DeterminePriority(xiiWorld* pWorld) const override;

  virtual void ProcessInput() override;

protected:
  virtual void ConfigureMainWindowInputDevices(xiiWindow* pWindow) override;
  virtual void ConfigureInputActions() override;
  virtual void ConfigureMainCamera() override;

private:
  virtual void OnActivation(xiiWorld* pWorld, const xiiTransform* pStartPosition) override;
  virtual void OnDeactivation() override;
  virtual void BeforeWorldUpdate() override;
  virtual void AfterWorldUpdate() override;

  xiiTexture2DResourceHandle m_hMonthlyTextures[12];
  const char* m_AssetPaths[12][12] = {};

  xiiUInt32 m_iCurrentMonth = 0;
  xiiUInt32 m_iCurrentYear = 0;

  float m_fLerpFactor = 1.0f;

  xiiHybridArray<const char*, 12u> m_Months;
  xiiHybridArray<const char*, 16u> m_Years;
};
