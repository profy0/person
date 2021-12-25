enum class Gender {
	male, female
};

class Person {
private:
	int ID;
	static int NextID;
	std::string name;
	Gender gender;
	Person* mom;
	Person* dad;
public:
	Person() : ID(++NextID) {}
	Person(std::string name, Gender gender, Person* mom = nullptr, Person* dad = nullptr) : ID(++NextID) {
		this->name = name;
		this->gender = gender;
		this->mom = mom;
		this->dad = dad;
		if (ID >= 3 && mom == nullptr) {
			throw std::exception("It is impossible to create a human being in this way");
		}
		if (this->dad != nullptr && this->dad->gender == Gender::female) throw std::exception("Wrong gender for dad");
		if (this->mom != nullptr && this->mom->gender == Gender::male) throw std::exception("Wrong gender for mom");
	}
	Person* GiveBirth(const std::string babyName, Gender babyGender, Person* babyDad = nullptr) {
		if (this->gender == Gender::male) throw std::exception("A man can't give birth");
		if (babyName == "") throw std::exception("Baby must have a name");
		Person* baby = new Person(babyName, babyGender, this, babyDad);
		return baby;
	}
	std::string getName() {
		return name;
	}
	const std::string getGender() {
		return (gender == Gender::male ? "male" : "female");
	}
	std::string getMom() {
		return mom->getName();
	}
	std::string getDad() {
		return dad->getName();
	}
	int getID() {
		return ID;
	}
	void print() {
		std::cout << "ID - " << getID() << "\n";
		std::cout << "Name - " << getName() << "\n";
		std::cout << "Gender - " << getGender() << "\n";
		if (mom != nullptr) std::cout << "Mom - " << getMom() << "\n";
		else std::cout << "This person does not have a mom\n";
		if (dad != nullptr) std::cout << "Dad - " << getDad() << "\n";
		else std::cout << "This person does not have a dad\n";
	}
	Person operator = (Person p) {
		return Person(name, gender, mom, dad);
	}
};

int Person::NextID = 0;
