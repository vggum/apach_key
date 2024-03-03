#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "../Common/SimpleHTTPConstruct.h"
#include <set>


using namespace std;
using namespace SimpleHTTPConstruct;

class mainFunc : public SimpleHTTPConstruct {
public:
    static const std::wstring action(void) {
        if (StringToWString(getenv("REQUEST_METHOD")) != L"") {
            return Paragrah(L"", StringToWString(getenv("QUERY_STRING")) );
        }
    }
    static void RunMainFunc(void) {
        std::wcout << AsIs(L"Content-Type: text/html; charset=utf-8" + std::wstring(L"\n\n"));

        std::wcout <<
            AsIs(L"<!DOCTYPE HTML>") +

            HTML(L"",
                Head(L"",
                    AsIs(L"<title> RZD </title>")
                ) +
                Body(L"",
                    Paragrah(L"align = \"center\" ",
                        Img(L"src = \"https://riamo.ru/files/image/05/35/94/-gallery!kt1.jpg\" alt = \"Can`t load RZD image\" width = \"700\"")
                    ) +
                    Form(L"METHOD=\"POST\" action = Autorization.cgi",
                        Paragrah(L"align = \"center\"",
                            AsIs(L"<input type = \"submit\" value=\"Let`s go!\"  style=\"background: rgb(250, 132, 43); border-radius: 0.3cm; width: 10cm;\" > ")
                            
                        )
                    ) 
                   + action()
                )
            );
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    mainFunc::RunMainFunc();
    return -1;
}

