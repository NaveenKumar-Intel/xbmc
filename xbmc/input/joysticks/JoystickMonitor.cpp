/*
 *  Copyright (C) 2015-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "JoystickMonitor.h"
#include "Application.h"
#include "games/controllers/ControllerIDs.h"
#include "input/InputManager.h"
#include "messaging/ApplicationMessenger.h"
#include "ServiceBroker.h"

#include <cmath>

using namespace KODI;
using namespace JOYSTICK;
using namespace KODI::MESSAGING;

#define AXIS_DEADZONE  0.05f

std::string CJoystickMonitor::ControllerID() const
{
  return DEFAULT_CONTROLLER_ID;
}

bool CJoystickMonitor::AcceptsInput(const FeatureName& feature) const
{
  return false; // todo: what is this for?
}

bool CJoystickMonitor::OnButtonPress(const FeatureName& feature, bool bPressed)
{
  if (bPressed)
  {
    CServiceBroker::GetInputManager().SetMouseActive(false);
    return ResetTimers();
  }

  return false;
}

bool CJoystickMonitor::OnButtonMotion(const FeatureName& feature, float magnitude, unsigned int motionTimeMs)
{
  if (std::fabs(magnitude) > AXIS_DEADZONE)
  {
    CServiceBroker::GetInputManager().SetMouseActive(false);
    return ResetTimers();
  }

  return false;
}

bool CJoystickMonitor::OnAnalogStickMotion(const FeatureName& feature, float x, float y, unsigned int motionTimeMs)
{
  // Analog stick deadzone already processed
  if (x != 0.0f || y != 0.0f)
  {
    CServiceBroker::GetInputManager().SetMouseActive(false);
    return ResetTimers();
  }

  return false;
}

bool CJoystickMonitor::OnWheelMotion(const FeatureName& feature, float position, unsigned int motionTimeMs)
{
  if (std::fabs(position) > AXIS_DEADZONE)
  {
    CServiceBroker::GetInputManager().SetMouseActive(false);
    return ResetTimers();
  }

  return false;
}

bool CJoystickMonitor::OnThrottleMotion(const FeatureName& feature, float position, unsigned int motionTimeMs)
{
  if (std::fabs(position) > AXIS_DEADZONE)
  {
    CServiceBroker::GetInputManager().SetMouseActive(false);
    return ResetTimers();
  }

  return false;
}

bool CJoystickMonitor::ResetTimers(void)
{
  g_application.ResetSystemIdleTimer();
  CApplicationMessenger::GetInstance().PostMsg(TMSG_RESETSCREENSAVERTIMER);
  CApplicationMessenger::GetInstance().PostMsg(TMSG_DEACTIVATESCREENSAVER);

  return true;
}
