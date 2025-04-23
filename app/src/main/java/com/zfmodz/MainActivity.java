package com.zfmodz;
 
import android.app.Activity;
import android.os.Bundle;

public class MainActivity extends Activity {
	static {
		System.loadLibrary("ZFMODZ");
	}
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
    }
} 
