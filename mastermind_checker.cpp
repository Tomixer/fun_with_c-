#include <iostream>
#include <vector>


using namespace std;

enum class VAL
{
	R,
	G,
	B,
	Y
};

struct Result
{
	int hits{0}; // good color good spot
	int pseudo_hits{0}; // good color bad spot
};

ostream& operator<<( ostream &output, const Result &h ) {
  output << "Hits: " << h.hits << ", pseudo hits: " << h.pseudo_hits;
  return output;
}

Result check(vector<VAL> guess, vector<VAL> solution)
{
	Result retVal;

	// matched or pseudo matched in solution
	vector<bool> hit = {false, false, false, false};
	vector<bool> phit = {false, false, false, false};
	// hits
	for(int i = 0; i < 4; i++)
	{
		if(guess[i] == solution[i])
		{
			hit[i] = true;
			retVal.hits++;
		}
	}

	// pseudohits
	for(int i = 0; i < 4; i++)
	{
		if( !hit[i] )
		{
			for(int j=0; j < 4; j++)
			{
				if( (i != j) 
					&& !hit[j] 
					&& !phit[j] 
					&& (guess[i] == solution[j]) )
				{
					phit[j] = true;
					retVal.pseudo_hits++;
				}
			}
		}
	}
	
	return retVal;
}

int main(int , char **)
{
	cout << check({VAL::R, VAL::G, VAL::B, VAL::Y}, {VAL::R, VAL::G, VAL::B, VAL::Y}) << endl;
	cout << check({VAL::R, VAL::R, VAL::R, VAL::R}, {VAL::R, VAL::G, VAL::B, VAL::Y}) << endl;
	cout << check({VAL::R, VAL::G, VAL::G, VAL::R}, {VAL::R, VAL::G, VAL::R, VAL::G}) << endl;
	cout << check({VAL::G, VAL::G, VAL::G, VAL::B}, {VAL::R, VAL::R, VAL::R, VAL::R}) << endl;
	return 0;
}