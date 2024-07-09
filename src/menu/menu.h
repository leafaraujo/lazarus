#ifndef MENU_H
#define MENU_H

#include <vector>
#include "../journey/journey.h"

using namespace std;

void displayMenu();

int searchAstronaut(string cpf, vector<Astronaut> &astronaut);
void cadastreAstro(string CPF, vector<Astronaut> &astronauts);
void cadastreJourney(int id, vector<Journey> &journeys);
void addAstro(vector<Journey> &journeys, vector<Astronaut> &astronauts);
void removeAstro(vector<Journey> journeys);
void launchJourney(int id, vector<Journey> &journeys);
void finishJourney(int status, vector<Journey> &journeys, vector<Astronaut> &astronauts);
void showJourney(vector<Journey> &journeys);
void detailsOfJourney(int id, vector<Journey> &journeys);
bool astronautAlreadyRegistered(string CPF, vector<Astronaut> &astronauts);
void verifyStatus(int id, vector<Journey> journeys);
void beginJourney(vector<Journey> &journeys, vector<Astronaut> &astronauts);

#endif