/*テクスチャコンバータ*/
#pragma once
#include <string>

//テクスチャコンバータ
class TextureConverter {
public:
	/// <summary>
	/// テクスチャをWICからDDSに変換
	/// </summary>
	/// <param name="filePath">ファイルパス</param>
	void ConvertTextureWICToDDS(const std::string& filePath);
};