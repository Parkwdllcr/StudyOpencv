#include "ClOpencvAndQt.h"

cv::Mat ClOpencvAndQt::QimageToMat(QImage QscrImage)
{
	Mat  resultImage;
	switch (QscrImage.format())
	{
	case QImage::Format_ARGB32_Premultiplied:
		resultImage = Mat(QscrImage.height(), QscrImage.width(), CV_8UC4, (void*)QscrImage.bits());
		break;
	case QImage::Format_RGB888:
		resultImage = Mat(QscrImage.height(), QscrImage.width(), CV_8UC3, (void*)QscrImage.bits());
		cvtColor(resultImage, resultImage, COLOR_BGR2RGB);//opencv4不一样
		break;
	case QImage::Format_Indexed8:
		resultImage = Mat(QscrImage.height(), QscrImage.width(), CV_8UC1, (void*)QscrImage.bits());
		break;
	default:
		resultImage = Mat(QscrImage.height(), QscrImage.width(), CV_8UC3, (void*)QscrImage.bits());
		cvtColor(resultImage, resultImage, COLOR_BGR2RGB);//opencv4不一样
		break;
	}
	return resultImage;
}

QImage ClOpencvAndQt::MatToQimage(Mat mtx)
{
	switch (mtx.type())
	{
	     case CV_8UC1:
	     {
	     	QImage img((const unsigned char*)(mtx.data), mtx.cols, mtx.rows, mtx.cols, QImage::Format_Grayscale8);
	     	return img;
	     }
	     break;
	     case CV_8UC3:
	     {
	     	QImage img((const unsigned char*)(mtx.data), mtx.cols, mtx.rows, mtx.cols * 3, QImage::Format_RGB888);
	     	return img.rgbSwapped();
	     }
	     break;
	     case CV_8UC4:
	     {
	     	QImage img((const unsigned char*)(mtx.data), mtx.cols, mtx.rows, mtx.cols * 4, QImage::Format_ARGB32);
	     	return img;
	     }
	     break;
	     default:
	     {
	     	QImage img;
	     	return img;
	     }
	     break;
	}

}



cv::Mat ClOpencvAndQt::raedPicture(std::string strPictureName)
{
	Mat  srcImage = imread(strPictureName);
	return srcImage;
}

void ClOpencvAndQt::WritePicture(Mat srcImage)
{
	imwrite("dstImage.jpg", srcImage);
}

void ClOpencvAndQt::ColorReduceOfAt(Mat& image, int idiv)
{
	//注意这种算法
	for (int i = 0;i != image.rows;i++)
	{
		for (int j = 0;j != image.cols;j++)
		{
			image.at<Vec3b>(i, j)[0] = image.at<Vec3b>(i, j)[0] / idiv * idiv + idiv / 2;
			image.at<Vec3b>(i, j)[1] = image.at<Vec3b>(i, j)[1] / idiv * idiv + idiv / 2;
			image.at<Vec3b>(i, j)[2] = image.at<Vec3b>(i, j)[2] / idiv * idiv + idiv / 2;
		}
	}
}

void ClOpencvAndQt::ColorReduceOfPtr(Mat& image, Mat& outImage, int idiv)
{
	//主要是要判断图片连续不连续
	int nr = image.rows;
	int nc = image.cols;
	outImage.create(image.size(), image.type());
	if (image.isContinuous() && outImage.isContinuous())
	{
		nr = 1;
		nc = nc * image.rows * image.channels();
	}
	for (int i = 0; i < nr; i++)
	    {
	        const uchar * inData = image.ptr<uchar>(i);
	        uchar * outData = outImage.ptr<uchar>(i);
	        for (int j = 0; j < nc; j++)
	        {
		        * outData++ = *inData++ / idiv * idiv + idiv / 2;
		    }
		}
}

void ClOpencvAndQt::ColorReduceOfVec(Mat& image, Mat& outImage, int idiv)
{
	//和上面的类似
	outImage.create(image.size(), image.type());
	MatConstIterator_<Vec3b> itbegin_in = image.begin<Vec3b>();
	MatConstIterator_<Vec3b> itend_in = image.end<Vec3b>();
	MatIterator_<Vec3b> itbeigin_out = outImage.begin<Vec3b>();
	MatIterator_<Vec3b> itend_out = outImage.end<Vec3b>();
	while (itbegin_in != itend_in)
	{
		(*itbeigin_out)[0] = (*itbegin_in)[0] / idiv * idiv + idiv / 2;
		(*itbeigin_out)[1] = (*itbegin_in)[1] / idiv * idiv + idiv / 2;
		(*itbeigin_out)[2] = (*itbegin_in)[2] / idiv * idiv + idiv / 2;
		itbegin_in++;
		itbeigin_out++;
	}
}

cv::Mat ClOpencvAndQt::AddOper(Mat srcIamgeOne, Mat srcImageTwo)
{
	Mat resImage = srcIamgeOne + srcImageTwo;
	return resImage;
}


cv::Mat ClOpencvAndQt::AddLine(Mat srcImageOne, double dbAlpha, Mat srcImageTwo)
{
	Mat resImage;
	scaleAdd(srcImageOne, dbAlpha, srcImageTwo, resImage);
	return resImage;
}

cv::Mat ClOpencvAndQt::AddImage(Mat srcImageOne, Mat srcImageTwo, double dbWeightTwo /*= 0.5*/, double dbWeightOne /*= 0.5*/, double dbgamma /*= 0.0*/)
{
	Mat ResultImage;
	addWeighted(srcImageOne, dbWeightOne, srcImageTwo, dbWeightTwo, dbgamma,ResultImage);
	return  ResultImage;
}

cv::Mat ClOpencvAndQt::SubOper(Mat srcImageOne, Mat srcImageTwo)
{
	Mat resImage = srcImageOne - srcImageTwo;
	return resImage;

}

cv::Mat ClOpencvAndQt::SubDiff(Mat srcImageOne, Mat srcImageTwo)
{
	Mat resImage;
	absdiff(srcImageOne, srcImageTwo, resImage);
	return resImage;
}

cv::Mat ClOpencvAndQt::mulOper(Mat srcImageOne, Mat srcImageTwo)
{
	Mat resultImage = srcImageOne * srcImageTwo;
	return resultImage;
}

cv::Mat ClOpencvAndQt::mul(Mat srcImageOne, Mat srcImageTwo)
{
	Mat resImage = srcImageOne.mul(srcImageTwo);
	return resImage;
}

