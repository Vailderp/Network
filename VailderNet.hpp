#pragma once
#include "iostream"
#include "SFML/Network.hpp"

// \brief Vailder's Network
namespace vn
{
	enum enums
	{

	};

	class SOCKET
	{
	private:
		sf::TcpSocket socket_;
	public:
		SOCKET() :
			socket_{}
		{

		}

		void connect(const std::string& ip_address, const unsigned __int16 port)
		{
			if (socket_.connect(ip_address, port) == sf::Socket::Done)
			{
				std::cout
					<< "> DONE > TCP SOCKET > CONNECT." << std::endl
					<< "-> REMOTE ADDRESS: " << socket_.getRemoteAddress() << std::endl
					<< "-> REMOTE PORT: " << socket_.getRemotePort() << std::endl
					<< "-> LOCAL PORT: " << socket_.getLocalPort() << std::endl
					<< ">" << std::endl;
			}
			else
			{
				std::cout
					<< "> ERROR > TCP SOCKET > CONNECT." << std::endl
					<< "-> REMOTE ADDRESS: " << socket_.getRemoteAddress() << std::endl
					<< "-> REMOTE PORT: " << socket_.getRemotePort() << std::endl
					<< "-> LOCAL PORT: " << socket_.getLocalPort() << std::endl
					<< ">" << std::endl;
			}
		}

		void send(const std::string& data_string)
		{
			sf::Packet packet;
			packet << data_string;
			if (socket_.send(packet) == sf::Socket::Done)
			{
				std::cout
					<< "> DONE > TCP SOCKET > SEND." << std::endl
					<< "-> REMOTE ADDRESS: " << socket_.getRemoteAddress() << std::endl
					<< "-> REMOTE PORT: " << socket_.getRemotePort() << std::endl
					<< "-> LOCAL PORT: " << socket_.getLocalPort() << std::endl
					<< ">" << std::endl;
			}
			else
			{
				std::cout
					<< "> ERROR > TCP SOCKET > SEND." << std::endl
					<< "-> REMOTE ADDRESS: " << socket_.getRemoteAddress() << std::endl
					<< "-> REMOTE PORT: " << socket_.getRemotePort() << std::endl
					<< "-> LOCAL PORT: " << socket_.getLocalPort() << std::endl
					<< ">" << std::endl;
			}
		}

		std::string receive()
		{
			sf::Packet packet;
			std::string data_string;
			if (socket_.receive(packet) == sf::Socket::Done)
			{
				std::cout
					<< "> DONE > TCP SOCKET > RECEIVE." << std::endl
					<< "-> REMOTE ADDRESS: " << socket_.getRemoteAddress() << std::endl
					<< "-> REMOTE PORT: " << socket_.getRemotePort() << std::endl
					<< "-> LOCAL PORT: " << socket_.getLocalPort() << std::endl
					<< ">" << std::endl;
				packet >> data_string;
				return data_string;
			}
			else
			{
				std::cout
					<< "> DONE > TCP SOCKET > RECEIVE." << std::endl
					<< "-> REMOTE ADDRESS: " << socket_.getRemoteAddress() << std::endl
					<< "-> REMOTE PORT: " << socket_.getRemotePort() << std::endl
					<< "-> LOCAL PORT: " << socket_.getLocalPort() << std::endl
					<< ">" << std::endl;
				return "null";
			}
			return NULL;
		}

		void operator << (const std::string& data_string)
		{
			send(data_string);
		}

		std::string operator >> (const std::string&)
		{
			return receive();
		}
	};

	class LISTENER
	{
	private:
		sf::TcpSocket socket_;
		sf::TcpListener listener_;
		std::vector<std::string> vec_on;

	public:
		LISTENER() :
			listener_{}
		{

		}

		void listen(const unsigned __int16 port)
		{
			if (listener_.listen(port) == sf::Socket::Done)
			{
				std::cout
					<< "> DONE > TCP LISTENER > LISTEN." << std::endl
					<< "-> LOCAL PORT: " << listener_.getLocalPort() << std::endl
					<< ">" << std::endl;
			}
			else
			{
				std::cout
					<< "> ERROR > TCP LISTENER > LISTEN." << std::endl
					<< "-> LOCAL PORT: " << listener_.getLocalPort() << std::endl
					<< ">" << std::endl;
			}
		}

		void operator << (const unsigned __int16 port)
		{
			listen(port);
		}

		std::string accept()
		{
			sf::Packet packet;
			std::string data_string;
			listener_.accept(socket_);
			if (socket_.receive(packet) == sf::Socket::Done)
			{
				std::cout
					<< "> DONE > TCP LISTENER > ACCEPT." << std::endl
					<< "-> REMOTE ADDRESS: " << socket_.getRemoteAddress() << std::endl
					<< "-> REMOTE PORT: " << socket_.getRemotePort() << std::endl
					<< "-> LOCAL PORT: " << socket_.getLocalPort() << std::endl
					<< ">" << std::endl;
				packet >> data_string;
				return data_string;
			}
			else
			{
				std::cout
					<< "> ERROR > TCP LISTENER > ACCEPT." << std::endl
					<< "-> REMOTE ADDRESS: " << socket_.getRemoteAddress() << std::endl
					<< "-> REMOTE PORT: " << socket_.getRemotePort() << std::endl
					<< "-> LOCAL PORT: " << socket_.getLocalPort() << std::endl
					<< ">" << std::endl;
				return "null";
			}
			return "null";
		}

		std::string operator >> (const std::string&)
		{
			return accept();
		}
	};
}
