/**
 * @file chartctr_wrapper.cc
 * @author hhool (hhool@outlook.com
 * @brief  chartctrl wrapper class definition with mfc support
 * @version 0.1
 * @date 2024-08-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "StdAfx.h"
#include "chartctr_wrapper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CChartCtrlWrapperApp, CWinApp)
END_MESSAGE_MAP()

CChartCtrlWrapperApp::CChartCtrlWrapperApp() {}

CChartCtrlWrapperApp theApp;

CChartCtrlWrapperApp::~CChartCtrlWrapperApp() {}

BOOL CChartCtrlWrapperApp::InitInstance() {
  InitCommonControls();
  CWinApp::InitInstance();
  return TRUE;
}

int CChartCtrlWrapperApp::ExitInstance() {
  return CWinApp::ExitInstance();
}