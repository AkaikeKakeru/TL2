#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "TextureConverter.h"

//コマンドライン
enum Argument {
	kApplicationPath_,	//アプリケーションのパス
	kFilePath,			//渡されたファイルのパス

	NumArgument_
};

int main(int argc, char* argv[]) {
/*
	//argcの数だけ繰り返す
	for (int i = 0; i < argc; i++) {
		//文字列argvのi番を表示
		printf(argv[i]);
		printf("\n");
	}
*/
	
	assert(argc >= NumArgument_);
	//テクスチャコンバータ
	TextureConverter converter;

	//テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	system("pause");
	return 0;
}