/**
 * @file main.cc
 * @author hhool (hhool@outlook.com)
 * @brief main entry of the application
 * @version 0.1
 * @date 2024-08-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#if defined(WIN32)
#if !defined(_AFXDLL)
#include <Windows.h>
#else
#include "StdAfx.h"
#endif
#endif

#if defined(_DEBUG) && defined(_MSC_VER) && defined(WIN32)
#include <crtdbg.h>
#endif

#include "ChartCtrl.h"

#if defined(WIN32)
#if !defined(UNDER_CE)
int main()
{
#else
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE /*hPrevInstance*/,
                     LPTSTR lpCmdLine,
                     int nCmdShow)
{
#endif
#else
int main()
{
#endif
#if defined(_DEBUG) && defined(_MSC_VER) && defined(WIN32)
    int Flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    Flag |= _CRTDBG_LEAK_CHECK_DF;
    _CrtSetDbgFlag(Flag);
    // _CrtSetBreakAlloc(2840);
#endif
    CChartCtrl *chart_ctrl = new CChartCtrl();
    return 0;
}