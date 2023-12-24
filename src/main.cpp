#include <iostream>
#include <string>
#include <vector>

class Talent {
protected:
	
	std::string talent_name;
public:
	virtual void getNameTalent() = 0;
};

class Swimming : virtual public Talent {
public:
	Swimming() {
		this->talent_name = "Swimming";
	}

	void getNameTalent() {
		std::cout << talent_name << std::endl;
	}
};

class Dancing : virtual public Talent {

public:
	Dancing() {
		this->talent_name = "Dancing";
	}
	void getNameTalent() {
		std::cout << talent_name << std::endl;
	}
};

class Counting : virtual public Talent {
	
public:
	Counting() {
		this->talent_name = "Counting";
	}
	void getNameTalent() {
		std::cout << talent_name << std::endl;
	}
};


 
class Animal {
protected:
	std::vector<Talent*> animal_talents;
	Talent* tal_arr[3];
	std::string dog_name;
	//std::string cat_name;
public:
	Animal () {
		tal_arr[0] = new Swimming();
		tal_arr[1] = new Dancing();
		tal_arr[2] = new Counting();
	}
	
	virtual void getAnimalName() = 0;
	virtual void getVoice() = 0;
};

class Dog : virtual public Animal{
public:

	Dog(std::string _dog_name) {
		this->dog_name = _dog_name;
	}
	void setDogTalents() {
		std::string dog_talent, answer;
		do {
			std::cout << "Enter the talent for the pet: " << std::endl;
			std::cin >> dog_talent;
			if (dog_talent == "Swimming") {
				animal_talents.push_back(tal_arr[0]);
			}
			else if (dog_talent == "Dancing") {
				animal_talents.push_back(tal_arr[1]);
			}
			else if (dog_talent == "Counting") {
				animal_talents.push_back(tal_arr[2]);
			}
			else {
				std::cout << "Talent input error!" << std::endl;
				continue;
			}
			std::cout << "Does your pet have any other talents? (yes/no)";
			std::cin >> answer;
			if (answer == "yes" && animal_talents.size() == 3) {
				std::cout << "We kindly ask you not to attribute non-existing talents to your pet!" << std::endl;
			}
		} while (answer != "No" && answer != "no" && animal_talents.size() != 3);
	}
	void getAnimalName() {

		std::cout << "My pet's name " << dog_name << std::endl;
	}
	void getDogTalents() {
		std::cout << "My pet can: " << std::endl;
		for (int t = 0; t < animal_talents.size(); t++) {
			std::cout << "\t";
			Animal::animal_talents[t]->getNameTalent();
			std::cout << "\n";
		}
	}
	void getVoice() {
		std::cout << "\tBark!";
	}

};
/*
class Cat : virtual public Animal {
public:
	
	Cat(std::string _cat_name) {
		this->cat_name = _cat_name;
	}
	
	void getAnimalName() {
		std::cout << cat_name << std::endl;
	}
	void getVoice() {
		std::cout << "Meow!" << std::endl;
	}
 };*/

int main() {
	std::string pets_talents;
	Dog d("Sharick");
	
	std::cout << "Which of these abilities does your pet have? (Swimming, Dancing, Counting)" << std::endl;
	d.setDogTalents();
	std::cout << "Introduce us to your pet: \n" << std::endl;
	d.getAnimalName();
	d.getDogTalents();
	std::cout << "And he gives voice!" << std::endl;
	d.getVoice();

	return 0;
}