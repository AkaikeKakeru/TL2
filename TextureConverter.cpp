#include "TextureConverter.h"
#include <stringapiset.h>


void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath) {
	//�@�e�N�X�`���t�@�C����ǂݍ���
	//LoadWICTextureFromFile

	//�ADDS�`���ɕϊ����ď�������
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath) {
	//�@�t�@�C���p�X�����C�h������ɕϊ�
	//�A�e�N�X�`����ǂݍ���
}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString) {
	//���C�h������ɕϊ������ۂ̕�����
	int bufferSize = 
		MultiByteToWideChar(CP_UTF8, 0, mString.c_str(), -1, nullptr, 0);

	//���C�h������
	std::wstring wString;
	wString.resize(bufferSize);

	//�ϊ�����
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], bufferSize);

	return std::wstring();
}
