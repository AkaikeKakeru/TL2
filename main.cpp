#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "TextureConverter.h"

//�R�}���h���C��
enum Argument {
	kApplicationPath_,	//�A�v���P�[�V�����̃p�X
	kFilePath,			//�n���ꂽ�t�@�C���̃p�X

	NumArgument_
};

int main(int argc, char* argv[]) {
/*
	//argc�̐������J��Ԃ�
	for (int i = 0; i < argc; i++) {
		//������argv��i�Ԃ�\��
		printf(argv[i]);
		printf("\n");
	}
*/
	
	assert(argc >= NumArgument_);
	//�e�N�X�`���R���o�[�^
	TextureConverter converter;

	//�e�N�X�`���ϊ�
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	system("pause");
	return 0;
}