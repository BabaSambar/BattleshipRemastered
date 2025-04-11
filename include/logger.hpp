#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

namespace BR {
	enum class LogType{
		NONE,
		ERROR,
		WARNING,
		MESSAGE
	};

	class Logger{
	public:	
		Logger(): m_LogType(LogType::NONE) {}

		void setLogType(LogType logType){
			m_logType = logType;
		}

		void Log(std::string _Message){
			switch (m_LogType){
				case LogType::NONE:
					std::cout << "[ERROR]: Log type not set. Use `m_Logger.setLogType()`";
					return;
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
		LogType m_logType = LogType::NONE;
	};

	extern Logger *m_logger;
}