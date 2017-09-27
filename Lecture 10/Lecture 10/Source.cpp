#include <iostream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;


float getValidInput(std::string prompt)
{
	std::string input;
	std::stringstream convert;
	float output;

	do
	{
		//Reset the stringstream, if applicable
		if (convert.fail())
		{
			convert = std::stringstream();
			convert.clear();
		}

		//Get input from the user
		cout << "PLease enter your " << prompt << " >";
		std::getline(cin, input);

		//Convert it to a number
		convert << input;
		convert >> output;

		if (convert.fail()) cout << "I'm sorry, I don't understand \"" << input << "\".  Please try again." << endl;
		else if (output <= 0) cout << "Please enter a value greater than 0." << endl;

	} while (convert.fail() || output <= 0);
	return output;
}


int main()
{
	float height = getValidInput("height");
	float weight = getValidInput("weight");


	float BMI = weight * 703 / pow(height, 2);

	cout << endl << "Your BMI is " << BMI << endl << endl;

	cout << "Interpretation and instructions:" << endl;
	if (BMI < 20) cout << "Underweight: Have a milk shake." << endl;
	else if (BMI < 26) cout << "Normal: Have a glass of milk." << endl;
	else if (BMI < 30) cout << "Overweight: Have a glass of iced tea." << endl;
	else cout << "Obese: See your doctor." << endl;

	std::cin.get();
}