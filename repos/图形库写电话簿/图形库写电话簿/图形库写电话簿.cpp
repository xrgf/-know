#include"button.h"
#include"dateOperate.h"
IMAGE img;
int main()
{
	
	


	initgraph(WIDTH, HEIGHT);
	while (1)
	{

		BeginBatchDraw();
		IPBUTTON deletepeople = creatbutton(230, 280, 100, 60, RED, BLUE, GREEN,"ɾ����ϵ��");
		IPBUTTON creatpeople = creatbutton(230, 200, 100, 60, RED, BLUE, GREEN,"�½���ϵ��");
		drawbutton(deletepeople);
		drawbutton(creatpeople);
		EASYXMSG m = getmessage();
		loadimage(&img, "����.jpg", WIDTH, HEIGHT);
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