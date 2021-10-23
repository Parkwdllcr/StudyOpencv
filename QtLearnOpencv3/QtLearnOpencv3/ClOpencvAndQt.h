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

	// ʵ��һ����Ƕ����������
	class CGarbo {
	public:
		~CGarbo() {
			if (ClOpencvAndQt::m_learnOpencv)
				delete ClOpencvAndQt::m_learnOpencv;
		}
	};
	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
	static CGarbo Garbo;
public:
    //QimageToMAt
    Mat     QimageToMat(QImage QscrImage);
    //MatToQImage
    QImage  MatToQimage(Mat smtx);
public:
	//��ͼƬ
	

	//��ͼƬ
	Mat		raedPicture(std::string strPictureName);
	//�����ļ�
	void	WritePicture(Mat srcImage);
	//ͼ������ֱ�����ʽ
	//��һ��at����
	void	ColorReduceOfAt(Mat& image, int idiv);
	//�ڶ��ַ�ʽ
	void	ColorReduceOfPtr(Mat &image,Mat &outImage,int idiv);
	//�����ַ�ʽ
	void	ColorReduceOfVec(Mat& image, Mat& outImage, int idiv);
	//���л�������
	//��
	Mat		AddOper(Mat srcIamgeOne, Mat srcImageTwo);
	Mat		AddLine(Mat srcImageOne, double dbAlpha, Mat srcImageTwo);
	Mat		AddImage(Mat srcImageOne, Mat srcImageTwo,double dbWeightTwo = 0.5, double dbWeightOne = 0.5,double dbgamma = 0.0);
	//��
	Mat		SubOper(Mat srcImageOne, Mat srcImageTwo);
	Mat		SubDiff(Mat srcImageOne, Mat srcImageTwo);
	//��
	//�����
	Mat		mulOper(Mat srcImageOne, Mat srcImageTwo);
	//���dot��������Լ�ע��
	//mul����
	Mat		mul(Mat srcImageOne, Mat srcImageTwo);
	//Mat		mulOper(Mat srcImageOne, Mat srcImageTwo);







private:
	// ���캯��˽��
	ClOpencvAndQt() {};
	// ������
	ClOpencvAndQt(ClOpencvAndQt  const&);
	static	std::mutex			m_mtx;
	static ClOpencvAndQt * m_learnOpencv; // ��������ָ��
};

