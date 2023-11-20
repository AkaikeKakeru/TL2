#include "TextureConverter.h"

#include <Windows.h>

void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath) {
	//①テクスチャファイルを読み込む
	LoadWICTextureFromFile(filePath);

	//②DDS形式に変換して書きだす
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath) {
	//①ファイルパスをワイド文字列に変換
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filePath);

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
	MultiByteToWideChar(CP_UTF8, 0, mString.c_str(), -1, &wString[0], bufferSize);

	return wString;
}
