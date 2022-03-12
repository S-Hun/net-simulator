#pragma once
#include<string>
typedef unsigned int __uint32;
typedef unsigned long long __uint64;

class net_terminal
{
	// Variables
	std::string name;
	__uint64 mac;
	__uint32 ip;
	__uint32 default_gateway;

public:
	net_terminal(std::string name = "Terminal") {
		this->name = name;
	}

	void change_name(std::string name) {
		this->name = name;
	}

	int update_net_info(__uint32 ip, __uint32 default_gateway) {
		this->ip = ip;
		this->default_gateway = default_gateway;
		return 0;
	}
};

