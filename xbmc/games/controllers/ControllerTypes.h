/*
 *      Copyright (C) 2015 Team Kodi
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include <memory>
#include <vector>

namespace GAME
{
  class CController;
  typedef std::shared_ptr<CController> ControllerPtr;
  typedef std::vector<ControllerPtr>   ControllerVector;

  /*!
   * \brief Types of features used in the controller abstraction
   */
  enum class FEATURE_TYPE
  {
    UNKNOWN,
    SCALAR,
    ANALOG_STICK,
    ACCELEROMETER,
    KEY,
    RELATIVE_POINTER,
    ABSOLUTE_POINTER,
    MOTOR,
  };

  enum class GEOMETRY
  {
    NONE,
    RECTANGLE,
    CIRCLE,
  };
}
