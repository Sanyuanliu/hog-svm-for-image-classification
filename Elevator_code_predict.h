#pragma once
#include <string>
#ifdef CodePredictDLL_EXPORTS  
#define CodePredictDLL_API __declspec(dllexport)   
#else  
#define CodePredictDLL_API __declspec(dllimport)   
#endif  



class CodePredict
{
public:
	CodePredictDLL_API CodePredict();
	CodePredictDLL_API ~CodePredict();
	CodePredictDLL_API bool Predict(std::string imgname);


};

