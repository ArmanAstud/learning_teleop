#include <iostream>
#include <opencv2/opencv.hpp>

#define ESCAPE 27

using namespace std;
using namespace cv;

int main()
{
	Mat frame;

	VideoCapture capture(0);

	char keypressed = 0;

	bool sucess;


	if(!capture.isOpened())
	{
		cout<<"No se pudo abrir video"<<endl;
		return 1;
	}
	else
	{
		cout<<"video cargada con exito"<<endl<<endl;
	}

	namedWindow("original", CV_WINDOW_AUTOSIZE);

	while(keypressed != ESCAPE)
	{
		sucess = capture.read(frame);
		if (sucess == false)
		{
			cout << "Cannot read the file" <<endl;
			return 1;
		}

		imshow("original", frame);

		//keypressed = waitKey(0);
		waitKey(20);
		
	}

	destroyWindow("original");
	capture.release();


	return 0;
}