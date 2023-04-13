#include <iostream>
#include <fstream>

class Address
{
protected:
	std::string City = "";
	std::string Street = "";
	int House = 1;
	int Flat = 1;
public:
	Address() {}
	Address(std::string City, std::string Street, int House, int Flat) {
		this->City = City;
		this->Street = Street;
		this->House = House;
		this->Flat = Flat;
	}
	void read(std::ifstream& File) {
		File >> City >> Street >> House >> Flat;
	}
	void write(std::ofstream& File1) {
		File1 << City << ", " << Street << ", " << House << ", " << Flat << std::endl;
	}
};

int main()
{
	std::ifstream File("in.txt");
	int N;
	File >> N;
	Address* p = new Address[N];
	int i = 0;
	while (File.good() && i < N) {
		p[i].read(File);
		i++;
	}
	File.close();

	std::ofstream File1("out.txt");
	File1 << N << std::endl;
	for (int i = N - 1; i >= 0; i--) {
		p[i].write(File1);
	}
	File1.close();

	delete[] p;
	return 0;
}