#pragma once
#include<string>
#include<vector>
#include<cstring>
typedef unsigned int __uint32;
typedef unsigned long long __uint64;

class net_router {
private:
	// Inner class
	class router_interface {
		__uint32 ip;
		__uint32 default_gateway;
		__int8 number;

	public:
		router_interface(__uint32 ip, __uint32 default_gateway, __int8 number) {
			this->ip = ip;
			this->default_gateway = default_gateway;
			this->number = number;
		}

		__uint32 getIp() { return this->ip; }
		__uint32 getDg() { return this->default_gateway; }
		__int8 getNum() { return number;  }
	};

	// Variables
	std::string name;
	__uint64 mac;
	std::vector<router_interface> ifs;

	// Private methods
	__int8 interfaceTypeChange(std::string number) {
		const char* str = number.c_str();
		if (strlen(str) != 3) return -1;
		else return (str[0] - '0') * 10 + str[2] - '1';
	}

public:
	net_router(std::string name = "Router") {
		this->name = name;
	}

	void change_name(std::string name) {
		this->name = name;
	}

	int add_interface(__uint32 ip, __uint32 default_gateway, __int8 number) {
		ifs.push_back(router_interface(ip, default_gateway, number));
		return 0;
	}

	int shutdown_interface(__int8 number) {
		int count = 0;
		auto iif = ifs.begin();
		while (iif != ifs.end()) {
			if (iif->getNum() == number) {
				ifs.erase(iif);
				count++;
			}
			++iif;
		}
		return count;
	}

	std::string show_table() {
		return "TABLE_TEST";
	}
};

