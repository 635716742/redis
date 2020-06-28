#pragma once
#include "cppredis_helper.h"

namespace RedisCommand
{
	/*
	ͨ����redis�������۲죬���������ֵ���ʹ����Ϊ��ô���֣�
	1���ɴ�ӡ���ַ������ͣ����磬Hash�е�Field��Set��Member�����ǲ���ʹ�ò��ɴ�ӡ�Ķ�������Ϊ������
	2�����������ͣ��������κζ����ư�ȫ�����ͣ�����Set�е�Value�����Դ洢�κζ����������������ͣ�����ʹ��ģ������Զ�ת����
	3���̶��������򸡵����ͣ�����ʹ���������ͣ������й̶�����Ĳ���������SET�еĹ���ʱ�䣬���������εȡ�
	4���Լ��������͵������汾������HMGET�е�Field�����������ݶ�������������Ļ�ȡ���ֵ��

	����������Ƴ�4���������ͣ�RedisString��RedisValue��RedisNumber��RedisFloat��
	RedisString�������˿ɴ�ӡ���ַ������ͣ������Ƕ����ơ�
	RedisNumber��RedisFloat�����RedisString���ԣ���������һ���ģ���Ҫת����string���д��ݲ��������RedisNumber��RedisFloat���Լ̳���
	RedisString�������ڲ����Ի���һ��int64��double�ı�����
	RedisBinaryBuf���ǿ��Դ洢�����Ƶģ������ڲ���װ�ķ������ῼ�ǰѶ������л��ɶ����ơ�
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