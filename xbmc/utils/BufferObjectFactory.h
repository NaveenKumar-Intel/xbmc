/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "BufferObject.h"

#include <functional>
#include <memory>
#include <vector>

class CBufferObjectFactory
{
public:
  static std::unique_ptr<CBufferObject> CreateBufferObject(int format);

  static void RegisterBufferObject(std::function<std::unique_ptr<CBufferObject>(int format)>);
  static void ClearBufferObjects();

protected:
  static std::vector<std::function<std::unique_ptr<CBufferObject>(int format)>> m_bufferObjects;
};
