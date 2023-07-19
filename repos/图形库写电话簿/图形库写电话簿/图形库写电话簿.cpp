#include"button.h"
#include"dateOperate.h"
IMAGE img;
int main()
{
	
	


	initgraph(WIDTH, HEIGHT);
	while (1)
	{

		BeginBatchDraw();
		IPBUTTON deletepeople = creatbutton(230, 280, 100, 60, RED, BLUE, GREEN,"删除联系人");
		IPBUTTON creatpeople = creatbutton(230, 200, 100, 60, RED, BLUE, GREEN,"新建联系人");
		drawbutton(deletepeople);
		drawbutton(creatpeople);
		EASYXMSG m = getmessage();
		loadimage(&img, "背景.jpg", WIDTH, HEIGHT);
		putimage(0, 0, &img);
		
		if (mousemove(creatpeople,m) && m.message == WM_LBUTTONDOWN)
		{
		
		}
		if (mousemove(deletepeople, m) && m.message == WM_LBUTTONDOWN)
		{

		}
		EndBatchDraw();
	}

	

	closegraph();









	return 0;
}