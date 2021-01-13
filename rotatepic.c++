#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	cout << "Enter Image paths: ";

	std::string image_path;
	cin >> image_path;
	Mat image = imread(image_path, IMREAD_COLOR);
	Mat dst;
	if (image.empty())
	{
		cout << "Error!!";
		cin.get();
		return-1;
	}
	Point2f pt(image.cols / 2., image.rows / 2.);
	double angle;
	cout << "\nInput rotation angle: ";
	cin >> angle;
	Mat r = getRotationMatrix2D(pt, angle, 1.0);
	warpAffine(image, dst, r, Size(image.cols, image.rows));
	String windowName = "My Window";
	namedWindow(windowName, WINDOW_AUTOSIZE);
	imshow(windowName, image);
	imshow(windowName, dst);
	waitKey(0);
	destroyWindow(windowName);
	return 0;
}
