#include"windows.h"
#include"button.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
int main()
{
	
	Windows windows(500, 500, "±³¾°.png");
	Button play(200, 200, 70, 30, "PLAY");
	Button resume(200, 250, 70, 30, "RESUME");
	Button pause(200, 300, 70, 30, "PAUSE");
	Button close(200, 350, 70, 30, "CLOSE");
	mciSendString("open,music.mp3", 0, 0, 0);
	while (1)
	{
		BeginBatchDraw();
		
		EASYXMSG m = getmessage();
		play.DrawButton();
		resume.DrawButton();
		pause.DrawButton();
		close.DrawButton();
		if (play.Click(m))
		{
			
			mciSendString("play music.mp3", 0, 0, 0);
		}
		if (resume.Click(m))
		{
			mciSendString("resume music.mp3", 0, 0, 0);
		}
		if (pause.Click(m))
		{
			mciSendString("pause music.mp3", 0, 0, 0);
		}
		if (close.Click(m))
		{
			mciSendString("close music.mp3", 0, 0, 0);
		}
		FlushBatchDraw();
		
	}
	EndBatchDraw();
	while (1) {};
	return 0;
}