#include "Log.h"

#include "CCStdC.h"

#include <time.h>
#include <ctime>
#include <stdarg.h>


Log::Log()
	:m_szDefaultPath("Log.txt")
{
	_Init();
}

Log::~Log()
{
	_Destroy();
}

/**
*brief	获得单例
*param	void
*return	返回CLog的单例指针
*/
Log* Log::GetInstance()
{
	static Log* pLog = new Log();
	return pLog;
}

/**
*brief		写日志到文件,并打印到控制台上
*param type	信息,错误,警告
*param path	格式化字符串
*param ...	可变参数,对应参数2格式化字符串
*return		void
*/
void Log::Print(Type type, const char* format, ...)
{
	const static int MAX_SIZE = 512;

	char buf[MAX_SIZE] = {0};

	va_list ap;
    va_start(ap, format);
    vsnprintf(buf, MAX_SIZE, format, ap);
    va_end(ap);
	
	Data data;
	time_t timeT = time(NULL);
	data._time = localtime(&timeT);
	data._type = type;
	data._str = buf;
	m_Logs.push_back(data);

	if (!m_OutputFlag)
		return;

	//输出到控制台
	memset(buf, 0, MAX_SIZE);
	snprintf(buf, MAX_SIZE, "%s: [%04d-%02d-%02d %02d:%02d:%02d] %s\n", 
				(int)m_TypeStr[data._type], 
				data._time->tm_year+1900,
				data._time->tm_mon,
				data._time->tm_mday,
				data._time->tm_hour,
				data._time->tm_min,
				data._time->tm_sec,
				data._str.c_str());
    printf("%s", buf);
}

/**
*brief	写缓存到指定文件
*param	void
*return	void
*/
void Log::Write()
{
	if (!m_WriteFlag)
		return;

	const static int WRITE_MAX_SIZE = 1024;
	FILE *pFile = fopen(m_szDefaultPath, "w");
	if (NULL == pFile)
	{
		return;
	}
		
	std::string outPutBuf;
	char buf[WRITE_MAX_SIZE] = {0};
	std::vector<Data>::iterator pData = m_Logs.begin();
	for (; pData!=m_Logs.end(); ++pData)
	{
		//type, time, str
		snprintf(buf, WRITE_MAX_SIZE, "%s: [%04d-%02d-%02d %02d:%02d:%02d] %s\n", 
				(int)m_TypeStr[pData->_type], 
				pData->_time->tm_year+1900,
				pData->_time->tm_mon,
				pData->_time->tm_mday,
				pData->_time->tm_hour,
				pData->_time->tm_min,
				pData->_time->tm_sec,
				pData->_str.c_str());
		outPutBuf += buf;
	}

	fwrite(outPutBuf.c_str(), sizeof(char), outPutBuf.length(), pFile);
	fclose(pFile);
}

/**
*brief	在Debug模式下是否打开日志输出
*param	true:打开;false:关闭;默认:true;
*return	void
*/
void Log::SetOutputFlag(bool flag)
{
	if (m_OutputFlag == flag)
		return;
	m_OutputFlag = flag;
}

void Log::SetWriteFlag(bool flag)
{
	if (m_WriteFlag == flag)
		return;
	m_WriteFlag = flag;
}

void Log::_Init() //初始化成员变量
{
	m_Logs.clear();

	strcpy(m_TypeStr[eInfo], "info");
	strcpy(m_TypeStr[eError], "error");
	strcpy(m_TypeStr[eWaring], "waring");
}

void Log::_Destroy() //重置成员变量
{
	m_Logs.clear();

	m_OutputFlag = true;
	m_WriteFlag = true;

	memset(m_TypeStr[eInfo], 0, sizeof(m_TypeStr[eInfo]));
	memset(m_TypeStr[eError], 0, sizeof(m_TypeStr[eError]));
	memset(m_TypeStr[eWaring], 0, sizeof(m_TypeStr[eWaring]));
}