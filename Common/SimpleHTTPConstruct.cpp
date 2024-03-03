#pragma once
#include "SimpleHTTPConstruct.h"

std::wstring SimpleHTTPConstruct::SimpleHTTPConstruct::Paragrah(std::wstring attributes, std::wstring content)
{
    std::wstring retString;
    retString = L"\n<p" + (attributes != L"" ? L" " + attributes + L">" : L">") + L"\n" + content + L"\n</p>";
    return retString;
}

std::wstring SimpleHTTPConstruct::SimpleHTTPConstruct::StringToWString(const std::string& s)
{
    std::wstring retWstr(s.begin(), s.end());
    return retWstr;
}

std::wstring SimpleHTTPConstruct::SimpleHTTPConstruct::Meta(std::wstring attributes)
{
    return L"<meta" + (attributes == L"" ? L">" : L" " + attributes + L" >") + L"\n";
}

std::wstring SimpleHTTPConstruct::SimpleHTTPConstruct::Body(std::wstring attributes, std::wstring content)
{
    return L"<body" + (attributes == L"" ? L">" : L" " + attributes + L" >") + content + L"\n</body>";
}

std::wstring SimpleHTTPConstruct::SimpleHTTPConstruct::Head(std::wstring attributes, std::wstring content)
{
    return L"<head" + (attributes == L"" ? L">" : attributes + L" >") + L"\n" + content + L"\n</head>\n";
}

std::wstring SimpleHTTPConstruct::SimpleHTTPConstruct::HTML(std::wstring attributes, std::wstring content)
{
    return L"\n<html" + (attributes == L"" ? L">" : attributes + L" >") + L"\n" + content + L"\n</html>";
}

std::wstring SimpleHTTPConstruct::SimpleHTTPConstruct::Form(std::wstring  attributes, std::wstring content)
{
    return L"\n<form" + (attributes == L"" ? L">" : L" "+ attributes + L" >") + content + L"</form>";
}

std::wstring SimpleHTTPConstruct::SimpleHTTPConstruct::Select(std::wstring attributes, std::vector<std::wstring> options)
{
    std::wstring options_wstr;
    
    for (auto& it : options) {
        options_wstr += L"<option value =\"" + it + L"\"> " + it + L" </option>\n";
    }


    return L"\n<select" + (attributes == L"" ? L">" : L" " + attributes + L" >") + options_wstr + L"</select>";
}



std::wstring SimpleHTTPConstruct::SimpleHTTPConstruct::AsIs(std::wstring content)
{
    return content;
}

std::wstring SimpleHTTPConstruct::SimpleHTTPConstruct::Img(std::wstring params)
{
    return L"<img " + params + L" >";
}

