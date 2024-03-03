#define _CRT_SECURE_NO_WARNINGS 



#include "../Common/SimpleHTTPConstruct.h"
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <map>
#include "../Common/SHA256.h"
#include "string"
#include <list>



class mainFunc : public SimpleHTTPConstruct::SimpleHTTPConstruct {
public:
    static void RunMainFunc(void);
};

#define HTTP_methoods SimpleHTTPConstruct::SimpleHTTPConstruct



void mainFunc::RunMainFunc() {

    std::wcout << AsIs(L"Content-Type: text/html; charset=utf-8" + std::wstring(L"\n\n"));

    std::wcout <<
        AsIs(L"<!DOCTYPE HTML>") +
        HTML(L"",
            Head(L"",
                L"<meta encoding = \"utf-8\">" +
                AsIs(L"\n<title> Авторизация </title>")
            ) +
            Body(L"align = \"left\"",
                Form(L"METHOD = \"POST\" action = RZD.cgi",
                    AsIs(L"<h1 align = \"left\" > Введите данные аккаунта </h1>\n") +
                    Paragrah(L"align = \"left\"",
                        Paragrah(L"", L"Логин:") +
                        AsIs(L"<input name = \"text\"> ") +
                        Paragrah(L"", L"Пароль:") +
                        AsIs(L"<input name = \"pass\">")
                    ) +
                    Paragrah(L"align = \"left\"",
                        AsIs(L"<input type = \"submit\"; style=\"background-color: blue\"; value = \"Вход\">")
                    )
                )
            )
        );


}



int main() {
    setlocale(LC_ALL, "Russian");
    mainFunc::RunMainFunc();
    return 0;
}