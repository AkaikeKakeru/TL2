#include "TextureConverter.h"
#include <stringapiset.h>


void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath) {
	//①テクスチャファイルを読み込む
	//LoadWICTextureFromFile

	//②DDS形式に変換して書き込む
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath) {
	//①ファイルパスをワイド文字列に変換
	//②テクスチャを読み込む
}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString) {
	//ワイド文字列に変換した際の文字数
	int bufferSize = 
		MultiByteToWideChar(CP_UTF8, 0, mString.c_str(), -1, nullptr, 0);

	//ワイド文字列
	std::wstring wString;
	wString.resize(bufferSize);

	//変換する
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], bufferSize);

	return std::wstring();
}
