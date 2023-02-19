#pragma once

#include <Core/World/Component.h>
#include <Core/World/ComponentManager.h>
#include <Core/World/World.h>
#include <GeospatialPlatformPlugin/GeospatialPlatformPluginDLL.h>

using BounceComponentManager = xiiComponentManagerSimple<class BounceComponent, xiiComponentUpdateType::WhenSimulating>;

class XII_GEOSPATIALPLATFORMPLUGIN_DLL BounceComponent : public xiiComponent
{
  XII_DECLARE_COMPONENT_TYPE(BounceComponent, xiiComponent, BounceComponentManager);

  //////////////////////////////////////////////////////////////////////////
  // xiiComponent

public:
  virtual void SerializeComponent(xiiWorldWriter& stream) const override;
  virtual void DeserializeComponent(xiiWorldReader& stream) override;

protected:
  virtual void OnSimulationStarted() override;

  //////////////////////////////////////////////////////////////////////////
  // BounceComponent

public:
  BounceComponent();
  ~BounceComponent();

private:
  void Update();

  float m_fAmplitude = 1.0f;               // [ property ]
  xiiAngle m_Speed = xiiAngle::Degree(90); // [ property ]
};
