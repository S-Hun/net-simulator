#include<iostream>
#include<string>

using namespace std;

int main() {
	string command;
	int status = 1;
	
	while (status > 0) {
		cin >> command;
		if (!command.compare("exit")) status -= 1;
	}
}