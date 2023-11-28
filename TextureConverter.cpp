#include "TextureConverter.h"

using namespace DirectX;

void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath) {
	//①テクスチャファイルを読み込む
	LoadWICTextureFromFile(filePath);

	//②DDS形式に変換して書きだす
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath) {
	HRESULT result;

	//①ファイルパスをワイド文字列に変換
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filePath);

	//②テクスチャを読み込む
	result = LoadFromWICFile(wfilePath.c_str(), WIC_FLAGS_NONE, &metadata_, scratchImage_
	);

	assert(SUCCEEDED(result));
}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString) {
	//ワイド文字列に変換した際の文字数
	int bufferSize = 
		MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//ワイド文字列
	std::wstring wString;
	wString.resize(bufferSize);

	//変換する
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], bufferSize);

	return wString;
}
