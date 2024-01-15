#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <cassert>

#include "TextureConverter.h"

//コマンドライン
enum Argument {
	kApplicationPath_,	//アプリケーションのパス
	kFilePath,			//渡されたファイルのパス

	NumArgument_
};

int main(int argc, char* argv[]) {
	//コマンドライン引数指定なし
	if (argc < NumArgument_) {
		//使い方を表示
		TextureConverter::OutputUsage();
		return 0;
	}

	//COM ライブラリの初期化
	HRESULT hr =
		CoInitializeEx(
			nullptr,
			COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//テクスチャコンバータ
	TextureConverter converter;

	//テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COM ライブラリの終了
	CoUninitialize();

	return 0;
}
