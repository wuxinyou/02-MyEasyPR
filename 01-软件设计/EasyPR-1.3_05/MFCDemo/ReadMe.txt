MFCDemo
20160809
1.测试将EasyPR和MFC融合。。。
2.基本完成EasyPR与MFC融合，EasyPR负责识别，MFC负责界面。20160811.
3.但是项目很乱没有整理。

EasyPR-1.3_03 MFCDemo
20160811
1.裁剪，整理基本完成.
2.删除了原有的Demo项目，只保留EasyPR和MFCDemo，其中MFCDemo是一个自建的MFC项目
3.新建MFC项目后，为MFCDemo添加引用EasyPR，然后在stdafx.h中添加相应的头文件，
	同时也需要在项目属性中添加：包含目录（include Directory），其目录就是相应头文件的目录。
4.然后在添加相应的识别代码，调试过程可能会出现一些报错，可以具体分析，然后解决。
5.问题：其中最大的问题就是：在unicode下string转CString的方法，还有转换后出现乱码的问题。
	chePai.Format(_T("%s"), CStringW(plateVec[0].data()));可以解决。
6.为了减小生成文件的大小和冗余，将输出文件统一放到上级目录的bin中。所以需要修改outPut directory和Intermidiate directory，
	修改后可能会生成多种中间文件从而造成编译异常，这时，可以将生成的中间文件全部删除掉，然后重新编译，运行，就没有问题了。

EasyPR-1.3_04 MFCDemo
20160811
1.编译成为一个可以发布运行的exe文件，由于在修改成use MFC in a static Library 后，编译出现问题，所以还是使用use  MFC in shared DLL.
	然后将需要的MFC库一起发布即可，实验证明使用shared DLL 的模式更好一些，在..\..\bin\debug目录下已经放置好的需要的MFC库以及OpenCV库，
	需要发布时，只需拷贝即可。

EasyPR-1.3_05 MFCDemo
20160812
1.添加拍照功能，实现了拍照后立即识别。
2.其中预览摄像头时用到了CvvImage类。是一个OpenCV1.0的类，高版本已经没有了，但是可以直接复制过来使用。

