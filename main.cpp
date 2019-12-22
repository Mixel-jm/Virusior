#include <iostream>
#include <fstream>
#include <windows.h>
#include <winuser.h>
#include <conio.h>
using namespace std;
void StartingLogs()
{
  std:ofstream outf("Logs.txt");
  fstream logs;
  logs.open("Logs.txt", ios::app);
  if(logs.is_open())
  {
    logs<<_getch();
    logs.close();
  }
}
int main()
{
  StartingLogs();
  return 0;
}
