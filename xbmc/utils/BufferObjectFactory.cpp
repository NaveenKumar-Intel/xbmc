/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "BufferObjectFactory.h"

std::vector<std::function<std::unique_ptr<CBufferObject>(int format)>>
    CBufferObjectFactory::m_bufferObjects;

std::unique_ptr<CBufferObject> CBufferObjectFactory::CreateBufferObject(int format)
{
  return m_bufferObjects.back()(format);
}

void CBufferObjectFactory::RegisterBufferObject(
    std::function<std::unique_ptr<CBufferObject>(int format)> createFunc)
{
  m_bufferObjects.emplace_back(createFunc);
}

void CBufferObjectFactory::ClearBufferObjects()
{
  m_bufferObjects.clear();
}
