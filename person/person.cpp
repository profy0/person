#include <iostream>
#include <string>
#include "pers.h"

using namespace std;

int main() {
	try {
		Person Adam("Adam", Gender::male);
		Person Eva("Eva", Gender::female);
		Person Masha = *Eva.GiveBirth("Masha", Gender::female, &Adam);
		Person Maksim = *Masha.GiveBirth("Maksim", Gender::male);
		Person Anna = *Eva.GiveBirth("Anna", Gender::female, &Adam);
		Person Nikita = *Anna.GiveBirth("Nikita", Gender::male);
		Nikita.print();
	}
	catch (exception t) {
		cerr << t.what() << "\n";
	}
}