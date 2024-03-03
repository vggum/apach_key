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
    static void RunMainFunc(std::string = 0);
};

#define HTTP_methoods SimpleHTTPConstruct::SimpleHTTPConstruct


void mainFunc::RunMainFunc(std::string input) {
    std::wcout << AsIs(L"Content-Type: text/html; charset=utf-8" + std::wstring(L"\n\n"));

    std::wcout <<
        AsIs(L"<!DOCTYPE HTML>") +

        HTML(L"",
            Head(L"",
                L"<meta encoding = \"utf-8\">" +
                AsIs(L"\n<title> login page </title>")
            ) +
            Body(L"align = \"center\"",
                Paragrah(L"align = \"center\"", StringToWString(input+ "test"))
            )
        );
}




std::wstring rawURLDecode(std::wstring raw) {
    int NumCntr = 0,
        TempNum = 0;

    std::wstring loginHex,
        passHex,
        temp,
        retval;
    std::vector<int>AlphasInUint;

    for (size_t it = 0; it < raw.size() + 1; it++) {

        if (raw[it] != '%' && it != raw.size()) {
            temp += raw[it];
        }
        else {
            NumCntr++;
            TempNum += std::stoi(temp, 0, 16);
            if (NumCntr == 2) {
                AlphasInUint.push_back(TempNum);
                TempNum = 0;
                NumCntr = 0;
            }
            temp.clear();
            continue;
        }
    }

    for (auto it = 0; it < AlphasInUint.size(); it++)
    {
        if (AlphasInUint.at(it) >= 352)
            AlphasInUint.at(it) += 688;
        else {
            AlphasInUint.at(it) += 751;

        }
        retval.push_back((AlphasInUint.at(it)));
    }
    return retval;
}


std::wstring StringToWString(const std::string& s)
{
    std::wstring retWstr(s.begin(), s.end());
    return retWstr;
}



//Вернуть RawValue 
std::string QueryTo_RawValue(std::string Name_var, std::string query) {

    std::string retval;
    size_t VarDev_Pos = query.find(Name_var);

    if (VarDev_Pos != std::wstring::npos) {
        std::string tempVar = query.substr(VarDev_Pos + Name_var.size() + 1, query.size());
        retval = tempVar;

        auto DeviderPos = tempVar.find('&');

        if (DeviderPos != std::wstring::npos) {
            retval = tempVar.substr(0, DeviderPos);
        }
    }
    else {
        return "";
    }
    return retval;
}





int main() {


    setlocale(LC_ALL, "Russian");

    //mainFunc::RunMainFunc();
    std::string body,
        action;
    std::getline(std::cin, body);
    action = getenv("REQUEST_URI");



    if (getenv("REQUEST_METHOD") != "GET" && action == "/cgi-bin/ZDParams.cgi") {

        std::string Name,
            Password;

        char* cPassword[20];


        if (body.find('%') != body.npos)

            std::wcout << HTTP_methoods::Paragrah(L"", L"<font color = \"red\"> <b> Логин и/или пароль содержат недопустимые символы <b> </font>");

        else {
            Name = QueryTo_RawValue("text", body);
            Password = QueryTo_RawValue("pass", body);

            if (Name != "") {
                
                mainFunc::RunMainFunc(body);
                
            }
            else {
                mainFunc::RunMainFunc(body);
            }


        }
    };
    return 0;
}
