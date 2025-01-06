//importing libraries
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

//funstion declarations
void blueFilter(string fileName);
void redFilter(string fileName);
void greenFilter(string fileName);
void grayScaleFilter(string fileName);

int main() {
	/*

	ofstream image;
	image.open("image.ppm");

	if (image.is_open()) {
		//place header info
		image << "P3" << endl;
		image << "250 250" << endl;
		image << "255" << endl;

		for (int y = 0; y < 250; y++) {
			for (int x = 0; x < 250; x++) {
				image << (x*y)%255 << " " << x << " " << x << endl;
			}
		}

	}

	image.close();

	ofstream image2;
	image2.open("image2.ppm");

	if (image2.is_open()) {
		//place header info
		image2 << "P3" << endl;
		image2 << "250 250" << endl;
		image2 << "255" << endl;

		for (int y = 0; y < 250; y++) {
			for (int x = 0; x < 250; x++) {
				image2 << (x * y) % 255 << " " << (x * y) % 255 << " " << (x * y) % 255 << endl;
			}
		}

	}

	image2.close();


	ofstream image3;
	image3.open("image3.ppm");
	//random number to set random colors
	srand((int)time(0));

	if (image3.is_open()) {
		//place header info
		image3 << "P3" << endl;
		image3 << "250 250" << endl;
		image3 << "255" << endl;

		for (int y = 0; y < 250; y++) {
			for (int x = 0; x < 250; x++) {
				image3 << rand() % 255 << " " << rand() % 255 << " " << rand() % 255 << endl;
			}
		}

	}

	image3.close();
	*/
	
	//getting file name from user

	string fileName = "";
	int filterOption = 0;

	cout << "What image would you like to filter (has to be a ppm file)?: " << endl;
	cin >> fileName;
	cout << "What filter would you like to use: " << endl;
	cout << "1- Red Filter" << endl;
	cout << "2- Green Filter" << endl;
	cout << "3- Blue Filter" << endl;
	cout << "4- grayScale Filter" << endl;
	cout << "Please select your option by entering the corresponding number: ";
	cin >> filterOption;

	cout << "Loading... This make take some time..." << endl;

	//switch handleling options
	//not passing by reference to avoid messing up the main file
	switch (filterOption) {
	case 1:
		redFilter(fileName);
		break;
	case 2:
		greenFilter(fileName);
		break;
	case 3:
		blueFilter(fileName);
		break;
	case 4:
		grayScaleFilter(fileName);
		break;
	default:
		cout << "an error occurred in the switch statement" << endl;
	}

	


	//displaying image using opencv
	//TODO do this without the OpenCV library

	cv::Mat imageReady = cv::imread("C:\\Users\\Jose\\source\\repos\\ImageProgrammingTest\\ImageProgrammingTest\\newimage.ppm");

	cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);

	// Display the image in a new window
	cv::imshow("Image", imageReady);

	cout << "filter applied, please check your files for new document." << endl;

	// Wait for a key press
	cv::waitKey(0);


	return 0;
}


//functions definitions

void blueFilter(string fileName) {

	/*BLUE FILTER*/
	ifstream image4;//getting image
	ofstream newimage;//creating new image holder

	image4.open(fileName); //openning image
	newimage.open("newimage.ppm"); //opening and creating new image holder

	//coppy over header information
	string type = "", width = "", height = "", RGB = "";
	//getting each string
	image4 >> type;
	image4 >> width;
	image4 >> height;
	image4 >> RGB;

	//transffering global identification files to new image
	newimage << type << endl;
	newimage << width << " " << height << endl;
	newimage << RGB << endl;

	//string placeholders
	string red = "", green = "", blue = "";
	int r = 0, g = 0, b = 0;

	//looping thru the original image data and copying it into string placeholders.
	while (!image4.eof()) {
		image4 >> red;
		image4 >> green;
		image4 >> blue;

		//convert to string placeholders to int
		stringstream redstream(red);
		stringstream greenstream(green);
		stringstream bluestream(blue);

		// writting int values into their respective int holders
		redstream >> r;
		greenstream >> g;
		bluestream >> b;

		//appying blue filter logic 
		if (b + 50 >= 255) {
			b = 255;
		}
		else {
			b += 50;
		}

		newimage << r << " " << g << " " << b << endl;

	}

	image4.close();
	newimage.close();
	//cout << type << width << height << RGB << endl;


}
void redFilter(string fileName) {

	/*RED FILTER*/
	ifstream image4;//getting image
	ofstream newimage;//creating new image holder

	image4.open(fileName); //openning image
	newimage.open("newimage.ppm"); //opening and creating new image holder

	//coppy over header information
	string type = "", width = "", height = "", RGB = "";
	//getting each string
	image4 >> type;
	image4 >> width;
	image4 >> height;
	image4 >> RGB;

	//transffering global identification files to new image
	newimage << type << endl;
	newimage << width << " " << height << endl;
	newimage << RGB << endl;

	//string placeholders
	string red = "", green = "", blue = "";
	int r = 0, g = 0, b = 0;

	//looping thru the original image data and copying it into string placeholders.
	while (!image4.eof()) {
		image4 >> red;
		image4 >> green;
		image4 >> blue;

		//convert to string placeholders to int
		stringstream redstream(red);
		stringstream greenstream(green);
		stringstream bluestream(blue);

		// writting int values into their respective int holders
		redstream >> r;
		greenstream >> g;
		bluestream >> b;

		//appying blue filter logic 
		if (r + 50 >= 255) {
			r = 255;
		}
		else {
			r += 50;
		}

		newimage << r << " " << g << " " << b << endl;

	}

	image4.close();
	newimage.close();
	//cout << type << width << height << RGB << endl;


}
void greenFilter(string fileName) {

	ifstream image4;
	ofstream newimage;

	/*GREEN Filter*/
	image4.open(fileName); // opening provided file to read contents
	newimage.open("newimage.ppm"); //output file with image with applied filter

	//creating string value holders
	string type = "", width = "", height = "", RGB = "";

	//getting the file info values. the ones that i dont need to iterate for
	image4 >> type;
	image4 >> width;
	image4 >> height;
	image4 >> RGB;

	newimage << type << endl;
	newimage << width << " " << height << " " << RGB <<endl;

	//iterating thru the file to get all RGB values
	string red;
	string green;
	string blue;

	int r;
	int g;
	int b;

	while (!image4.eof()) {
		image4 >> red;
		image4 >> green;
		image4 >> blue;
		
		stringstream redstream(red);
		stringstream greenstream(green);
		stringstream bluestream(blue);

		redstream >> r;
		greenstream >> g;
		bluestream >> b;

		if (g + 50 >= 250) {
			g = 250;
		}
		else {
			g += 50;
		}

		newimage << r << " " << g << " " << b << endl;
	}

	image4.close();
	newimage.close();

}
void grayScaleFilter(string fileName) {
	//take the sum of the RGB and divide it by 3

	/*GrayScale FILTER*/
	ifstream image4;//getting image
	ofstream newimage;//creating new image holder

	image4.open(fileName); //openning image
	newimage.open("newimage.ppm"); //opening and creating new image holder

	//coppy over header information
	string type = "", width = "", height = "", RGB = "";
	//getting each string
	image4 >> type;
	image4 >> width;
	image4 >> height;
	image4 >> RGB;

	//transffering global identification files to new image
	newimage << type << endl;
	newimage << width << " " << height << endl;
	newimage << RGB << endl;

	//string placeholders
	string red = "", green = "", blue = "";
	int r = 0, g = 0, b = 0;

	//looping thru the original image data and copying it into string placeholders.
	while (!image4.eof()) {
		image4 >> red;
		image4 >> green;
		image4 >> blue;

		//convert to string placeholders to int
		stringstream redstream(red);
		stringstream greenstream(green);
		stringstream bluestream(blue);

		// writting int values into their respective int holders
		redstream >> r;
		greenstream >> g;
		bluestream >> b;

		//appying blue filter logic 
		if ((r+g+b)/3 >= 255) {
			r = g = b = 225;
		}
		else {
			r = g = b = (r+g+b)/3;
		}

		newimage << r << " " << g << " " << b << endl;

	}

	image4.close();
	newimage.close();
	//cout << type << width << height << RGB << endl;

}