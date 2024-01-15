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

	//argcの数だけ繰り返す
	for (int i = 0; i < argc; i++) {
		//文字列argvのi番を表示
		printf(argv[i]);
		printf("\n");
	}

	assert(argc >= NumArgument_);

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
