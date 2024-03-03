#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm> 
#include <iomanip>
#include <sstream>

using namespace std;


bool writeOutput(string output) {
	ofstream outputFile;
	//open the output file and store the results
	outputFile.open("output.txt");
	if (outputFile.is_open())
	{
		outputFile << output;
		outputFile.close();

		return true;
	}

	return false;
};


double calculateMedian(vector<int> nums)
{
	size_t vectorSize = nums.size();

	//If the size of the vector is even, then the average of the two middle numbers is the median, else the median is the middle number.
	if (vectorSize % 2 == 0)
	{
		return (nums[vectorSize / 2 - 1] + nums[vectorSize / 2]) / 2;
	}
	else {
		return (nums[vectorSize / 2]);
	}

}


double calculateMean(double sum, int n)
{
	//divide the sum of all the numbers with the count of numbers to get the mean value
	return sum / n;
}



vector<int> calculateModes(vector<int> nums, vector<int> mode, int n) {
	vector<int> modeNumberVector;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) { continue; }
			//Check how many times each number is found in the vector
			if (nums[i] == nums[j])
			{
				mode[i]++;
			}
		}
	}

	//Check which number has the most repetitions in the set (could be multiple numbers)
	int max = mode[0];
	for (int i = 1; i < mode.size(); i++)
	{
		if (mode[i] > max)
		{
			max = mode[i];
		}
	}

	//If each number is unique, then there is no mode in the set
	if (max != 0) {
		for (int i = 0; i < mode.size(); i++)
		{
			if (mode[i] == max)
			{
				//Get the numbers found the most times in the vector
				modeNumberVector.push_back(nums[i]);
			}
		}

		sort(modeNumberVector.begin(), modeNumberVector.end());
		//remove any duplicated found in the vector
		modeNumberVector.erase(unique(modeNumberVector.begin(), modeNumberVector.end()), modeNumberVector.end());

		return modeNumberVector;

	}
}
int main() {

	ifstream inputFile;
	int inputNumber;
	int numberCounter = 0;
	int oddCounter = 0;
	int evenCounter = 0;
	int sum = 0;
	double mean = 0.0;
	double median = 0.0;
	int modeNumber = 0;
	bool foundMode = false;
	vector<int> mode;
	vector<int> numbersVector;
	vector<int> modeNumbers;


	//open the file
	inputFile.open("input.txt");
	if (inputFile.is_open()) {
		while (inputFile.good())
		{
			inputFile >> inputNumber;
			//store input numbers in a vector
			numbersVector.push_back(inputNumber);
			//init mode vector
			mode.push_back(0);

			sum += inputNumber;
			numberCounter++;
			//if the input number mod 2 is equal to 0 it means that its an even number, else its an odd number
			if (inputNumber % 2 == 0) {
				evenCounter++;
			}
			else {
				oddCounter++;
			}
		}
		mean = calculateMean(static_cast<double>(sum), numberCounter);


		


	}


	sort(numbersVector.begin(), numbersVector.end());

	modeNumbers = calculateModes(numbersVector, mode, numberCounter);
	



	median = calculateMedian(numbersVector);


	//use string stream to store the final values
	stringstream stream;
	stream << "Mean: " << mean << endl;
	stream << "Median: " << median << endl;
	//Check whether there set has mode numbers or not
	if (!modeNumbers.empty())
	{
		stream << "Mode: ";
		for (auto num : modeNumbers)
		{
			stream <<  num << " ";
		}
		stream << endl;
	}
	else {
		stream << "Mode: None (no repeated value)" << endl;
	}
	stream << "Even count: " << evenCounter << endl;
	stream << "Odd count: " << oddCounter << endl;
	writeOutput(stream.str());


	cout << stream.str();




	return 0;
};


