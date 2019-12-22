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
  for(;;){
  fstream logs;
  logs.open("Logs.txt", ios::app);
  if(logs.is_open())
  {
    x=_getch();
    logs<<x;
    logs.close();
  }
  if(plik.good()!=true)
  {
    logs<<"Error";
    exit(0)
  }
}
}
int main()
{
  StartingLogs();
  return 0;
}
