#ifndef EASYPR_PLATE_HPP
#define EASYPR_PLATE_HPP

namespace easypr {

namespace demo {

using namespace cv;
using namespace std;

int test_plate_locate() {
  cout << "test_plate_locate" << endl;

  const string file = "resources/image/test.jpg";

  cv::Mat src = imread(file);
  
  //TODO：原plateLocate需要被替换

  vector<cv::Mat> resultVec;
  CPlateLocate plate;
  plate.setDebug(1);
  plate.setLifemode(true);

  int result = plate.plateLocate(src, resultVec);
  if (result == 0) {
    size_t num = resultVec.size();
    for (size_t j = 0; j < num; j++) {
      cv::Mat resultMat = resultVec[j];
      imshow("plate_locate", resultMat);
      waitKey(0);
    }
    destroyWindow("plate_locate");
  }

  return result;
}

int test_plate_judge() {
  cout << "test_plate_judge" << endl;

  cv::Mat src = imread("resources/image/plate_judge.jpg");

  //可能是车牌的图块集合
  vector<cv::Mat> matVec;

  //经过SVM判断后得到的图块集合
  vector<cv::Mat> resultVec;

  CPlateLocate lo;
  lo.setDebug(1);
  lo.setLifemode(true);

  int resultLo = lo.plateLocate(src, matVec);

  if (0 != resultLo)
    return -1;

  cout << "plate_locate_img" << endl;
  size_t num = matVec.size();
  for (size_t j = 0; j < num; j++) {
    Mat resultMat = matVec[j];
    imshow("plate_judge", resultMat);
    waitKey(0);
  }
  destroyWindow("plate_judge");

  CPlateJudge ju;
  ju.LoadModel("resources/model/svm.xml");
  int resultJu = ju.plateJudge(matVec, resultVec);

  if (0 != resultJu)
    return -1;

  cout << "plate_judge_img" << endl;
  num = resultVec.size();
  for (size_t j = 0; j < num; j++) {
    Mat resultMat = resultVec[j];
    imshow("plate_judge", resultMat);
    waitKey(0);
  }
  destroyWindow("plate_judge");

  return resultJu;
}

int test_plate_detect() {
  cout << "test_plate_detect" << endl;

  cv::Mat src = imread("resources/image/plate_detect.jpg");

  vector<CPlate> resultVec;
  CPlateDetect pd;
  pd.setPDLifemode(true);

  int result = pd.plateDetect(src, resultVec);
  if (result == 0) {
    size_t num = resultVec.size();
    for (size_t j = 0; j < num; j++) {
      CPlate resultMat = resultVec[j];

      imshow("plate_detect", resultMat.getPlateMat());
      waitKey(0);
    }
    destroyWindow("plate_detect");
  }

  return result;
}


//车牌识别函数：
//步骤：包含加载图片，加载训练好的模型，车牌识别，返回车牌号字符串。
int test_plate_recognize()
{
  cout << "test_plate_recognize" << endl;

  Mat src = imread("resources/image/test.jpg");

  CPlateRecognize pr;
  pr.LoadANN("resources/model/ann.xml");
  pr.LoadSVM("resources/model/svm.xml");

  pr.setLifemode(true);
  pr.setDebug(true);

  vector<string> plateVec;

  //其中plateRecognize()就是车牌识别的整个过程
  //src是图片mat，plateVec是字符串向量，因为有可能存在多个车牌
  //返回0说明识别完成，但是不一定正确，因为算法是无法知道正确与否的，他肯定认为自己的结果一定是正确的。
 
  int result = pr.plateRecognize(src, plateVec);


  if (result == 0) {
	  //保存车牌数目
    size_t num = plateVec.size();
    for (size_t j = 0; j < num; j++) {
      cout << "plateRecognize: " << plateVec[j] << endl;
    }
  }

  //
  //cout << "ResultPlateRecognize: " << plateVec[j] << endl;

  if (result != 0)
    cout << "result:" << result << endl;

  return result;
}

}
//end of namespace demo


} //end of namespace easypr

#endif //EASYPR_PLATE_HPP
