#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <opencv2/ml.hpp>
#include "Elevator_code_predict.h"

using namespace std;
using namespace cv;
using namespace cv::ml;
cv::Ptr<cv::ml::SVM> model = cv::ml::SVM::create();


	CodePredict::CodePredict()
	{
		model->setType(cv::ml::SVM::C_SVC);
		model->setKernel(cv::ml::SVM::LINEAR);
		model = SVM::load<SVM>("SVM_HOG_v1.xml");
	}

	CodePredict::~CodePredict()
	{
	}

	bool CodePredict::Predict(string imgname)
	{
		cv::Mat test = cv::imread(imgname);
		cv::resize(test, test, cv::Size(96, 96));
		std::vector<float> descriptors_test;
		cv::HOGDescriptor hog(cv::Size(96, 96), cv::Size(16, 16), cv::Size(8, 8), cv::Size(8, 8), 9);
		hog.compute(test, descriptors_test, cv::Size(8, 8));
		int DestestDim = int(descriptors_test.size());
		cv::Mat SampleTest = cv::Mat::zeros(1, DestestDim, CV_32FC1);
		for (int i = 0; i < DestestDim; i++)
		{
			SampleTest.at<float>(0, i) = descriptors_test[i];
		}
		int a = model->predict(SampleTest);
		return a;
			
	}




//#include <iostream>
//#include <string>
//#include "Elevator_code_predict.h"
//#pragma comment(lib,"DEMO.lib")
//
//	using namespace std;
//
//	int main()
//	{
//		CodePredict Elevator_code_predicter;
//
//		if (Elevator_code_predicter.Predict("pos.jpg"))
//		{
//			cout << "Predict result: positive sample" << endl;
//		}
//		else
//		{
//			cout << "Predict result: negative sample" << endl;
//		}
//
//		system("pause");
//		return 0;
//
//
//	}