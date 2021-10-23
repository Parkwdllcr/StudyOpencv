#pragma once
#include <QImage>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QApplication>
#include <QFileDialog>

using namespace cv;
class ClOpencvAndQt  
{

public:
	static	ClOpencvAndQt* getInstance()
	{
		if (nullptr == m_learnOpencv)
		{
			m_mtx.lock();
			if (nullptr == m_learnOpencv)
				m_learnOpencv = new ClOpencvAndQt();
			m_mtx.unlock();
		}
		return m_learnOpencv;
	}

	// 实现一个内嵌垃圾回收类
	class CGarbo {
	public:
		~CGarbo() {
			if (ClOpencvAndQt::m_learnOpencv)
				delete ClOpencvAndQt::m_learnOpencv;
		}
	};
	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;
public:
    //QimageToMAt
    Mat     QimageToMat(QImage QscrImage);
    //MatToQImage
    QImage  MatToQimage(Mat smtx);
public:
	//打开图片
	

	//读图片
	Mat		raedPicture(std::string strPictureName);
	//保存文件
	void	WritePicture(Mat srcImage);
	//图像的五种遍历方式
	//第一种at遍历
	void	ColorReduceOfAt(Mat& image, int idiv);
	//第二种方式
	void	ColorReduceOfPtr(Mat &image,Mat &outImage,int idiv);
	//第三种方式
	void	ColorReduceOfVec(Mat& image, Mat& outImage, int idiv);
	//进行基本操作
	//加
	Mat		AddOper(Mat srcIamgeOne, Mat srcImageTwo);
	Mat		AddLine(Mat srcImageOne, double dbAlpha, Mat srcImageTwo);
	Mat		AddImage(Mat srcImageOne, Mat srcImageTwo,double dbWeightTwo = 0.5, double dbWeightOne = 0.5,double dbgamma = 0.0);
	//减
	Mat		SubOper(Mat srcImageOne, Mat srcImageTwo);
	Mat		SubDiff(Mat srcImageOne, Mat srcImageTwo);
	//乘
	//矩阵乘
	Mat		mulOper(Mat srcImageOne, Mat srcImageTwo);
	//点乘dot函数这个自己注意
	//mul函数
	Mat		mul(Mat srcImageOne, Mat srcImageTwo);
	//Mat		mulOper(Mat srcImageOne, Mat srcImageTwo);







private:
	// 构造函数私有
	ClOpencvAndQt() {};
	// 防拷贝
	ClOpencvAndQt(ClOpencvAndQt  const&);
	static	std::mutex			m_mtx;
	static ClOpencvAndQt * m_learnOpencv; // 单例对象指针
};

