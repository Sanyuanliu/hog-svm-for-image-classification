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


	void CodePredict::Model_train()
	{
		
		//cv::HOGDescriptor hog(cv::Size(48, 48), cv::Size(16, 16), cv::Size(8, 8), cv::Size(8, 8), 9);
		//int DescriptorDim;
		//int PosSamNO, NegSamNO, HardExampleNO;
		//PosSamNO = 989;
		//NegSamNO = 1634;
		//HardExampleNO = 0;
		//cv::Ptr<cv::ml::SVM> svm = cv::ml::SVM::create();
		//svm->setType(cv::ml::SVM::Types::C_SVC);
		//svm->setKernel(cv::ml::SVM::KernelTypes::LINEAR);
		//svm->setTermCriteria(cv::TermCriteria(cv::TermCriteria::MAX_ITER, 100, 1e-6));
		//std::string ImgName;
 	//	std::ifstream finPos("positive.txt");
		//std::ifstream finNeg("negative.txt");
 	//	cv::Mat sampleFeatureMat;
  //		cv::Mat sampleLabelMat;
 	//	for (int num = 0; num < PosSamNO && std::getline(finPos, ImgName); num++)
		//{
		//	cv::Mat image = cv::imread(ImgName);
		//	cv::resize(image, image, cv::Size(48, 48));
		//	std::vector<float> descriptors;
		//	hog.compute(image, descriptors, cv::Size(8, 8));
		//	if (0 == num)
		//	{
		//		DescriptorDim = int(descriptors.size());
		//		sampleFeatureMat = cv::Mat::zeros(PosSamNO + NegSamNO, DescriptorDim, CV_32FC1);
		//		sampleLabelMat = cv::Mat::zeros(PosSamNO + NegSamNO, 1, CV_32SC1);
		//	}
  // 
		//	for (int i = 0; i < DescriptorDim; i++)
		//	{
		//		sampleFeatureMat.at<float>(num, i) = descriptors[i];
		//	}  
		//	sampleLabelMat.at<int>(num, 0) = 1;
		//}

  // 
		//for (int num = 0; num < NegSamNO && getline(finNeg, ImgName); num++)
		//{

		//	cv::Mat src = cv::imread(ImgName);
		//	cv::resize(src, src, cv::Size(48, 48));


		//	std::vector<float> descriptors;
 
		//	hog.compute(src, descriptors, cv::Size(8, 8));
  //
		//	for (int i = 0; i < DescriptorDim; i++)
		//	{
		//		sampleFeatureMat.at<float>(num + PosSamNO, i) = descriptors[i];
		//	}

		//	sampleLabelMat.at<int>(num + PosSamNO, 0) = -1;
		//}


		//if (HardExampleNO > 0)
		//{
 
		//	std::ifstream finHardExample("hard_samples_d.txt");
		//	for (int num = 0; num < HardExampleNO && getline(finHardExample, ImgName); num++)
		//	{
		//		cv::Mat src = cv::imread(ImgName, cv::IMREAD_GRAYSCALE);
		//		cv::resize(src, src, cv::Size(48, 48));
		//		std::vector<float> descriptors;
		//		hog.compute(src, descriptors, cv::Size(8, 8));
		//		for (int i = 0; i < DescriptorDim; i++)
		//		{
		//			sampleFeatureMat.at<float>(num + PosSamNO + NegSamNO, i) = descriptors[i];
		//		}
		//		sampleLabelMat.at<float>(num + PosSamNO + NegSamNO, 0) = -1;
		//	}
		//}
		//
		//
		//
		//svm->train(sampleLabelMat);

		//svm->save("svm.xml");
	
	
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