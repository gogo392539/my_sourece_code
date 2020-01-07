#include "stdafx.h"
#include "fileFunc.h"

int fileFunc::createDir(const char* pszDirName)
{
	int nReturn = 0;
	int nResult = 0;
	char szErrMsg[400] = { 0, };
	struct _stat s_stat = { 0, };

	nReturn = _stat(pszDirName, &s_stat);
	if (nReturn != 0) {
		if (_mkdir(pszDirName) != 0 && errno != EEXIST) {
			nResult = -1;
		}
	}
	else if (!(s_stat.st_mode & _S_IFDIR)) {
		strerror_s(szErrMsg, errno);
		cout << szErrMsg << ": 4" << pszDirName << endl;
		errno = ENOTDIR;
		nResult = -1;
	}

	return nResult;
}

int fileFunc::makeDir(const char* pszDirPath)
{
	int		nResult = 0;
	char	szCpyDirPath[FILENAME_MAX] = { 0, };
	char	szCreateDirPath[FILENAME_MAX] = { 0, };
	char	szDelimiter[10] = "\\";
	char* pszTmpData = NULL;
	char* pszToken = NULL;
	char* pszContext = NULL;

	strcpy_s(szCpyDirPath, FILENAME_MAX, pszDirPath);
	pszTmpData = szCpyDirPath;

	nResult = 0;
	pszToken = strtok_s(pszTmpData, szDelimiter, &pszContext);
	strcpy_s(szCreateDirPath, FILENAME_MAX, pszToken);
	while ((nResult == 0) && (pszToken != NULL)) {
		nResult = createDir(szCreateDirPath);

		pszToken = strtok_s(NULL, szDelimiter, &pszContext);
		if (pszToken == NULL) {
			break;
		}

		strcat_s(szCreateDirPath, FILENAME_MAX, szDelimiter);
		strcat_s(szCreateDirPath, FILENAME_MAX, pszToken);
	}

	return nResult;
}

int fileFunc::makeDir2(const char* pszDirPath)
{
	int		nResult = 0;
	char	szCopyDirPath[FILENAME_MAX] = { 0, };
	char	szCreateDirPath[FILENAME_MAX] = { 0, };
	char	szDelimiter[10] = "\\";
	char	*pszTmpData = NULL;
	char	*pszToken = NULL;
	char	*pszContext = NULL;
	struct stat s_stat = { 0, };

	strcpy_s(szCopyDirPath, FILENAME_MAX, pszDirPath);
	pszTmpData = szCopyDirPath;
	nResult = 0;

	pszToken = strtok_s(pszTmpData, szDelimiter, &pszContext);
	strcpy_s(szCreateDirPath, FILENAME_MAX, pszToken);
	while ((nResult == 0) && (pszToken != NULL)) {
		cout << szCreateDirPath << endl;
		//nResult = _access_s(szCreateDirPath, 00);
		//if (nResult != 0) {
		//	nResult = _mkdir(szCreateDirPath);
		//}
		nResult = stat(szCreateDirPath, &s_stat);
		if ((nResult != 0) || !(s_stat.st_mode & S_IFDIR)) {
			nResult = _mkdir(szCreateDirPath);
		}

		pszToken = strtok_s(NULL, szDelimiter, &pszContext);
		if (pszToken == NULL) {
			break;
		}

		strcat_s(szCreateDirPath, FILENAME_MAX, szDelimiter);
		strcat_s(szCreateDirPath, FILENAME_MAX, pszToken);
	}


	nResult = _access(pszDirPath, 00);


	return 0;
}

int fileFunc::viewFileList(const char* pszFileName)
{
	int nResult = 0;
	intptr_t hHandle = 0L;
	_finddata_t	findData;
	char szDelimiter[10] = "\\*.*";
	char szCopyFileName[FILENAME_MAX] = { 0, };

	strcpy_s(szCopyFileName, FILENAME_MAX, pszFileName);
	strcat_s(szCopyFileName, FILENAME_MAX, szDelimiter);


	hHandle = _findfirst(szCopyFileName, &findData);
	if (hHandle == -1) {
		cout << "no files" << endl;
		return -1;
	}

	while (nResult != -1) {
		if ((strcmp(findData.name, ".") == 0) || (strcmp(findData.name, "..")) == 0) {
			nResult = _findnext(hHandle, &findData);
			continue;
		}

		cout << "File : " << findData.name << endl;
		nResult = _findnext(hHandle, &findData);
	}
	_findclose(hHandle);

	return 0;
}

int fileFunc::viewFileList2(const char* pszFileName)
{
	bool bResult = false;
	HANDLE Hhandle = 0L;
	WIN32_FIND_DATA	findData;
	char szDelimiter[10] = "\\*.*";
	char szCopyFileName[FILENAME_MAX] = { 0, };

	strcpy_s(szCopyFileName, FILENAME_MAX, pszFileName);
	strcat_s(szCopyFileName, FILENAME_MAX, szDelimiter);


	Hhandle = FindFirstFile(szCopyFileName, &findData);
	if (Hhandle == INVALID_HANDLE_VALUE) {
		cout << "no files" << endl;
		return -1;
	}

	bResult = true;
	while (bResult != false) {
		if ((strcmp(findData.cFileName, ".") == 0) || (strcmp(findData.cFileName, "..")) == 0) {
			bResult = FindNextFile(Hhandle, &findData);
			continue;
		}

		cout << "File : " << findData.cFileName << endl;
		bResult = FindNextFile(Hhandle, &findData);
	}
	FindClose(Hhandle);

	return 0;
}