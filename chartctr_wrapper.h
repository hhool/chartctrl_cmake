/**
 * @file chartctr_wrapper.h
 * @author hhool (hhool@outlook.com)
 * @brief chartctrl wrapper class definition with mfc support
 * @version 0.1
 * @date 2024-08-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CHARTCTRL_SOURCE_CHARTCTR_WRAPPER_H_
#define CHARTCTRL_SOURCE_CHARTCTR_WRAPPER_H_

#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER > 1000

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

class CChartCtrlWrapperApp : public CWinApp {
 public:
  CChartCtrlWrapperApp();
  virtual ~CChartCtrlWrapperApp();

  virtual BOOL InitInstance();
  virtual int ExitInstance();

  DECLARE_MESSAGE_MAP()
};

#endif
