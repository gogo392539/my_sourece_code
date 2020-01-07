#pragma once

class fileFunc
{
private:
	
public:
	int makeDir(const char* pszDirPath);
	int makeDir2(const char* pszDirPath);
	int viewFileList(const char* pszFileName);
	int viewFileList2(const char* pszFileName);

private:
	int createDir(const char* pszDirPath);

};

