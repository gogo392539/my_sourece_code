#pragma once

class fileFunc
{
private:
	
public:
	int makeDir(const char* pszDirPath);
	int makeDir2(const char* pszDirPath);
	int viewFileList(const char* pszFileName);
	int viewFileList2(const char* pszFileName);
	int fn_StrDecimalToNumber(const char* pszNumbers, int nConvertBase);	// ���� ���ڿ� cConvertBase�� �´� ������ ��ȯ

private:
	int createDir(const char* pszDirPath);

};

