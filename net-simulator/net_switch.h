#pragma once
#include<vector>
#include<string>
typedef unsigned long long __uint64;

class net_switch
{
private:
	class component {
		__uint64 mac;
		int type;
		int port;

	public:
		component(__uint64 mac, int type, int port) {
			this->mac = mac;
			this->type = type;
			this->port = port;
		}
	};
	std::vector<component> comps;
public:
	// Variables
	std::string name;
	__uint64 mac;

	net_switch(std::string name = "Router") {
		this->name = name;
	}

	void change_name(std::string name) {
		this->name = name;
	}

	int add_comp(__uint64 mac, int type, int port) {
		comps.push_back(component(mac, type, port));
		return 0;
	}

	std::string get_table() {
		return "TEST_RETURN";
	}
};

