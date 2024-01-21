#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <cassert>

#include "TextureConverter.h"

//コマンドライン
enum Argument {
	kApplicationPath_,	//アプリケーションのパス
	kFilePath_,			//渡されたファイルのパス

	NumArgument_
};

int main(
	int argc,
	char* argv[]) {
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

	//オプションの数
	int numOptions = argc - NumArgument_;

	//オプション配列 (ダブルポインタ)
	char** options = argv + NumArgument_;

	//テクスチャ変換
	converter.ConvertTextureWICToDDS(
		argv[kFilePath_],
		numOptions,
		options);

	//COM ライブラリの終了
	CoUninitialize();

	return 0;
}
