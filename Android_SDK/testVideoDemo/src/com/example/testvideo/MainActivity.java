package com.example.testvideo;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import x1.Studio.Core.OnlineService;




public class MainActivity extends Activity {
//	 "guozeng";
//	 static char *password = "161619";
//	 static char *host = "www.scc21.com";
	private OnlineService ons;
	public String username="E320955";
	public String password="12023";
	public String host="www.scc21.com";
	
	
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		Button c = (Button) findViewById(R.id.click);
		ons = new OnlineService();
		c.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO 自动生成的方法存根
				int login_re = ons.sccLogin(username, password, host);
				Log.v(OnlineService.loglog,"login_re:"+login_re);
				
				/*int initv_re = ons.InitVideo();
				Log.v(OnlineService.loglog,"initv_re:"+initv_re);
				
				String H = ons.HK_VIDEO_H264;
				String get = ons.sccWANDevidCalling(1,devusername,devpsw,H,0);
				Log.v(OnlineService.loglog, "c click get:"+get);*/
			}
		});
	}

	

}
