#ifndef __FUNS_LOG_H__
#define __FUNS_LOG_H__

#include <vector>
#include <string>
#include <iosfwd>

class Log
{
public:
	enum Type
	{
		eInfo, 
		eError,
		eWaring,
		eNum,
	};

	struct Data
	{
		tm *_time; //该日志输出到控制台的时间
		Type _type; //eInfo, eError,eWaring,
		std::string _str; //字符串内容

		Data()
			:_time(NULL), _type(eInfo), _str()
		{}

		~Data()
		{
			_time = NULL;
			_type = eInfo;
			_str.clear();
		}
	};

private:
	Log();
public:
	virtual ~Log();

public:
	/**
	  *brief	获得单例
	  *param	void
	  *return	返回CLog的单例指针
	*/
	static Log* GetInstance();

	/**
	  *brief		打印到控制台上,并将字符串存入容器
	  *param type	信息,错误,警告
	  *param format	模式化字符串
	  *param ...	可变参数,对应参数3格式化字符串
	  *return		void
	*/
	void Print(Type type, const char* format, ...);

	/**
	  *brief	写缓存到指定文件
	  *param	void
	  *return	void
	*/
	void Write();

	/**
	  *brief	是否打开日志输出到控制台
	  *param	true:打开;false:关闭;默认:true;
	  *return	void
	*/
	void SetOutputFlag(bool flag);

	/**
	  *brief	是否打开日志输出到磁盘
	  *param	true:打开;false:关闭;默认:false;
	  *return	void
	*/
	void SetWriteFlag(bool flag);

private:
	/**
	  *brief	初始化该单例类的成员变量
	  *param	void
	  *return	void
	*/
	void _Init();

	/**
	  *brief	重置该单例类成员变量，析构函数的时候调用
	  *param	void
	  *return	void
	*/
	void _Destroy();

	std::vector<Data> m_Logs; //日志集
	const char *m_szDefaultPath; //日志系统输出的默认路径
	char m_TypeStr[eNum][32]; //信息种类字符串
	bool m_OutputFlag; //日志输出到控制台开关 
	bool m_WriteFlag; //日志输出到磁盘开关
};

#endif