#include <iostream>
using namespace std;

class Game {
public:
	Game(string n = " ", int score = 0) { name = n; this->score = score; }
	string GetName() const;
	int GetScore() const;
private: 
	string name;
	int score;
};

class Score {
public:
	Score(int max_cap=10);
	~Score();
	void add(const Game& player_info);
	Game remove(int index);
private:
	int max_capacity;
	int current_cap;
	Game* entries;
};

int main() {


	return 0;
}

string Game::GetName() const
{
	return name;
}

int Game::GetScore() const
{
	return score;
}

Score::Score(int max_cap)
{
	max_capacity = max_cap;
	current_cap = 0;
	entries = new Game[max_capacity];
}

Score::~Score()
{
	delete[] entries;
}


void Score::add(const Game& player_info)
{
	int new_score = player_info.GetScore();

	if (current_cap == max_capacity)
		if (new_score <= entries[max_capacity - 1].GetScore())
			return;
		else
		current_cap++;
    
	int next_elem = current_cap - 2;
	while (next_elem >= 0 && new_score > entries[next_elem].GetScore()) {
		entries[next_elem + 1] = entries[next_elem];
		next_elem--;
	}
	entries[next_elem + 1] = player_info;
}

Game Score::remove(int index)
{
	if ((index < 0) || (index > max_capacity))
		throw ("Out of boundaries");

	Game player_to_remove = entries[index];
	for (int next_index = index + 1; next_index < max_capacity; next_index++) {
		entries[next_index - 1] = entries[next_index];
	}
	max_capacity--;
	return player_to_remove;
}
