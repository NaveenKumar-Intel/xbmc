/*
 *  Copyright (C) 2017-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "WinSystemWayland.h"
#include "rendering/vulkan/wayland/RenderSystemVulkanWayland.h"

namespace KODI
{
namespace WINDOWING
{
namespace WAYLAND
{

class CWinSystemWaylandVulkanContext : public CWinSystemWayland,
                                       public KODI::RENDERING::VULKAN::CRenderSystemVulkanWayland
{
public:
  // Implementation of CWinSystemBase via CWinSystemWayland
  CRenderSystemBase* GetRenderSystem() override { return this; }
  bool InitWindowSystem() override;
  bool DestroyWindowSystem() override;

  bool CreateNewWindow(const std::string& name, bool fullScreen, RESOLUTION_INFO& res) override;
  bool DestroyWindow() override;

  void PresentRender(bool rendered, bool videoLayer) override;

protected:
  void SetContextSize(CSizeInt size) override;

private:
  CSizeInt GetNativeWindowAttachedSize();
};

} // namespace WAYLAND
} // namespace WINDOWING
} // namespace KODI
