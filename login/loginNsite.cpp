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
                )+
                Body(L"align = \"center\"", L"<br> <br> <br>")
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



    void siteLogicRun(std::string input) {

        std::wcout << HTTP_methoods::AsIs(L"<h1 align = \"center\"> RZD TICKETS </h1>");

        std::wcout << HTTP_methoods::Paragrah(L"align = \"center\"", 
            HTTP_methoods::Form(L"METHOD = \"POST\" action = RZD.cgi", 
                HTTP_methoods::Paragrah(L"", L"Откуда<br>") +
                HTTP_methoods::Select(L"name=\"Departure\"", { L"Москва", L"Тверь", L"Калуга", L"Рязань", L"Санкт-Петербург", L"Воронеж", L"Владимир", L"Анапа", L"Геленджик", L"Казань", L"Владивосток" })+L"<br>" +
                HTTP_methoods::Paragrah(L"", L"Куда<br>") +
                HTTP_methoods::Select(L"name=\"Arrive\"", { L"Москва", L"Тверь", L"Калуга", L"Рязань", L"Санкт-Петербург", L"Воронеж", L"Владимир", L"Анапа", L"Геленджик", L"Казань", L"Владивосток" }) + L"<br><br>" +

                L"<input type = \"submit\"; style=\"background-color: green\"; value = \"Выберите время поездки\">"));

    }

    bool AuthService(std::pair<std::string, std::string> AuthDATa) {

        bool AllowLogging = false;

        std::string credentials;
        std::map<std::string, std::string> credentialVector;

        const std::string accounts_path = "account.properties";
        std::ifstream ifstr(accounts_path);

        if (!ifstr) {
            std::wcout << L"Конфигурационный файл не существует<br>";

            //Создаем файл с AuthDATa внутри
            std::ofstream ofstr(accounts_path);
            ofstr << AuthDATa.first << " " << AuthDATa.second << "\n";
            ofstr.close();
            AllowLogging = true;
        }
        else {

            if (ifstr.is_open())
            {
                while (std::getline(ifstr, credentials))
                {
                    if (credentials != "") {
                        size_t spaceSymb = credentials.find(" ");
                        credentialVector.emplace(credentials.substr(0, spaceSymb), credentials.substr(spaceSymb + 1, credentials.size() - spaceSymb));
                        credentials.clear();
                    }
                }
            }


            ifstr.close();
            if (!credentials.size()) {
                if (credentialVector.find(AuthDATa.first) != credentialVector.end()) {


                    if (credentialVector.at(AuthDATa.first) == AuthDATa.second) {
                        AllowLogging = true;
                        siteLogicRun(AuthDATa.first);
                    }
                    else {
                        std::wcout << HTTP_methoods::Paragrah(L"align = \"center\"", L"Некорректный пароль" +
                                HTTP_methoods::Form(L"METHOD = \"POST\" action = Autorization.cgi",
                                    HTTP_methoods::AsIs(L"<input type = \"submit\"; style=\"background-color: red\"; value = \"ВЕРНУТЬСЯ НАЗАД\">"))
                        );

                    }
                }
                else {
                    std::wcout << HTTP_methoods::Paragrah(L"", L"НЕ НАЙДЕН ПОЛЬЗОВАТЕЛЬ С ТАКИМИ ДАННЫМИ\n");
                    std::wcout <<
                        HTTP_methoods::Form(L"METHOD = \"POST\" action = UserRegistration.cgi",

                            HTTP_methoods::Paragrah(L"align = \"center\"",
                                HTTP_methoods::AsIs(L"<input type = \"submit\"; style=\"background-color: Yellow\"; value = \"Зарегистрировать нового пользователя\">")
                            )
                        );
                    }
            }
        }
        return AllowLogging;     
    }


    int main() {
        setlocale(LC_ALL, "Russian");

        mainFunc::RunMainFunc();
        std::string body,
                    action;
        std::getline(std::cin, body);
        action = getenv("REQUEST_URI");

        if (getenv("REQUEST_METHOD") != "GET" && action == "/cgi-bin/RZD.cgi") {

            std::string Name,
                        Password;

            char* cPassword[20];


            //if (body.find('%') != body.npos) {
               // std::wcout << HTTP_methoods::Paragrah(L"align = \"center\"", L"Логин и/или пароль содержат недопустимые символы" +
                 //   HTTP_methoods::Form(L"METHOD = \"POST\" action = Autorization.cgi",
                     //   HTTP_methoods::AsIs(L"<input type = \"submit\"; style=\"background-color: red\"; value = \"ВЕРНУТЬСЯ НАЗАД\">"))
              //  );
           // }else {
              Name = QueryTo_RawValue("text", body);
              Password = QueryTo_RawValue("pass", body);


                for (auto it = 0; it < Password.size(); it++) 
                    *(cPassword + it) = &(Password.at(it));

                SHA256Crypt CrypthPass(*cPassword);

                AuthService(std::make_pair(Name, CrypthPass.Crypted));
            
        };
        return 0;
    }
