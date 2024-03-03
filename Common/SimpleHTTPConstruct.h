#pragma once
#include <string>
#include <vector>

namespace SimpleHTTPConstruct {

	class SimpleHTTPConstruct {
	public:
		static std::wstring Paragrah(std::wstring content, std::wstring attributes);
		static std::wstring Meta(std::wstring attributes = L"");
		static std::wstring Body(std::wstring attributes, std::wstring content);
		static std::wstring Form(std::wstring attributes, std::wstring content);
		static std::wstring Select(std::wstring attributes, std::vector<std::wstring> options);
		static std::wstring AsIs(std::wstring content);
		static std::wstring Img(std::wstring params);
		static std::wstring Head(std::wstring attributes, std::wstring content);
		static std::wstring HTML(std::wstring attributes, std::wstring content);
		static std::wstring StringToWString(const std::string& s);



	};


};