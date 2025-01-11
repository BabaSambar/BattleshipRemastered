#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

namespace Utility {
	enum class LogType{
		ERROR,
		WARNING,
		MESSAGE
	};

	class Logger{
	public:
		static Logger* GetInstance(){
			if(m_Instance = nullptr) m_Instance = new Logger();
			return m_Instance;
		}

		void SetLogType(LogType _LogType){
			m_LogType = _LogType;
		}

		void Log(std::string _Message){
			switch (m_LogType){
				case LogType::ERROR:
					std::cout << "[ERROR]: ";
					break;
				case LogType::WARNING:
					std::cout << "[WARNING]: ";
					break;
				case LogType::MESSAGE:
					std::cout << "[MESSAGE]: ";
					break;
			}
			std::cout << _Message << std::endl;
		}

	private:
		static Logger* m_Instance;
		LogType m_LogType;
		Logger(): m_LogType(LogType::MESSAGE) {}
	};
}