#pragma once
#include "cppredis_helper.h"

namespace RedisCommand
{
	/*
	通过对redis命令来观察，命令参数的值类型大体分为这么几种：
	1、可打印的字符串类型，比如，Hash中的Field，Set中Member。他们不能使用不可打印的二进制作为参数。
	2、二进制类型，可以是任何二进制安全的类型，比如Set中的Value，可以存储任何东西。对于这种类型，可以使用模板进行自动转换。
	3、固定的整数或浮点类型，不能使用其它类型，都是有固定意义的参数，比如SET中的过期时间，排名中名次等。
	4、以及上述类型的批量版本，比如HMGET中的Field可以连续传递多个，用于批量的获取多个值。

	我们首先设计出4个基本类型：RedisString、RedisValue、RedisNumber、RedisFloat。
	RedisString：代表了可打印的字符串类型，不能是二进制。
	RedisNumber、RedisFloat：相比RedisString而言，本质上是一样的，都要转换成string进行传递参数，因此RedisNumber和RedisFloat可以继承自
	RedisString，并且内部可以缓存一个int64或double的变量。
	RedisBinaryBuf：是可以存储二进制的，所以内部封装的方法，会考虑把对象序列化成二进制。
	*/
	class RedisString
	{
	public:
		RedisString() = delete;

		RedisString(const std::string& str) : m_str(str)
		{
		};

		RedisString(const char* str) : m_str(str)
		{

		};

		void SetString(const std::string& str)
		{
			m_str = str;
		};

		void SetString(const char* str)
		{
			m_str = str;
		};

		template <typename T>
		void SetString(const T&& t)
		{
			SetString(std::to_string(t));
		};

		const std::string& GetString()
		{
			return m_str;
		};

		RedisString& operator=(const char* str)
		{
			m_str = str;
			return *this;
		}

		RedisString& operator=(const std::string& str)
		{
			SetString(str);
			return *this;
		}

	protected:
		std::string m_str;
	};

	class RedisNumber
	{

	};

	class RedisFloat
	{

	};

	class RedisBinaryBuf
	{

	};
};